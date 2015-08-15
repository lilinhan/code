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

    for(auto it = a.begin() ; it != a.end() ; it++)  {
        std::cout << *it << std::endl;
    }
    a.swap(b);

    for(auto it = a.begin() ; it != a.end() ; it++)  {
        std::cout << *it << std::endl;
    }

    for(auto it = b.begin() ; it != b.end() ; it++) {
        std::cout << *it << std::endl;
    }
    return EXIT_SUCCESS;
}

