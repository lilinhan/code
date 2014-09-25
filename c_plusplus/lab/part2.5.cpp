// =====================================================================================
// 
//       Filename:  part2.5.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月17日 08时43分10秒
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

void f( int a[] , int n, int & max, int & min )  
{
	max = min = a[0];
	for( int i = 1; i < n ; i++ )  {
		if( max < a[i] )  max = a[i];
		if( min > a[i] )  min = a[i];
	}
}

int main(int argc, char *argv[])
{
	int a[10] = {2, 5, 3, 9, 0, 8 , 1, 7, 6, 4};
	int max,min;
	f(a,10,max,min);
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;

	return 0;
}

