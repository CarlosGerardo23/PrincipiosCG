#include "Application.h"
#include <cmath>



Application::Application()
{
	
	
}
Vector3& Application::midpoint(Vector3& a, Vector3& b)
{
	Vector3 as((a.m[0] + b.m[0]) / 2, (a.m[1] + b.m[1]) / 2);
	return as;
}
void Application::sierpinsky(Vector3 a, Vector3 b, Vector3 c, int iteracion) 
{
	if (iteracion == 0) 
	{
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
	}
	else
	{
		Vector3 ab=midpoint(a, b);
		Vector3 bc = midpoint(b, c);
		Vector3 ca = midpoint(c, a);
		sierpinsky(a,ab,ca,iteracion-1);
		sierpinsky(ab, b,bc, iteracion - 1);
		sierpinsky(ca, bc, c, iteracion - 1);
	}
	
}
void Application::linea_Baja(int x1, int y1, int x2, int y2,Color a)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int d = 2 * (dx - dy);
	int x = x1;
	int y = y1;
	while (y <= y2)
	{
		y++;
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * dy;
		}
			d = d + 2 * dx;
		putPixel(x, y,a);
	}
}
void Application::linea_Alta(int x1, int y1, int x2, int y2, Color a)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int d = 2 * (dy - dx);
	int y = y1;
	int x = x1;
	while (x <= x2)
	{
		x++;
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * dx;
		}
			d = d + 2 * dy;
             putPixel(x, y, a);
	}
}
void Application::linea(int x1, int y1, int x2, int y2)
{
	Color b(255, 0, 0, 255);
	Color a(0, 255, 0, 255);
	Color c(0, 0, 255, 255);
	Color d(255, 0, 255, 255);
	if (abs(x2 - x1) < abs(y2 - y1))
	{
		if (y1 > y2)
		{
            linea_Baja(x2, y2, x1, y1,a);
		}
			
		else
			linea_Baja(x1, y1, x2, y2,a);
	}
	else
	{
		if (x1 > x2)
			linea_Alta(x2, y2, x1, y1,a);
		else
			linea_Alta(x1, y1, x2, y2,a);
	}
	
}
void Application::linea(int x1, int y1, int x2, int y2, Color a) {

	if (abs(x2 - x1) < abs(y2 - y1))
	{
		if (y1 > y2)
		{
			linea_Baja(x2, y2, x1, y1, a);
		}

		else
			linea_Baja(x1, y1, x2, y2, a);
	}
	else
	{
		if (x1 > x2)
			linea_Alta(x2, y2, x1, y1, a);
		else
			linea_Alta(x1, y1, x2, y2, a);
	}
}
void Application::clear_screen() 
{
	Color n(0, 0, 0,255);
	for (int i = 0; i <= WIDTH; i++)
	{
		for (int j = 0; j <= HEIGHT; ++j)
		{
			putPixel(i, j, n);
	   }
	}
	
}
void Application::moveto(int x, int y)
{
	gx = x;
	gy = y;
}
void Application::lineto(int x1, int y1)
{
	linea(gx,gy,x1,y1);
	moveto(x1, y1);
}
void Application::lineto(int x1, int y1, Color d)
{
	linea(gx, gy, x1, y1,d);
	moveto(x1, y1);
}
void Application::create_poligon(int lados)
{
	int contador = 1;
	int tx, ty;
	int angulo = 360;
	
	angulo = angulo / lados;
	for (int i = angulo; i <= 360; i += angulo)
	{

		int x = 300 * std::cos(i*pi / 180.0f);
		int y = 300 * std::sin(i*pi / 180.0f);
		if (i == angulo)
		{
			moveto(x + WIDTH / 2, y + HEIGHT / 2);
			tx = x;
			ty = y;
			
		}
		else if (i==360)
		{
			
			lineto(x + WIDTH / 2, y + HEIGHT / 2);
			
			lineto(tx + WIDTH / 2, ty + HEIGHT / 2);
			
		}
		else
		{
			lineto(x + WIDTH / 2, y + HEIGHT / 2);
			
		}
		contador++;
		
	}
}
void Application::triangle(Vector3 a, Vector3 b, Vector3 c)
{
	moveto(a.m[0], a.m[1]);
	lineto(b.m[0], b.m[1]);
	lineto(c.m[0], c.m[1]);
	lineto(a.m[0], a.m[1]);
}
void Application::triangle(Vec4 a, Vec4 b, Vec4 c) 
{
	moveto(a.m[0], a.m[1]);
	lineto(b.m[0], b.m[1]);
	lineto(c.m[0], c.m[1]);
	lineto(a.m[0], a.m[1]);
}
void Application::triangle(Vec4 a, Vec4 b, Vec4 c, Color sa)
{
	float rango_viejo = 2;
	float rango_nuevo = 1024;

	for (int i = 0; i < 4; i++)
	{
		a.m[i] = (((a.m[i] - (-1))*rango_nuevo) / rango_viejo);
		b.m[i] = (((b.m[i] - (-1))*rango_nuevo) / rango_viejo);
		c.m[i] = (((c.m[i] - (-1))*rango_nuevo) / rango_viejo);
	}
	
	moveto(a.m[0], a.m[1]);
	lineto(b.m[0], b.m[1], sa);
	lineto(c.m[0], c.m[1], sa);
	lineto(a.m[0], a.m[1], sa);
}
void Application::cube(float w, float h, float z) {
    Vec4 a(  - w, - h, z);
    Vec4 b(  - w, + h, z);
    Vec4 c(  + w, - h, z);
	Vec4 d(  + w, + h, z);

	Vec4 a_back(  - w, - h, -z);
	Vec4 b_back(  - w, + h, -z);
	Vec4 c_back(  + w, - h, -z);
	Vec4 d_back(  + w, + h, -z);

	Vec4 a_right( + w, h, +z);
	Vec4 b_right( + w, h, +z);
	Vec4 c_right( + w, h, -z);
	Vec4 d_right( + w, h, -z);

	Vec4 a_left(  - w, - h, -z);
	Vec4 b_left(  - w, + h, -z);
	Vec4 c_left(  - w, - h, +z);
	Vec4 d_left(  - w, + h, +z);
					 
	Vec4 a_top(   - w,  - h, -z);
	Vec4 b_top(   - w,  - h, +z);
	Vec4 c_top(   + w,  - h, -z);
	Vec4 d_top(   + w,  - h, +z);

Vec4 a_bottom ( - w,   + h, -z);
Vec4 b_bottom ( - w,   + h, +z);
Vec4 c_bottom ( + w,   + h, -z);
Vec4 d_bottom ( + w,   + h, +z);

	v4.push_back(a);
	v4.push_back(b);
	v4.push_back(c);
	v4.push_back(d);

	v4.push_back(a_back);
	v4.push_back(b_back);
	v4.push_back(c_back);
	v4.push_back(d_back);

	v4.push_back(a_right);
	v4.push_back(b_right);
	v4.push_back(c_right);
	v4.push_back(d_right);

	v4.push_back(a_left);
	v4.push_back(b_left);
	v4.push_back(c_left);
	v4.push_back(d_left);

	v4.push_back(a_top);
	v4.push_back(b_top);
	v4.push_back(c_top);
	v4.push_back(d_top);

	v4.push_back(a_bottom);
	v4.push_back(b_bottom);
	v4.push_back(c_bottom);
	v4.push_back(d_bottom);

}
void Application::cube2(float w, float h, float z) {
	Vec4 a(cx-w, cy-h, z);
	Vec4 b(cx-w, cy+h, z);
	Vec4 c(cx+w, cy-h, z);
	Vec4 d(cx+w, cy+h, z);

	Vec4 a_back(cx-w, cy-h, -z);
	Vec4 b_back(cx-w, cy+h, -z);
	Vec4 c_back(cx+w, cy-h, -z);
	Vec4 d_back(cx+w, cy+h, -z);

	Vec4 a_right(cx+w, h, +z);
	Vec4 b_right(cx+w, h, +z);
	Vec4 c_right(cx+w, h, -z);
	Vec4 d_right(cx+w, h, -z);

	Vec4 a_left(cx-w, cy-h, -z);
	Vec4 b_left(cx-w, cy+h, -z);
	Vec4 c_left(cx-w, cy-h, +z);
	Vec4 d_left(cx-w, cy+h, +z);

	Vec4 a_top(cx-w, cy-h, -z);
	Vec4 b_top(cx-w, cy-h, +z);
	Vec4 c_top(cx+w, cy-h, -z);
	Vec4 d_top(cx+w, cy-h, +z);

	Vec4 a_bottom(cx-w, cy+h, -z);
	Vec4 b_bottom(cx-w, cy+h, +z);
	Vec4 c_bottom(cx+w, cy+h, -z);
	Vec4 d_bottom(cx+w, cy+h, +z);

	v4.push_back(a);
	v4.push_back(b);
	v4.push_back(c);
	v4.push_back(d);

	v4.push_back(a_back);
	v4.push_back(b_back);
	v4.push_back(c_back);
	v4.push_back(d_back);

	v4.push_back(a_right);
	v4.push_back(b_right);
	v4.push_back(c_right);
	v4.push_back(d_right);

	v4.push_back(a_left);
	v4.push_back(b_left);
	v4.push_back(c_left);
	v4.push_back(d_left);

	v4.push_back(a_top);
	v4.push_back(b_top);
	v4.push_back(c_top);
	v4.push_back(d_top);

	v4.push_back(a_bottom);
	v4.push_back(b_bottom);
	v4.push_back(c_bottom);
	v4.push_back(d_bottom);

}
void Application::lines(std::vector<Vec4>v)
{
	for (int i = 0; i < v.size(); i += 2)
	{
		if (i == 0)
		{
         moveto(v[i].m[0],v[i].m[1]);
		 lineto(v[i+1].m[0], v[i+1].m[1]);
		}
		else
		{
			moveto(v[i ].m[0], v[i ].m[1]);
			lineto(v[i + 1].m[0], v[i + 1].m[1]);

		}
		
		
	}
}
void Application::lines_strip(std::vector<Vec4>v)
{
	for (int i = 0; i < v.size(); i += 2)
	{
		if (i == 0)
		{
			moveto(v[i].m[0], v[i].m[1]);
			lineto(v[i + 1].m[0], v[i + 1].m[1]);
		}
		else
		{
			lineto(v[i].m[0], v[i].m[1]);
			lineto(v[i + 1].m[0], v[i + 1].m[1]);

		}


	}

}
void Application::lines_loop(std::vector<Vec4>v)
{
	Vec4 temp(0, 0, 0);
	for (int i = 0; i < v.size(); i += 1)
	{
		if (i == 0)
		{
			temp = v[i];
			moveto(v[i].m[0], v[i].m[1]);
			lineto(v[i + 1].m[0], v[i + 1].m[1]);
		}
		else if (i == v.size() - 1) 
		{
			lineto(temp.m[0], temp.m[1]);
		}
		else
		{
			lineto(v[i].m[0], v[i].m[1]);
			lineto(v[i + 1].m[0], v[i + 1].m[1]);

		}


	}
}
void Application::triangle_fan(std::vector<Vec4>v)
{
	Vec4 temp(0, 0, 0);
	for (int i = 0; i < v.size(); i += 1)
	{
		if (i == 0)
		{
			temp = v[i];
			moveto(v[i].m[0], v[i].m[1]);
			lineto(v[i + 1].m[0], v[i + 1].m[1]);
		}
		else
		{
			lineto(v[i].m[0], v[i].m[1]);
			lineto(temp.m[0], temp.m[1]);
			moveto(v[i].m[0], v[i].m[1]);

		}


	}
}
void Application::triangle_strip(std::vector<Vec4>v)
{
	for (int i = 0; i < v.size(); i += 4)
		{
			triangle(v[i], v[i + 1], v[i + 2]);
			triangle(v[i + 3], v[i + 1], v[i + 2]);
		}
}
void Application::circle(int c_x, int c_y, int R)
{
	Color a(200, 0, 180, 255);
	int x = 0;
	int y = R;
	float d= 1 - R;
	while (x<y) {
		putPixel( x + c_x, y + c_y,a);
		putPixel(-x+ c_x, y + c_y, a);
		putPixel(-x+ c_x, -y +c_y, a);
		putPixel(x + c_x, -y +c_y,a);
					  		   
		putPixel(y + c_x, -x +c_y,a);
		putPixel(-y +c_x, -x +c_y, a);
		putPixel(-y +c_x, x + c_y, a);
		putPixel(y + c_x, x + c_y, a);
		if (d<0) {
			d += 2*x + 3;
		}
		else {
			--y;
			d += 2*x - 2*y + 5;
		}
		++x;
	}
}
void Application::drawGeometry(std::vector<Vec4> vcopy, int metodo)
{
	enum met
	{
		Triangles,
		Points,
		Lines,
		Lines_Strip,
		Lines_Loop,
		Triangle_Fan,
		Triangle_Strip
	};

	switch (metodo)
	{
	case Triangles:
	{
		for (int i = 0; i < vcopy.size(); i += 3)
		{
			triangle(vcopy[i], vcopy[i + 1], vcopy[i + 2]);
		}
			
	}
		break;
	case Points:
	{
		for (int i = 0; i < vcopy.size(); i += 1)
		{
			if (i == 0)
			{
				moveto(vcopy[i].m[0], vcopy[i].m[1]);
			}
			else
			{
				lineto(vcopy[i].m[0], vcopy[i].m[1]);
			}
		}
	}
		break;
	case Lines:
	{
		lines(vcopy);
	}
		break;
	case Lines_Strip:
	{
		lines_strip(vcopy);
	}
		break;
	case Lines_Loop:
	{
		lines_loop(vcopy);
	}
		break;
	case Triangle_Fan:
	{
		triangle_fan(vcopy);
	}
		break;
	case Triangle_Strip:
	{
		triangle_strip(vcopy);
	}
		break;
	default:
		break;
	}
}
void Application::setup() 
{


}
void Application::update()
{
	

}

void Application::draw()
{

	circle(cx + 50, +cy + 100, 100);
	circle(cx, cy, 100);

	circle(cx - 50, +cy + 10, 100);
	circle(cx-300, cy+20, 100);

	circle(cx + 100, +cy -100, 100);
	circle(cx-60, cy+300, 100);

	circle(cx + 59, +cy+400 + 100, 100);
	circle(cx-200, cy+90, 100);

	circle(cx + 50, +cy, 100);
	circle(cx, cy-90, 100);

	circle(cx , +cy + 100, 100);
	circle(cx-100, cy, 100);

	circle(cx -30, +cy + 180, 100);
	circle(cx, cy-41, 100);
	circle(cx + 350, +cy + 100, 100);

	
}

Application::~Application()
{
}
