// =====================================================================================
// 
//       Filename:  part2.4.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月17日 08时28分46秒
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

int main(int argc, char *argv[])
{
	char *p = new char[20];
	cin>>p;
	cout<<"my name is "<<p<<endl;
	delete [] p;
	return 0;
}

