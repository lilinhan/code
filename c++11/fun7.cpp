/*************************************************************************
    > File Name: fun7.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月09日 星期日 11时05分28秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<memory>

int main( int argc , char * argv[] )  {
    //std::shared_ptr<std::string> sp = "abcd";  错误的写法
    std::shared_ptr<std::string> sp = std::make_shared<std::string>("abcd");

    auto sp2 = std::make_shared<std::string>(10,'a');

    auto sp3(sp2);

    auto sp4(sp2);

    sp = sp4;
    std::cout << *sp4 << "\t" << sp2.use_count() << "\t" << sp2.unique()<< std::endl;
    std::cout << *sp << "\t" << sp.use_count()  << "\t"  << sp.unique() << std::endl;
    return EXIT_SUCCESS;
}

