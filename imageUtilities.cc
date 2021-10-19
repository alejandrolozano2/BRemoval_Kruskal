
#include "imageUtilities.h"


int bgr2grey (cv::Mat & src, cv::Mat & dst) {
        cv::Size s = src.size();

        uint8_t * gImage = dst.ptr<uint8_t>(0);
        RGB * data = src.ptr<RGB>(0);
        for ( int h = 0; h < s.height; h++) {
                for (int w = 0; w < s.width; w++) {
                        *gImage++ = (data->blue* 0.114 + data->green* 0.587 + data->red* 0.299);
                        data++;
                }
        }

}