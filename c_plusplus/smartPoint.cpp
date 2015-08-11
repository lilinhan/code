/*************************************************************************
    > File Name: smartPoint.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 17时41分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<memory>

std::unique_ptr<Test> fun()
{
    return std::unique_ptr<Test>(new Test("789"));
}

int main( int argc , char * argv[] )  {
    std::unique_ptr<Test> ptest(new Test("123");
    std::unique_ptr<Test> ptest2(new Test("456"));
    ptest->print();
    ptest2 = std::move(ptest);
    if( ptest == NULL )
    {
        std::cout<<"ptest = NULL\n";
    }
    Test * p = ptest2.release();
    p->print();
    ptest.reset(p);
    ptest->print();
    ptest2 = fun();
    ptest->print();
    return EXIT_SUCCESS;
}

