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
void Application::circle(int x, int y, int R)
{
	Color a(200, 0, 180, 255);
	x = 0;
	y = R;
	float d= 1 - R;
	while (x<y) {
		putPixel(x + cx, y + cy,a);
		putPixel(-x + cx, y + cy, a);
		putPixel(-x + cx, -y + cy, a);
		putPixel(x + cx, -y + cy,a);

		putPixel(y + cx, -x + cy,a);
		putPixel(-y + cx, -x + cy, a);
		putPixel(-y + cx, x + cy,a);
		putPixel(y + cx, x + cy, a);
		if (d<0) {
			d += 2*x + 3;
		}
		else {
			--y;
			d += 2*x - 2*y + 5;
		}
		++x;
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
void Application::SetRobotPieces(std::vector<Vec4>&p,float w, float h, float z)
{
	
	Vec4 a(-w, -h, z);
	Vec4 b(-w, +h, z);
	Vec4 c(+w, -h, z);
	Vec4 d(+w, +h, z);

	Vec4 a_back(-w, -h, -z);
	Vec4 b_back(-w, +h, -z);
	Vec4 c_back(+w, -h, -z);
	Vec4 d_back(+w, +h, -z);

	Vec4 a_right(+w, h, +z);
	Vec4 b_right(+w, h, +z);
	Vec4 c_right(+w, h, -z);
	Vec4 d_right(+w, h, -z);

	Vec4 a_left(-w, -h, -z);
	Vec4 b_left(-w, +h, -z);
	Vec4 c_left(-w, -h, +z);
	Vec4 d_left(-w, +h, +z);

	Vec4 a_top(-w, -h, -z);
	Vec4 b_top(-w, -h, +z);
	Vec4 c_top(+w, -h, -z);
	Vec4 d_top(+w, -h, +z);

	Vec4 a_bottom(-w, +h, -z);
	Vec4 b_bottom(-w, +h, +z);
	Vec4 c_bottom(+w, +h, -z);
	Vec4 d_bottom(+w, +h, +z);

	p.push_back(a);
	p.push_back(b);
	p.push_back(c);
	p.push_back(d);
	
	p.push_back(a_back);
	p.push_back(b_back);
	p.push_back(c_back);
	p.push_back(d_back);
	
	p.push_back(a_right);
	p.push_back(b_right);
	p.push_back(c_right);
	p.push_back(d_right);
	
	p.push_back(a_left);
	p.push_back(b_left);
	p.push_back(c_left);
	p.push_back(d_left);
	
	p.push_back(a_top);
	p.push_back(b_top);
	p.push_back(c_top);
	p.push_back(d_top);
	
	p.push_back(a_bottom);
	p.push_back(b_bottom);
	p.push_back(c_bottom);
	p.push_back(d_bottom);
	
	Vec4 tra(0, h/2, 0);
	Vec4 tra2(cx,cy, 0);
	Mat4 set = Mat4::translate(tra);
	Mat4 origin = Mat4::translate(tra2);
	Mat4 acum = origin * set;
	for (int i = 0; i < p.size(); i++)
	{
		Vec4 pr(0, 0, 0);
		pr = acum * p[i];
		p[i] = pr;
	}

	
}

void Application::BuildRobot()
{
	SetRobotPieces(cabeza, 50, 50, 50);
	SetRobotPieces(torso, 75, 75, 55);
	SetRobotPieces(anteBrazo, 15, 55, 20);
	SetRobotPieces(anteBrazo2, 15, 55, 20);
	SetRobotPieces(brazo, 15, 40, 30);
	SetRobotPieces(brazo2, 15, 40, 30);
	SetRobotPieces(muslo, 30, 80, 20);
	SetRobotPieces(muslo2, 30, 80, 20);
	SetRobotPieces(pierna, 25, 65, 20);
	SetRobotPieces(pierna2, 25, 65, 20);
	Vec4 tra(-cx, -cy, 0);
	Vec4 tra2(cx, cy, 0);
	Vec4 c(0, -120, 0);
	Vec4 ab(100, 0, 0);
	Vec4 ab2(-100, 0, 0);
	Vec4 b(0, 110, 0);
	Vec4 p(42, 80, 0);
	Vec4 p2(-42, 80, 0);
	Vec4 m(0, 80, 0);
	Vec4 p_(0, 250, 0);
	 Mat4 buildc =Mat4::translate(c);
	 Mat4 buildb =Mat4::translate(ab);
	 Mat4 buildb2  =Mat4::translate(ab2);
	 Mat4 buildp  =Mat4::translate(p);
	 Mat4 buildp2 = Mat4::translate(p2);
	 Mat4 buildb_ = Mat4::translate(b);
	 Mat4 buildm_ = Mat4::translate(m);
	 Mat4 buildp_ = Mat4::translate(p_);
	 Mat4 rot1= Mat4::rotate_y(90);
	 Mat4 tras1 = Mat4::translate(tra);
	 Mat4 tras2 = Mat4::translate(tra2);
	 
	 Mat4 rot = rot1*tras1;
	 rot = tras2 * rot;
	 
	
	for (int i = 0; i < cabeza.size(); i++)
	{
		Vec4 pr(0, 0, 0);
		pr = buildc * cabeza[i];
		cabeza[i] = pr;
	}
	for (int i = 0; i < brazo.size(); i++)
	{
		Vec4 pr(0, 0, 0);
		Vec4 pr2(0, 0, 0);
		pr = buildb * anteBrazo[i];
		pr2 = buildb * brazo[i];
		pr2 = buildb_ * pr2;
		anteBrazo[i] = pr;
		brazo[i] = pr2;
	}
	for (int i = 0; i < brazo.size(); i++)
	{
		Vec4 pr(0, 0, 0);
		Vec4 pr2(0, 0, 0);
		pr = buildb2 * anteBrazo2[i];
		pr2 = buildb2 * brazo2[i];
		pr2 = buildb_ * pr2;
		anteBrazo2[i] = pr;
		brazo2[i] = pr2;
	}
	for (int i = 0; i < pierna.size(); i++)
	{
		Vec4 pr(0, 0, 0);
		Vec4 pr2(0, 0, 0);
		pr = buildp * muslo[i];
		pr2 = buildp * pierna[i];
		pr = buildm_ * pr;
		pr2 = buildp_ * pr2;
		muslo[i] = pr;
		pierna[i] = pr2;
	}
	for (int i = 0; i < pierna.size(); i++)
	{
		Vec4 pr(0, 0, 0);
		Vec4 pr2(0, 0, 0);
		pr = buildp2 * muslo2[i];
		pr2 = buildp2 * pierna2[i];
		pr = buildm_ * pr;
		pr2 = buildp_ * pr2;
		muslo2[i] = pr;
		pierna2[i] = pr2;
	}
	for (int i = 0; i < pierna.size(); i++)
	{
		Vec4 pr_c(0, 0, 0);
		Vec4 pr_t(0, 0, 0);
		Vec4 pr_ab(0, 0, 0);
		Vec4 pr_ab2(0, 0, 0);
		Vec4 pr_b(0, 0, 0);
		Vec4 pr_b2(0, 0, 0);
		Vec4 pr_m(0, 0, 0);
		Vec4 pr_m2(0, 0, 0);
		Vec4 pr_p(0, 0, 0);
		Vec4 pr_p2(0, 0, 0);
	
		pr_c = rot * cabeza[i];
		pr_t = rot * torso[i];
		pr_ab = rot * anteBrazo[i];
		pr_ab2 = rot * anteBrazo2[i];
		pr_b = rot * brazo[i];
		pr_b2 = rot * brazo2[i];
		pr_m = rot * muslo[i];
		pr_m2 = rot * muslo2[i];
		pr_p = rot * pierna[i];
		pr_p2 = rot * pierna2[i];

		cabeza[i] = pr_c;
		torso[i] = pr_t;
		anteBrazo[i] = pr_ab;
		anteBrazo2[i] = pr_ab2	 ;
		brazo[i]	= pr_b 	 ;
		brazo2[i]	= pr_b2	 ;
		muslo[i]	= pr_m 	 ;
		muslo2[i]	= pr_m2	 ;
		pierna[i]	= pr_p 	 ;
		pierna2[i]	= pr_p2	 ;
	}
}
void Application::RobotAnimation()
{
	muslo2_.clear();
	pierna2_.clear();
	muslo_.clear();
	pierna_.clear();
	anteBrazo_.clear();
	brazo_.clear();

	//Traslacion de antebrazo
	Vec4 tras_ab(-cx-15, -cy-55, 0);
	Vec4 tras_ab2(cx+15, cy+55, 0);
	Mat4 trasAB = Mat4::translate(tras_ab);
	Mat4 trasAB2 = Mat4::translate(tras_ab2);

	//Traslacion de brazo
	Vec4 tras_b(-cx - 30, -cy - 95, 0);
	Vec4 tras_b2(cx + 30, cy + 95, 0);
	Mat4 trasB = Mat4::translate(tras_b);
	Mat4 trasB2 = Mat4::translate(tras_b2);

	//Rotacion del antebrazo y brazo
	Mat4 rot_ab = Mat4::rotate_z(ang_a);
	Mat4 rot_b = Mat4::rotate_z(ang2_a);

	//Acumulado del antebrazo
	Mat4 acum_ab = rot_ab * trasAB;
	acum_ab = trasAB2 * acum_ab;

	//Acumulado de brazo
	Mat4 acum_b = rot_b * trasB;
	acum_b = trasB2 * acum_b;
	acum_b = acum_ab * acum_b;

	//Traslacion del muslo
	Vec4 tra1(-cx+42,-cy-160, 0);
	Vec4 tra2(cx-42, cy+160, 0);
	Mat4 tran = Mat4::translate(tra1);
    Mat4 transl2 = Mat4::translate(tra2);

	//Traslacion de la pierna
	Vec4 tra1p(-cx + 42, -cy - 330, 0);
	Vec4 tra2p(cx - 42, cy +330, 0);
    Mat4 tranp = Mat4::translate(tra1p);
	Mat4 transl2p = Mat4::translate(tra2p);
	
	//rotacion de la pierna (muslo/pierna)
	Mat4 rot = Mat4::rotate_z(ang2);
	Mat4 rot2 = Mat4::rotate_z(ang);

	//rotacion de la pierna 1
	Mat4 rot_ = Mat4::rotate_z(ang2_);
	Mat4 rot2_ = Mat4::rotate_z(ang_);

	//Acumulado del muslo 2
	Mat4 acum = rot * tran;
	acum = transl2 * acum;

	//Acumulado de la pierna 2
	Mat4 acump = rot2 * tranp;
	acump = transl2p * acump;
	acump = acum*acump ;

	//Acumulado del muslo1
	Mat4 acum_2 = rot_ * tran;
	acum_2 = transl2 * acum_2;

	//Acumulado de la pierna 1
	Mat4 acump_ = rot2_ * tranp;
	acump_ = transl2p * acump_;
	acump_ = acum_2 * acump_;
	for (int i = 0; i < muslo2.size(); i++)
	{
		Vec4 a(0, 0, 0);
		Vec4 b(0, 0, 0);

		Vec4 a_(0, 0, 0);
		Vec4 b_(0, 0, 0);


		Vec4 a_a(0, 0, 0);
		Vec4 b_b(0, 0, 0);


		a = acum *muslo2[i];
		b = acump *pierna2[i];

		a_ = acum_2 * muslo[i];
		b_ = acump_ * pierna[i];

		a_a = acum_ab * anteBrazo[i];
		b_b = acum_b * brazo[i];

		muslo_.push_back(a);
		pierna_.push_back(b);
		muslo2_.push_back(a_);
		pierna2_.push_back(b_);
		anteBrazo_.push_back(a_a);
		brazo_.push_back(b_b);

	}
	if (ang >= 20) {
		num2 *= -1;
		num *= -1;
		num2_ *= -1;
		num_ *= -1;
	}
	if (ang < -10)
	{
		num2 *= -1;
		num *= -1;
		num2_ *= -1;
		num_ *= -1;
	}
	ang_a += num_a;
	ang += num;
	ang2 += num2;
	ang_ += num_;
	ang2_ += num2_;
}
void Application::DrawRobot(std::vector<Vec4>c, std::vector<Vec4>t, std::vector<Vec4>aB,
	std::vector<Vec4>aB2, std::vector<Vec4>b, std::vector<Vec4>b2, std::vector<Vec4>m,
	std::vector<Vec4>m2, std::vector<Vec4>p, std::vector<Vec4>p2)
{

}
void Application::setup() 
{
	BuildRobot();

}
void Application::update()
{
	
    muslo2_.clear();
	pierna2_.clear();
	RobotAnimation();
	
}

void Application::draw()
{
	clear_screen();

	for (int i = 0; i < cabeza.size(); i += 4)
	{

		triangle(cabeza[i], cabeza[i + 1], cabeza[i + 2]);
		triangle(cabeza[i + 3], cabeza[i + 1], cabeza[i + 2]);

		triangle(torso[i], torso[i + 1], torso[i + 2]);
		triangle(torso[i + 3], torso[i + 1], torso[i + 2]);

		triangle(anteBrazo[i], anteBrazo[i + 1], anteBrazo[i + 2]);
		triangle(anteBrazo[i + 3], anteBrazo[i + 1], anteBrazo[i + 2]);

		triangle(anteBrazo2[i], anteBrazo2[i + 1], anteBrazo2[i + 2]);
		triangle(anteBrazo2[i + 3], anteBrazo2[i + 1], anteBrazo2[i + 2]);

		triangle(brazo[i], brazo[i + 1], brazo[i + 2]);
		triangle(brazo[i + 3], brazo[i + 1], brazo[i + 2]);

		triangle(brazo2[i], brazo2[i + 1], brazo2[i + 2]);
		triangle(brazo2[i + 3], brazo2[i + 1], brazo2[i + 2]);


		/*triangle(muslo2[i],     muslo2[i + 1], muslo2[i + 2]);
		triangle(muslo2[i + 3], muslo2[i + 1], muslo2[i + 2]);*/


		/*triangle(pierna2[i],     pierna2[i + 1], pierna2[i + 2]);
		triangle(pierna2[i + 3], pierna2[i + 1], pierna2[i + 2]);
*/


	}
	drawGeometry(muslo2_, 6);
	drawGeometry(pierna2_, 6);
	drawGeometry(muslo_, 6);
	drawGeometry(pierna_, 6);
	drawGeometry(anteBrazo, 6);
	drawGeometry(brazo, 6);
	
}

Application::~Application()
{
}
