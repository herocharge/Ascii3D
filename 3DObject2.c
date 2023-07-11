#include "3DObject2.h"


Object instantiate(int h, int w, int d){
    Object obj;
    obj.x = 0;
    obj.y = 0;
    obj.z = DEFAULT_DEPTH;
    obj.height = h;
    obj.width = w;
    obj.depth = d;
    obj.pointCount = 0;
    obj.voxels = (Vector3 *)malloc(h * w * d * sizeof(Vector3));
    assert(obj.voxels != NULL);
    return obj;
}

void insertPoint(Object* obj, Vector3 p){
    // assert(1 == 2);
    if(obj->pointCount == obj->height * obj->width * obj->depth){return;}
    obj->voxels[obj->pointCount] = p;
    obj->pointCount++;
}

void rotateObject(Object obj, Vector3 center, Vector3 theta){
    for(int i = 0; i < obj.pointCount; i++){
        obj.voxels[i] = Transform(obj.voxels[i], center, theta);
    }
}

void mapToFrame(Object obj, Frame f, int color){
    int cx = f.width/2;
    int cy = f.height/2;
    if(color < 0)color *= -1;
    color = color%BLACK;
    // while(color > BLACK)color--;
    // color = ((BLACK - color) )% BLACK;
    // assert(color < 9);
    // assert(color >= 0);
    for(int i = 0; i < obj.pointCount; i++){
        double x = obj.voxels[i].x;
        double y = obj.voxels[i].y;
        double z = obj.voxels[i].z;
        double scalar = (f.camDepth * 1.0)/z;
        int fx = x*scalar;
        int fy = y*scalar;
        if(fx + cx < f.width && fy + cy < f.height && fx + cx >= 0 && fy + cy >= 0 && z > 0 && z < f.zvals[fy + cy][fx + cx]){
            f.pixels[fy + cy][fx + cx] = color;
            f.zvals[fy + cy][fx + cx] = z;
            // printw("%d\n", z);
        }
    }
}

void destroy(Object obj){
    free(obj.voxels);
}