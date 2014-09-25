// =====================================================================================
// 
//       Filename:  part2.2.cpp
//
//    Description:  
//
//
//        Version:  1.0
//        Created:  2014年09月17日 08时07分49秒
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

void sqr_it( int & i );

int main(int argc, char *argv[])
{
	int x;
	x = 10;
	sqr_it(x);
	cout<<"the square of x is "<<x<<'\n';
	return 0;
}

void sqr_it( int & i)
{
	i = (i) * (i);
}

