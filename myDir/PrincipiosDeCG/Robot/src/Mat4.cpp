#include "Mat4.h"
#include <cmath>

Mat4::Mat4()
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
		{
			if (i == j)
			{
				this->mt[i][j] = 1;
			}
			else {
				this->mt[i][j] = 0;
			}
		}
}

Mat4& Mat4::rotate_x(const float& angle)
{
	Mat4 rotate;
	rotate.mt[1][1] = std::cos(angle*3.1416f / 180.0);
	rotate.mt[1][2] = -std::sin(angle*3.1416f / 180.0);
	rotate.mt[2][1] = std::sin(angle*3.1416f / 180.0);
	rotate.mt[2][2] = std::cos(angle*3.1416f / 180.0);
	return rotate;
}
Mat4& Mat4::rotate_y(const float& angle)
{
	Mat4 rotate;
	rotate.mt[0][0] = std::cos(angle*3.1416f / 180.0);
	rotate.mt[0][2] = -std::sin(angle*3.1416f / 180.0);
	rotate.mt[2][0] = std::sin(angle*3.1416f / 180.0);
	rotate.mt[2][1] = std::cos(angle*3.1416f / 180.0);
	return rotate;
}
Mat4& Mat4::rotate_z(const float& angle)
{
	Mat4 rotate;
	rotate.mt[0][0] = std::cos(angle*3.1416f / 180.0);
	rotate.mt[0][1] = -std::sin(angle*3.1416f / 180.0);
	rotate.mt[1][0] = std::sin(angle*3.1416f / 180.0);
	rotate.mt[1][1] = std::cos(angle*3.1416f / 180.0);
	return rotate;
}

Mat4& Mat4::scale(const Vec4& v)
{
	Mat4 escala;
	for (int i = 0; i <=3; i++)
		for (int j = 0; j <=3; j++)
		{
			if (i == j)
			{
				escala.mt[i][j] = v.m[i];
			}
			else {
				escala.mt[i][j] = 0;
			}
		}
	return escala;
}
Mat4& Mat4::scale(const float&a, const float&b)
{
	Mat4 escala;
	escala.mt[0][0] = a;
	escala.mt[1][1] = b;
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
		{
			if (i == j)
			{
				continue;
			}
			else {
				escala.mt[i][j] = 0;
			}
		}
	return escala;
}
Mat4& Mat4::translate(const Vec4& v)
{

	Mat4 traslacion;
	traslacion.mt[0][3] = v.m[0];
	traslacion.mt[1][3] = v.m[1];
	traslacion.mt[2][3] = v.m[2];
	return traslacion;
}

