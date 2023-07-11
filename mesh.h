#include <stdlib.h>
#include <assert.h>

#include "vector.h"
#include "surface.h"
#include "frameRenderer.h"
#include "3DObject2.h"

typedef struct _mesh{
    Vector3 position;
    int surfaceCount;
    Surface* surfaces;
} Mesh;

Mesh makeMesh(int count);
void insertSurface(Mesh* m, Surface s);
void meshToFrame(Mesh m, Frame f);
void rotateMesh(Mesh m, Vector3 center, Vector3 theta);
void translate(Mesh* m, Vector3 move);
Mesh loadTriangles(char* name);