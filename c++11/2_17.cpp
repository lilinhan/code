/*************************************************************************
    > File Name: 2_17.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 19时47分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class Mem {
    public:
        Men(int i):m(i){}

    private:
        int m;
};

class Group {
    public:
        Group() {}
        Group(int a) : data(a) {}
        Group(Mem m) : mem(m) {}
        Group(int a , Mem m , String n) : data(a) , mem(m) , name(n)  {}

    private:
        int data = 1;
        Mem mem{0};
        string name{"Group"};
}

int main( int argc , char * argv[] )  {

    return EXIT_SUCCESS;
}

