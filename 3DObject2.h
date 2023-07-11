#ifndef __3D_OBJECT
#define __3D_OBJECT

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "frameRenderer.h"
#include "vector.h"

#define DEFAULT_DEPTH 10

typedef struct _object{
    int height;
    int width;
    int depth;
    int x;
    int y;
    int z;
    int pointCount;
    Vector3* voxels;
}Object;

Object instantiate(int h, int w, int d);
void insertPoint(Object* obj, Vector3 p);
void mapToFrame(Object obj, Frame f, int color);
void rotateObject(Object obj, Vector3 center, Vector3 theta);
void destroy(Object obj);
#endif