#include "Application.h"



Application::Application()
{
	
	
}
void Application::draw()
{
	int x, y;
	Color a(0, 255, 0, 255);
	
	Color b(255, 0, 0, 255);
	for (int i = 4; i<WIDTH; i++)
	{
		putPixel(i, HEIGHT/2, a);
	}
	for (int i = 4; i < HEIGHT; i++) {
		putPixel(WIDTH / 2, i, a);
	}
	for (int i = 0; i < 1024; i++) {
		putPixel(i, i, b);
		putPixel( i*-1, i, b);
		
		
	}
	/*for (x = 0, y = HEIGHT; x < WIDTH&&y>0;x++,y--) {
		putPixel(x, y, a);
		

	}*/
}

Application::~Application()
{
}
