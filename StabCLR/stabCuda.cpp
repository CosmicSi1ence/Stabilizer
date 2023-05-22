#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudafilters.hpp>

#include <iostream>
#include <windows.h>

#include "stab.h"
#include "stab2.h"
#include "stab2g.h"
#include "err.h"
#include "filter_gpu.h"

#include <string>

using namespace cv;
using namespace std;

int stabCuda() {
    //clock_t tStart = clock();
    //printCudaDeviceInfo(0);

    ShowWindow(GetConsoleWindow(), SW_SHOW);    //     вкл/выкл назойливую консоль (переключение SW_SHOW / SW_HIDE)

    uint16_t delta = 30;
    uint8_t k_filter = 11;

    //char filename1[] = "Resources/image1.jpg";
    //char fullFilename1[MAX_PATH];
    //GetFullPathNameA(filename1, MAX_PATH, fullFilename1, nullptr);
    //Mat img = imread(fullFilename1, IMREAD_GRAYSCALE);
    //string img_label = "img " + to_string(img.cols) + "x" + to_string(img.rows);
    //namedWindow(img_label, WINDOW_AUTOSIZE);
    //imshow(img_label, img);
    //moveWindow(img_label, 0, 65);

    //Mat img1_(img, Rect(delta, delta, img.cols - 2 * delta, img.rows - 2 * delta));
    //Mat img1;
    //img1_.copyTo(img1);
    //string img1_label = "img1 " + to_string(img1.cols) + "x" + to_string(img1.rows);
    //namedWindow(img1_label, WINDOW_AUTOSIZE);
    //imshow(img1_label, img1);
    //moveWindow(img1_label, img.cols+1, 65);

    //Mat img2_(img, Rect(delta, 0, img.cols - 2 * delta, img.rows - 2 * delta));
    //Mat img2;
    //img2_.copyTo(img2);
    //string img2_label = "img2 " + to_string(img2.cols) + "x" + to_string(img2.rows);
    //namedWindow(img2_label, WINDOW_AUTOSIZE);
    //imshow(img2_label, img2);
    //moveWindow(img2_label, img.cols + 1 + img1.cols + 1, 65);



    ////////////////////////////////////////////////////////////////////////////////////////

    //Mat img1_roi_(img1, Rect(0, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));
    //Mat img1_roi;
    //img1_roi_.copyTo(img1_roi);
    //string img1_roi_label = "img1_roi " + to_string(img1_roi.cols) + "x" + to_string(img1_roi.rows);
    //namedWindow(img1_roi_label, WINDOW_AUTOSIZE);
    //imshow(img1_roi_label, img1_roi);
    //moveWindow(img1_roi_label, 0, 65);

    //Mat img1_f;
    //img1_roi.copyTo(img1_f);
    //boxFilter(img1_roi, img1_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);
    //Mat img2_st;
    //stab2(img1_f, img2, delta, k_filter).copyTo(img2_st);
    //string img2_st_label = "img2_st " + to_string(img2_st.cols) + "x" + to_string(img2_st.rows);
    //namedWindow(img2_st_label, WINDOW_AUTOSIZE);
    //imshow(img2_st_label, img2_st);
    //moveWindow(img2_st_label, img1_roi.cols + 1, 65);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //  Defining the paths:
    char filenameSource[] = "Resources/vid1.mp4";
    char filenameResult[] = "Resources/vid1st.mp4";
    char fullFilenameSource[MAX_PATH];
    char fullFilenameResult[MAX_PATH];
    GetFullPathNameA(filenameSource, MAX_PATH, fullFilenameSource, nullptr);
    GetFullPathNameA(filenameResult, MAX_PATH, fullFilenameResult, nullptr);

    Mat source, source_f, result, result_f;   //  Matrices for source, filtered source and result images

    VideoCapture cap(fullFilenameSource);
    cap.read(source);

    Size S = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT));
    int ex = static_cast<int>(cap.get(CAP_PROP_FOURCC));                                            //  Get Codec Type- Int form
    source = source(Rect(delta, 0, source.cols - 2 * delta, source.rows - 2 * delta));              //  Cropping  the first frame

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto start = getTickCount();    ////////////////////////////////////////////////////
    cvtColor(source, source, CV_8UC1);
    auto end = getTickCount();
    printf("\nCVT: %f\n", (end - start) / getTickFrequency());///////////////////////////

    auto fil = cuda::createBoxFilter(source.type(), source.type(), Size(k_filter, k_filter), Point(-1, -1), BORDER_REFLECT);

    //boxFilter(source, source_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT); //  filtering the first frame
    source_f = filter_gpu(source, *fil);

    VideoWriter writer;
    writer.open(fullFilenameResult, ex, cap.get(CAP_PROP_FPS), Size(source_f.cols, source_f.rows), true);

    int count = 0;
    while(true) {
        bool isSuccess = cap.read(result);

        if (result.empty()) {
            printf("Video ended\n");
            break;
        }

        auto start = getTickCount();    ///////////////////////////

        //stab2(source_f, result, delta, k_filter).copyTo(result);
        stab2g(source_f, result, *fil, delta, k_filter).copyTo(result);

        auto end = getTickCount();      ///////////////////////////

        auto totalTime = (end - start) / getTickFrequency();
        auto fps = 1 / totalTime;
        printf("%d\tFrame time: %f\t", count, totalTime);
        putText(result, to_string(totalTime), Point(5, 25), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 200), 2);
        imshow("Video " + to_string(result.cols) + "x" + to_string(result.rows), result);
        writer << result;
        result.copyTo(source);

        waitKey(1);
        ++count;
    }
    cap.release();


    //waitKey(0);
    destroyAllWindows();
    return 0;

}
