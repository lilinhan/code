/*************************************************************************
    > File Name: 3-22.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年05月26日 星期二 08时34分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
using namespace std;

class StuID{
    public:
        StuID( int id )  {
            value = id;
            cout<<"Assigning student id"<<value<<endl;
        }
        ~StuID() {
            cout<<"Destructing id " << value<<endl;
        }
        int getId()  {
            return value;
        }
    protected:
        int value;
};

class student{
    public:
        student( char * pName = "noname" , int ssID = 0 ) {
            cout<<"Constructing student "<<pName <<endl;
            strncpy(name , pName , sizeof(name)) ;
            name[sizeof(name) - 1] = '\0';
            StuID id(ssID);
        }
        void display()  {
            cout<<"student  "<< name << "\t" << id.getId() << endl;
        }
    private :
        char name[20];
        StuID id;
};

int main( int argc , char * argv[] )  {
    student s ("Tom" , 9818);
    s.display();
    return EXIT_SUCCESS;
}

