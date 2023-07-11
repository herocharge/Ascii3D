import numpy as np
import open3d as o3d
a = o3d.geometry.TriangleMesh.create_sphere()
a.compute_vertex_normals()

arr = (np.asarray(a.triangles))

print(arr)
for x in arr:
    for p in x:
        print(p, end=" ")
    print()


