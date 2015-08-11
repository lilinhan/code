/*************************************************************************
    > File Name: 3_3.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月22日 星期三 08时36分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

struct Base{
    void f( double i )  {
        std::cout << "Base:" << i << std::endl;
    }
};

struct Derived : Base  {
    using Base::f;
    void f( double i )  {
        std::cout << "Derived:" << i << std::endl;
    }
};

int main( int argc , char * argv[] )  {
    Base b;
    b.f(4.5);

    Derived d;
    d.f(4.5);
    return EXIT_SUCCESS;
}

