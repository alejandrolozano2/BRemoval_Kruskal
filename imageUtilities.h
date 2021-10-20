#ifndef IMAGE_UTILITIES_H
#define IMAGE_UTILITIES_H

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cstdlib>

#define diff(x,y)   (x-y)
#define sqr(d) (d*d)
#define bgrDiff(x, y)  (abs(diff(x[0], y[0])) + abs(diff(x[1], y[1])) + abs(diff(x[2], y[2])))


struct RGB {
   uchar blue;
   uchar green;
   uchar red;
 };

/*Onw implementation for gray conversion*/
int bgr2grey (cv::Mat & src, cv::Mat & dst);

#endif

