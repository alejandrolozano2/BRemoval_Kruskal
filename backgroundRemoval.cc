#include "imageUtilities.h"
#include <iostream>
#include <time.h>
#include <cstdlib>


using namespace cv;
using namespace std;


int main(int argc, char * argv[]) {

        VideoCapture cam(0);
        cv::Mat colorMat;
                
        if (!cam.isOpened()) return -1;

        /*Save JPG of first capture*/
        cam >> colorMat;
        imwrite("Prueba.jpg", colorMat);

        for(;;) {
                cam >> colorMat;
                imshow("Color",colorMat);
                
                char c=(char)waitKey(25);
                if(c==27)
                        break;

        }

        return 1;
}
