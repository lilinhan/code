/*************************************************************************
	> File Name: compliler.cpp
	> Author: lewin
	> Mail: lilinhan1303@gmail.com
	> Company: Xiyou Linux Group
	> Created Time: 2015年11月23日 星期一 15时18分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"lexical.cpp"
#include"lexical.h"

class Compliler {
    private:
    std::string target_file_name;
    std::ofstream file;

    public:
    std::string temp = "\n";
    std::string buffer = "";
    std::string end = "mov ah,4ch\nint 21h\ncode ends\nend start\n";
    Compliler(std::string name):target_file_name(name) {
        file.open(target_file_name);
    }
    ~Compliler(){}

    void loop_each_token(std::vector<Token>);
    //void generate_data_segment(std::string);
    void print_assembly_code();
    void result_in_file();
    
};

void Compliler::loop_each_token(std::vector<Token> para) {
    int model;
    auto segmentit = para.begin();
    for(auto it = para.begin(); it != para.end(); it++) {
        if((*it).num == KEYWORD){
            buffer += "data segment";
            buffer += temp;
            segmentit = it+1;
            while(((*segmentit).num != SEPARATOR) || ((*segmentit).value != ";")){
                if((*segmentit).num == VARIABLE) {
                    buffer += (*segmentit).value;
                    buffer += " db ?";
                    buffer += temp;
                }
                segmentit++;

            }
            buffer += "data ends\ncode segment\nassume cs:code,ds:data\nstart:\n";
            it = segmentit;
        }else if((*it).num == OPERATOR && (*it).value == "="){
            if((*(it+1)).num == NUMBER)  {
                buffer += "mov ax,";
                buffer += (*(it+1)).value;
                buffer += "\nmov ";
                buffer += (*(it-1)).value;
                buffer += ",ax\n";
                it += 2;
            }else {
                if((*(it + 2)).value == "+") {
                    model = 1;
                    buffer += "\nmov al,";
                    buffer += (*(it + 1)).value;
                    buffer += "\nmov bl,";
                    buffer += (*(it + 3)).value;
                    buffer += "\nxor ah,ah\nadd al,bl\naaa\nmov ";
                    buffer += (*(it - 1)).value;
                    buffer += ",ax";
                    buffer += temp;
                }else if((*(it + 2)).value == "-") {
                    model = 2;
                    buffer += "\nmov ax,";
                    buffer += (*(it + 1)).value;
                    buffer += "\nxor ah,ah\nsub ax,";
                    buffer += (*(it + 3)).value;
                    buffer += "\naas\nmov ";
                    buffer += (*(it - 1)).value;
                    buffer += ",ax";
                    buffer += temp;
                }else if((*(it + 2)).value == "*") {
                    model = 3;
                    buffer += "\nmov ax,";
                    buffer += (*(it + 1)).value;
                    buffer += "\nmov bl,";
                    buffer += (*(it + 3)).value;
                    buffer += "\nmul bl\naam\nmov ";
                    buffer += (*(it - 1)).value;
                    buffer += ",ax";
                    buffer += temp;
                }else if((*(it + 2)).value == "/"){
                    model = 4;
                    buffer += "\nmov ah,0\nmov al,";
                    buffer += (*(it + 1)).value;
                    buffer += "\nmov bl,";
                    buffer += (*(it + 3)).value;
                    buffer += "\nadd\ndiv bl\nmov ";
                    buffer += (*(it - 1)).value;
                    buffer += ",ax";
                    buffer += temp;   
                }
                it += 4;
            }
        }else if(((*(it)).num == FUNCTION) && ((*(it)).value == "printf")){
            while((*it).num != VARIABLE) {
                it++;
            }
            switch(model) {
                case 1:{
                    buffer += "\nmov ax,";
                    buffer += (*it).value;
                    buffer += "\nmov dl,ah\nadd dl,30h\nmov ah,2\nint 21h\n";
                    buffer += "mov ax,";
                    buffer += (*it).value;
                    buffer += "\nmov dl,al\nadd dl,30h\nmov ah,2\nint 21h\n";
                };break;
                case 2:{
                    buffer += "mov ax,";
                    buffer += (*it).value;
                    buffer += "\nadd ah,30h\nmov dl,ah\nmov ah,2\nint 21h\n";
                    buffer += "mov ax,";
                    buffer += (*it).value;
                    buffer += "\nadd al,30h\nmov dl,al\nmov ah,2\nint 21h\n";
                };break;
                case 3:{
                    buffer += "mov ax,";
                    buffer += (*it).value;
                    buffer += "\nadd ah,30h\nmov dl,ah\nmov ah,2\nint 21h\n";
                    buffer += "mov ax,";
                    buffer += (*it).value;
                    buffer += "\nadd al,30h\nmov dl,al\nmov ah,2\nint 21h\n";
                };break;
                case 4:{
                    buffer += "mov ax,";
                    buffer += (*it).value;
                    buffer += "\nadd al,30h\nmov dl,al\nmov ah,2\nint 21h\n";
                };break;
            }
        }
    }
    buffer += end;
}

void Compliler::print_assembly_code() {
    std::cout << buffer <<std::endl;
}

void Compliler::result_in_file(){
    file << buffer;
}

int main(int argc, char* argv[])
{
    std::string read_file_name = "test.c";
    std::string write_file_name = "test.asm";
    Compliler compliler(write_file_name);
    Lexical lexical(read_file_name);
    lexical.read_file();
    lexical.loop_each_character();
//    lexical.print_result();
    
    compliler.loop_each_token(lexical.result);
    compliler.print_assembly_code();
    compliler.result_in_file();
    return EXIT_SUCCESS;
}

