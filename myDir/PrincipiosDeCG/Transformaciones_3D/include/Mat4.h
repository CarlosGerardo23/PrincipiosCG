#ifndef MAT4_H
#define MAT4_H
#include "Vec4.h"

class Mat4
{
public:
	float mt[4][4];
	Mat4();
	Mat4& operator *(const Mat4& MM);
	Vec4& operator*(const Vec4& VM);
	static Mat4& scale(const Vec4& v);
	static Mat4& scale(const float& a, const float&b);
	static Mat4& rotate_x(const float& angle);
	static Mat4& rotate_y(const float& angle);
	static Mat4& rotate_z(const float& angle);
	static Mat4& translate(const Vec4& v);
	static Mat4& lookAt(const Vec4& eye, const Vec4& target, const Vec4& up);
	static Mat4& perspective(float& FOV, const int& aspect, const float& near, const float& far);

};

#endif
