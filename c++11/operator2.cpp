/*************************************************************************
    > File Name: operator2.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月30日 星期日 11时02分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class Point {
    private:
        int x;
    public:
        Point(int x1) {
            x = x1;
        }

        const int operator() (const Point & p);
};

const int Point::operator() (const Point & p)  {
    return (x+p.x);
}

int main( int argc , char * argv[] )  {
    Point a(1);
    Point b(2);
    std::cout << a(b);
    return EXIT_SUCCESS;
}

