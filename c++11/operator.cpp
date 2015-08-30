/*************************************************************************
    > File Name: operator.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月29日 星期六 11时54分06秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class fruit {
    public:
        fruit(const std::string &nst = "apple" , const std::string & cst = "gre") {}
        ~fruit() {}

        friend std::ostream & operator << ( std::ostream & os , const fruit & f);
        friend std::istream & operator >> ( std::istream & is , fruit & f);
    private:
        std::string name;
        std::string colour;
};

std::ostream & operator << (std::ostream & os , const fruit & f)  {
    os << "the name is " << f.name << ".the clolour is " << f.colour;
    return os;
}

std::istream& operator >> (std::istream & is , fruit & f) {
    is >> f.name >> f.colour;
    if( !is )  {
        std::cerr << "wrong input!" << std::endl;
    }
    return is;
}

int main( int argc , char * argv[] )  {
    fruit apple;
    std::cout << " Input the name and colour of a kind of fruit." << std::endl;
    std::cin >> apple;
    std::cout << apple;
    return EXIT_SUCCESS;
}

