#include "Vec4.h"
#include <math.h>

Vec4::Vec4(float a, float b, float c)
{
	m[0] = a;
	m[1] = b;
	m[2] = c;
	m[3] = 1;
}
Vec4& Vec4::operator*( const Vec4& RV)
{
	Vec4 result(0, 0, 0);
	result.m[0] =( m[1] * RV.m[2]) - (m[2] * RV.m[1]);
	result.m[1] =-((m[0] * RV.m[2]) - (m[2] * RV.m[0]));
	result.m[2] = (m[0] * RV.m[1]) - (m[1] * RV.m[0]);
	return result;
}

Vec4& Vec4::normalize(const Vec4 a)
{
	Vec4 final(0,0,0);
	float cuadrados = (a.m[0] * a.m[0])+ (a.m[1] * a.m[1]) + (a.m[2] * a.m[2]) ;
	float n = sqrt(cuadrados);
	final.m[0] = a.m[0] / n;
	final.m[1] = a.m[1] / n;
	final.m[2] = a.m[2] / n;
	return final;
}

Vec4& Vec4::operator-(const Vec4& RV)const
{
	Vec4 final(0,0,0);
	final.m[0] = m[0] - RV.m[0];
	final.m[1] = m[1] - RV.m[1];
	final.m[2] = m[2] - RV.m[2];
	return final;

}
float& Vec4::punto(const Vec4& VR)
{
	float final = (m[0] * VR.m[0]) + (m[1] * VR.m[1]) + (m[2] * VR.m[2]);
	return final;
}
Vec4& Vec4::negativos(const Vec4& v) 
{
	Vec4 final(-v.m[0],-v.m[1],-v.m[2]);
	return final;
}