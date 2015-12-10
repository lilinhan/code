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

int men_size = DEFAULT_MEM_SIZE;
int ma_algorith = MA_FF;
static int pid = 0;
int flag = 0;

class MemoryManagement{
    public:
        std::list<FreeBlockType> FreeMemoryList;
        std::list<AllocatedBlock> AllocatedBlockList;

        void DisplayMemoryUsage();
};

