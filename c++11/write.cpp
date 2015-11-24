/*************************************************************************
	> File Name: write.cpp
	> Author: lewin
	> Mail: lilinhan1303@gmail.com
	> Company: Xiyou Linux Group
	> Created Time: 2015年11月23日 星期一 17时49分04秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char* argv[])
{
    std::ofstream f;
    f.open("test.txt");
    std::string a = "hello \n\tworld";
    f << a;

    return EXIT_SUCCESS;
}

