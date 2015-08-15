/*************************************************************************
    > File Name: stream.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月15日 星期六 15时16分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<sstream>
#include<fstream>

int main( int argc , char * argv[] )  {
    std::string str = "hello world!";
    std::stringstream sstr;
    std::wstringstream ws;
    std::string temp;
    sstr << str;

    ws << sstr;
    ws >> sstr;
    sstr >> temp;
    std::cout << temp << std::endl;
    return EXIT_SUCCESS;
}

