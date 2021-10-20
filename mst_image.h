#ifndef MST_IMAGE_H
#define MST_IMAGE_H

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>

/*Finds parent. Used for find/joing algorithm*/
uint32_t findLeader(uint32_t * parents, uint32_t size, uint32_t value);

/*Join Elements*/
bool join(uint32_t * parents, uint32_t * rank, uint32_t size, uint32_t i, uint32_t j);

/*MST Kruskal i,j,w*/
void kruskal(uint32_t  (& edges)[10][3], uint32_t size);

#endif