/*************************************************************************
    > File Name: MemoryManagement.h
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月10日 星期四 08时29分16秒
 ************************************************************************/

class AllocatedBlock{
    public:
        int Processid;
        int AllocatedMemorySize;
        int AllocatedStartAddress;
        std::string ProcessName;

        AllocatedBlock(int id, int size, int address, std::string name):Processid(id),AllocatedMemorySize(size),AllocatedStartAddress(address),ProcessName(name) {}
        ~AllocatedBlock(){}
};

