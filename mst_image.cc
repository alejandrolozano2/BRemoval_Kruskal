#include "mst_image.h"

uint32_t findLeader(uint32_t * parents, uint32_t size, uint32_t value) {

    while(parents[value] != value) {
        value = parents[value];
    }

    return value;
}

bool join(uint32_t * parents, uint32_t * rank, uint32_t size, uint32_t i, uint32_t j) {

    uint32_t li = findLeader(parents, size, i);
    uint32_t lj = findLeader(parents, size, j);

    if (li == lj)
        return false;
    
    uint32_t ri = rank[li];
    uint32_t rj = rank[lj];

    if ((ri > rj) || (ri == rj && li > lj)) {
        parents[lj] = li;
        rank[li]+= rj;
    }
    else {
        parents[li]=lj;
        rank[lj]+= ri;
    }

    return true;
}