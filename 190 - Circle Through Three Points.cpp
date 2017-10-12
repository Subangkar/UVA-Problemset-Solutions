#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x,y;
};

double D(double A[][4])
{
    return A[1][1]*(A[2][2]*A[3][3]-A[2][3]*A[3][2])-A[2][1]*(A[1][2]*A[3][3]-A[3][2]*A[1][3])+A[3][1]*(A[1][2]*A[2][3]-A[1][3]*A[2][2]);
}

double Det(double x11,double x21,double x31,double x12,double x22,double x32,double x13,double x23,double x33)
{
    double A[4][4];
    A[1][1] = x11;
    A[1][2] = x12;
    A[1][3] = x13;
    A[2][1] = x21;
    A[2][2] = x22;
    A[2][3] = x23;
    A[3][1] = x31;
    A[3][2] = x32;
    A[3][3] = x33;

    return D(A);
}


class Circle
{
	double r() { return sqrt(g*g + f*f - c); }
	double h() { return -g; }
	double k() { return -f; }
	double g, f, c;

public:

    void getCircleEqn(Point a,Point b,Point c)
    {
        double d1,d2,d3;
        d1 = -0.5*(a.x*a.x + a.y*a.y);
        d2 = -0.5*(b.x*b.x + b.y*b.y);
        d3 = -0.5*(c.x*c.x + c.y*c.y);

		double Dgfc = Det(a.x, b.x, c.x, a.y, b.y, c.y, 0.5, 0.5, 0.5);

		double Dg = Det(d1, d2, d3, a.y, b.y, c.y, 0.5, 0.5, 0.5);
		double Df = Det(a.x, b.x, c.x, d1, d2, d3, 0.5, 0.5, 0.5);
		double Dc = Det(a.x, b.x, c.x, a.y, b.y, c.y, d1, d2, d3);

        this->g = (Dg/Dgfc);
        this->f = (Df/Dgfc);
        this->c = (Dc/Dgfc);
    }

    void PrintGenEqn()
    {
		cout << ("x^2 + y^2");
		if (g)cout << (g < 0 ? " - " : " + ") << 2 * abs(g) << "x";
		if (f)cout << (f < 0 ? " - " : " + ") << 2 * abs(f) << "y";
		if (c)cout << (c < 0 ? " - " : " + ") << abs(c) << " = 0" << endl;
    }

	void PrintCenRadEqn()
	{

		if(g)cout << "(x" << (g < 0 ? " - " : " + ") << abs(g) << ")^2 + ";
		else cout << "x^2 + ";
		if(f)cout << "(y" << (f < 0 ? " - " : " + ") << abs(f) << ")^2";
		else cout << "y^2";
		cout << " = " << r() << "^2" << endl;
	}
};


int main()
{
	Point a, b, c;
	Circle C;

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(3);

	while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)
	{
		C.getCircleEqn(a, b, c);

		C.PrintCenRadEqn();
		C.PrintGenEqn();

		cout << endl;
	}

    return 0;
}
