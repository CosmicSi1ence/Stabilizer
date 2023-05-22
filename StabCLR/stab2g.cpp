#include "stab2g.h"
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

Mat stab2g(Mat& img1_f, Mat& img2, cv::cuda::Filter& fil, uint16_t delta, uint8_t k_filter) {

	auto start = getTickCount();    ///////////////////////////

	Mat img2_f;
	img2_f = filter_gpu(img2, fil);

	auto end = getTickCount();    ///////////////////////////
	auto totalTime = (end - start) / getTickFrequency();
	printf("\tFiltering time: %f", totalTime);

	uint16_t shift_x = 0;
	uint16_t shift_y = 0;
	uint32_t error = 0;

	uint8_t s = 2 * delta + 1;
	uint16_t w = img1_f.cols;
	uint16_t h = img1_f.rows;

	uint32_t min = w * h * 255;

	Mat roi_, roi;

	for (uint32_t i = 0; i < 2 * delta + 1; ++i) {
		roi_ = img2_f(Rect(i, delta, w, h));
		roi = roi_.clone();
		error = err(img1_f, roi);

		if (error < min) {
			min = error;
			shift_x = i;
		}
	}

	for (uint32_t j = 0; j < 2 * delta + 1; ++j) {
		roi_ = img2_f(Rect(shift_x, j, w, h));
		roi = roi_.clone();
		error = err(img1_f, roi);

		if (error < min) {
			min = error;
			shift_y = j;
		}
	}

	for (uint32_t i = 0; i < 2 * delta + 1; ++i) {
		roi_ = img2_f(Rect(i, shift_y, w, h));
		roi = roi_.clone();
		error = err(img1_f, roi);

		if (error < min) {
			min = error;
			shift_x = i;
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