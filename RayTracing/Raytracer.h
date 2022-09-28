#pragma once

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "Triangle.h"
#include "Square.h"

#include <vector>

namespace hlab
{
	using namespace std;
	using namespace glm;

	class Raytracer
	{
	public:
		int width, height;
		Light light;
		vector<shared_ptr<Object>> objects;

		Raytracer(const int &width, const int &height)
			: width(width), height(height)
		{
			auto sphere1 = make_shared<Sphere>(vec3(0.0f, -0.1f, 2.f), 1.0f);

			sphere1->amb = vec3(0.2f,0.f,0.f);
			sphere1->dif = vec3(1.0f, 0.0f, 0.0f);
			sphere1->spec = vec3(1.0f);
			sphere1->alpha = 50.0f;
			sphere1->reflection = 0.2f;
			sphere1->transparency = 0.f;

			objects.push_back(sphere1);


			auto sphere2 = make_shared<Sphere>(vec3(1.f, -1.f, 1.5f), .3f);

			sphere2->amb = vec3(0.f,0.f, 0.2f);
			sphere2->dif = vec3(0.0f, 0.0f, 1.0f);
			sphere2->spec = vec3(1.0f);
			sphere2->alpha = 50.0f;
			sphere2->reflection = 0.1f;
			sphere2->transparency = 0.f;

			objects.push_back(sphere2);


			auto sphere3 = make_shared<Sphere>(vec3(-.7f, -1.f, 1.2f), .4f);

			sphere3->amb = vec3(0.2f);
			sphere3->dif = vec3(1.0f, 0.0f, 0.0f);
			sphere3->spec = vec3(1.0f);
			sphere3->alpha = 50.0f;
			sphere3->reflection = 0.f;
			sphere3->transparency = 1.f;

			objects.push_back(sphere3);


			auto groundTexture = std::make_shared<Texture>("shadertoy_abstract1.jpg");

			auto ground = make_shared<Square>(vec3(-10.0f, -4.f, -10.0f), vec3(-10.0f, -4.f, 10.0f), vec3(10.0f, -4.f, 10.0f), vec3(10.0f, -4.f,-10.0f),
											  vec2(0.0f, 0.0f), vec2(4.0f, 0.0f), vec2(4.0f, 4.0f), vec2(0.0f, 4.0f));

			ground->amb = vec3(1.0f);
			ground->dif = vec3(1.0f);
			ground->spec = vec3(1.0f);
			ground->alpha = 10.0f;
			ground->reflection = 0.3f;
			ground->transparency = 0.3f;
			ground->ambTexture = groundTexture;
			ground->difTexture = groundTexture;

			objects.push_back(ground);
#pragma region cube
			auto squareTexture1 = std::make_shared<Texture>("SaintPetersBasilica/posz.jpg");
			auto square1 = make_shared<Square>(vec3(-10.0f, 10.0f, 10.0f), vec3(10.0f, 10.0f, 10.0f), vec3(10.0f, -10.0f, 10.0f), vec3(-10.0f, -10.0f, 10.0f),
											  vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));
			//뒷면
			square1->amb = vec3(1.0f);
			square1->dif = vec3(0.0f);
			square1->spec = vec3(0.0f);
			square1->alpha = 10.0f;
			square1->reflection = 0.0f;
			square1->ambTexture = squareTexture1;
			square1->difTexture = squareTexture1;

			objects.push_back(square1);

