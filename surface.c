#include "surface.h"

Surface makeSurface(Vector3 p1, Vector3 p2, Vector3 p3){
    Surface s;
    s.p1 = p1;
    s.p2 = p2;
    s.p3 = p3;
    return s;
}

int sameSide(Vector3 p1, Vector3 p2, Vector3 a, Vector3 b){
    Vector3 cp1 = crossProduct(diff(b, a), diff(p1, a));
    Vector3 cp2 = crossProduct(diff(b, a), diff(p2, a));
    return dotProduct(cp1, cp2) >= 0; 
}
 

int pointInTriangle(Vector3 p, Vector3 a, Vector3 b, Vector3 c){
    int retVal = sameSide(p, a, b, c);
    retVal &= sameSide(p, b, a, c);
    retVal &= sameSide(p, c, a, b);
    Vector3 v = crossProduct(crossProduct(diff(p, a), diff(b, a)), Normal(diff(b, a), diff(c, a)));
    double delta = 50;
    retVal &= ((v.x <= delta && v.y <= delta && v.z <= delta));
    retVal &= ((v.x >= -delta && v.y >= -delta && v.z >= -delta));
    
    return retVal;
}

int pointInTriangle2(Vector3 p, Vector3 a, Vector3 b, Vector3 c){
    // Compute vectors        
    Vector3 v0 = diff(c, a);
    Vector3 v1 = diff(b, a);
    Vector3 v2 = diff(p, a);

    // Compute dot products
    double dot00 = dotProduct(v0, v0);
    double dot01 = dotProduct(v0, v1);
    double dot02 = dotProduct(v0, v2);
    double dot11 = dotProduct(v1, v1);
    double dot12 = dotProduct(v1, v2);

    // Compute barycentric coordinates
    double invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle
    return (u >= 0) && (v >= 0) && (u + v < 1);
}

void surfaceToObject(Object* obj, Surface s){
    Vector3 maxBound, minBound;
    maxBound.x = maxElement(makeVector3(s.p1.x, s.p2.x, s.p3.x));
    maxBound.y = maxElement(makeVector3(s.p1.y, s.p2.y, s.p3.y));
    maxBound.z = maxElement(makeVector3(s.p1.z, s.p2.z, s.p3.z));

    minBound.x = minElement(makeVector3(s.p1.x, s.p2.x, s.p3.x));
    minBound.y = minElement(makeVector3(s.p1.y, s.p2.y, s.p3.y));
    minBound.z = minElement(makeVector3(s.p1.z, s.p2.z, s.p3.z));

    Vector3 dims = diff(maxBound, minBound);
   
    Vector3 a, b, c;
    Vector3 ORIGIN = {0, 0, 0};
    a = add(s.p1, ORIGIN);
    b = add(s.p2, ORIGIN);
    c = add(s.p3, ORIGIN);

    insertPoint(obj, makeVector3(a.x, a.y, a.z));
    insertPoint(obj, makeVector3(b.x, b.y, b.z));
    insertPoint(obj, makeVector3(c.x, c.y, c.z));
    int off = 1;    
    for(int i = minBound.x; i <= maxBound.x+off; i++){
        for(int j = minBound.y; j <= maxBound.y+off; j++){
            for(int k = minBound.z; k <= maxBound.z+off; k++){
                if(pointInTriangle(makeVector3(i, j, k), a, b, c)){
                    insertPoint(obj, makeVector3(i, j, k));
                }
            }
        }
    }
}


void Rotate(Surface* s, Vector3 center, Vector3 theta){
    s->p1 = Transform(s->p1, center, theta);
    s->p2 = Transform(s->p2, center, theta);
    s->p3 = Transform(s->p3, center, theta);
}
