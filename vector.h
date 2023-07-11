#ifndef __VECTOR_H
#define __VECTOR_H

#include <math.h>
#include <assert.h>

typedef struct _vector2
{
    int x;
    int y;
} Vector2;

typedef struct _vector3
{
    double x;
    double y;
    double z;
} Vector3;

typedef struct _vector4
{
    int x;
    int y;
    int z;
    int w;
}Vector4;


Vector2 makeVector2(int x, int y);
Vector3 makeVector3(double x, double y, double z);
Vector4 makeVector4(int x, int y, int z, int w);
double dotProduct(Vector3 v1, Vector3 v2);
Vector3 crossProduct(Vector3 v1, Vector3 v2);
double maxElement(Vector3 v);
double minElement(Vector3 v);
Vector3 diff(Vector3 v1, Vector3 v2);
Vector3 Transform(Vector3 p, Vector3 center, Vector3 theta);
Vector3 Normal(Vector3 v1, Vector3 v2);
Vector3 normalize(Vector3 v);
double Q_rsqrt(double number);
Vector3 add(Vector3 v1, Vector3 v2);
#endif