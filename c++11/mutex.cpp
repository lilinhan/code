/*************************************************************************
    > File Name: mutex.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年02月01日 星期一 13时29分07秒
 ************************************************************************/
#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>

std::mutex mtx;
std::condition_variable va;

void process() {
    std::unique_lock<std::mutex> lk(mtx);
    std::cout << "hello" << std::endl;
    va.wait(lk);
}

int main(int argc, char *argv[])
{
    std::thread t1(process), t2(process);
    t1.join();
    t2.join();
    return EXIT_SUCCESS;
}

