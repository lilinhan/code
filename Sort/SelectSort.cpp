/*************************************************************************
    > File Name: SelectSort.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月25日 星期一 14时14分45秒
 ************************************************************************/
#pragma once

#include<iostream>
#include<vector>

template<typename type>
void SelectSort(std::vector<type> &ve) {
    int min;
    for(int i = 0 ; i < ve.size(); i++) {
        min = i;
        for(int j = i+1; j < ve.size(); j++) {
            if(ve[j] <= ve[min]) {
                min = j;
            }
        }
        auto temp = ve[min];
        ve[min] = ve[i];
        ve[i] = temp;
    }

}
/*
int main(int argc, char *argv[])
{
    std::vector<int> ve = {2,3,6,1,9,5,7,4,8};
    SelectSort(ve);

    for(int i = 0 ; i < ve.size() ; i++) {
        std::cout << ve[i] << " ";
    }
    return EXIT_SUCCESS;
}
*/
