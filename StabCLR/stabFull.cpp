#include "stabFull.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <windows.h>
#include "err.h"

#include <time.h>
#include <iostream>

using namespace cv;

Mat stabFull(Mat& img1_f, Mat& img2, uint16_t delta, uint8_t k_filter) {

	auto start = getTickCount();    ///////////////////////////

	Mat img2_f;
	boxFilter(img2, img2_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);	//	img2 filtering

	auto end = getTickCount();    ///////////////////////////
	auto totalTime = (end - start) / getTickFrequency();
	printf("\tFiltering time: %f", totalTime);

	uint16_t shift_x = 0;
	uint16_t shift_y = 0;
	uint32_t error = 0;
	uint32_t min = img2_f.rows * img2_f.cols * 255;
	for (uint16_t i = 0; i < 2 * delta + 1; ++i) {
		for (uint16_t j = 0; j < 2 * delta + 1; ++j) {
			Mat img2_f_roi_(img2_f, Rect(j, i, img1_f.cols, img1_f.rows));
			Mat img2_f_roi = img2_f_roi_.clone();
			error = err(img1_f, img2_f_roi);

			if (error < min) {
				min = error;
				shift_x = j;
				shift_y = i;
			}
		}
	}

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