/*************************************************************************
    > File Name: operator1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月29日 星期六 15时39分12秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class Num{
    public:
        void setNum(int x) {
            num = x;
        }
        int num;
};

Num operator+ (const Num &a ,const Num &b)  {
    Num sum;
    sum.num = a.num + b.num;
    return sum;
}

int main( int argc , char * argv[] )  {
    Num x , y , s;
    x.setNum(10);
    y.setNum(20);

    s = x+y;
    std::cout << s.num << std::endl;
    return EXIT_SUCCESS;
}

