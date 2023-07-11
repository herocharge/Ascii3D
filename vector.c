#include "vector.h"

Vector2 makeVector2(int x, int y){
    Vector2 p;
    p.x = x;
    p.y = y;
    return p;
}

Vector3 makeVector3(double x, double y, double z){
    Vector3 p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

Vector4 makeVector4(int x, int y, int z, int w){
    Vector4 p;
    p.x = x;
    p.y = y;
    p.z = z;
    p.w = w;
    return p;
}



double dotProduct(Vector3 v1, Vector3 v2){
    double dot = v1.x * v2.x;
    dot += v1.y * v2.y;
    dot += v1.z * v2.z;
    return dot;
}

Vector3 crossProduct(Vector3 v1, Vector3 v2){
    Vector3 cross;
    cross.x = v1.y * v2.z - v2.y * v1.z;
    cross.y = v2.x * v1.z - v1.x * v2.z;
    cross.z = v1.x * v2.y - v2.x * v1.y;
    return cross;
}

double maxElement(Vector3 v){
    int mx = v.x;
    if(v.y > mx) mx = v.y;
    if(v.z > mx) mx = v.z;
    return mx;
}

double minElement(Vector3 v){
    int mn = v.x;
    if(v.y < mn) mn = v.y;
    if(v.z < mn) mn = v.z;
    return mn;
}

Vector3 diff(Vector3 v1, Vector3 v2){
    return makeVector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3 add(Vector3 v1, Vector3 v2){
    return makeVector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3 Transform(Vector3 p, Vector3 center, Vector3 theta){
    Vector3 np = diff(p, center);
    Vector3 ret;
    ret.x = np.x * cos(theta.x) + np.z * sin(theta.x);
    ret.y = np.y;
    ret.z = -1 * np.x * sin(theta.x) + np.z * cos(theta.x);
    ret.y = ret.y * cos(theta.y) + ret.z * sin(theta.y);
    ret.x = ret.x;
    ret.z = -1 * ret.y * sin(theta.y) + ret.z * cos(theta.y);
    ret = makeVector3(ret.x + center.x, ret.y + center.y, ret.z + center.z);
    return ret;
}

double Q_rsqrt(double number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5fe6eb50c7b537a9 - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

Vector3 normalize(Vector3 v){
    double isqr = 1.0/sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    v.x *= isqr;
    v.y *= isqr;
    v.z *= isqr;
    return v;
}

Vector3 Normal(Vector3 v1, Vector3 v2){
    Vector3 new = crossProduct(v1, v2);
    // assert(new.x != 0 || new.y != 0 || new.z != 0);
    new = normalize(new);
    return new; 
}