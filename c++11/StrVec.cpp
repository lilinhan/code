/*************************************************************************
    > File Name: StrVec.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月15日 星期六 10时19分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<memory>

class StrVec {
    public:
        StrVec():elements(nullptr) , first_free(nullptr) , cap(nullptr) {}
        explicit StrVec(const StrVec &);
        StrVec & operator= (const StrVec &);
        ~StrVec();

        void push_back(const std::string&);
        size_t size() const { return first_free - elements;}
        size_t capcity() const {return cap - elements;}
        std::string *begin() const { return elements;}
        std::string *end() const { return first_free;}

    private:
        static std::allocator<std::string> alloc; // 分配元素
        void chk_n_alloc() { if( size() == capcity() ) reallocate(); }

        std::pair<std::string * , std::string *> alloc_n_copy(const std::string* , const std::string*);
        void free();
        void reallocate();
        std::string *elements;
        std::string *first_free;
        std::string *cap;
};

void StrVec::push_back(const std::string & s) {
    chk_n_alloc();
    alloc.construct(first_free++ , s);
}

std::pair<std::string * , std::string*> StrVec::alloc_n_copy(const std::string *b , const string *e)  {
    auto data = alloc.allocator(e - b);
    return { data , std::uninitialized_copy(b,e,data)};
}

void StrVec::free()  {
    if( elements )  {
        for( auto p = first_free ; p != elements ; )  {
            alloc.destory(--p);
        alloc.deallocate(elements , cap - elements);
        }
    }
}

StrVec::StrVec(const StrVec &s)  {
    auto newdata = alloc_n_copy(s.begin() , s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free();}

StrVec & StrVec::operator=(const StrVec & rhs)  {
    auto data = alloc_n_copy(rhs.begin() , rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second();
    return *this;
}

int main( int argc , char * argv[] )  {

    return EXIT_SUCCESS;
}
