#include "library.h"
#include <QApplication>
#include "bdatabase.h"
#include "rdatabase.h"
#include "reader.h"
#include "book.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Bdatabase bone;
    rdatabase rone;
    int c;
    int b;
    string bbook;
    string rname;
    book *tmp;
    reader *an;
    cout<<"are you a old user"<<endl;
    cout<< "1.no   2.yes"<<endl;

    cin>>b;
    if(b==1)
    {
        cout<<"now creat a new account"<<endl;
        an=rone.addraeders();
        cout<<"finished"<<endl;

    }
    else
    {
        an=rone.identity();
    }
    if(an==NULL)
    {
        return 0;
    }
    if(an->getkind()==0)
    {
        cout<<"hello,administrator"<<endl;
        cout<<"what do you want yo do"<<endl;
        cout<<"1.add new book"<<endl;
        cout<<"2.add new paper"<<endl;
        cout<<"3.delete book"<<endl;
        cout<<"4.add new user"<<endl;
        cout<<"5.delete user"<<endl;
        cout<<"6.look up a book"<<endl;
        cin>>c;
        if(c==1)
        {
            bone.addbooks();
        }
       /* else if(c==2)
        {
            bone.addpapers();
        }*/
        else if(c==3)
        {
            cout<<"please input the complete name of your book:"<<endl;
            getline(cin,bbook);
            bone.deletebooks(bbook);
        }
        else if(c==4)
        {
            rone.addraeders();
        }
        else if(c==5)
        {
            cout<<"please input the user*s name who you want to delete:"<<endl;
            cin>>rname;
            rone.deletreadrs(rname);
        }
        else
        {
            cout<<"please input the complete name of your book:"<<endl;
            getline(cin,bbook);
            tmp=bone.findbooks(bbook);
        }
    }
    else
    {
         cout<<"hello,user"<<endl;
         cout<<"what do you want yo do?"<<endl;
         cout<<"1.borrow the book"<<endl;
         cout<<"2.ret the book"<<endl;
         cout<<"3.read e_book"<<endl;
         cout<<"4.download the book"<<endl;
         cout<<"5.look up a book"<<endl;
         cin>>c;
         if(c==1)
         {
             cout<<"please input the complete name of your book:"<<endl;
             getline(cin,bbook);
             tmp=bone.findbooks(bbook);
             tmp->borrowbook();
         }
         else if(c==2)
         {
             cout<<"please input the complete name of your book:"<<endl;
             getline(cin,bbook);
             tmp=bone.findbooks(bbook);
             tmp->retbook();
         }
         else if(c==3)
         {
             cout<<"please input the complete name of your book:"<<endl;
             getline(cin,bbook);
             tmp=bone.findbooks(bbook);
             tmp->reading_on();
         }
        /* else if(c==4)
         {
             //后续补充。
         }*/
         else
         {
             cout<<"please input the complete name of your book:"<<endl;
             getline(cin,bbook);
             tmp=bone.findbooks(bbook);
         }
    }
   bone.showing();

   cout<<"thanks"<<endl;
   //rdatabase::~rdatabase();
   //Bdatabase::~Bdatabase();
   return 0;
}
