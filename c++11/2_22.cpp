/*************************************************************************
    > File Name: 2_22.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 20时01分47秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
template <typename T> class DefenderT {
    public:
        friend T;
        void Defence(int x , int y){}
        void Tackle(int x , int y){}

    private:
        int pos_x = 15;
        int pos_y = 0;
        int speed = 2;
        int stamina = 120;
};

template<typename T> class AttackerT  {
    public:
        friend T;
        void Move( int x , int y )  {}
        void SpeedUp(float ratio) {}

    private:
        int pos_x = 0;
        int pos_y = -30;
        int speed = 3;
        int stamina = 100;
};

using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;

#ifdef UNIT_TEST

class Validator {
    public:
        void Validate(int x , int y , DefenderTest & d) {}
        void Validate(int x , int y , AttackerTest & a) {}
};

using DefenderTest = DefenderT<Validator>;
using AttackerTest = AttackerT<Validator>;

int main( int argc , char * argv[] )  {
    DefenderTest d;
    AttackerTest a;
    a.Move(15,30);
    d.Defence(15,30);
    a.SpeedUp(15 , 30);
    Validator v;
    v.Validate(7 , 0 , d );
    v.Validate(1 , -10 , a);
    return EXIT_SUCCESS;
}

#endif
