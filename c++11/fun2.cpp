/*************************************************************************
    > File Name: fun2.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月07日 星期五 09时53分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<list>
#include<algorithm>
#include<iterator>

int main( int argc , char * argv[] )  {
//    std::istream_iterator<int> in(std::cin) , eof;
//    std::cout << accumulate(in , eof , 0) << std::endl;

    std::vector<int> vec = {1,2,3,4,5};
    std::ostream_iterator<int> out_iter(std::cout ," ");
    for(auto e : vec)  {
        *out_iter++ = e;
    }
    std::cout << std::endl;

    copy(vec.begin() , vec.end() , out_iter);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

