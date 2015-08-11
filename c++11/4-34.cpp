/*************************************************************************
    > File Name: 4-34.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月29日 星期三 22时44分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<algorithm>

void action1(int & e) { e *= 2 ;}
void action2(int & e) { std::cout << e << '\t';}

int main( int argc , char * argv[] )  {
    int arr[5] = {1,2,3,4,5};
    std::for_each(arr , arr+sizeof(arr)/sizeof(arr[0]) , action1);
    std::for_each(arr , arr+sizeof(arr)/sizeof(arr[0]) , action2);
    return EXIT_SUCCESS;
}

