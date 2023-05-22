#pragma once

#include <opencv2/core.hpp>
#include <opencv2/cudafilters.hpp>

cv::Mat stab2g(cv::Mat& img1_f, cv::Mat& img2, cv::cuda::Filter& fil, uint16_t delta, uint8_t k_filter);