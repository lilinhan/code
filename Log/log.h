/*************************************************************************
  > File Name: log.h
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Organization: Xiyou Linux Group
  > Created Time: 2016年01月22日 星期五 13时33分18秒
 ************************************************************************/
#pragma once

#ifndef LOG_H_
#define LOG_H_

#include<iostream>
#include<ctime>

enum Level{  //日志等级模仿java log4j
    OFF,    //最高级别 关闭日志记录
    FATAL,  //导致程序提前终止的严重错误 还需要将错误打印到终端上
    ERROR,  //其他运行时的错误或意外情况 还需要将错误打印到终端上
    WARN,   //使用已过时的API或者API滥用潜在错误 还需要将错误打印到终端上
    INFO,   //人们感兴趣的运行事件 还需要将错误打印到终端上
    DEBUG,  //流经系统的详细信息 只需写到log中
    TRACE,  //最详细的信息  只需要写到log中
};

namespace MyTinyLog{
    class LOG{
        private:
            Level level;    //日志等级
            std::time_t CurrentTime;    //打日志的时间
            int ProcessID;    //当前进程的ID
            int PthreadID;  //当前线程的ID
            std::string Filter; //谁的动作(主要用于区分代码是谁写的)
            std::string text;   //log的正文
            std::string SourceFileName; //源文件的名字
            int LineNum;    //源文件行号

            bool setLevel();
            bool setCurrentTime();
            bool setProcessID();
            bool setPthreadID();
            bool setText();
            bool setSourceFileName();
            bool setLineNum();

        public:
            LOG(std::string AuthorName);
            ~LOG();

            bool setParam(Level level, std::string text);
            bool appendLogTail();
            bool stopLog();
    };
}


#endif
