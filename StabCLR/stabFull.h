#pragma once

#include <opencv2/core.hpp>

cv::Mat stabFull(cv::Mat& img1_f, cv::Mat& img2, uint16_t delta, uint8_t k_filter);