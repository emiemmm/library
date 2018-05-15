#include "reader.h"

reader::reader()
{    
}
void reader::addreader(string i,string c,string Name,int k)
{
    setid(i);
    setcode(c);
    setname(Name);
    setkind(k);
    setb_book();
    return;
}

reader::~reader()
{
}

