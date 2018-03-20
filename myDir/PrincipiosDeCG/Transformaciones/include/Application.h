#ifndef APPLICATION_H
#define APPLICATION_H
#include "BaseApplication.h"
#include <vector>
#include "Vector3.h"
#include "Mat3.h"
class Application:public BaseApplication
{

	
public:
	Application();
	~Application();
	void setup() override;
	
	int xs = 0,ys=0;
	int ang = 0;
	int ang2 = 0;
	int gx = WIDTH / 2, gy = HEIGHT / 2;
	std::vector<Vector3>v;
	std::vector<Vector3>vp;
	void sierpinsky(Vector3 a, Vector3 b, Vector3 c, int iteracion);
	Vector3& midpoint(Vector3& a, Vector3& b);
	void draw() override;
	void linea(int x1, int y1, int x2, int y2);
	void linea_Alta(int x1, int y1, int x2, int y2, Color a);
	void linea_Baja(int x1, int y1, int x2, int y2, Color a);
	float pi= 3.1416f;
	void moveto(int x, int y);
	void lineto(int x1, int y1);
	void create_poligon(int lados);
	void clear_screen();
	void triangle(Vector3 a, Vector3 b, Vector3 c);
	void update() override;
};

#endif 