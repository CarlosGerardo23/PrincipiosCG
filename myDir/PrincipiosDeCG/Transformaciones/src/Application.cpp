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
			linea_Baja(x1, y1, x2, y2,b);
	}
	else
	{
		if (x1 > x2)
			linea_Alta(x2, y2, x1, y1,c);
		else
			linea_Alta(x1, y1, x2, y2,d);
	}
	/*int dx = X2 - X1;
	int dy = Y2 - Y1;

	int d = 2*(dy - dx) ;
	int x = Y1, y = X1;
	while (x < X2)
	{
		x++;		
		if (d > 0)
			d = 2*dy;
		else
		{
			d += 2*(dy - dx);
			y++;
		}
		putPixel(x, y, b);
	}*/
	
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
void Application::setup() 
{
	Vector3 a1(WIDTH/2,(HEIGHT/2)- 300);
	Vector3 b1((WIDTH / 2)-300, (HEIGHT / 2)+100);
	Vector3 c1((WIDTH / 2)+300,( HEIGHT / 2)+100);
	sierpinsky(a1, b1, c1, 6);
	
	
}
void Application::update()
{
	//Vector3 s(-WIDTH/2,-HEIGHT/2);
	//Vector3 s2(WIDTH / 2, HEIGHT / 2);
	//Vector3 s3((-WIDTH/2)+50,  (-HEIGHT / 2)-70);
	//Vector3 s4((-WIDTH / 2) - 50, (-HEIGHT / 2) + 70);
	//Vector3 s5(.5, .5);
	////Vector3 s3()
	//vp.clear();
	//Vector3 a(0, 0);
	//Mat3 acum;
	//Mat3 tras = Mat3::translate(s);
	//Mat3 scale2 = Mat3::rotate(ang);
	//Mat3 trans2 = Mat3::translate(s3);
	//Mat3 rot2 = Mat3::rotate(ang2);
	//Mat3 trans3 = Mat3::translate(s4);
	//ys += 50;
	//ang +=10;
	//ang2 += 1;
	//Mat3 acum2 = Mat3::translate(s2);
	//acum = (scale2*tras);
	//Mat3 acum3 = rot2 * trans2;
	//Mat3 acumt1 = acum2 * acum;
	//Mat3 acum4 = trans3;
	//Mat3 acumtt2 = acum4 * acum3;
	////Mat3 acumtt2s = acumtt2 * Mat3::scale(s5);
	//Mat3 acumtt = acumtt2 * acumt1;
	//Vector3 tras2=Mat3::translate()
	vp.clear();
	Vector3 a(0, 0);
	Vector3 t1(-WIDTH / 2, -HEIGHT / 2);
	Vector3 t2(100, -100);
	Vector3 t3(WIDTH / 2, HEIGHT / 2);
	ang += 4;
	ang2 -= 2;
	Mat3 acumtt;
	Mat3 tras=Mat3::translate(t1);
	Mat3 tras2 = Mat3::translate(t2);
	Mat3 tras3 = Mat3::translate(t3);
	Mat3 rot=Mat3::rotate(ang);
	Mat3 rot2=Mat3::rotate(ang2);
	//tras3 * ((rot2*tras2)*(rot*tras));
	Mat3 acum = (rot*tras);
	Mat3 acum2 = (rot2*tras2);
	Mat3 acum3 = acum2 * acum;
	acumtt = tras3*acum3;
	for (int i = 0; i < v.size(); i++)
	{
		a = acumtt * v.at(i);
		vp.push_back(a);
	}
}
void Application::draw()
{
	
	/*Vector3 a(WIDTH / 2, (HEIGHT / 2) - 300);
	Vector3 b((WIDTH / 2) - 300, (HEIGHT / 2) + 100);
	Vector3 c((WIDTH / 2) + 300, (HEIGHT / 2) + 100);
	Vector3 s(0.5,0.5);
	Mat3 scala;
	
	
	scala = Mat3::scale(s);
	Vector3 ar = scala*a;
	Vector3 br = scala*b;
	Vector3 cr= scala*c;

	triangle(ar, br, cr);*/
	/*
	for (int angulo = 0; angulo < 360; ++angulo)
	{
		
		int x = 300 * std::cos((angulo*(pi / 180.0)));
		int y = 300 * std::sin((angulo*pi / 180.0));
		linea(WIDTH/2, HEIGHT/2, x+WIDTH / 2, y  + HEIGHT / 2);
	}*/
	//create_poligon(4);
	clear_screen();
	/*for (int i = 0; i < v.size(); i+=3)
	{
	
	}*/
	for (int i = 0; i < vp.size(); i+=3)
	{
		triangle(vp[i], vp[i + 1], vp[i + 2]);
	}
	
}

Application::~Application()
{
}
