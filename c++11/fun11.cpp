/*************************************************************************
    > File Name: fun11.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月13日 星期四 14时54分31秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class A{
    public:
        A():i(0),s(" "),p(new std::string) {}
        A(int t1, std::string s1):i(t1) , s(s1) , p(new std::string()) {
            std::cout << "调用构造函数" << std::endl;
        }
        A(const A & f)  {
            i = f.i;
            s = f.s;
            p = new std::string(*f.p);
            std::cout << "调用拷贝构造函数" << std::endl;
        }

        A & operator=(const A & f) {
            i = f.i;
            s = f.s;
            p = new std::string(*f.p);
            std::cout << "调用赋值构造函数" << std::endl;
            return *this;
        }
        ~A() {
            delete p;
            std::cout << "调用析构函数" << std::endl;
        }

    private:
        int i;
        std::string s;
        std::string *p;
};

A fun(A f) {
    A f2(f);
    A f3;
    f3 = f2;
    return f2;
}

int main( int argc , char * argv[] )  {
    A f1(1, "123");
    A f2 = fun(f1);
    return EXIT_SUCCESS;
}

