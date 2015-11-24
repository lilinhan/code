/*************************************************************************
	> File Name: lexical.cpp
	> Author: lewin
	> Mail: lilinhan1303@gmail.com
	> Company: Xiyou Linux Group
	> Created Time: 2015年11月18日 星期三 19时29分02秒
 ************************************************************************/

#include"lexical.h"

//Token结构
class Token{
    public:
        int num;
        std::string value;
};

//词法分析器类
class Lexical{
    private:
        std::fstream fin;
        std::string open_file_name;
        std::string str;
        std::vector<std::string> table = {{"main"}, {"printf"}};

    public:
        Token token;
        std::vector<Token> result;
        int position_filedata;
        std::string file_data;
        std::string val;

    Lexical(std::string name):open_file_name(name) {
        fin.open(open_file_name);
        position_filedata = 0;
    }
    ~Lexical() {}

    void read_file();
    void parsing_string(char);
    void make_token(int);
    void print_result();
    bool token_value_in_table();
    void loop_each_character();
    void print_token();
};

//判断toke是否在枚举类型的table中
bool Lexical::token_value_in_table() {
    for(auto it : table) {
        if(it == val) {
            return 1;
        }
    }
    return 0;
}

//测试时打印一个Token
void Lexical::print_token()  {
    std::cout << val << std::endl;
}

//读文件
void Lexical::read_file() {
    std::string string;
    while(std::getline(fin,string)) {
        file_data += string;
    }
}

//循环遍历每一个字符
void Lexical::loop_each_character() {
    for(position_filedata = 0; position_filedata < file_data.size(); position_filedata++) {
        parsing_string(file_data[position_filedata]);
    }
}

//解析字符，生成字符串
void Lexical::parsing_string(char c) {
    int type;
    //空格直接跳过
    if(c==' ') return;
    //判断分隔符
    else if(c=='{'||c== '}'||c=='('||c==')'||c == ';'||c==','||c=='"') {
        val.insert(val.end(), c);
        type = SEPARATOR;
    //判断变量，关键字，函数，值
    }else if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))  {
        while((c>='A'&& c<='Z')||(c>='a'&&c<='z')) {
            val.insert(val.end(), c);
            c = file_data[++position_filedata];
        }
        type = VARIABLE;  //变量
        if(val == "char") {
            type = KEYWORD; // 关键字
        }
        if(token_value_in_table()) {
            type = FUNCTION;  //函数
        }
        position_filedata--;
    }else if((c>='0' && c<='9')) {
        while((c>='0' && c<='9'))  {
            val.insert(val.end(), c);
            c = file_data[++position_filedata];
        }
        position_filedata--;
        type = NUMBER;  //值
    //最后判断运算符
    }else{
        switch(c) {
            case '*':type=OPERATOR;val.insert(val.end(), c);break;
            case '/':type=OPERATOR;val.insert(val.end(), c);break;
            case '+':type=OPERATOR;val.insert(val.end(), c);break;
            case '-':type=OPERATOR;val.insert(val.end(), c);break;
            case '=':type=OPERATOR;val.insert(val.end(), c);break;
            case '%': //这里是判断printf函数的参数  %d
                val.insert(val.end(), c);
                c = file_data[++position_filedata];
                val.insert(val.end(), c);break;
            default:type=ERROR;break;
        }
    }
    //创建Token
    make_token(type);
}

//创建Token
void Lexical::make_token(int num) {
    token.num = num;
    token.value = val;
    result.push_back(token);  //将token加入到一个数组(vector)中
    val.clear();
}

//打印全部的Token
void Lexical::print_result(){
    for(auto iterator = result.begin(); iterator != result.end(); iterator++) {
        std::cout << iterator->num << "  " << iterator->value << std::endl;
    }
}
/*
 * 下面是写词法分析器后测试的代码
int main(int argc, char* argv[])
{
    std::string name = "test.c";
    Lexical lexical(name);
    lexical.read_file();
    lexical.loop_each_character();
    lexical.print_result();
    return EXIT_SUCCESS;
}
*/
