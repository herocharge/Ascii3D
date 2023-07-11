#include "3DObject.h"


Object instantiate(int h, int w, int d){
    Object obj;
    obj.x = 0;
    obj.y = 0;
    obj.z = DEFAULT_DEPTH;
    obj.height = h;
    obj.width = w;
    obj.depth = d;
    obj.voxels = (int ***)malloc(h * sizeof(int **));
    assert(obj.voxels != NULL);
    for(int i = 0; i < h; i++){
        obj.voxels[i] = (int **)malloc(w * sizeof(int *));
        assert(obj.voxels[i] != NULL);
        for(int j = 0; j < w; j++){
            obj.voxels[i][j] = (int *)malloc(d * sizeof(int));
            assert(obj.voxels[i][j] != NULL);
            obj.voxels[i][j][0] = 0;
        }
    }
    return obj;
}

void mapToFrame(Object obj, Frame f){
    for(int i = 0; i < f.height; i++){
        for(int j = 0; j < f.width; j++){
            if(i-obj.y >= 0 && i-obj.y < obj.height && j-obj.x >= 0 && j-obj.x < obj.width){
                for(int k = 0; k < obj.depth; k ++){
                    if(obj.voxels[i-obj.y][j-obj.x][0]){
                        f.pixels[i][j] = (obj.voxels[i-obj.y][j-obj.x][1]);
                    }
                }
            }
        }
    }
}

void destroy(Object obj){
    for(int i = 0; i < obj.height; i++){
        for(int j = 0; j < obj.width; j++){
            free(obj.voxels[i][j]);
        }
        free(obj.voxels[i]);
    }
    free(obj.voxels);
}