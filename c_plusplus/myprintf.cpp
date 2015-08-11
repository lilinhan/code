/*************************************************************************
    > File Name: myprintf.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 16时40分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<cassert>

void myprintf(const char * ptext)
{
    assert(ptext != NULL);
    std::cout<<ptext;
}

template<typename T , typename... Args>
void myprintf(const char * ptext , T value , Args... args)
{
    assert( ptext != NULL ) ;
    while(*ptext)
    {
        if(*ptext == '%' && *++ptext != '%')
        {
            std::cout<<value;
            myprintf(++ptext,args...);
            return;
        }
        std::cout<<*ptext++;
    }
}
int main( int argc , char * argv[] )  {
    myprintf("1");
    myprintf("1","2");
    myprintf("1","2","3");
    return EXIT_SUCCESS;
}

