/*************************************************************************
    > File Name: test.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月02日 星期日 19时58分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<algorithm>

void fun(std::string & s)  {
    std::string str[] = {"/b/c/a.txt" , "/b/a/t" , "/b/a.out"};
    std::string temp;
    int num = s.length();
    std::cout << num << std::endl;
    for( int i = 0 ; i < 3 ; ++i )  {
        int loc = str[i].find( '/' , num );
        //std::cout << loc << std::endl;
        temp = "";
        if(loc)  {
            temp = str[i].substr(num,loc-num+1);
        }else{
            temp = str[i].substr(num - 1,str[i].rfind('\0'));
        }
        std::cout << temp << std::endl;
    }

}

int main( int argc , char * argv[] )  {
   // std::string s = "/b/";
   // fun(s);
  //  char * ss = "lalala";
   // std::string str = ss;

    /*int a = 11;
    std::string str = "a";
    str = str + std::to_string(a);
    std::cout << str << std::endl;
*/
    int a1[] = {0,1,2,3,4,5,6,7,8};
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = std::copy(std::begin(a1) , std::end(a1) ,a2);
    for (auto a : a2)  {
        std::cout << a << std::endl;
    }
    return EXIT_SUCCESS;
}

