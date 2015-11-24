/*************************************************************************
	> File Name: lexical.cpp
	> Author: lewin
	> Mail: lilinhan1303@gmail.com
	> Company: Xiyou Linux Group
	> Created Time: 2015年11月18日 星期三 19时29分02秒
 ************************************************************************/

#include"lexical.h"

class Token{
    public:
        int num;
        std::string value;
};

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

bool Lexical::token_value_in_table() {
    for(auto it : table) {
        if(it == val) {
            return 1;
        }
    }
    return 0;
}

void Lexical::print_token()  {
    std::cout << val << std::endl;
}

void Lexical::read_file() {
    std::string string;
    while(std::getline(fin,string)) {
        file_data += string;
    }
}

void Lexical::loop_each_character() {
    for(position_filedata = 0; position_filedata < file_data.size(); position_filedata++) {
        parsing_string(file_data[position_filedata]);
    }
}

void Lexical::parsing_string(char c) {
    int type;
    if(c==' ') return;
    else if(c=='{'||c== '}'||c=='('||c==')'||c == ';'||c==','||c=='"') {
        val.insert(val.end(), c);
        type = SEPARATOR;
    }else if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))  {
        while((c>='A'&& c<='Z')||(c>='a'&&c<='z')) {
            val.insert(val.end(), c);
            c = file_data[++position_filedata];
        }
        type = VARIABLE;
        if(val == "char") {
            type = KEYWORD;
        }
        if(token_value_in_table()) {
            type = FUNCTION;
        }
        position_filedata--;
    }else if((c>='0' && c<='9')) {
        while((c>='0' && c<='9'))  {
            val.insert(val.end(), c);
            c = file_data[++position_filedata];
        }
        position_filedata--;
        type = NUMBER;
    }else{
        switch(c) {
            case '*':type=OPERATOR;val.insert(val.end(), c);break;
            case '/':type=OPERATOR;val.insert(val.end(), c);break;
            case '+':type=OPERATOR;val.insert(val.end(), c);break;
            case '-':type=OPERATOR;val.insert(val.end(), c);break;
            case '=':type=OPERATOR;val.insert(val.end(), c);break;
            case '%':
                val.insert(val.end(), c);
                c = file_data[++position_filedata];
                val.insert(val.end(), c);break;
            default:type=ERROR;break;
        }
    }
    make_token(type);
}

void Lexical::make_token(int num) {
    token.num = num;
    token.value = val;
    result.push_back(token);
    val.clear();
}

void Lexical::print_result(){
    for(auto iterator = result.begin(); iterator != result.end(); iterator++) {
        std::cout << iterator->num << "  " << iterator->value << std::endl;
    }
}
/*
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
