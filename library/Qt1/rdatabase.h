#ifndef RDATABASE_H
#define RDATABASE_H
#include "reader.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

class rdatabase
{
private:
    reader rtarray[10000];
    int top;
public:
    rdatabase();
    int delereader;
    reader *addraeders();
    void deletreadrs(string nam);
    void record(); //每个用户用一个文件txt储存借出或还书记录。(还未实现）
    reader* check(string name,string code,string id);//登录时密码验证
    reader *identity();//登录
    ~rdatabase();
};

#endif // RDATABASE_H
