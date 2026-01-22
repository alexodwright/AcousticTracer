#ifndef AT_VOXEL_H
#define AT_VOXEL_H

#include "at.h"

typedef struct {
    uint32_t index;
    float *bins;
} AT_Voxel;

#endif // AT_VOXEL_H