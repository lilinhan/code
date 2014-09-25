// =====================================================================================
// 
//       Filename:  p41.2.c
//
//    Description:  p41 第二题
//
//        Version:  1.0
//        Created:  2014年09月15日 21时26分51秒
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

class counter
{
	int value;
	public:
	counter(int number);
	void increment();
	void decrement();
	int getvalue();
	void print();
};

counter::counter(int number)
{
	value = number;
}

void counter ::increment()
{
	value++;
}

void counter :: decrement()
{
	value--;
}

int counter :: getvalue()
{
	return value;
}

void counter :: print()
{
	cout<<"the value is "<<value<<endl;
}

int main(int argc, char *argv[])
{
	int gets;
	counter num(7);

	num.increment();
	num.print();

	num.decrement();
	num.print();

	gets = num.getvalue();

	num.print();

	return 0;
}

