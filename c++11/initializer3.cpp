/*************************************************************************
    > File Name: initializer3.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 11:33:07 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class Foo
{
    int a,b,c,d,e,f;
    public:
    Foo(std::initializer_list<int>){}
};

Foo foo = {1,2,3,4,5,6};
int main( int argc , char * argv[] )  {
    return EXIT_SUCCESS;
}

