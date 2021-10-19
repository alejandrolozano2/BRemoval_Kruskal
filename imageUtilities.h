#ifndef IMAGE_UTILITIES_H
#define IMAGE_UTILITIES_H

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>


struct RGB {
   uchar blue;
   uchar green;
   uchar red;
 };

/*Onw implementation for gray conversion*/
int bgr2grey (cv::Mat & src, cv::Mat & dst);

#endif

