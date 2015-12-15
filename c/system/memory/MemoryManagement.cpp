/*************************************************************************
  > File Name: MemoryManagement.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Organization: Xiyou Linux Group
  > Created Time: 2015年12月10日 星期四 08时27分49秒
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<list>

#include"MemoryManagement.h"

void MemoryManagement::SetMemSize() {
    int size;
    if(flag != 0) {
        std::cout << "Can't set memory size again or you have already started using the memory!\n";
        return;
    }
    std::cout << "Total memory size = ";
    std::cin >> size;

    if(size > 0) {
        mem_size = size;
        FreeBlockType block(size, DEFAULT_MEM_START);
        FreeMemoryList.push_back(block);
    }
    flag = 1;
}

void MemoryManagement::SetAlgorithm() {
    int algorithm;
    std::cout << "\t1- First Fit\n";
    std::cout << "\t2- Best Fit\n";
    std::cout << "\t3- Worst Fit\n";
    std::cin >> algorithm;
    if(algorithm >= 1 && algorithm <= 3) {
        ma_algorith = algorithm;
    }
    rearrage(ma_algorith);
}

void MemoryManagement::NewProcess()  {
    char *buf;
    int size;
    sprintf(buf, "%d",pid);
    std::string name = "PROCESS -" + buf;
    while(1) {
        std::cout << "Please input the memory size:";
        std::cin >> size;
        if(size <= mem_size && size > 0)  {
            AllocatedBlock process(pid, size, name);
            break;
        }else {
            std::cout << "size error" << std::endl;
        }
    }
    AllocatedBlockList.push_back(process);





}

void MemoryManagement::KillProcess() {

}

void MemoryManagement::DisplayMemoryUsage() {

}

void MemoryManagement::rearrage(int choice) {

}

void MemoryManagement::rearrage_FF() {

}

void MemoryManagement::rearrage_BF() {

}

void MemoryManagement::rearrage_WF() {

}


