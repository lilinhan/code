/*************************************************************************
    > File Name: template1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年09月06日 星期日 15时48分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>

template <typename T>
auto func(T beg , T end)  -> decltype(*beg)  {
    return *(beg + (end - beg) / 2);
}

int main( int argc , char * argv[] )  {
    std::vector<std::string>  sevc = {"123" , "222" , "333"};
    std::cout << func(sevc.begin() , sevc.end()) << std::endl;
    return EXIT_SUCCESS;
}

