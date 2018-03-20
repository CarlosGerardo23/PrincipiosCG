#include "Mat3.h"
#include <cmath>
Mat3::Mat3()
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
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

Mat3& Mat3::rotate(const float& angle)
{
	Mat3 rotate;
	rotate.mt[0][0] = std::cos(angle*3.1416f/180.0);
	rotate.mt[0][1] = -std::sin(angle*3.1416f / 180.0);
	rotate.mt[1][0] = std::sin(angle*3.1416f / 180.0);
	rotate.mt[1][1] = std::cos(angle*3.1416f / 180.0);
	return rotate;

}
Mat3& Mat3::scale(const Vector3& v)
{
	Mat3 escala;
	for(int i=0; i<=2;i++)
		for (int j = 0; j <= 2; j++)
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
Mat3& Mat3::scale(const float&a, const float&b)
{
	Mat3 escala;
	escala.mt[0][0] = a;
	escala.mt[1][1] = b;
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
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
Mat3& Mat3::translate(const Vector3& v)
{
	Mat3 traslacion;
	traslacion.mt[0][2] = v.m[0];
	traslacion.mt[1][2] = v.m[1];
	return traslacion;
}
Mat3& Mat3::operator*(const Mat3& MM) 
{
	int r = 0, c = 0,mmr=0,mmc=0,zr=0,zc=0;
	Mat3 z;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			z.mt[i][j] = 0;
		}
	}
	/*while (zr <= 2 && zc <= 2)
	{
		zr = r;
		zc = mmc;
		if (mmr == 2)
		{
			z.mt[zr][zc] += mt[r][c] * MM.mt[mmr][mmc];
			mmr = 0;
			mmc++;
			if (mmc > 2)
			{
				mmc = 0;
				r++;
			}
			continue;
		}
		else
		{
			if (c == 2)
			{
				c = 0;
			}
			z.mt[zr][zc] += mt[r][c] * MM.mt[mmr][mmc];
			c++;
			mmr++;

		}
	}*/
	
	z.mt[0][0] += mt[0][0] * MM.mt[0][0] + mt[0][1] * MM.mt[1][0] + mt[0][2] * MM.mt[2][0];
	z.mt[1][0] += mt[1][0] * MM.mt[0][0] + mt[1][1] * MM.mt[1][0] + mt[1][2] * MM.mt[2][0];
	z.mt[2][0] += mt[2][0] * MM.mt[0][0] + mt[2][1] * MM.mt[1][0] + mt[2][2] * MM.mt[2][0];

	z.mt[0][1] += mt[0][0] * MM.mt[0][1] + mt[0][1] * MM.mt[1][1] + mt[0][2] * MM.mt[2][1];
	z.mt[1][1] += mt[1][0] * MM.mt[0][1] + mt[1][1] * MM.mt[1][1] + mt[1][2] * MM.mt[2][1];
	z.mt[2][1] += mt[2][0] * MM.mt[0][1] + mt[2][1] * MM.mt[1][1] + mt[2][2] * MM.mt[2][1];

	z.mt[0][2] += mt[0][0] * MM.mt[0][2] + mt[0][1] * MM.mt[1][2] + mt[0][2] * MM.mt[2][2];
	z.mt[1][2] += mt[1][0] * MM.mt[0][2] + mt[1][1] * MM.mt[1][2] + mt[1][2] * MM.mt[2][2];
	z.mt[2][2] += mt[2][0] * MM.mt[0][2] + mt[2][1] * MM.mt[1][2] + mt[2][2] * MM.mt[2][2];
return z;

}
Vector3& Mat3::operator*(const Vector3& VM)
{
	int r = 0, c = 0, mmr = 0, zr = 0;
	Vector3 z(0,0);
	for (int i = 0; i <= 2; i++)
	{
		
			z.m[i] = 0;
		
	}
	z.m[0] += (mt[0][0] * VM.m[0])+ (mt[0][1] * VM.m[1])+ (mt[0][2] * VM.m[2]);
	z.m[1] += (mt[1][0] * VM.m[0]) + (mt[1][1] * VM.m[1]) + (mt[1][2] * VM.m[2]);
	z.m[2] += (mt[2][0] * VM.m[0]) + (mt[2][1] * VM.m[1]) + (mt[2][2] * VM.m[2]);
	/*while (zr <= 2)
	{
		zr = r;
		
		if (mmr == 2)
		{
			z.m[zr]+= mt[r][c] * VM.m[mmr];
			mmr = 0;
			r++;
			continue;
		}
		else
		{
			if (c == 2)
			{
				c = 0;
			}
			z.m[zr] += mt[r][c] * VM.m[mmr];
			c++;
			mmr++;

		}
	}*/
	return z;
}
//Mat3& Mat3::identity()
//{
//
// }
