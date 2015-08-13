/*************************************************************************
    > File Name: fun10.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月13日 星期四 10时39分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class A {
    public:
        A() {}
        A(int v) {
            p = new int(v);
        }
        ~A() {
            delete p;
        }
        int *p;
};

int main( int argc , char * argv[] )  {
    A a;
    A b(10);
    a = b;
    std::cout << a.p << std::endl;
    std::cout << b.p <<std::endl;
    return EXIT_SUCCESS;
}

