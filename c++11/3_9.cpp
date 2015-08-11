/*************************************************************************
    > File Name: 3_9.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月22日 星期三 09时41分06秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class Info {
    public:
        Info() : Info(1 , 'a') {}
        Info(int i) : Info( i , 'a') {}
        Info(char e) : Info(1 , e) {}

    private:
        Info(int i , char e) : type(i) , name(e) { /*code*/ };
        int type;
        char name;
}

int main( int argc , char * argv[] )  {

    return EXIT_SUCCESS;
}

