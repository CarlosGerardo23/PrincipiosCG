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
	//void update() override;
};

#endif 