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
	cube(50,50,50);

}
void Application::update()
{
	//	//Vector3 s(-WIDTH/2,-HEIGHT/2);
	//	//Vector3 s2(WIDTH / 2, HEIGHT / 2);
	//	//Vector3 s3((-WIDTH/2)+50,  (-HEIGHT / 2)-70);
	//	//Vector3 s4((-WIDTH / 2) - 50, (-HEIGHT / 2) + 70);
	//	//Vector3 s5(.5, .5);
	//	////Vector3 s3()
	//	//vp.clear();
	//	//Vector3 a(0, 0);
	//	//Mat3 acum;
	//	//Mat3 tras = Mat3::translate(s);
	//	//Mat3 scale2 = Mat3::rotate(ang);
	//	//Mat3 trans2 = Mat3::translate(s3);
	//	//Mat3 rot2 = Mat3::rotate(ang2);
	//	//Mat3 trans3 = Mat3::translate(s4);
	//	//ys += 50;
	//	//ang +=10;
	//	//ang2 += 1;
	//	//Mat3 acum2 = Mat3::translate(s2);
	//	//acum = (scale2*tras);
	//	//Mat3 acum3 = rot2 * trans2;
	//	//Mat3 acumt1 = acum2 * acum;
	//	//Mat3 acum4 = trans3;
	//	//Mat3 acumtt2 = acum4 * acum3;
	//	////Mat3 acumtt2s = acumtt2 * Mat3::scale(s5);
	//	//Mat3 acumtt = acumtt2 * acumt1;
	//	//Vector3 tras2=Mat3::translate()
	//	vp.clear();
	//	Vector3 a(0, 0);
	//	Vector3 t1(-WIDTH / 2, -HEIGHT / 2);
	//	Vector3 t2(100, -100);
	//	Vector3 t3(WIDTH / 2, HEIGHT / 2);
	//	ang += 2;
	//	ang2 -= 1;
	//	Mat3 acumtt;
	//	Mat3 tras=Mat3::translate(t1);
	//	Mat3 tras2 = Mat3::translate(t2);
	//	Mat3 tras3 = Mat3::translate(t3);
	//	Mat3 rot=Mat3::rotate(ang);
	//	Mat3 rot2=Mat3::rotate(ang2);
	//	//tras3 * ((rot2*tras2)*(rot*tras));
	//	Mat3 acum = (rot*tras);
	//	Mat3 acum2 = (rot2*tras2);
	//	Mat3 acum3 = acum2 * acum;
	//	acumtt = tras3*acum3;
	//	for (int i = 0; i < v.size(); i++)
	//	{
	//		a = acumtt * v.at(i);
	//		vp.push_back(a);
	//	}
	v4_p.clear();
	Vec4 a(-cx, -cy, 0);
	Vec4 b(cx, cy, 0);
	Vec4 eye(1, 0, 1);
	Vec4 target(0, 0, 0);
	Vec4 up(0, 1, 0);
	float fov = 60;
	Vec4 centro(WIDTH / 2, HEIGHT / 2, WIDTH / 2);


	Mat4 rot = Mat4::rotate_x(ang);
	Mat4 rot2 = Mat4::rotate_y(ang2);
	Mat4 tra = Mat4::translate(a);
	Mat4 tra2 = Mat4::translate(b);
	Mat4 acum = rot;
	acum = rot2 * acum;
	acum = tra2 * acum;
	Mat4 cam = Mat4::lookAt(eye, target, up);
	Mat4 proy = Mat4::perspective(fov, WIDTH / HEIGHT, 0.0001, 20);
	Mat4 camara = proy * cam;
	Mat4 acumf = camara * acum;
	ang += 4;
	ang2 += 2;
	xcam += 0.999;
	/*Vec4 t(-WIDTH / 2, -HEIGHT / 2, 0);
	Vec4 t2(WIDTH / 2, HEIGHT / 2, 0);
	Vec4 a(0, 0, 0);
	Vec4 eye(0, 0, 0);
	Vec4 target(0,0, 0);
	Vec4 Up(0,1,0);
	Mat4 rot1 = Mat4::rotate_x(ang);
	Mat4 rot2 = Mat4::rotate_y(ang);
	float pespective = 45;
	Mat4 tra1 = Mat4::translate(t);
	Mat4 tra2 = Mat4::translate(t2);
	Mat4 rott = tra2 * rot2;
	Mat4 trast = rot1 * tra1;
	Mat4 acum = rott * trast;
	Mat4 cam = Mat4::lookAt(eye,target,Up);
	Mat4 proy = Mat4::perspective(pespective, 1, 0.0001, 10000);
	Mat4 acumF = cam*acum;
	Mat4 acumFF = proy * acumF;
	ang+=2;
	ycam -= 20;
	xcam -= 10;*/

	for (int i = 0; i < v4.size(); i++) 
	{
		a=acum*v4[i];
		v4_p.push_back(a);
	}

}

void Application::draw()
{
	Vec4 a(cx-500,cy-500, 0);
	Vec4 b(cx - 400, cy - 400, 0);
	Vec4 c(cx -400, cy - 500, 0);
	Vec4 d(cx + -300, cy - 400, 0);


	Vec4 a1(cx - 50, cy - 500, 0);
	Vec4 b1(cx - 30, cy - 400, 0);
	Vec4 c1(cx + 50, cy - 500, 0);
	Vec4 d1(cx + 70, cy - 400, 0);


	Vec4 a2(cx -50+400, cy - 500, 0);
	Vec4 b2(cx - 30+400, cy - 400, 0);
	Vec4 c2(cx + 50+400, cy - 500, 0);
	Vec4 d2(cx + 70+400, cy - 400, 0);


	Vec4 a3(cx - 400, cy +300, 0);
	Vec4 b3(cx - 500, cy + 300, 0);
	Vec4 c3(cx - 300, cy + 300, 0);
	Vec4 d3(cx + -200, cy + 400, 0);



	Vec4 a4(cx - 50, cy + 400, 0);
	Vec4 b4(cx - 30, cy + 300, 0);
	Vec4 c4(cx + 50, cy + 400, 0);
	Vec4 d4(cx + 70, cy + 300, 0);
	
	/*Mat3 scala;
	
	
	scala = Mat3::scale(s);
	Vector3 ar = scala*a;
	Vector3 br = scala*b;
	Vector3 cr= scala*c;*/

	/*triangle(ar, br, cr);*/
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
	for (int i = 0; i < v4_p.size(); i+=4)
	{

        triangle(v4_p[i], v4_p[i + 1], v4_p[i + 2]);
		triangle(v4_p[i+3], v4_p[i + 1], v4_p[i + 2]);
		
	
		
	}
	std::vector<Vec4> l;
	std::vector<Vec4> ls;
	std::vector<Vec4> ll;
	std::vector<Vec4> tf;
	std::vector<Vec4> ts;
	l.push_back(a);
	l.push_back(b);
	l.push_back(c);
	l.push_back(d);

	ls.push_back(a1);
	ls.push_back(b1);
	ls.push_back(c1);
	ls.push_back(d1);

	ll.push_back(a2);
	ll.push_back(b2);
	ll.push_back(c2);
	ll.push_back(d2);

	tf.push_back(d3);
	tf.push_back(b3);
	tf.push_back(a3);
	tf.push_back(c3);

	ts.push_back(a4);
	ts.push_back(b4);
	ts.push_back(c4);
	ts.push_back(d4);

	drawGeometry(l, 2);
	drawGeometry(ls, 3);
	drawGeometry(ll, 4);
	drawGeometry(tf, 5);
	drawGeometry(ts, 6);

	

	
}

Application::~Application()
{
}
