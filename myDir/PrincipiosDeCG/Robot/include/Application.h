#ifndef APPLICATION_H
#define APPLICATION_H
#include "BaseApplication.h"
#include <vector>
#include "Vector3.h"
#include "Vec4.h"
#include "Mat4.h"
#include "Mat3.h"
class Application :public BaseApplication
{


public:
	Application();
	~Application();

	void setup() override;
	int num = 1, num2 = -1,num_ = -1, num2_ = 1,num_a = -1, num_b = 1;
	int color = 1;
	int ycam = 0;
	int xcam = 0;
	int xs = 0, ys = 0;
	int ang = 1;
	int ang2 = 1;
	int ang_ = 1;
	int ang2_ = 1;

	int ang_a = 1;
	int ang2_a = 1;
	int gx = WIDTH / 2, gy = HEIGHT / 2;
	int cx = WIDTH / 2, cy = HEIGHT / 2;
	std::vector<Vector3>v;
	std::vector<Vec4>v4;
	std::vector<Vector3>vp;
	std::vector<Vec4>v4_p;

	std::vector<Vec4>cabeza;
	std::vector<Vec4>torso;
	std::vector<Vec4>anteBrazo;
	std::vector<Vec4>anteBrazo2;
	std::vector<Vec4>brazo;
	std::vector<Vec4>brazo2;
	std::vector<Vec4>muslo;
	std::vector<Vec4>muslo2;
	std::vector<Vec4>pierna;
	std::vector<Vec4>pierna2;

	std::vector<Vec4>cabeza_;
	std::vector<Vec4>torso_;
	std::vector<Vec4>anteBrazo_;
	std::vector<Vec4>anteBrazo2_;
	std::vector<Vec4>brazo_;
	std::vector<Vec4>brazo2_;
	std::vector<Vec4>muslo_;
	std::vector<Vec4>muslo2_;
	std::vector<Vec4>pierna_;
	std::vector<Vec4>pierna2_;

	void SetRobotPieces(std::vector<Vec4>&p, float w, float h, float z);
	void BuildRobot();
	void RobotAnimation();
	void DrawRobot(std::vector<Vec4>c, std::vector<Vec4>t, std::vector<Vec4>aB,
		std::vector<Vec4>aB2, std::vector<Vec4>b, std::vector<Vec4>b2, std::vector<Vec4>m,
		std::vector<Vec4>m2, std::vector<Vec4>p, std::vector<Vec4>p2);

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
	void circle(int x, int y, int R);
	void drawGeometry(std::vector<Vec4> vcopy, int metodo);
};

#endif 