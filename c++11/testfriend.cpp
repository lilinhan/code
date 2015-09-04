/*************************************************************************
    > File Name: testfriend.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年09月04日 星期五 15时18分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
template <typename type> class Bar {
    friend type;
};


int main( int argc , char * argv[] )  {
    type a;
    return EXIT_SUCCESS;
}

