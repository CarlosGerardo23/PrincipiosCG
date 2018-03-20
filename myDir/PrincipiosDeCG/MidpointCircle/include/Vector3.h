#ifndef VECTOR3_H
#define VECTOR3_H
class Vector3
{
public:
	float m[3];
	float x() { return m[0]; }
	float y() { return m[1]; }
	Vector3(float a, float b);
	/*Vector3& operator*(const Vector3& v);*/
};
#endif
