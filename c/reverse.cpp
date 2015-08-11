/*************************************************************************
  > File Name: reverse.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Company:  Xiyou Linux Group
  > Created Time: 2015年05月29日 星期五 10时46分14秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<cmath>

using namespace std;
int reverse(int x) {
    int res = 0;
    int temp = x;
    int loc = -1;
    while(temp)  {
        temp /= 10;
        loc++;
    }
    int j = loc;
    int i = 0;
    for(  i = 0 ; i < j ; i++ , loc-- )  {
        temp = (x % (int)pow(10 , i+1)) / pow(10 , i);
        res += temp * pow(10 , loc);
    }
    temp = x / pow(10 , i);
    res += temp;

    if( res > pow(2,31)-1 && res < (-1)*pow(2,31)){
        return 0;
    }
    return res;
}

int main( int argc , char * argv[] )  {
    int x;
    cin>>x;
    cout<<reverse(x)<<endl;
    return EXIT_SUCCESS;
}

