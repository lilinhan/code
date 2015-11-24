/*************************************************************************
	> File Name: lexical.h
	> Author: lewin
	> Mail: lilinhan1303@gmail.com
	> Company: Xiyou Linux Group
	> Created Time: 2015年11月18日 星期三 19时37分22秒
 ************************************************************************/
#pragma once

#ifndef _LEXICAL_H
#define _LEXICAL_H
#endif

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
//#include<utility>
#include<map>

//定义Token的类型(num)  -1是错误，1是关键字，2是变量，3是函数，4是分隔符，5是数字，6是运算符
#define ERROR -1
#define KEYWORD 1
#define VARIABLE 2
#define FUNCTION 3
#define SEPARATOR 4
#define NUMBER 5
#define OPERATOR 6



