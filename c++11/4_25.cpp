/*************************************************************************
    > File Name: 4_25.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月29日 星期三 17时30分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

int main( int argc , char * argv[] )  {
    int i = 4;
    int arr[5] = {0};
    int *ptr = arr;

    struct S {double d;} s;

    void Overloaded( int );
    void Overloaded( char );

    int && RvalRef();
    const bool Func( int );

    decltype(arr) var1;

    return EXIT_SUCCESS;
}

