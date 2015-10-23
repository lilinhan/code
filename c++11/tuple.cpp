/*************************************************************************
    > File Name: tuple.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Wed 21 Oct 2015 15:44:46 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<tuple>

int main( int argc , char * argv[] )  {
    std::tuple<size_t , size_t , size_t> fuck(1,2,3);
    /*
    std::cout << std::get<0>(fuck) << std::endl;;
    std::cout << std::get<1>(fuck) << std::endl;;
    std::cout << std::get<2>(fuck) << std::endl;
    */

    /*
    typedef decltype(fuck) trans;  //得知tuple对象的类型
    size_t sz = std::tuple_size<std::tuple<size_t,size_t,size_t>>::value;  //给定tuple中成员的数量
    std::tuple_element<1,trans>::type cnt = std::get<1>(fuck);  //表示给定tuple类型中指定成员的类型
    std::cout << cnt <<std::endl;
    */

    /*
    std::tuple<std::string , std::string> duo("1","2");
    std::tuple<size_t , size_t> twoD(1, 2);
    // bool b = (duo == twoD);  类型不匹配
    std::tuple<size_t , size_t , size_t> threedD(1, 2, 3);
    //bool b = (twoD == threedD); 成员数量不同
    std::tuple<size_t , size_t> orign(3, 1);
    bool b =(orign < twoD);
    std::cout << b;
    */


    return EXIT_SUCCESS;
}

