/*************************************************************************
    > File Name: 2_6.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 19时24分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<cassert>

char * ArrayAlloc(int n)  {
    assert( n > 0 );
    return new char[n];
}

int main( int argc , char * argv[] )  {
    char * a = ArrayAlloc(10);
    return EXIT_SUCCESS;
}

