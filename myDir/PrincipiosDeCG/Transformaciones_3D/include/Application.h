#ifndef APPLICATION_H
#define APPLICATION_H
#include "BaseApplication.h"
#include <vector>
#include "Vector3.h"
#include "Vec4.h"
#include "Mat4.h"
#include "Mat3.h"
class Application:public BaseApplication
{

	
public:
	Application();
	~Application();
	
	void setup() override;
	int color = 1;
	int ycam = 0;
	int xcam = 0;
	int xs = 0,ys=0;
	int ang = 0;
	int ang2 = 0;
	int gx = WIDTH / 2, gy = HEIGHT / 2;
	int cx=WIDTH / 2, cy = HEIGHT / 2;
	std::vector<Vector3>v;
	std::vector<Vec4>v4;
	std::vector<Vector3>vp;
	std::vector<Vec4>v4_p;
	void sierpinsky(Vector3 a, Vector3 b, Vector3 c, int iteracion);
	Vector3& midpoint(Vector3& a, Vector3& b);
	void draw() override;
	void linea(int x1, int y1, int x2, int y2);
	void linea(int x1, int y1, int x2, int y2, Color a);
	void linea_Alta(int x1, int y1, int x2, int y2, Color a);
	void linea_Baja(int x1, int y1, int x2, int y2, Color a);
	float pi= 3.1416f;
	void moveto(int x, int y);
	void lineto(int x1, int y1);
	void lineto(int x1, int y1, Color d);
	void create_poligon(int lados);
	void clear_screen();
	void triangle(Vector3 a, Vector3 b, Vector3 c);
	void triangle(Vec4 a, Vec4 b, Vec4 c);
	void triangle(Vec4 a, Vec4 b, Vec4 c, Color sa);
	void update() override;
	void cube(float w, float h, float z);
	void cube2(float w, float h, float z);
	void lines(std::vector<Vec4>v);
	void lines_strip(std::vector<Vec4>v);
	void lines_loop(std::vector<Vec4>v);
	void triangle_fan(std::vector<Vec4>v);
	void triangle_strip(std::vector<Vec4>v);

	void drawGeometry(std::vector<Vec4> vcopy, int metodo);
};

#endif 