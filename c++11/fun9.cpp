/*************************************************************************
    > File Name: fun9.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月13日 星期四 10时30分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class A {
    public:
        A() {}
        A(int v) : v(v){}
        A(const A & b)  {
            v = b.v;
        }
        A & operator = (const A & r) {
            v = r.v;
            return *this;
        }

        int v;
};

int main( int argc , char * argv[] )  {
    A a(1);
    A b;
    b = a;
    A c = a;

    std::cout << b.v << std::endl;
    std::cout << c.v << std::endl;
    return EXIT_SUCCESS;
}

