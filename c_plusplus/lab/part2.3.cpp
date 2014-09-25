// =====================================================================================
// 
//       Filename:  part2.3.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月17日 08时13分56秒
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

class Max
{
	int int_a,int_b;
	long long_a,long_b;
	double double_a,double_b;
	public:
	Max(int a , int b,long c,long d,double e, double f)  {
		int_a = a;
		int_b = b;
		long_a = c;
		long_b = d;
		double_a = e;
		double_b = f;
	}
	void max(int int_a ,int int_b)  {
		if(int_a > int_b)  {
			cout<<"max of "<<int_a<<" and "<<int_b<<" is "<<int_a<<endl;
		}
		else{
			cout<<"max of "<<int_a<<" and "<<int_b<<" is "<<int_b<<endl;
		}

	}
	void max(long long_a ,long long_b)  {
		if(long_a > long_b)  {
			cout<<"max of "<<long_a<<" and "<<long_b<<" is "<<long_a<<endl;
		}
		else{
			cout<<"max of "<<long_a<<" and "<<long_b<<" is "<<long_b<<endl;
		}

	}
	void max(double double_a ,double double_b)  {
		if(double_a > double_b)  {
			cout<<"max of "<<double_a<<" and "<<double_b<<" is "<<double_a<<endl;
		}
		else{
			cout<<"max of "<<double_a<<" and "<<double_b<<" is "<<double_b<<endl;
		}

	}
};
int main(int argc, char *argv[])
{
	Max get_max(3,5,88888888,555555555,2.718,3.14);
	get_max.max(3,5);
	get_max.max(88888888,5555555);
	get_max.max(2.718,3.14);


	return 0;
}

