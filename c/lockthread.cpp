/*************************************************************************
    > File Name: lockthread.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月20日 星期一 17时01分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<mutex>
#include<thread>

std::mutex mutex;

void print_block(int n , char c)  {
    mutex.lock();
    for( int i = 0 ; i < n ; i++ ) {
        std::cout<<c;
    }

    std::cout<<"\n";
    mutex.unlock();
}

int main( int argc , char * argv[] )  {
    std::thread pth1(print_block,50,'*');
    std::thread pth2(print_block,50,'$');

    pth1.join();
    pth2.join();
    return EXIT_SUCCESS;
}

