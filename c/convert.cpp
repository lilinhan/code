/*************************************************************************
    > File Name: convert.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年05月28日 星期四 19时28分08秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
using namespace std;

string convert(string s , int numRows)  {
    string str = "";
    int interval = 0;
    int loc = 0;
    vector<string> a = {};
    if( s.size() <= 2 || numRows == 1 )  {
        return s;
    }

    for( int i = numRows ; i >=  0 ; i-- ) {
        loc = i;
        if( loc == 0 || loc == numRows - 1)  {
            interval = 2 * numRows - 2;
            while( loc < s.size() )  {
                str += s[loc];
                loc += interval;
            }
        }
        else {
            interval = numRows - 1;
            while(loc < s.size())  {
                str += s[loc];
                loc += interval;
            }
        }
        a.push_back(str);
        str = "";
    }
    for( auto temp = a.end() - 1 ; temp != a.begin() ; temp-- )  {
        str += *temp;
    }
    return str;
}

int main( int argc , char * argv[] )  {
    string s = "abcdef";
    int x;
    cin>>x;

    cout<<convert(s,x)<<endl;
    return EXIT_SUCCESS;
}

