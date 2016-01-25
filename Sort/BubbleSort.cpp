/*************************************************************************
    > File Name: BubbleSort.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月25日 星期一 13时59分25秒
 ************************************************************************/
#pragma once

#include<iostream>
#include<vector>

template<typename type>
void BubbleSort(std::vector<type> &ve) {
    for(auto i = 0; i < ve.size(); i++) {
        for(auto j = 0; j < ve.size()-1; j++) {
            if(ve[i] > ve[j]) {
                auto temp = ve[i];
                ve[i] = ve[j];
                ve[j] = temp;
            }
        }
    }
}

/*
int main(int argc, char *argv[])
{
    std::vector<int> ve = {2,3,4,1,6,8,5,7,9};
    BubbleSort(ve);
    for(int i = 0 ; i < 9; i++) {
        std::cout << ve[i] << "  " ;
    }
    return EXIT_SUCCESS;
}
*/
