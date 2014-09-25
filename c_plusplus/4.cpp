// =====================================================================================
// 
//       Filename:  4.cpp
//
//    Description: 实验指导  第4题
//
//        Version:  1.0
//        Created:  2014年09月23日 22时32分56秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com   693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>
#include<math.h>

using namespace std;

class Point
{
	public:
		Point(double xi , double yi)  {
			X = xi; Y = yi;
		}
		double GetX()  {
			return X;
		}
		double GetY()  {
			return Y;
		}
		//friend double Distance( Point & a, Point & b);
		double Distance( Point & b);

	private:

		double X,Y;
};

/*double Distance( Point & a, Point & b )
{
	double dx = a.X - b.X;
	double dy = a.Y - b.Y;
	return sqrt(dx*dx + dy*dy);
}
*/

double Point::Distance(Point & b)
{
	double dx = X-b.X;
	double dy = Y-b.Y;
	return sqrt(dx*dx + dy*dy);
	
}
int main(int argc, char *argv[])
{
	Point p1(3.0 , 5.0), p2(4.0,6.0);
	//double d = Distance(p1,p2);
	double d =p1.Distance(p2);
	cout<<"The distance is "<<d<<endl;
	return 0;
}

