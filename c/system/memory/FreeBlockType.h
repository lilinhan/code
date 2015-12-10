/*************************************************************************
    > File Name: MemoryManagement.h
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月10日 星期四 08时29分16秒
 ************************************************************************/

class FreeBlockType{
    public:
        int FreeBlockSize;
        int FreeBlockStartAddress;

        FreeBlockType(int size, int start):FreeBlockSize(size), FreeBlockStartAddress(start){}  //init_free_block function
        ~FreeBlockType(){}
};
