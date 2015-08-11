/*************************************************************************
    > File Name: 11_2.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月08日 星期六 11时28分21秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
#include<map>
#include<set>

int main( int argc , char * argv[] )  {
    std::vector<int> ivec;
    for( std::vector<int>::size_type i = 0 ; i != 10 ; ++i )  {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    std::set<int> iset(ivec.begin() , ivec.end());
    std::multiset<int> miset( ivec.begin() , ivec.end());

    std::cout << ivec.size() << std::endl;
    std::cout << iset.size() << std::endl;
    std::cout << miset.size() << std::endl;

    return EXIT_SUCCESS;
}

