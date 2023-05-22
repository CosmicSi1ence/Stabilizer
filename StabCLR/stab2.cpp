#include "stab2.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <windows.h>
#include "err.h"

#include <time.h>
#include <iostream>

using namespace cv;

Mat stab2(Mat& img1_f, Mat& img2, uint16_t delta, uint8_t k_filter) {

	auto start = getTickCount();						///////////////////////////

	Mat img2_f;
	boxFilter(img2, img2_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);

	auto end = getTickCount();						    ///////////////////////////
	auto totalTime = (end - start) / getTickFrequency();
	printf("\tFiltering time: %f\t", totalTime);

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

	Mat img_f(img2_f, shift);

	img_f.copyTo(img1_f);

	return img_out;
}













//#include "stab2.h"
//
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//
//#include <windows.h>
//#include "err.h"
//
//#include <time.h>
//#include <iostream>
//
//using namespace cv;
//
////static double ax, bx, delta_x, ay, by, delta_y;
//
//Mat stab2(Mat& img1_f, Mat& img2, uint16_t delta, uint8_t k_filter) {
//
//	Mat img2_f;						//	Создание объектa под фильтрацию
//
//	auto start = getTickCount();    ///////////////////////////
//
//	img2.copyTo(img2_f);			//	Копирование
//	boxFilter(img2, img2_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);	//	img2 filtering
//
//	auto end = getTickCount();    ///////////////////////////
//	auto totalTime = (end - start) / getTickFrequency();
//	printf("\tFiltering time: %f", totalTime);
//
//	//	TEST:
//	uint32_t errors[40][40];
//
//
//	uint16_t shift_x = 0;
//	uint16_t shift_y = 0;
//	uint32_t error = 0;
//	uint32_t min = img2_f.rows * img2_f.cols * 255;
//	for (uint16_t i = 0; i < 2 * delta + 1; ++i) {
//		for (uint16_t j = 0; j < 2 * delta + 1; ++j) {
//			Mat img2_f_roi_(img2_f, Rect(j, i, img1_f.cols, img1_f.rows));
//			Mat img2_f_roi;
//			img2_f_roi_.copyTo(img2_f_roi);
//			error = err(img1_f, img2_f_roi);
//
//			//	TEST:
//			errors[i][j] = error;
//
//			if (error < min) {
//				min = error;
//				shift_x = j;
//				shift_y = i;
//			}
//		}
//	}
//
//	//	TEST:
//	printf("\n\n");
//	for (uint32_t i = 0; i < 40; ++i) {
//		for (uint32_t j = 0; i < 40; ++i) {
//			printf("%d\t", errors[i][j]);
//		}
//		printf("\n");
//	}
//
//
//	int dx = shift_x - delta;
//	int dy = shift_y - delta;
//	printf("\tdx:%d\tdy:%d\n", dx, dy);
//	Rect shift = Rect(shift_x, shift_y, img1_f.cols, img1_f.rows);
//
//	Mat img_out(img2, shift);
//	//Mat img_out_(img2, shift);
//	//Mat img_out;
//	//img_out_.copyTo(img_out);
//
//	Mat img_f(img2_f, shift);
//
//	img_f.copyTo(img1_f);
//
//	return img_out;
//}