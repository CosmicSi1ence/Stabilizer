#include "stabMain.h"

#include "stab.h"
#include "stab2.h"
#include "stab2g.h"
#include "stabFull.h"
#include "stabFullg.h"
#include "err.h"
#include "filter_gpu.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudafilters.hpp>

#include <iostream>
#include <windows.h>
#include <string>

using namespace cv;
using namespace std;

int stabMain(string sourcePath, string resultPath, uint8_t k_filter, uint8_t delta, uint8_t alg, uint8_t proc, uint8_t info, bool* close, double* timeRem, bool* stopTimer) {

    Mat source, source_f, result, result_f;   //  Matrices for source, filtered source and result images

    VideoCapture cap(sourcePath);
    cap.read(source);
    uint32_t framesRem = cap.get(CAP_PROP_FRAME_COUNT);

    Mat source_(source, Rect(delta, 0, source.cols - 2 * delta, source.rows - 2 * delta));
    source = source_.clone();

    Size S = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT));
    int ex = static_cast<int>(cap.get(CAP_PROP_FOURCC));                                            //  Get Codec Type- Int form

    auto fil = cuda::createBoxFilter(24, 24, Size(k_filter, k_filter), Point(-1, -1), BORDER_REFLECT);

    if (proc == 0) {
        boxFilter(source, source_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);
    }
    else if (proc == 1) {
        source_f = filter_gpu(source, *fil);
    }


    VideoWriter writer;
    writer.open(resultPath, ex, cap.get(CAP_PROP_FPS), Size(source_f.cols, source_f.rows), true);

    int count = 0;
    while (true) {
        cap.read(result);

        if (result.empty()) {
            printf("Video ended\n");
            break;
        }

        auto start = getTickCount();    ///////////////////////////

        if (proc == 0 && alg == 0) {
            stab2(source_f, result, delta, k_filter).copyTo(result);
        }
        else if (proc == 1 && alg == 0) {
            stab2g(source_f, result, *fil, delta, k_filter).copyTo(result);
        }
        else if (proc == 0 && alg == 1) {
            stabFull(source_f, result, delta, k_filter).copyTo(result);
        }
        else if (proc == 1 && alg == 1) {
            stabFullg(source_f, result, *fil, delta, k_filter).copyTo(result);
        }

        auto end = getTickCount();      ///////////////////////////

        auto frameTime = (end - start) / getTickFrequency();
        auto fps = 1 / frameTime;
        printf("%d\tFrame time: %f\t", count, frameTime);
        Mat resultInfo = result.clone();
        if (info == 0) {
            putText(resultInfo, to_string(frameTime), Point(5, 25), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 200), 2);
        }
        else if (info == 1) {
            putText(resultInfo, to_string((int)fps), Point(5, 25), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 200), 2);
        }
        imshow("Video " + to_string(resultInfo.cols) + "x" + to_string(resultInfo.rows), resultInfo);
        writer << result;
        source = result.clone();

        if (*close) {
            break;
        }

        waitKey(1);

        auto end2 = getTickCount();
        auto frameTime2 = (end2 - start) / getTickFrequency();
        --framesRem;
        *timeRem = frameTime2 * (double)framesRem;
        //printf("\nFrames:\t%f\tFrametime:\t%f\tTIME:\t%f\n", (double)framesRem, frameTime2, *timeRem);
        ++count;
    }
    cap.release();
    *stopTimer = true;

    //waitKey(0);
    destroyAllWindows();
    return 0;
}
