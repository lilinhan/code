/*************************************************************************
    > File Name: sorttest.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月15日 星期二 09时57分03秒
 ************************************************************************/
#include<iostream>
#include<list>
#include<algorithm>
#include<functional>

class A{
    public :
    int size;
    int start;

    A(int s, int st):size(s), start(st) {}

    bool operator <(const A& a) const {
        return size < a.size;
    }
};

void printList(std::list<A> list) {
    for(auto ss : list) {
        std::cout << "Size = " << ss.size << "   , Start = " << ss.start << std::endl;
    }
}

bool sort_by_size(const A &a1, const A &a2)  {
    return a1.size > a2.size;
}

bool sort_by_start(const A &a1, const A &a2)  {
    return a1.start < a2.start;
}

int main(int argc, char *argv[])
{
    std::list<A> list;
    for(int i = 0 , j = 10 ; i < 10 ; i++, j--)  {
        A a(i, j);
        list.push_back(a);
    }
    printList(list);
/*
    list.sort(sort_by_start);
    std::cout << "After size sort: \n\n\n";
    printList(list);
    */
    list.sort(sort_by_size);
    std::cout << "After start sort: \n\n\n";
    printList(list);


    return EXIT_SUCCESS;
}

