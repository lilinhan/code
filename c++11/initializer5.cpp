/*************************************************************************
    > File Name: initializer5.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 12:18:54 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

void func(std::initializer_list<int> li)
{
    for(auto it = li.begin(); it != li.end(); ++it){
        std::cout << *it << std::endl;
    }
}

int main( int argc , char * argv[] )  {
    func({});
    func({ 1, 2, 3 });
    return EXIT_SUCCESS;
}

