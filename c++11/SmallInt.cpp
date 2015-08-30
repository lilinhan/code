/*************************************************************************
    > File Name: SmallInt.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月30日 星期日 15时10分52秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<stdexcept>

class SmallInt {
    public:
        SmallInt(int i = 0):val(i)  {
            if( i < 0 || i > 255 )  {
                std::throw std::out_of_rang("bad SmallInt value");
            }
        }

        operator int() const {return val;}

    private:
            std::size_t val;
};

int main( int argc , char * argv[] )  {
    SmallInt si = 3.14;
    si = 4;
    si += 3;

    return EXIT_SUCCESS;
}

