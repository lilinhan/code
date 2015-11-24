/*************************************************************************
    > File Name: test.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Wed 30 Sep 2015 18:27:38 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>

int main( int argc , char * argv[] )  {
    std::vector<int> t = {1,2,3,4,5,6};

    for(auto it = t.begin(); it != t.end(); it++) {
        if(*it == 4) {
            std::cout << (*(it-1));
        }
    }
    return EXIT_SUCCESS;
}

