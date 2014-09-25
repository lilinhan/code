// =====================================================================================
// 
//       Filename:  p83.4.cpp
//
//    Description:  课本p83 第4题
//
//        Version:  1.0
//        Created:  2014年09月23日 20时56分59秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com   693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>

using namespace std;

class samp
{
	int i;
	public:
	samp(int n)
	{
		i = n;
	}
	void set_i(int n)
	{
		i = n;
	}
	int get_i()
	{
		return i;
	}
	
};

void sqr_it(samp &o)
{
	o.set_i(o.get_i() * o.get_i());
	cout<<"Copy of a has i value of "<<o.get_i();
	cout<<"\n";
}

int main(int argc, char *argv[])
{
	samp a(10);
	sqr_it(a);
	cout<<"Copy of a has i value of "<<a.get_i();
	

	return 0;
}

