#include "err.h"

int32_t err(cv::Mat& img1, cv::Mat& img2) {
	int32_t error = 0;

	uint16_t size = img2.rows * img2.cols;
	for (uint16_t i = 0; i < size; ++i) {
		error += abs(*(img1.datastart + i) - *(img2.datastart + i));
	}

	return error;
}