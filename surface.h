#ifndef __SURFACE_H
#define __SURFACE_H

#include <math.h>
#include <assert.h>
#include <stdlib.h> 
#include "vector.h"
#include "3DObject2.h"

typedef struct _surface
{
    Vector3 p1;
    Vector3 p2;
    Vector3 p3;
} Surface;

Surface makeSurface(Vector3 p1, Vector3 p2, Vector3 p3);
void surfaceToObject(Object* obj, Surface s);
int sameSide(Vector3 p1, Vector3 p2, Vector3 a, Vector3 b);
int pointInTriangle(Vector3 p, Vector3 a, Vector3 b, Vector3 c);
void Rotate(Surface* s, Vector3 center, Vector3 theta);


#endif