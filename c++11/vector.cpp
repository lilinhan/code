/*************************************************************************
    > File Name: vector.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月15日 星期六 15时37分38秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>

int main( int argc , char * argv[] )  {
    std::vector<int> s = {1,2,3,40};
    std::vector<int> a(s.begin() , s.end());
    std::vector<int> b{1,2,3,4};

    a.emplace_back(1900);
    for(auto it = a.cbegin() ; it != a.cend() ; it++) {
        (*it)++;
    }
    for(auto it = a.rbegin() ; it != a.rend() ; it++) {
        std::cout << *it << std::endl;
    }
    return EXIT_SUCCESS;
}

