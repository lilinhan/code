// =====================================================================================
// 
//       Filename:  p42.8.cpp
//
//    Description:  p42 第8题
//
//        Version:  1.0
//        Created:  2014年09月16日 16时13分13秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com    693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Rectangle
{
	double lengthe;
	double widthe;
	double area;
	public:
	void init(double a ,double b)  {
		lengthe = a;
		widthe = b;
		area = lengthe * widthe;
	}
	int text()  {
		if(lengthe < 1 || widthe < 1)  {
			cout<<"数据有误\n";
			return -1;
		}

	}
	void print()  {
		cout<<"area = "<<area<<endl;
	}
};

int main(int argc, char *argv[])
{
	int flag;
	double x, y;
	Rectangle a;
	cout<<"请输入边长\n";
	cin>>x>>y;
	
	a.init(x,y);
	flag = a.text();
	if(flag != -1)
		a.print();

	return 0;
}

