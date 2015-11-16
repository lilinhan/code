/*************************************************************************
    > File Name: for_each4.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 13:29:59 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>

std::vector<int> arr = {1, 2, 3, 4, 5};

std::vector<int>& get_range(void) {
    std::cout << "get_range ->: " << std::endl;
    return arr;
}

int main( int argc , char * argv[] )  {
    for(auto val : get_range())  {
        std::cout << val << std::endl;
    }
    return EXIT_SUCCESS;
}

