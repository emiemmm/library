#include "book.h"
#include <fstream>
#include <string.h>
const int b_sum=0;
book::book()
{
}
void book::reading_on()
{
    ifstream newFile;
    newFile.open(position.c_str());
    //newFile.close;
}
void book::addbook(string nam,string writ,string isb,bool r,string posi,int nu)
{   b_name=nam;
    writer=writ;
    isbn=isb;
    re=r;
    on=1;
    num=nu;
    position=posi;
}

//book::download()




