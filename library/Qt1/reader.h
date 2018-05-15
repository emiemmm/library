#ifndef READER_H
#define READER_H
#include <iostream>
using namespace std;
#include <string.h>

class reader
{
private:
    string id;//读者编号
    string code;
    string name;
    int kind;  //用户还是管理员  //管理员是0，用户是1.
    int b_book;//借的实体图书数量
public:
    reader();
    string getcode()
    {
        return code;
    }
    string getid()
    {
        return id;
    }
    string getname()
    {
        return name;
    }
    int getkind()
    {
        return kind;
    }
    int getb_book()
    {
        return b_book;
    }

    void setid(string i)
    {
       id=i;
        return;
    }
    void setcode(string cod)
    {
        code=cod;
        return;
    }
    void setname(string nam)
    {
        name=nam;
        return;
    }
    void setkind(int a)
    {
        kind=a;
        return;
    }
    void setb_book()
    {
        b_book=0;
        return;
    }

    void addreader(string i,string c,string Name,int k);
    ~reader();
};

#endif // READER_H
