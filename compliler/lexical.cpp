/*************************************************************************
  > File Name: lexical.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Company:  Xiyou Linux Group
  > Created Time: Sun 15 Nov 2015 13:43:34 CST
 ************************************************************************/

#pragma once
#include"lexical.hpp"

class Lexical:public ReadFile { //词法分析器类
    public:
        enum{
            KEYWORD, VARIABLE, FUNCTION, SYMBOL, OPREATOR
        }all_type;  //所有的
        std::map<int, std::string> result;   //将分词分好的结果放入

        void iterate_each_row();   //遍历每个字符
        void analyze_string_stat(char *);  //判断字符串是什么属性的
        void make_token(char *);  //制作Token
};


