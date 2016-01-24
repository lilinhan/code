/*************************************************************************
    > File Name: main.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月23日 星期六 10时20分54秒
 ************************************************************************/
#include"log.cpp"
using namespace MyTinyLog;

int main() {
    time_t start, end;
    time(&start);
    LOG log("lewin");
    for(int i = 0 ; i < 2000 ; i++)  {
        log.setParam(OFF, "file error", __FILE__, __LINE__);
        //   log.print();
        log.appendLogTail();
    }
    time(&end);
    std::cout << "Time = " << (end-start) << "s" << std::endl;
}
