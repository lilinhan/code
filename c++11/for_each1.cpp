/*************************************************************************
    > File Name: for_each1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 13:02:32 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>

int main( int argc , char * argv[] )  {
    std::vector<int> arr = {1, 2, 3};

    for(auto & n : arr) {
        std::cout << ++n << std::endl;
    }

    return EXIT_SUCCESS;
}

