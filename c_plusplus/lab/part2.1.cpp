// =====================================================================================
// 
//       Filename:  part2.1.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月17日 08时00分16秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com    693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>

 int model = 90;
 int v[] = { 1, 2 , 3, 4};
const int x = 10;

void f()  {
	model = 200;
	v[2]++;
}


int main(int argc, char *argv[])
{
	f();
	return 0;
}

