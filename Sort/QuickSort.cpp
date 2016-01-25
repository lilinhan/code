/*************************************************************************
    > File Name: QuickSort.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月25日 星期一 12时24分39秒
 ************************************************************************/
#pragma once

template<typename type>
int partition(std::vector<type> &ve, int low, int high) {
    type temp = ve[low];
    while(low < high) {
        while(low < high && ve[high] >= temp)  {
            high--;
        }
        ve[low] = ve[high];
        while(low < high && ve[low] <= temp) {
            low++;
        }
        ve[high] = ve[low];
    }
    ve[low] = temp;
    return low;
}

template<typename type>
void QuickSort(std::vector<type> &ve, int low, int high) {
    if(low < high) {
        int mid = partition(ve, low, high);
        QuickSort(ve, low, mid-1);
        QuickSort(ve, mid+1, high);
    }
}
/*
int main(int argc, char *argv[])
{
    std::vector<int> ve = {2, 3, 9, 4, 8, 6, 1};
    QuickSort(ve, 0, ve.size()-1);

    for(auto it = ve.begin(); it != ve.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
*/
