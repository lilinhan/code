/*************************************************************************
    > File Name: fun5.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月08日 星期六 09时06分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<algorithm>
#include<vector>

int main( int argc , char * argv[] )  {
    std::vector<int>  v1 = {0,1,2,3,4,5,6,7,8};
    std::vector<int>  v2;

    std::remove_copy_if(v1.begin() , v1.end() , std::back_inserter(v2) , [](int i) {return i % 2;});

    for( auto a : v2 ) {
        std::cout << a << std::endl;
    }
    return EXIT_SUCCESS;
}

