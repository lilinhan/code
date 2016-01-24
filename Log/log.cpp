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
    std::ifstream fin("./config/log.conf");
    std::string str;
    fin >> str;  //如果配置文件多了改这里
    str = str.substr(str.find('=')+1);
    LogPath = str; //日志文件的路径
    if(access(LogPath.c_str(), F_OK) == -1)  {  //判断制定目录下是否有该日志文件 没有则创建
        int fd = open(LogPath.c_str(), O_CREAT | O_EXCL, 0666);
        close(fd);
    }
}

LOG::~LOG(){}

void LOG::setParam(Level le, std::string text, std::string FileName, int line) {
    setCurrentTime();
    setLevel(le);
    setProcessID();
    setPthreadID();
    setText(text);
    setSourceFileName(FileName);
    setLineNum(line);
}

void LOG::setText(std::string text) {
    Text = text;
}

void LOG::setSourceFileName(std::string FileName) {
    SourceFileName = FileName;
}

void LOG::setLineNum (int line)  {
    LineNum = line;
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
    std::cout << level<<"  " << SourceFileName<<"("<<LineNum<<")"  << "  " << ProcessID << "  " << PthreadID <<"  " << Filter << "  " <<CurrentTime << "  " << Text << std::endl;
}

std::string LOG::transLevel() {
    switch(level) {
        case Level::OFF : return std::string("OFF");break;
        case Level::FATAL : return std::string("FATAL");break;
        case Level::ERROR : return std::string("ERROR");break;
        case Level::WARN : return std::string("WARN");break;
        case Level::INFO : return std::string("INFO");break;
        case Level::DEBUG : return std::string("DEBUG");break;
        case Level::TRACE : return std::string("TRACE");break;
        default: return std::string("Shit");break;
    }
    return NULL;
}


void LOG::spliceString() {
    std::string model(" ");

    char temp1[100];
    sprintf(temp1, "%d", ProcessID);
    std::string pid(temp1);

    char temp2[100];
    sprintf(temp2, "%lu", PthreadID);
    std::string tid(temp2);

    char temp3[100];
    sprintf(temp3, "%d", LineNum);
    std::string linenum1(temp3);

    std::string leveltemp = transLevel();
    std::string str = leveltemp + model + SourceFileName +"("\
                      + linenum1 + ")"+ model + pid + model + tid \
                      + model + Filter + model + "\""+ Text +"\""\
                      + model + CurrentTime + "\n";

    Data += str;
}

void LOG::writeLog() {
    Logfd = open(LogPath.c_str(), O_WRONLY | O_APPEND, 0666);
    if(write(Logfd, Data.c_str(), Data.size()) < 0) {
        perror("write in log file error\n");
    }
    close(Logfd);
}

void LOG::appendLogTail() {
    spliceString();
/*
    std::lock_guard<std::mutex> lock(mutex);
    std::thread thread(std::bind(&LOG::writeLog,this));
    thread.join();
    */
}

/*int main() {
  LOG log("lewin");
  log.setParam(OFF, "file error", __FILE__, __LINE__);
//   log.print();
log.appendLogTail();
}
*/
