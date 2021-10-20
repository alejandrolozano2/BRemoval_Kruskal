#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <time.h>
#include <cstdlib>

void sort_edges( uint32_t (* es)[3], uint32_t (* ed)[3], uint32_t size , uint32_t maxVal);
void count_sort(uint32_t * source, uint32_t * destination, uint32_t size, uint32_t maxValue);
void printArray(uint32_t * arr, uint32_t size);
void printEdge(uint32_t ( & es)[3], uint32_t size);
void printEdgeArray(uint32_t (*es)[3], uint32_t size);

#endif