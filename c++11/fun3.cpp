/*************************************************************************
    > File Name: fun3.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月07日 星期五 15时41分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
#include<algorithm>

int main( int argc , char * argv[] )  {
    std::vector<int> vec = {0,1,2,3,4,5,6};

/*   for(auto r_iter = vec.crbegin() ; r_iter != vec.crend() ; ++r_iter) {
        std::cout << *r_iter << std::endl;
    }*/
    std::sort(vec.rbegin() , vec.rend());
    for(auto a : vec) {
        std::cout << a << "\t";
    }
    std::cout << std::endl;

    std::sort(vec.begin()  , vec.end());
    for(auto a : vec) {
        std::cout << a << "\t";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

