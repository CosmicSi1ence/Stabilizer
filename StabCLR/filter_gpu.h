#pragma once

#include <opencv2/core.hpp>
#include <opencv2/cudafilters.hpp>

cv::Mat filter_gpu(cv::Mat& img, cv::cuda::Filter& fil);
