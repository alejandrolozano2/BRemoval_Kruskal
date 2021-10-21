#include "imageUtilities.h"
#include "mst_image.h"
#include "sorting.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>


using namespace cv;
using namespace std;
using namespace std::chrono;


int main(int argc, char * argv[]) {

        VideoCapture cam(0);
        cv::Mat colorMat;
#if 0
/****************************Count Sort Test******************************************/
        uint32_t testArray[] = {4,6,2,3,5,0,2,1,7,8,9,11};
        uint32_t sortedArray[sizeof(testArray)/sizeof(uint32_t)] = {};

        printArray(testArray, sizeof(testArray)/sizeof(uint32_t));
        countSort(testArray, sortedArray, sizeof(testArray)/sizeof(uint32_t), 11);
        printArray(sortedArray, sizeof(testArray)/sizeof(uint32_t));

        uint32_t testEdgeArray[][3] = {{1,2,9}, {2,3,5}, {3,4,6}, {4,5,1}};
        uint32_t sortedEdgeArray[sizeof(testEdgeArray)/ (sizeof(uint32_t)*3)][3] = {};
        
        printEdgeArray(testEdgeArray, 4);
        sortEdges(testEdgeArray, sortedEdgeArray, 4, 9);
        printEdgeArray(sortedEdgeArray, 4);
#endif
/*************************************************************************************/
        if (!cam.isOpened()) return -1;
        /*Save JPG of first capture*/
        cam >> colorMat;
        imwrite("Prueba.jpg", colorMat);

        cv::Size s = colorMat.size();
        uint32_t imageSize = s.height * s.width;
        uint32_t * parents = new uint32_t[imageSize];
        uint32_t * ranks = new uint32_t[imageSize];
        uint32_t nEdges = imageSize * 2 - (s.width + s.height);
        uint32_t * edges = new uint32_t[nEdges *3];
        uint32_t sortedEdges[nEdges][3] = {}; 

        auto start = high_resolution_clock::now();
        initParents(parents, imageSize);
        initRanks(ranks, imageSize);
        *parents = *parents++;
        *ranks = *ranks++;
        auto max = buildEdges(colorMat, (uint32_t(*)[3])edges, 0);
        sortEdges((uint32_t(*)[3])edges, sortedEdges, nEdges, max);
        auto stop = high_resolution_clock::now();

        //printEdgeArray(sortedEdges, imageSize * 2 - (s.width + s.height));
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "buildEdges: " << duration.count() << " Microseconds"<< endl;


/*****************************Build Edges Test****************************************/

/*************************************************************************************/

        for(;;) {
                cam >> colorMat;
                imshow("Color",colorMat);
                
                char c=(char)waitKey(25);
                if(c==27)
                        break;

        }

        return 1;
}
