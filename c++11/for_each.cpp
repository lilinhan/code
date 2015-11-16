/*************************************************************************
    > File Name: for_each.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 12:57:04 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
#include<algorithm>

void do_cout(int n) {
    std::cout << n << std::endl;
}

int main( int argc , char * argv[] )  {
    std::vector<int> arr = {1, 2, 3, 4};
    std::for_each(arr.begin(), arr.end(), do_cout);
    return EXIT_SUCCESS;
}

