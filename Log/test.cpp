/*************************************************************************
    > File Name: test.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月23日 星期六 11时31分36秒
 ************************************************************************/
#include<iostream>
#include<thread>

class A{
    public:
        static void dosometing() {
            std::cout << "lalala" << std::endl;
        }
};

int main(int argc, char *argv[])
{
    std::thread t2(A::dosometing);
    t2.join();
    return EXIT_SUCCESS;
}

