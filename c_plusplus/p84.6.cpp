// =====================================================================================
// 
//       Filename:  84.6.cpp
//
//    Description:  课本p84 第6题
//
//        Version:  1.0
//        Created:  2014年09月23日 21时10分58秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com   693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>
using namespace std;

class Circle
{
	public:
		Circle(float r)  {
			radius = r;
			++count;
		}
		~Circle(){
			--count;
		}
		static int num()  {
			return count;
		}
		void print()	{
			cout<<radius<<"  "<<count<<endl;
		}
	private:
		float radius;
		static int count;

};

int Circle::count = 0;

int main(int argc, char *argv[])
{
	int b;
	Circle a(3.14);
	a.print();
	b = Circle::num();
	return 0;
}

