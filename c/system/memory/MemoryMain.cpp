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

#include"MemoryManagement.cpp"

void display_menu()  {
    std::cout << "\n---------------------------------------------"<< std::endl;
    std::cout << "  Memory management experment " << std::endl;
    std::cout << "  1 - Set memory size(default =  " << DEFAULT_MEM_SIZE << ")"<< std::endl;
    std::cout << "  2 - Select memory allocation algorithm " << std::endl;
    std::cout << "  3 - New Process " << std::endl;
    std::cout << "  4 - Kill a process " << std::endl;
    std::cout << "  5 - Display memory usage " << std::endl;
    std::cout << "  0 - Exit " << std::endl;
    std::cout << "---------------------------------------------"<< std::endl;
}

int main(int argc, char *argv[])
{
    MemoryManagement manager;
    char choice;
    while(1){
        display_menu();
        std::cout << "What do you want?" << std::endl;
        choice = getchar();
        switch(choice)  {
            case '1':manager.SetMemSize();system("clear");break;
            case '2':manager.SetAlgorithm();manager.flag = 1;system("clear");break;
            case '3':manager.NewProcess();manager.flag = 1;system("clear");break;
            case '4':manager.KillProcess();manager.flag = 1;system("clear");break;
            case '5':manager.DisplayMemoryUsage();manager.flag = 1;break;
            case '0':exit(1);break;
            default:break;
        }
        /*
        std::cout << "Manager Size:" << manager.mem_size << std::endl;
        std::cout << "Manager Algorithm:" << manager.ma_algorith << std::endl;
        std::cout << "Manager Pid:" << manager.pid << std::endl;
        std::cout << "Manager flag:" << manager.flag << std::endl;
        */
    }
    return EXIT_SUCCESS;
}

