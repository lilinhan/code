/*************************************************************************
  > File Name: time.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Organization: Xiyou Linux Group
  > Created Time: 2016年01月22日 星期五 13时52分47秒
 ************************************************************************/
#include<iostream>
#include<ctime>
#include<string>
enum level{
    one,
    two,
    three,
};

namespace lala{
    class A{
        public:
        level le;
    };
}

int main(int argc, char *argv[])
{
 /*      std::time_t t = std::time(0);
        std::string str(std::asctime(std::localtime(&t)));
        std::cout << str;
    lala::A a;
    a.le = one;
    std::cout << a.le; */
    std::string str(__FILE__);
    std::cout << str << std::endl;
    return EXIT_SUCCESS;
}

