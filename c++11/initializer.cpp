/*************************************************************************
    > File Name: initializer.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 10:53:19 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

int i_arr[3] = {1,2,3};

struct A
{
    int x;
    struct B
    {
        int i;
        int j;
    }b;
}a = {1, {2, 3} };

int i = 0;

class Foo
{
    public:
        Foo(int) {}
}foo = 123;

int j = 0;

Foo bar(123);

int main( int argc , char * argv[] )  {

    return EXIT_SUCCESS;
}