			//왼쪽
			auto squareTexture2 = std::make_shared<Texture>("SaintPetersBasilica/negx.jpg");
			auto square2 = make_shared<Square>(vec3(-10.0f, 10.0f, -10.0f), vec3(-10.0f, 10.0f, 10.0f), vec3(-10.0f, -10.0f, 10.0f), vec3(-10.0f, -10.0f, -10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			square2->amb = vec3(1.0f);
			square2->dif = vec3(0.0f);
			square2->spec = vec3(0.0f);
			square2->alpha = 10.0f;
			square2->reflection = 0.0f;
			square2->ambTexture = squareTexture2;
			square2->difTexture = squareTexture2;

			objects.push_back(square2);
			//오른쪽
			auto squareTexture3 = std::make_shared<Texture>("SaintPetersBasilica/posx.jpg");
			auto square3 = make_shared<Square>(vec3(10.0f, 10.0f, 10.0f), vec3(10.0f, 10.0f, -10.0f), vec3(10.0f, -10.0f, -10.0f), vec3(10.0f, -10.0f, 10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));



			square3->amb = vec3(1.0f);
			square3->dif = vec3(0.0f);
			square3->spec = vec3(0.0f);
			square3->alpha = 10.0f;
			square3->reflection = 0.0f;
			square3->ambTexture = squareTexture3;
			square3->difTexture = squareTexture3;

			objects.push_back(square3);

			//앞쪽
			auto squareTexture4 = std::make_shared<Texture>("SaintPetersBasilica/negz.jpg");
			auto square4 = make_shared<Square>(vec3(10.0f, 10.0f, -10.0f), vec3(-10.0f, 10.0f, -10.0f), vec3(-10.0f, -10.0f, -10.0f), vec3(10.0f, -10.0f, -10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));


			square4->amb = vec3(1.0f);
			square4->dif = vec3(0.0f);
			square4->spec = vec3(0.0f);
			square4->alpha = 10.0f;
			square4->reflection = 0.0f;
			square4->ambTexture = squareTexture4;
			square4->difTexture = squareTexture4;

			objects.push_back(square4);

			//위쪽
			auto squareTexture5 = std::make_shared<Texture>("SaintPetersBasilica/posy.jpg");
			auto square5 = make_shared<Square>(vec3(-10.0f, 10.0f, -10.0f), vec3(10.0f, 10.0f, -10.0f), vec3(10.0f, 10.0f, 10.0f), vec3(-10.0f, 10.0f, 10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));


			square5->amb = vec3(1.0f);
			square5->dif = vec3(0.0f);
			square5->spec = vec3(0.0f);
			square5->alpha = 10.0f;
			square5->reflection = 0.0f;
			square5->ambTexture = squareTexture5;
			square5->difTexture = squareTexture5;

			objects.push_back(square5);

			//아래쪽

			auto squareTexture6 = std::make_shared<Texture>("SaintPetersBasilica/negy.jpg");
			auto square6 = make_shared<Square>(vec3(-10.0f, -10.0f, 10.0f), vec3(10.0f, -10.0f, 10.0f), vec3(10.0f, -10.0f, -10.0f), vec3(-10.0f, -10.0f, -10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));


			square6->amb = vec3(1.0f);
			square6->dif = vec3(0.0f);
			square6->spec = vec3(0.0f);
			square6->alpha = 10.0f;
			square6->reflection = 0.0f;
			square6->ambTexture = squareTexture6;
			square6->difTexture = squareTexture6;

			objects.push_back(square6);
#pragma endregion comment
			light = Light{{1.0f, 3.f, 0.3f}}; // 화면 뒷쪽


		}

		Hit FindClosestCollision(Ray &ray)
		{
			float closestD = 1000.0; // inf
			Hit closestHit = Hit{-1.0, dvec3(0.0), dvec3(0.0)};

			for (int l = 0; l < objects.size(); l++)
			{
				auto hit = objects[l]->CheckRayCollision(ray);

				if (hit.d >= 0.0f)
				{
					if (hit.d < closestD)
					{
						closestD = hit.d;
						closestHit = hit;
						closestHit.obj = objects[l];

						// 텍스춰 좌표
						closestHit.uv = hit.uv;
					}
				}
			}

			return closestHit;
		}

		// 광선이 물체에 닿으면 그 물체의 색 반환
		vec3 traceRay(Ray &ray, const int recurseLevel)
		{
			if (recurseLevel < 0)
				return vec3(0.0f);

			// Render first hit
			const auto hit = FindClosestCollision(ray);

			if (hit.d >= 0.0f)
			{
				glm::vec3 color(0.0f);

				// Diffuse
				const vec3 dirToLight = glm::normalize(light.pos - hit.point);
				float distToLight = glm::length(light.pos- hit.point);
				glm::vec3 phongColor(0.0f);

				const float diff = glm::max(dot(hit.normal, dirToLight), 0.0f);

				Ray ShadowRay;
				ShadowRay.start = hit.point + dirToLight * 1e-4f; 
				ShadowRay.dir = dirToLight;
				auto ShadowHit = FindClosestCollision(ShadowRay);//맞은곳 찾고, 여기서 문제 발생
				if (ShadowHit.d < 0.0f||ShadowHit.d>=distToLight)
				{
					const vec3 reflectDir = hit.normal * 2.0f * dot(dirToLight, hit.normal) - dirToLight;
					const float specular = glm::pow(glm::max(glm::dot(-ray.dir, reflectDir), 0.0f), hit.obj->alpha);

					if (hit.obj->ambTexture)
					{
						phongColor += hit.obj->amb * hit.obj->ambTexture->SampleLinear(hit.uv);
					}
					else
					{
						phongColor += hit.obj->amb;
					}

					if (hit.obj->difTexture)
					{
						phongColor += diff * hit.obj->dif * hit.obj->difTexture->SampleLinear(hit.uv);
					}
					else
					{
						phongColor += diff * hit.obj->dif;
					}

					phongColor += hit.obj->spec * specular;

					color += phongColor * (1.0f - hit.obj->reflection - hit.obj->transparency);
				}
				else//맞으면
				{
					if (hit.obj->ambTexture)
					{
						phongColor += hit.obj->amb * hit.obj->ambTexture->SampleLinear(hit.uv);
					}
					else
					{
						phongColor += hit.obj->amb;
					}
					color += phongColor * (1.0f - hit.obj->reflection - hit.obj->transparency);
				}

				// Specular


				
				//auto total = hit.obj->reflection + hit.obj->transparency;
				//cos값은 수직일때 0, 평행일때 1 따라서 수직일때 reflection이 커야되니 45도를 기준으로 선형적으로 45도보다 작으면  투과에 더함, 45도보다 크면 반사에 더함

				if (hit.obj->reflection != 0 && hit.obj->transparency != 0)
				{
					float cosTheta = glm::dot(-hit.normal, ray.dir);//둘다 Unit 벡터라 cos값, 이미 normal이 반대쪽인 면은 제외됨
					if (cosTheta < 1.0f&&cosTheta>0.f)
					{
						//std::cout << cosTheta << endl;
						//서로 수직이면 빛이 반사가 증가, 평행에 가까우면 투과가 더 커짐
						auto degrees = glm::acos(cosTheta) * 360 / 3.14;
						//std::cout << degrees << endl;
						if (degrees > 90.f)
							degrees -= 90.f;
						//std::cout << degrees << endl;

						float pivot = 70.f;
						if (degrees > pivot)
						{
							hit.obj->reflection += (degrees - pivot) / pivot * hit.obj->transparency;
							hit.obj->transparency -= (degrees - pivot) / pivot * hit.obj->transparency;
						}
						else
						{
							hit.obj->transparency += (degrees ) / pivot * hit.obj->reflection;
							hit.obj->reflection -= (degrees ) / pivot * hit.obj->reflection;
						}
					}
				}

					
				
				if (hit.obj->reflection)
				{
						// 수치 오류 주의
						// 반사광이 반환해준 색을 더할 때의 비율은 hit.obj->reflection
					vec3 m = ray.dir - glm::dot(ray.dir, hit.normal) * hit.normal;;
					const vec3 reflectedDirection = glm::normalize(-ray.dir + 2.f * m);
					Ray subRay;
					subRay.dir = reflectedDirection;
					subRay.start = hit.point + 1e-4f * reflectedDirection;
					color += traceRay(subRay, recurseLevel - 1) * hit.obj->reflection;
					
					//const auto reflectedDirection = glm::normalize(2.0f * hit.normal * dot(-ray.dir, hit.normal) + ray.dir);
					//Ray reflection_ray{hit.point + reflectedDirection * 1e-4f, reflectedDirection}; // add a small vector to avoid numerical issue

					//color += traceRay(subRay, recurseLevel - 1) * hit.obj->reflection;
				}

				if (hit.obj->transparency)
				{
					const float ior = 1.5f; // Index of refraction (유리: 1.5, 물: 1.3)

					float eta; // sinTheta1 / sinTheta2
					vec3 normal;

					if (glm::dot(ray.dir, hit.normal) < 0.0f) // 밖에서 안에서 들어가는 경우 (예: 공기->유리)
					{
						eta = ior;
						normal = hit.normal;
					}
					else // 안에서 밖으로 나가는 경우 (예: 유리->공기)
					{
						eta = 1.0f / ior;
						normal = -hit.normal;
					}

					const float cosTheta1 = -glm::dot(normal, ray.dir);
					const float sinTheta1 = glm::sqrt(1-cosTheta1*cosTheta1); // cos^2 + sin^2 = 1
					const float sinTheta2 = sinTheta1/eta ;
					const float cosTheta2 = glm::sqrt(1-sinTheta2*sinTheta2);

					const vec3 m = glm::normalize(ray.dir+normal*glm::dot(-ray.dir,normal));
					 const vec3 a = m*sinTheta2;
					 const vec3 b = -normal*cosTheta2;
					const vec3 refractedDirection = glm::normalize(a + b); // transmission
					Ray transparentRay;
					transparentRay.dir = refractedDirection;
					transparentRay.start = hit.point + refractedDirection * 1e-4f;
					color += traceRay(transparentRay,recurseLevel -1)*hit.obj->transparency;

					// Fresnel 효과는 생략되었습니다.
				}

				return color;
			}

			return vec3(0.0f);
		}

		void Render(std::vector<glm::vec4> &pixels)
		{
			std::fill(pixels.begin(), pixels.end(), vec4(0.0f, 0.0f, 0.0f, 1.0f));

			const vec3 eyePos(0.0f, 0.5f, -1.f);//Z를 픽셀에 멀리 띄우면확대됨,,ㅋㅋ 픽셀에서 멀어져서 볼 수 있는 범위가 좁아짐

#pragma omp parallel for
			for (int j = 0; j < height; j++)
				for (int i = 0; i < width; i++)
				{
					const vec3 pixelPosWorld = TransformScreenToWorld(vec2(i, j));
					Ray pixelRay{pixelPosWorld, glm::normalize(pixelPosWorld - eyePos)};
					pixels[i + width * j] = vec4(glm::clamp(traceRay(pixelRay, 5), 0.0f, 1.0f), 1.0f);
				}
		}

		glm::vec3 TransformScreenToWorld(glm::vec2 positionScreen)
		{
			// 여기서 좌표계 변환 구현
			// 스크린 좌표계는 [0, width-1] x [0, height-1]
			// 여기서 우리가 정의한 월드(World) 좌표계는 [-aspect, +aspect] x [-1, +1]
			// 화면비율 aspect = float(width) / height
			float aspect = (float)width / (float)height;
			float newX = 2.f * aspect / ((float)width - 1.f) * positionScreen.x - aspect;
			float newY = -2.f / ((float)height - 1) * positionScreen.y + 1;

			return glm::vec3(newX, newY,0.0f);//z축의 값이 0에 픽셀들을 놓음
		}
	};
}