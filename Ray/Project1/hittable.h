#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"
//抽象虚基类，抽象出一个接口， 记录好光线和物体相交的逻辑，对应的相交法线、交点以及光线的t位置记录。
class hit_record {
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    //COMMENT：
    //在着色阶段再处理法向量也是可以解决的。但如果材质过多我们需要逐个材质进行向量重处理。
    //由于我们的材质与几何相比材质种类更多，因此我们考虑在此处的几何相交的部分就直接确认好法向量的方向。
    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.（我们假定这个向量是单位向量）

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};



class hittable {
public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif

