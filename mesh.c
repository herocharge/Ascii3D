#include "mesh.h"

Mesh makeMesh(int count){
    Mesh m;
    m.surfaceCount = 0;
    m.position = makeVector3(0, 0, 10);
    m.surfaces = (Surface *)malloc(count * sizeof(Surface));
    assert(m.surfaces != NULL);
    return m;
}

void insertSurface(Mesh* m, Surface s){
    // assert(m->surfaceCount < sizeof(m->surfaces)/sizeof(Surface));
    m->surfaces[m->surfaceCount] = s;
    m->surfaceCount++;
}

void meshToFrame(Mesh m, Frame f){
    for(int i = 0; i < m.surfaceCount; i++){
        Object obj = instantiate(100, 100, 100);
        obj.x = m.position.x;
        obj.y = m.position.y;
        obj.z = m.position.z;

        surfaceToObject(&obj, m.surfaces[i]);
        Vector3 a = m.surfaces[i].p1;
        Vector3 b = m.surfaces[i].p2;
        Vector3 c = m.surfaces[i].p3;
        Vector3 n = Normal(diff(b, a), diff(c, a));
        Vector3 G = add(a, add(b, c));
        G.x /= 3;
        G.y /= 3;
        G.z /= 3;
        double dp = dotProduct(n, normalize(G));
        if(dp < 0)dp*=-1;
        // assert(dp <= 1);
        // printw("%lf\n", (BLACK-2)*(1-dp));
        mapToFrame(obj, f, /*WHITE);*/(BLACK-2)*(1-dp));
        destroy(obj);
    }
}

void rotateMesh(Mesh m, Vector3 center, Vector3 theta){
    for(int i = 0; i < m.surfaceCount; i++){
        // Rotate(&m.surfaces[i], center, theta);
        m.surfaces[i].p1 = Transform(m.surfaces[i].p1, center, theta);
        m.surfaces[i].p2 = Transform(m.surfaces[i].p2, center, theta);
        m.surfaces[i].p3 = Transform(m.surfaces[i].p3, center, theta);
        
        // Vector3 a = m.surfaces[i].p1;
        // Vector3 b = m.surfaces[i].p2;
        // Vector3 c = m.surfaces[i].p3;
        // Vector3 n = Normal(diff(b, a), diff(c, a));
        // double dp = dotProduct(n, makeVector3(0, 0, 1));
        
        // if(dp < 0){
        //     Vector3 tmp = m.surfaces[i].p2;
        //     m.surfaces[i].p2 = m.surfaces[i].p3;
        //     m.surfaces[i].p3 = tmp;
        // }
    }
}

void translate(Mesh* m, Vector3 move){
    m->position = add(m->position, move);
    for(int i =0;i < m->surfaceCount;i++){
        m->surfaces[i].p1 = add(m->surfaces[i].p1, move);
        m->surfaces[i].p2 = add(m->surfaces[i].p2, move);
        m->surfaces[i].p3 = add(m->surfaces[i].p3, move);
    }
}

Mesh loadTriangles(char* name){
    
    
    Mesh m = makeMesh(16000);
    int k = 0;
    Vector3 p[16000];
    int count = 0;
    
    FILE* f = fopen(name, "r");
    while(k != EOF){
        char c;
        k = fscanf(f, "%c", &c);
        while(k != EOF && c != 'v' && c!='f'){
            k = fscanf(f, "%c", &c);
        }
        if(k == EOF)break;
        if(c == 'v'){
            // printw("v\n");
            k = fscanf(f, "%lf %lf %lf" , &p[count].x, &p[count].y, &p[count].z);
            double rectangulation = 1;
            p[count].x *= 5;
            p[count].y *= 5*rectangulation;
            p[count].z *= 5;
            // p[count].z += 30;
            // Surface s = makeSurface(p[count], p[count], p[count]);
            // insertSurface(&m, s);
            count++;
        }
        else {
            // printw("f\n");
            assert(c == 'f');
            int p1, p2, p3;
            k = fscanf(f, "%d %d %d", &p1, &p2, &p3);
            Surface s = makeSurface(p[p1-1], p[p2-1], p[p3-1]);
            insertSurface(&m, s);
        }
    }
            printw("done");

    return m;
}