/*************************************************************************
    > File Name: log.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月22日 星期五 14时36分58秒
 ************************************************************************/
#include"log.h"
using namespace MyTinyLog;

LOG::LOG(std::string AuthorName) {
    Filter = AuthorName;
    //config文件
}

LOG::~LOG(){}

void LOG::setParam(Level le, std::string text, std::string FileName, int line) {
    setCurrentTime();
    setLevel(le);
    setProcessID();
    setPthreadID();
}

void LOG::setCurrentTime() {
    std::time_t t = std::time(0);
    std::string temp(std::asctime(std::localtime(&t)));
    CurrentTime = temp;
}

void LOG::setLevel(Level le) {
    level = le;
}

void LOG::setProcessID() {
    ProcessID = getpid();
}

void LOG::setPthreadID() {
    PthreadID = pthread_self();
}

void LOG::print() {
    std::cout << level << "\t" << ProcessID << "\t" << PthreadID <<"\t" << Filter << "\t" <<CurrentTime;
}

int main() {
    LOG log("lewin");
    log.setParam(OFF, "file error", __FILE__, 56);
    log.print();
}
