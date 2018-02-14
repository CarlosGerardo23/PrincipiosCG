#ifndef APPLICATION_H
#define APPLICATION_H
#include "BaseApplication.h"
class Application:public BaseApplication
{
public:
	Application();
	~Application();
	//void setup() override;
	void draw() override;
	void linea(int x1, int y1, int x2, int y2);
	void linea_Alta(int x1, int y1, int x2, int y2, Color a);
	void linea_Baja(int x1, int y1, int x2, int y2, Color a);
	float pi= 3.1416;
	//void update() override;
};

#endif 