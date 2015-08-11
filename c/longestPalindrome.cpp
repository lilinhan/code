/**************************************************************************
> File Name: longestPalindrome.cpp
> Author: lewin
> Mail: lilinhan1303@gmail.com
> Company:  Xiyou Linux Group
> Created Time: 2015年05月27日 星期三 21时28分01秒
************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
using namespace std;

string longestPalindrome(string s) {
    if( s.empty() )  {
        return "";
    }
    if( s.size() == 1 )  {
        return s;
    }
    string ret = "^#";
    for ( int i = 0 ; i < s.size() ; i++ )  {
        ret += s[i];
        ret += "#";
    }
    ret += "$";
    cout<<ret<<endl;
    char * r , * l;
    int count;
    int loc = 0, max = 0;
    for(int i = 1 ; i < ret.size() - 1; i++ )  {
        l = &ret[i - 1];
        r = &ret[i + 1];
        count = 1;
        if( *r == *l )  {
            while( *r == *l )  {
                r++;
                l--;
                count++;
            }
        }
        if( count > max ) {
            max = count - 1;
            loc = i;
        }
            cout<<max<<endl;
            cout<<loc<<endl;
    }
    return ret.substr( loc-max+1 , 2*max-1);
}


int main( int argc , char * argv[] )  {
    string a;
    cin>>a;
    cout<<longestPalindrome(a)<<endl;
    return EXIT_SUCCESS;
}

