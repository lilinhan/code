/*************************************************************************
    > File Name: functional.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月30日 星期日 15时59分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<functional>

int main( int argc , char * argv[] )  {
    std::cout << "算术" << std::endl;
    int a = 10 , b = 20;
    int ret;

    std::plus<int>add;
    ret = add(a,b);
    std::cout << ret << std::endl;

    std::minus<int> min;
    ret = min(b,a);
    std::cout << ret << std::endl;

    std::multiplies<int> mp;
    ret = mp(a,b);
    std::cout << ret << std::endl;

    std::divides<int> divi;
    ret = divi(a,b);
    std::cout << ret << std::endl;

    std::modulus<int> mod;
    ret = mod(a,b);
    std::cout << ret << std::endl;

    std::negate<int> neg;
    ret = neg(a);
    std::cout << ret << std::endl;


    std::cout << "关系" <<std::endl;
    int a2 = 10 , b2 = 20;
    int ret2;
    std::equal_to<int> et;
    ret2 = et(a,b);
    std::cout << ret2 <<std::endl;

    std::not_equal_to<int> net;
    ret2 = net(a,b);
    std::cout << ret2 << std::endl;

    std::greater<int>gt;
    ret2 = gt(b,a);
    std::cout << ret2 << std::endl;

    std::greater_equal<int> gte;
    ret2 = gte(a,b);
    std::cout << ret2 <<std::endl;

    std::less<int> ls;
    ret2 = ls(a,b);
    std::cout << ret2 << std::endl;

    std::less_equal<int> lel;
    ret2 = lel(a,b);
    std::cout << ret2 << std::endl;

    std::cout << "逻辑" << std::endl;
    int ret3;
    std::logical_and<int> la;
    ret3 = la(a,b);
    std::cout << ret3 <<std::endl;

    std::logical_or<int> lo;
    ret3 = lo(a,b);
    std::cout << ret3 << std::endl;

    std::logical_not<int>ln;
    ret3 = ln(b);
    std::cout << ret3 <<std::endl;

    return EXIT_SUCCESS;
}

