/*************************************************************************
    > File Name: InsetionSort.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月25日 星期一 14时59分05秒
 ************************************************************************/
#pragma once

#include<iostream>
#include<vector>

template<typename type>
void InsertionSort(std::vector<type> &ve){
    type temp;
    int i,j;
    for(i = 0 ; i < ve.size(); i++) {
        temp = ve[i];
        for(j = i; j > 0 && ve[j-1] > temp; j--) {
            ve[j] = ve[j-1];
        }
        ve[j] = temp;
    }
}
/*
int main(int argc, char *argv[])
{
    std::vector<int> ve = {2,7,1,6,4,9,5,8};
    InsetionSort(ve);
    for(int i = 0 ; i < ve.size(); i++) {
        std::cout << ve[i] << " ";
    }
    return EXIT_SUCCESS;
}
*/
