#ifndef __3D_OBJECT
#define __3D_OBJECT

#include <stdlib.h>
#include <assert.h>
#include "frameRenderer.h"

#define DEFAULT_DEPTH 10 

typedef struct _obj{
    int x;
    int y;
    int z;
    int height;
    int width;
    int depth;
    int*** voxels;
} Object;

Object instantiate(int h, int w, int d);
void mapToFrame(Object obj, Frame f);
void destroy(Object obj);

#endif