Mat4& Mat4::operator*(const Mat4& MM)
{
	Mat4 z;
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			z.mt[i][j] = 0;
		}
	}
	z.mt[0][0] += mt[0][0] * MM.mt[0][0] + mt[0][1] * MM.mt[1][0] + mt[0][2] * MM.mt[2][0] + mt[0][3] * MM.mt[3][0];
	z.mt[1][0] += mt[1][0] * MM.mt[0][0] + mt[1][1] * MM.mt[1][0] + mt[1][2] * MM.mt[2][0] + mt[1][3] * MM.mt[3][0];
	z.mt[2][0] += mt[2][0] * MM.mt[0][0] + mt[2][1] * MM.mt[1][0] + mt[2][2] * MM.mt[2][0] + mt[2][3] * MM.mt[3][0];
	z.mt[3][0] += mt[3][0] * MM.mt[0][0] + mt[3][1] * MM.mt[1][0] + mt[3][2] * MM.mt[2][0] + mt[3][3] * MM.mt[3][0];

	z.mt[0][1] += mt[0][0] * MM.mt[0][1] + mt[0][1] * MM.mt[1][1] + mt[0][2] * MM.mt[2][1] + mt[0][3] * MM.mt[3][1];
	z.mt[1][1] += mt[1][0] * MM.mt[0][1] + mt[1][1] * MM.mt[1][1] + mt[1][2] * MM.mt[2][1] + mt[1][3] * MM.mt[3][1];
	z.mt[2][1] += mt[2][0] * MM.mt[0][1] + mt[2][1] * MM.mt[1][1] + mt[2][2] * MM.mt[2][1] + mt[2][3] * MM.mt[3][1];
	z.mt[3][1] += mt[3][0] * MM.mt[0][1] + mt[3][1] * MM.mt[1][1] + mt[3][2] * MM.mt[2][1] + mt[3][3] * MM.mt[3][1];

	z.mt[0][2] += mt[0][0] * MM.mt[0][2] + mt[0][1] * MM.mt[1][2] + mt[0][2] * MM.mt[2][2] + mt[0][3] * MM.mt[3][2];
	z.mt[1][2] += mt[1][0] * MM.mt[0][2] + mt[1][1] * MM.mt[1][2] + mt[1][2] * MM.mt[2][2] + mt[1][3] * MM.mt[3][2];
	z.mt[2][2] += mt[2][0] * MM.mt[0][2] + mt[2][1] * MM.mt[1][2] + mt[2][2] * MM.mt[2][2] + mt[2][3] * MM.mt[3][2];
	z.mt[3][2] += mt[3][0] * MM.mt[0][2] + mt[3][1] * MM.mt[1][2] + mt[3][2] * MM.mt[2][2] + mt[3][3] * MM.mt[3][2];

	z.mt[0][3] += mt[0][0] * MM.mt[0][3] + mt[0][1] * MM.mt[1][3] + mt[0][2] * MM.mt[2][3] + mt[0][3] * MM.mt[3][3];
	z.mt[1][3] += mt[1][0] * MM.mt[0][3] + mt[1][1] * MM.mt[1][3] + mt[1][2] * MM.mt[2][3] + mt[1][3] * MM.mt[3][3];
	z.mt[2][3] += mt[2][0] * MM.mt[0][3] + mt[2][1] * MM.mt[1][3] + mt[2][2] * MM.mt[2][3] + mt[2][3] * MM.mt[3][3];
	z.mt[3][3] += mt[3][0] * MM.mt[0][3] + mt[3][1] * MM.mt[1][3] + mt[3][2] * MM.mt[2][3] + mt[3][3] * MM.mt[3][3];

	return z;
}
Vec4& Mat4::operator*(const Vec4& VM)
{
	Vec4 z(0, 0,0);
	for (int i = 0; i <= 3; i++)
	{

		z.m[i] = 0;

	}
	z.m[0] += (mt[0][0] * VM.m[0]) + (mt[0][1] * VM.m[1]) + (mt[0][2] * VM.m[2]) + (mt[0][3] * VM.m[3]);
	z.m[1] += (mt[1][0] * VM.m[0]) + (mt[1][1] * VM.m[1]) + (mt[1][2] * VM.m[2]) + (mt[1][3] * VM.m[3]);
	z.m[2] += (mt[2][0] * VM.m[0]) + (mt[2][1] * VM.m[1]) + (mt[2][2] * VM.m[2]) + (mt[2][3] * VM.m[3]);
	z.m[3] += (mt[3][0] * VM.m[0]) + (mt[3][1] * VM.m[1]) + (mt[3][2] * VM.m[2]) + (mt[3][3] * VM.m[3]);
	return z;
}
//acabatr el look at
Mat4& Mat4::lookAt(const Vec4& eye, const Vec4& target, const Vec4& up)
{
	Mat4 final;
	Mat4 rot;
	Mat4 Tras;
	Vec4 F(0, 0, 0);
	Vec4 R(0, 0, 0);
	Vec4 U(0, 0, 0);
	Vec4 tra(-eye.m[0], -eye.m[1], -eye.m[2]);
	/*F = Vec4::normalize(target-eye);
	U = Vec4::normalize(F*up);
	R = Vec4::normalize(U*F);
	Vec4 tra(U.punto(Vec4::negativos(eye)), R.punto(Vec4::negativos(eye)), F.punto(Vec4::negativos(eye)));*/

	Tras = Mat4::translate(tra);
	F = Vec4::normalize(target - eye);
	R= Vec4::normalize(F*up);
	U = R*F;
	rot.mt[0][0] = R.m[0];
	rot.mt[1][0] = R.m[1];
	rot.mt[2][0] = R.m[2];

	rot.mt[0][1] = U.m[0];
	rot.mt[1][1] = U.m[1];
	rot.mt[2][1] = U.m[2];

	rot.mt[0][2] = -F.m[0];
	rot.mt[1][2] = -F.m[1];
	rot.mt[2][2] = -F.m[2];
	/*rot.mt[0][0] = R.m[0];
	rot.mt[0][1] = R.m[1];
	rot.mt[0][2] = R.m[2];

	rot.mt[1][0] = U.m[0];
	rot.mt[1][1] = U.m[1];
	rot.mt[1][2] = U.m[2];

	rot.mt[2][0] = -F.m[0];
	rot.mt[2][1] = -F.m[1];
	rot.mt[2][2] = -F.m[2];*/
	final =rot*Tras;
	return final;
}
Mat4& Mat4::perspective(float& FOV, const int& aspect, const float& near, const float& far)
{
	FOV = (FOV * 3.1416f )/ 180, 0;
	float d = 1 / std::tan(FOV / 2);
	Mat4 final;
	final.mt[0][0] = d / aspect;
	final.mt[1][1] = d;
	final.mt[2][2] = (-(far + near) / (far - near));
	final.mt[2][3] = (-(2 * far*near) / (far - near));
	final.mt[3][2] = -1;
	return final;
}