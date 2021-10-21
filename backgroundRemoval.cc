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
        //imwrite("Prueba.jpg", colorMat);

        cv::Size s = colorMat.size();
        uint32_t imageSize = s.height * s.width;
        uint32_t * parents = new uint32_t[imageSize];
        uint32_t * ranks = new uint32_t[imageSize];
        uint32_t nEdges = imageSize * 2 - (s.width + s.height);
        uint32_t * edges = new uint32_t[nEdges *3];
        uint32_t * sortedEdges= new uint32_t[nEdges *3]; 
        uint32_t threshold = 6;
        uint32_t mergedCount, maxLeader;

/*****************************Build Edges Test****************************************/

/*************************************************************************************/

        for(;;) {
                cam >> colorMat;
                
                auto start = high_resolution_clock::now();
                initParentsAndRanks(parents, ranks, imageSize);
                auto max = buildEdges(colorMat, (uint32_t(*)[3])edges, 0);
                sortEdges((uint32_t(*)[3])edges, (uint32_t(*)[3])sortedEdges, nEdges, max);
                //printEdgeArray(sortedEdges, imageSize * 2 - (s.width + s.height));
                mergedCount = kruskal((uint32_t(*)[3])sortedEdges, nEdges, imageSize, parents, ranks, threshold);
                maxLeader = getMaxParent(ranks, imageSize);
                RGB * p = colorMat.ptr<RGB>(0);
                for (int i = 0 ; i < imageSize; i++, p++) {
                        uint32_t l = findLeader(parents, imageSize, i);
                        if (l == maxLeader) {
                                p->blue = 0;
                                p->green = 0;
                                p->red = 0;
                        }
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << duration.count() << " Microseconds " << "MergedCount " << mergedCount << " MaxLeader " <<  maxLeader << endl;    
                imshow("Color",colorMat);

                char c=(char)waitKey(25);
                if(c==27)
                        break;

        }

        return 1;
}
