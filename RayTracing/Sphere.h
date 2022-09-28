#pragma once
#include "Object.h"

namespace hlab
{
    using namespace glm;

    class Sphere : public Object
    {
    public:
        vec3 center;
        float radius;

        Sphere(const vec3 &center, const float radius, const vec3 &color = vec3(1.0f))
            : center(center), radius(radius), Object(color)
        {
        }

        Hit CheckRayCollision(Ray& ray)
        {
            Hit hit = Hit{ -1.0f, vec3(0.0f), vec3(0.0f) }; // d가 음수이면 충돌을 안한 것으로 가정

            /*
             * hit.d = ... // 광선의 시작점으로부터 충돌지점까지의 거리 (float)
             * hit.point = ... // 광선과 구가 충돌한 지점의 위치 (vec3)
             * hit.normal = .. // 충돌 지점에서 구의 단위 법선 벡터(unit normal vector)
             */
            float b = 2 * glm::dot(ray.dir, (ray.start - center));
            //std::cout << firstterm << std::endl;
            float discriminant = b * b / 4.f - (glm::dot((ray.start - center), (ray.start - center)) - radius * radius);
            //std::cout << discriminant << std::endl;
            float d = -b / 2.f;
            if (discriminant < 0)
            {
                return hit;
            }
            if (discriminant == 0)
            {
                hit.d = d;
                hit.point = ray.start + ray.dir * hit.d;
                hit.normal = glm::normalize(hit.point - center);
            }
            if (discriminant > 0)
            {
                float tmp = d - sqrtf(discriminant);
                if (tmp < 0)
                    return hit;
                hit.d = tmp;
                hit.point = ray.start + ray.dir * hit.d;

                hit.normal = glm::normalize(hit.point - center);
            }
            return hit;
        }
    };
}
