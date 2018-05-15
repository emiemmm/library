#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;
//extern const int b_sum; 全局变量问题  static
class book
{
private:
            string b_name;
            int num;   //图书编号
            string writer;
            string isbn;
            bool re;//是否是实体书；
            bool on;//如是实体书，是否在架
            string position;
public:
            book();
            string getname()
            {
                return b_name;
            }
            int getnum()
            {
                return num;
            }
            string getwriter()
            {
                 return writer;
            }

            string getisbn()
            {
                   return isbn;
             }
            string getposition()
            {
                   return position;
            }

            bool getre()
            {
                return re;
            }
            void showwing()
            {
                cout<<"the book*s number:"<<getnum()<<endl;
                cout<<"the book*s name："<<getname()<<endl;
                cout<<"the book*s writer："<<getwriter()<<endl;
                cout<<"isbn:"<<getisbn()<<endl;
                cout<<"the book*s location："<<getposition()<<endl;

            }
            void addbook(string nam,string writ,string isb,bool r,string posi,int nu);
            void borrowbook()
            {
                if(on=1)
                {
                    on=0;
                }
                else cout<<"sorry,the book is not on";
            }
            void retbook ()
            {
                on=1;
            }
            void reading_on();
            void download();

};

#endif // BOOK_H
