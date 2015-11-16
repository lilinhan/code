/*************************************************************************
    > File Name: initializer2.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 11:28:37 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

struct ST
{
    int x;
    double y;
    private:
    static int z;
};


struct Foo
{
    ST st;
    int x;
    double y;
};

Foo foo { {4, 5.6}, 1, 2.5};

int main( int argc , char * argv[] )  {

    return EXIT_SUCCESS;
}

