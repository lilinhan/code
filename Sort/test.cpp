/*************************************************************************
    > File Name: test.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月25日 星期一 13时20分08秒
 ************************************************************************/
#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include"QuickSort.cpp"
#include"BubbleSort.cpp"
#include"SelectSort.cpp"

int main(int argc, char *argv[])
{
    std::random_device rd;
    std::vector<int> ve;
 //   std::mt19937 mt(rd());
    for(int i = 1 ; i < 50000 ; i++) {
        //std::cout << rd()%10 << std::endl;
        ve.push_back(rd()%10);
    }
    auto start = std::chrono::system_clock::now();
   // QuickSort(ve, 0, ve.size()-1);
   // BubbleSort(ve);
    SelectSort(ve);
    auto end = std::chrono::system_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << "seconds" << std::endl;

    return EXIT_SUCCESS;
}

