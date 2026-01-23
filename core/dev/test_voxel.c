#include "../src/at_voxel.h"
#include <stdio.h>

int main()
{
    printf("Voxel!\n");

    AT_Voxel vs = {0};
    AT_voxel_init(&vs);
    AT_voxel_bin_append(&vs, 5.0f);
    AT_voxel_bin_append(&vs, 10.0f);
    AT_voxel_bin_append(&vs, 15.0f);

    for (size_t i = 0; i < vs.count; i++) {
        printf("Voxel %zu: %f\n", i, vs.items[i]);
    }

    return 0;
}
