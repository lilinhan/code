/*************************************************************************
  > File Name: 2.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Company:  Xiyou Linux Group
  > Created Time: 2015年05月26日 星期二 20时51分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<algorithm>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size() + nums2.size();
    int dec = size % 2;
    vector<int> nums3;
    nums3.insert(nums3.begin() , nums1.begin() , nums1.end() );
    nums3.insert(nums3.end() , nums2.begin() , nums2.end());
    if( nums3.size() == 1 ) {
        return nums3[0];
    }
    sort(nums3.begin() , nums3.end());
    if( dec == 1 )  {
        return nums3[size/2];
    }else {
        return (nums3[size/2] + nums3[size/2 - 1] ) / 2;
    }
}

int main( int argc , char * argv[] )  {
    vector<int> a = { 1, 1};
    vector<int> b = {2 , 3};
    int x = findMedianSortedArrays(a,b);

    cout<<x<<endl;
    return EXIT_SUCCESS;
}

