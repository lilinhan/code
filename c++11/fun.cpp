/*************************************************************************
    > File Name: fun.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月06日 星期四 15时29分26秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<algorithm>
#include<vector>

bool isShorter( const std::string & s1 , const std::string &s2 )  {
    return s1.size()  < s2.size();
}

void elimDups( std::vector<std::string>  &words  )  {
    std::sort (words.begin() , words.end());
    auto end_unique = unique(words.begin() , words.end());
    words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words , std::vector<std::string>::size_type sz)  {
    elimDups(words);
    stable_sort(words.begin() , words.end() , [](const std::string & a , const std::string &b ) { return a.size() <  b.size();});

    auto wc = find_if(words.begin() , words.end() , [sz](const std::string & a) { return a.size() >= sz ;});

    auto count = words.end() - wc;
    std::cout << count << " of_length " << sz << "or longer" << std::endl;

    for_each(wc,words.end() , [](const std::string & s){std::cout << s << std::endl;});
    std::cout << std::endl;
}

void test()  {
   // auto f = [] { return 42; };
   // std::cout << f() << std::endl;
}

int main( int argc , char * argv[] )  {
    std::vector<std::string>  strs = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    int sz=0;
    biggies(strs , 3);
    return EXIT_SUCCESS;
}

