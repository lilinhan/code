/*************************************************************************
    > File Name: for_each2.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 13:21:29 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<map>

int main( int argc , char * argv[] )  {
    std::map<std::string, int> mm = {
        {"1", 1}, {"2", 2}, {"3", 3}
    };

    for(auto ite = mm.begin(); ite!= mm.end(); ++ite) {
        std::cout << ite->first << "-->" << ite->second << std::endl;
    }

    for(auto & val : mm) {
        std::cout << val.first << "->" << val.second << std::endl;
    }

    return EXIT_SUCCESS;
}

