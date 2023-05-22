#include "filter_gpu.h"

#include <opencv2/core.hpp>
#include <opencv2/cudafilters.hpp>

cv::Mat filter_gpu(cv::Mat& img, cv::cuda::Filter& fil) {
	cvtColor(img, img, CV_8UC1);
	cv::cuda::GpuMat img2GPU, img2_fGPU;
	img2GPU.upload(img);
	fil.apply(img2GPU, img2_fGPU);
	cv::Mat img_f;
	img2_fGPU.download(img_f);
	cvtColor(img_f, img_f, 16);
	return img_f;
}