#include "Application.h"
#include <cmath>



Application::Application()
{
	
	
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
void Application::lineto(int x1, int y1, int x2, int y2)
{
	linea(x1, y1, x2, y2);
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
		if (contador == 1)
		{
			moveto(x + WIDTH / 2, y + HEIGHT / 2);
			tx = x;
			ty = y;
		}
		else if (contador == lados)
		{
			lineto(gx, gy, x + WIDTH / 2, y + HEIGHT / 2);
			moveto(x + WIDTH / 2, y + HEIGHT / 2);
			lineto(gx, gy, tx + WIDTH / 2, ty + HEIGHT / 2);
		}
		else
		{
			lineto(gx, gy, x + WIDTH / 2, y + HEIGHT / 2);
			moveto(x + WIDTH / 2, y + HEIGHT / 2);
		}
		contador++;
		
	}
}
void Application::draw()
{
	/*
	for (int angulo = 0; angulo < 360; ++angulo)
	{
		
		int x = 300 * std::cos((angulo*(pi / 180.0)));
		int y = 300 * std::sin((angulo*pi / 180.0));
		linea(WIDTH/2, HEIGHT/2, x+WIDTH / 2, y  + HEIGHT / 2);
	}*/
	create_poligon(4);
	clear_screen();
	
}

Application::~Application()
{
}
