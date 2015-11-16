/*************************************************************************
    > File Name: for_each5.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 13:33:16 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>

int main( int argc , char * argv[] )  {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    for(auto val : arr) {
        std::cout << val << std::endl;
        arr.push_back(0);
    }
    return EXIT_SUCCESS;
}

