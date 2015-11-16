/*************************************************************************
    > File Name: initializer4.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 11:36:27 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
#include<map>


class FooVector
{
    std::vector<int> content_;

    public:
    FooVector(std::initializer_list<int> list) {
        for(auto it = list.begin(); it != list.end() ; it++) {
            content_.push_back(*it);
        }
    }
};

class FooMap
{
    std::map<int, int> content_;
    using pair_t = std::map<int, int>::value_type;

    public:
    FooMap(std::initializer_list<pair_t> list) {
        for(auto it = list.begin(); it != list.end(); it++) {
            content_.insert(*it);
        }
    }
};

int main( int argc , char * argv[] )  {
    FooVector foo_1 = {1, 2, 3, 4, 5};
    FooMap foo_2 = { { 1, 2}, { 3, 4}, { 5, 6} };
    return EXIT_SUCCESS;
}

