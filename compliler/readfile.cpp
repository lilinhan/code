/*************************************************************************
  > File Name: lexical.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Company:  Xiyou Linux Group
  > Created Time: Sun 15 Nov 2015 13:43:34 CST
 ************************************************************************/

#pragma once


class ReadFile{
    public:
        std::string filename;
        std::ifstream fin;

    public:
        ReadFile(char *name):filename(name){
            fin.open(filename);
        }
        ~ReadFile(){}

        void read_file();   //从文件中读数据
        void loop_file_data(); // 循环读文件

};

void ReadFile::loop_file_data() {
    std::string s;
    while(std::getline(fin, s)) {
        std::cout << s << std::endl; //这里可以遍历每一行
    }
}

void ReadFile::read_file(){   //读文件
    loop_file_data();
}


