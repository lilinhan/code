// =====================================================================================
// 
//       Filename:  p83.1.cpp
//
//    Description:  课本p83 第1题
//
//        Version:  1.0
//        Created:  2014年09月23日 20时26分27秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com   693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Student
{
	int a[5];
	public:
	void init(int b[]) {
		int i;
		for( i = 0 ; i < 5 ; i++ )  {
			a[i] = b[i];
		}
	}
	void print()  {
		int i;
		for( i = 0 ; i < 5 ; i++ )  {
			cout<<a[i]<<"  ";
		}
	}
};

int main(int argc, char *argv[])
{
	int b[5],i;
	Student stu;

	cout<<"请输入数据"<<endl;
	for( i = 0 ; i < 5 ; i++ )  {
		cin>>b[i];
	}
	stu.init(b);
	stu.print();

	return 0;
}

