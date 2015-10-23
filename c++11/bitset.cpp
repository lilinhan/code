/*************************************************************************
    > File Name: bitset.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Wed 21 Oct 2015 16:23:36 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<bitset>

int main( int argc , char * argv[] )  {
    std::bitset<32> bitvec(1U); // defined 32 bits variable

    std::string str("1111110000001100001101");
    std::bitset<32> bitsevc5(str, 5, 4);
    std::bitset<32> bitvec6(str, str.size()-4);

    std::cout << bitsevc5 << std::endl;
    std::cout << bitvec6 << std::endl;

    std::cout << bitsevc5.to_ulong() << std::endl;
    return EXIT_SUCCESS;
}

