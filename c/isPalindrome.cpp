/*************************************************************************
    > File Name: isPalindrome.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年06月05日 星期五 16时50分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<cmath>
using namespace std;

bool isPalindrome(int x) {
    int digit = -1;
    int result = 0;
    int temp = x;
    int h = 0;
    int y  = 0;
    if( x <= 0 ||  x >= 2147483647){
        return false;
    }

    if ( x  == 0 )  {
        return true;
    }
    //将x的位数算出来;
    while( temp != 0 ) {
        temp = temp / 10;
        digit++;
    }
    temp = x;

    for( int i = 1; i <= digit ; ++i ) {
        temp = x % (int)pow(10,i) / pow(10,i-1);
        result += temp*pow(10 , digit-i+1);
    }

    result += x/(int)pow(10,digit);
    if(result == x)  {
        return true;
    }else {
        return false;
    }
}

int main( int argc , char * argv[] )  {
    int x ;
    cout<<isPalindrome(1999999991)<<endl;
    return EXIT_SUCCESS;
}

