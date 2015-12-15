/*************************************************************************
  > File Name: MemoryManagement.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Organization: Xiyou Linux Group
  > Created Time: 2015年12月10日 星期四 08时27分49秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<list>

#include"MemoryManagement.h"

bool SortAlgriothmByFF(const FreeBlockType &pre, const FreeBlockType &next) {
    return pre.FreeBlockStartAddress < next.FreeBlockStartAddress;
}

bool SortAlgriothmByBF(const FreeBlockType &pre, const FreeBlockType &next) {
    return pre.FreeBlockSize < next.FreeBlockSize;
}

bool SortAlgriothmByWF(const FreeBlockType &pre, const FreeBlockType &next) {
    return pre.FreeBlockSize > next.FreeBlockSize;
}

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
    rearrage();
}

void MemoryManagement::NewProcess()  {
    char buf[255];
    int size, addr;
    sprintf(buf, "%d",pid);
    std::string temp = buf;
    AllocatedBlock process;
    std::string name = "PROCESS -" + temp;
    while(1) {
        std::cout << "Please input the memory size:";
        std::cin >> size;
        if(size <= mem_size && size > 0)  {
            break;
        }else {
            std::cout << "size error" << std::endl;
        }
    }

    //Traverse the list
    for(auto it = FreeMemoryList.begin(); it != FreeMemoryList.end(); it++) {
        if(it->FreeBlockSize >= size)  {
            if(it->FreeBlockSize <= (size + MIN_SLICE))  {
                process.AllocatedStartAddress = it->FreeBlockStartAddress;
                process.Processid = pid;
                process.AllocatedMemorySize = it->FreeBlockSize;
                process.ProcessName = name;
                AllocatedBlockList.push_back(process);
                FreeMemoryList.erase(it);
            }else {
                process.AllocatedStartAddress = mem_size - size;
                process.Processid = pid;
                process.AllocatedMemorySize = size;
                process.ProcessName = name;
                AllocatedBlockList.push_back(process);
                it->FreeBlockSize -= size;
            }
        }
    }
    pid++;
    mem_size -= size;
}

void MemoryManagement::KillProcess() {
    int id;
    std::cout << "please input you want kill procee's id:";
    std::cin >> id;


}

void MemoryManagement::DisplayMemoryUsage() {
    std::cout << "内存空闲情况:" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "\tStart Address\tSize" << std::endl;
    for(auto block : FreeMemoryList)  {
        std::cout << "\t\t" << block.FreeBlockStartAddress << "\t" << block.FreeBlockSize << std::endl;
    }
    std::cout << "\n\n内存使用情况:" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "PID\tStart Address\tSize" << std::endl;
    for(auto block : AllocatedBlockList) {
        std::cout << block.Processid << "\t\t" << block.AllocatedMemorySize << "\t" << block.AllocatedMemorySize << std::endl;
    }
}

void MemoryManagement::rearrage() {
    switch(ma_algorith)  {
        case 1:rearrage_FF();break;
        case 2:rearrage_BF();break;
        case 3:rearrage_WF();break;
    }
}

void MemoryManagement::rearrage_FF() {
    FreeMemoryList.sort(SortAlgriothmByFF);
}

void MemoryManagement::rearrage_BF() {
    FreeMemoryList.sort(SortAlgriothmByBF);
}

void MemoryManagement::rearrage_WF() {
    FreeMemoryList.sort(SortAlgriothmByWF);
}


