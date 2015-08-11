/*************************************************************************
    > File Name: test1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月20日 星期一 15时07分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>


typedef void(*fun)(int , int );

void min(int a , int b);
void max(int a , int b);

void min(int a , int b)  {
        int minvalue = a<b?a:b;
        std::cout<<"min value is "<<minvalue<<"\n";
}

void max(int a , int b)  {
        int maxvalue = a>b?a:b;
        std::cout<<"Max value is "<<maxvalue<<"\n";
}

int main( int argc , char * argv[] )  {
	fun pfun = NULL;
        pfun = &min;
        pfun(1,2);
    return EXIT_SUCCESS;
}

