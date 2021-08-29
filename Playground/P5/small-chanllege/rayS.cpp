float max(vec3 v) { return max (max(v.x, v.y), v.z); }
// box.rotation = object-to-world, invRayDir unused if oriented
bool ourIntersectBox(Box box, Ray ray, out float distance, out vec3 normal,
const bool canStartInBox, const in bool oriented, in vec3 _invRayDir) {
    ray.origin = ray.origin - box.center;
    if (oriented) {
         ray.dir *= box.rot; ray.origin *= box.rot; 
    }
    float winding = canStartInBox && (max(abs(ray.origin) * box.invRadius)< 1.0) ? -1 : 1;
    vec3 sgn = -sign(ray.dir);
    // Distance to plane
    vec3 d = box.radius * winding * sgn - ray.origin;
    if (oriented) d /= ray.dir; else d *= _invRayDir;
    # define TEST(U, VW) (d.U >= 0.0) && \
    all(lessThan(abs(ray.origin.VW + ray.dir.VW * d.U), box.radius.VW))
    bvec3 test = bvec3(TEST(x, yz), TEST(y, zx), TEST(z, xy));
    sgn = test.x ? vec3(sgn.x,0,0) : (test.y ? vec3(0,sgn.y,0) :
    vec3(0,0,test.z ? sgn.z:0));
    # undef TEST
    distance = (sgn.x != 0) ? d.x : ((sgn.y != 0) ? d.y : d.z);
    normal = oriented ? (box.rot * sgn) : sgn;
    return (sgn.x != 0) || (sgn.y != 0) || (sgn.z != 0);
}
