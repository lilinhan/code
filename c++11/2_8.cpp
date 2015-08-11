/*************************************************************************
    > File Name: 2_8.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 19时37分12秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cerrno>
#include<cassert>
#include<cstring>
#include<string>

template<typename T , typename U> int bit_copy(T& a , U&b)  {
    assert(sizeof(b) == sizeof(a));
    memcpy(&a , &b , sizeof(b));
};

int main( int argc , char * argv[] )  {
    int a = 0x2468;
    double b;
    bit_copy(a , b);
    return EXIT_SUCCESS;
}

