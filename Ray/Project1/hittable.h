#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"
//��������࣬�����һ���ӿڣ� ��¼�ù��ߺ������ཻ���߼�����Ӧ���ཻ���ߡ������Լ����ߵ�tλ�ü�¼��
class hit_record {
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    //COMMENT��
    //����ɫ�׶��ٴ�������Ҳ�ǿ��Խ���ġ���������ʹ���������Ҫ������ʽ��������ش���
    //�������ǵĲ����뼸����Ȳ���������࣬������ǿ����ڴ˴��ļ����ཻ�Ĳ��־�ֱ��ȷ�Ϻ÷������ķ���
    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.�����Ǽٶ���������ǵ�λ������

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

