#ifndef MAT3_H
#define MAT3_H
#include "Vector3.h"
class Mat3
{
public:
	float mt[3][3];
	Mat3();
	Mat3& operator *(const Mat3& MM);
	Vector3& operator*(const Vector3& VM);
	static Mat3& scale(const Vector3& v);
	static Mat3& scale(const float&a,const float&b);
	static Mat3& rotate(const float& angle);
	static Mat3& translate(const Vector3& v);
	/*static Mat3& identity();*/
};

#endif
