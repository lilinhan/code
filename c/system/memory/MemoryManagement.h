/*************************************************************************
    > File Name: MemoryManagement.h
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月10日 星期四 08时29分16秒
 ************************************************************************/
#pragma once

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<list>

#include"AllocatedBlock.h"
#include"FreeBlockType.h"


//define constant
#define PROCESS_NAME_LEN 32
#define MIN_SLICE 10
#define DEFAULT_MEM_SIZE 1024
#define DEFAULT_MEM_START 0

#define MA_FF 1
#define MA_BF 2
#define MA_WF 3

class MemoryManagement{
    public:
        int mem_size;
        int ma_algorith;
        int pid;
        int flag;

        std::list<FreeBlockType> FreeMemoryList;
        std::list<AllocatedBlock> AllocatedBlockList;

        MemoryManagement():pid(0), flag(0){
            mem_size = DEFAULT_MEM_SIZE;
            ma_algorith = MA_FF;
        }
        ~MemoryManagement() {}

        void SetMemSize();
        void SetAlgorithm();
        void NewProcess();
        void KillProcess();
        void DisplayMemoryUsage();
        void rearrage();
        void rearrage_FF();
        void rearrage_BF();
        void rearrage_WF();
};

