/*************************************************************************
    > File Name: fun1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月06日 星期四 17时25分58秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<algorithm>

void fcn3()  {
    size_t v1 = 42;
    auto f = [v1]() mutable {return ++v1;};
    v1 = 0;
    std::cout << v1 << std::endl;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn4()  {
    size_t v1 = 42;
    auto f2 = [&v1]  { return ++v1;};
    std::cout << v1 << std::endl;
    auto j = f2();
    std::cout << v1 << std::endl;
}


int main( int argc , char * argv[] )  {
    //fcn4();
   // std::vector<int> v1 = {1,-2,3,-4,5,-6};
   // transform(v1.begin() , v1.end() , v1.begin() , [](int i) {if( i < 0 ) return -i; else return i;});

    return EXIT_SUCCESS;
}

