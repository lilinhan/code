/*************************************************************************
    > File Name: 2_7.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 19时30分52秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<cassert>

enum FeatureSupports {
    C99         =       0x0001,
    ExtInt      =       0x0002,
    SAssert     =       0x0004,
    NoExcept    =       0x0008,
    SMAX        =       0x0010,
};

struct Compiler {
    const char * name;
    int spp;        //使用FeatureSupports枚举
};

int main( int argc , char * argv[] )  {
    assert((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));

    Compiler a = {"abc" , (C99 | SAssert)};


    return EXIT_SUCCESS;
}

