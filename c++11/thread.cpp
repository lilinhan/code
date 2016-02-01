/*************************************************************************
    > File Name: thread.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月29日 星期五 09时00分09秒
 ************************************************************************/
#include<iostream>
#include<thread>

void dosomething(int &i) {
    i++;
}
class func{
    public:
        int &i_;
        func(int &i):i_(i){}
        void operator() (){
            for(int j = 0; j < 100; j++) {
                dosomething(i_);
            }
        }
};

void dosomethingincurrentthread() {}

void f() {
    int local = 0;
    func my_func(local);
    std::thread t(my_func);
    try{
        dosomethingincurrentthread();
    }catch(...){
        t.join();
        throw;
    }
    t.join();
}

int main(int argc, char *argv[])
{
    f();
    return EXIT_SUCCESS;
}

