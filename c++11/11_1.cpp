/*************************************************************************
    > File Name: 11_1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月08日 星期六 10时01分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<map>

int main( int argc , char * argv[] )  {
    std::map<std::string , size_t> word_count;
    std::string word;

    while( std::cin >> word )  {
        ++word_count[word];
    }
    for(const auto &w : word_count)  {
        std::cout << w.first << " occurs"  << w.second << ((w.second > 1) ? "times" : "time")  << std::endl;
    }
    return EXIT_SUCCESS;
}

