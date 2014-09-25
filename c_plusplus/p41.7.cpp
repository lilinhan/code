// =====================================================================================
// 
//       Filename:  p41.7.cpp
//
//    Description:  p41 第七题
//
//        Version:  1.0
//        Created:  2014年09月16日 15时21分15秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Lilinhan, lilinhan1303@gmail.com    693465363@qq.com
//        Company:  Xiyou Linux Group
// 
// =====================================================================================

#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

class my_string
{
	char contents[200];
	int lengths;
	public:
	void init(char a[])  {
		strcpy(contents,a);
	}
	int get_length()  {
		return strlen(contents);
	}
	void cat_string(char string1[100])  {
		strcat(contents,string1);
	}
	void print()  {
		cout<<contents<<endl;
	}
};

int main(int argc, char *argv[])
{
	char stringw[100];
	int lengths;
	my_string string;
	
	cin>>stringw;
	
	string.init(stringw);
	lengths = string.get_length();
	
	cout<<"length is "<<lengths<<endl;

	string.print();
	cout<<"请输入字符串:";

	cin>>stringw;

	string.cat_string(stringw);
	string.print();

	return 0;
}

