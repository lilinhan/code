/*************************************************************************
    > File Name: maxandmin.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Wed 21 Oct 2015 10:54:22 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
#include<stdlib.h>
#include<random>
#include<assert.h>

#define INIT_MIN 32767
#define INIT_MAX -1000
#define MIN_LIMIT -100
#define MAX_LIMIT 100

void maxandmin( std::vector<int> & arry , int left , int right ,int &max , int &min) {
    /* arry放整个数组
     * left是分开之后数组最左边的元素
     * right是分开之后最右边的元素
     * max中存放当前最大值
     * min中存放当前最小值
     */
    if(right - left <= 0) {  //判断数组元素个数  如果小于等于2 则根据元素大小覆盖max或者min的值
        if(arry[left] > arry[right])  {
            if(arry[left] > max)    max = arry[left];
            if(arry[right] < min)   min = arry[right];
        }else {
            if(arry[right] > max)  max = arry[right];
            if(arry[left] < min)    min = arry[left];
        }
        return;
    }
    //如果数组元素个数大于2  我们就要进行分治法将数组分开分别求最大和最小的元素
    int mid = left + (right - left) / 2;
    maxandmin(arry, left, mid, max, min);
    maxandmin(arry, mid+1 , right, max, min);
}

int main( int argc , char * argv[] )  {
    int i , num , rad , min_limit = MIN_LIMIT , max_limit = MAX_LIMIT;
    std::vector<int> arry;
    int max = INIT_MAX;
    int min = INIT_MIN;

    std::cout << "How many num do you want?" << std::endl; // 输入数组的大小
    std::cin >> num;

    assert(num > 0);
    for( i = 0 ; i < num ; ++i )  {  //给数组赋值
        rad = rand()%(max_limit - min_limit + 1) + min_limit;
        arry.push_back(rad);
        std::cout << rad << " ";
    }
    maxandmin(arry , 0 , num-1 , max , min);  //分治法求数组的最大最小元素
    std::cout << "\nThe max num is " << max << std::endl;
    std::cout << "The min num is " << min << std::endl;

    return EXIT_SUCCESS;
}

