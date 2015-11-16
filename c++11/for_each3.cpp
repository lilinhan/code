/*************************************************************************
    > File Name: for_each3.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 13:28:10 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<set>

int main( int argc , char * argv[] )  {
    std::set<int> ss = {1, 2, 3};

    for(auto &val : ss) {
        std::cout << val++ << std::endl;
    }
    return EXIT_SUCCESS;
}

