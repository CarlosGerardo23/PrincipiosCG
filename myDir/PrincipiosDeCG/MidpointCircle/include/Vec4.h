#ifndef VEC4_H
#define VEC4_H

class Vec4 
{
public:
	float m[4];
	float x() { return m[0]; }
	float y() { return m[1]; }
	float z() { return m[2]; }
	Vec4(float a, float b,float c);
	static Vec4& normalize(const Vec4 a);
	Vec4& operator *( const Vec4& RV);
	Vec4& operator -(const Vec4&RV)const;
	static Vec4& negativos(const Vec4& y);
	float& punto(const Vec4& VR);
};

#endif