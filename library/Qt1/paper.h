#ifndef PAPER_H
#define PAPER_H
#include <iostream>
using namespace std;
int p_sum=0;
class paper
{
public:
     paper();
        paper(int nu,char *b_nam,char *writ,char *position);
        char* getname()
        {
            return p_name;
        }
        int getnum()
        {
            return num;
        }
        char *getwriter()
        {
             return writer;
        }

        char *getisbn()
        {
               return isbn;
         }
        char *getposition()
        {
               return position;
        }

        bool getre()
        {
            if(re)  return 1;
            else return 0;
        }
        void showwing()
        {
            cout<<"编号:"<<getnum()<<endl;
            cout<<"书名："<<getname()<<endl;
            cout<<"作者："<<getwriter()<<endl;
            cout<<"isbn:"<<getisbn()<<endl;
            cout<<"位置："<<getposition()<<endl;
        }
       void addpaper(char *nam,char *writ,char * publish,char *tim);
         ~paper();
    private:
        char p_name[50];
        int num;            //图书编号
        char publisher[30];
        char writer[50];   // 多个作者？
        char time[10];     //发布时间
        char position[20];


};

#endif // PAPER_H
