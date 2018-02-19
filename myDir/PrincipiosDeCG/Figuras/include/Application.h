#ifndef APPLICATION_H
#define APPLICATION_H
#include "BaseApplication.h"
class Application:public BaseApplication
{

	
public:
	Application();
	~Application();
	//void setup() override;
	int gx = WIDTH / 2, gy = HEIGHT / 2;
	void draw() override;
	void linea(int x1, int y1, int x2, int y2);
	void linea_Alta(int x1, int y1, int x2, int y2, Color a);
	void linea_Baja(int x1, int y1, int x2, int y2, Color a);
	float pi= 3.1416f;
	void moveto(int x, int y);
	void lineto(int x1, int y1, int x2, int y2);
	void create_poligon(int lados);
	void clear_screen();
	//void update() override;
};

#endif 