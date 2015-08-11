/*************************************************************************
    > File Name: 3_22.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月22日 星期三 11时20分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class HugeMem {
    public:
        HugeMem( int size ) : sz(size > 0 ? size : 1 )  {
            c = new int[sz];
        }
        ~HugeMem() { delete [] c ;}
        HugeMem( HugeMem && hm ) : sz(hm.sz) , c(hm.c){
            hm.c = nullptr;
        }
        int * c;
        int sz;
};

class Moveable {
    public:
        Moveable():i(new int(3)) , h(1024) {}
        ~Moveable() { delete i; }
        Moveable (Moveable && m) : i(m.i) , h(std::move(m.h)) {
            m.i = nullptr;
        }
        int * i;
        HugeMem h;
};

Moveable GetTemp() {
    Moveable tmp = Moveable();
    std::cout << std::hex << "Huge Mem from " << __func__ << "@" << tmp.h.c << std::endl;
    return tmp;
}

int main( int argc , char * argv[] )  {
    Moveable a(GetTemp());
    std::cout << std::hex << "Hug Men from " << __func__ << "@" << a.h.c <<std::endl;
    return EXIT_SUCCESS;
}

