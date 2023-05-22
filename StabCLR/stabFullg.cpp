#include "stabFullg.h"
#include "filter_gpu.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/cudafilters.hpp>

#include <windows.h>
#include "err.h"

#include <time.h>
#include <iostream>

using namespace cv;

Mat stabFullg(Mat& img1_f, Mat& img2, cv::cuda::Filter& fil, uint16_t delta, uint8_t k_filter) {

	auto start = getTickCount();    ///////////////////////////

	Mat img2_f;
	img2_f = filter_gpu(img2, fil);

	auto end = getTickCount();    ///////////////////////////
	auto totalTime = (end - start) / getTickFrequency();
	printf("\tFiltering time: %f", totalTime);

	//	TEST:
	//uint32_t errors[40][40];


	uint16_t shift_x = 0;
	uint16_t shift_y = 0;
	uint32_t error = 0;
	uint32_t min = img2_f.rows * img2_f.cols * 255;
	for (uint16_t i = 0; i < 2 * delta + 1; ++i) {
		for (uint16_t j = 0; j < 2 * delta + 1; ++j) {
			Mat img2_f_roi_(img2_f, Rect(j, i, img1_f.cols, img1_f.rows));
			Mat img2_f_roi = img2_f_roi_.clone();
			error = err(img1_f, img2_f_roi);

			//	TEST:
			//errors[i][j] = error;

			if (error < min) {
				min = error;
				shift_x = j;
				shift_y = i;
			}
		}
	}

	////	TEST:
	//printf("\n\n");
	//for (uint32_t i = 0; i < 40; ++i) {
	//	for (uint32_t j = 0; i < 40; ++i) {
	//		printf("%d\t", errors[i][j]);
	//	}
	//	printf("\n");
	//}


	int dx = shift_x - delta;
	int dy = shift_y - delta;
	printf("\tdx:%d\tdy:%d\n", dx, dy);
	Rect shift = Rect(shift_x, shift_y, img1_f.cols, img1_f.rows);

	Mat img_out_(img2, shift);
	Mat img_out = img_out_.clone();

	Mat img2to1_f(img2_f, shift);
	img1_f = img2to1_f.clone();

	return img_out;
}