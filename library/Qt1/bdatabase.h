#ifndef BDATABASE_H
#define BDATABASE_H
#include "book.h"
#include <fstream>
#include <iostream>
using namespace std;
const long long BMAX=10000;
class Bdatabase
{
private:
    book btarray[BMAX];
    int top;
public:
    Bdatabase();
    int delebook;
    void addbooks();
    void deletebooks(string nam);
    book* findbooks(string a);  //查询书籍状况并输出。
    void filein(string nam);
    void showing();
    //void addpapers();
    ~Bdatabase();
};

#endif // BDATABASE_H
