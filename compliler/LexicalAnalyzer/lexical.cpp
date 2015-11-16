/*************************************************************************
  > File Name: lexical.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Company:  Xiyou Linux Group
  > Created Time: Sun 15 Nov 2015 13:43:34 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<map>
#include<string>
#include<fstream>
#include<regex>

class ReadFile{
    private:
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
        std::cout << s << std::endl;
    }
}

void ReadFile::read_file(){   //读文件
    loop_file_data();
}

class Lexical:public ReadFile{ //继承ReadFile
    public:
        enum{
            KEYWORD, VARIABLE, FUNCTION, SYMBOL, OPREATOR
        }all_type;  //所有的
        std::map<int, std::string> result;   //将分词分好的结果放入



};



int main( int argc , char * argv[] )  {

    return EXIT_SUCCESS;
}

