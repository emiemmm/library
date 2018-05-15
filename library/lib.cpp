#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std; 
class book
{
public:
    book(char *bookname); 
    void set_book(char *bookname);
    //void status(char *bookname);
    ~book();
private:
    char publisher[50];
    char ISBN[15];
    char author[50];
    char statusofbook[50];
    char name[50];
};

void book::set_book(char *bookname) 
{	
	 
    ofstream out("booknames");
    out<<bookname<<endl;
    out.close();
    ofstream enter(bookname);
	
    enter<<"The book you want to find is aviliable!"<<endl;
    enter<<"BOOK"<<endl;
    enter <<bookname<<endl;
    cout<<"Please enter the author of this book."<<endl;
    cin>>author;
    enter<<"Author:"<<author<<endl;
    cout<<"Please enter the publisher date of this book."<<endl;
    cin>>publisher;
    enter<<"Publisher:"<<publisher<<endl;
    cout<<"Please enter the ISBN of this book."<<endl;
    cin>>ISBN;
    enter<<"ISBN:"<<ISBN<<endl;
    enter<<"Sorry,this paper-book doesn't support online viewing!"<<endl;
    enter<<"You can only get the basic information there,"<<endl;
    enter<<"But you can borrow it for more content."<<endl;
    enter.close();
    cout <<"Set successfully!"<<endl;
}


book::book(char *bookname)
{	
	strcpy(name,bookname);
}
book::~book()
{
/*void book::status(char *bookname){
    cout <<"Please enter the bookname:"<<endl;
    char bookname[50];
    cin >>bookname;
    ifstream in (bookname);
    char statusofbook[50];
    in.getline(statusofbook,50);
    cout<<statusofbook<<endl;
}*/
}
class database
{
public:
    database(char *bookname); 
    void deletecontent(char *bookname);
    void viewcontent(char *bookname);
    void research();
    ~database();
private:
	char name[50];
};
void database::deletecontent(char *bookname){
    if(remove(bookname)==0)
    {
        cout<<"Successfully delete!"<<endl;
    }
    else
    {
        cout<<"Failed to delete!"<<endl;
    }
}
void database::viewcontent(char *bookname){
    ifstream in (bookname);
    while(!in){
        cout <<"The book you want to read is not exist!"<<endl;
        cout <<"Please enter the book again:"<<endl;
        cin >>bookname;
        in.open(bookname);
    }
    char show[200];
       while (!in.eof()){
        in.getline (show,200);
        cout <<show<<endl;
    }
    in.close();
    
    
}
void database::research(){
	cout<<"Please enter the key word"<<endl;
	char key[20];
	char*p;
	int g=0;
	cin>>key;
	char SHOW[50];
	char show[500];
	ifstream in("booknames");
	while(!in.eof()){
		in.getline(SHOW,50);
		if(strstr(SHOW,key)!=NULL){
			g=1;
			cout<<"The book you want to find is "<<SHOW<<endl;
			ifstream iin(SHOW);
			while(!iin.eof()){
				iin.getline(show,500);
				cout<<show<<endl;
			}
			iin.close();
			break;
		}
	}
	if(g==0)	
	cout<<"no find the key";
	in.close(); 
}
database::database(char *bookname)
{
	strcpy(name,bookname);
}
database::~database()
{

}
class ebook 
{
public:
    ebook(char *bookname);
    void set_author(char *bookname);
    ~ebook();
private:
    char author[50];
    char name[50];
};
void ebook::set_author(char *bookname){
    ofstream out("booknames");
    out<<bookname<<endl;
    out.close();
    ofstream enter(bookname);
    enter<<"EBOOK"<<endl;
    enter <<bookname<<endl;
    cout<<"Please enter the author of this book."<<endl;
    cin>>author;
    enter<<"Author:"<<author<<endl;
    cout <<"Please enter the content of the ebook:"<<endl;
    char content[10000];
    getchar();
    cin.getline (content,10000);
    enter<<content<<endl;
    enter.close();
    cout <<"Set successfully!"<<endl;
}
ebook::ebook(char *bookname)
{	
	strcpy(name,bookname);
}
ebook::~ebook()
{

}
class paper
{
public:
    paper(char *bookname);
    void set_paper(char *bookname);
    ~paper();
private:
    char number[20];
    char authors[50];
    char title[50];
    char magazine[50];
    char date[50];
    char name[50];
};
void paper::set_paper(char *bookname){
    ofstream out("booknames");
    out<<bookname<<endl;
    out.close();
    ofstream enter(bookname);
    enter <<bookname<<endl;
    enter <<"PAPER"<<endl;
    cout<<"Please enter the authors of this paper."<<endl;
    cin>>authors;
    enter<<"Authors:"<<authors<<endl;
    cout<<"Please enter the issue date of this paper."<<endl;
    cin>>date;
    enter<<"Date:"<<date<<endl;
    cout<<"Please enter the magazine of this paper."<<endl;
    cin>>magazine;
    enter<<"Magazine:"<<magazine<<endl;
    cout<<"Please enter the title of this paper."<<endl;
    cin>>title;
    enter<<"Title:"<<title<<endl;
    cout<<"Please enter the number of this paper."<<endl;
    cin>>number;
    enter<<"Number:"<<number<<endl;
    cout<<"Please enter the content of this paper."<<endl;
    char content[10000];
    getchar();
    cin.getline(content,10000);
    enter<<content<<endl;
    enter.close();
}
paper::paper(char *bookname)
{
	strcpy(name,bookname);
}
paper::~paper()
{

}
class user 
{
public:
    user(char *bookname);
    void book_borrow(char *bookname);
    void book_return(char *bookname);
    void book_read(char *bookname);
    void log_in();
    void user_delete();
    ~user();
private:
    char ID[20];
    char password[20];
    char name[50];
};
void user::book_borrow(char *bookname){
    ifstream in(bookname);
    while(!in){
        cout <<"The book you want to find is not exist!"<<endl;
        cout <<"Please enter the book again:"<<endl;
        cin >>bookname;
        in.open(bookname);
    }
        char statusnew[200];
        in.getline(statusnew,200);
        if (strcmp(statusnew,"The book you want to find is aviliable!")==0){
            cout<<"You can borrow this book!"<<endl;
            ofstream inn("copybook");
            inn<<"The book is in "<<ID<<"'s hand."<<endl;
            while (!in.eof())
            {
                in.getline(statusnew,200);
                inn<<statusnew<<endl;
            }
            in.close();
            inn.close();
            remove(bookname);
            rename("copybook",bookname);
            cout <<"Borrow it successfully!"<<endl;
        }else{
            cout<<"You cannot borrow this book!"<<endl;
        }
}
void user::book_return(char *bookname){
    ifstream enter(bookname); 
    while(!enter){
        cout <<"The book is not exist!"<<endl;
        cout <<"Please enter the book again:"<<endl;
        cin >>bookname;
        enter.open(bookname);
    }
    enter.close();
    ofstream in ("copy");
    in <<"The book you want to find is aviliable!"<<endl;
    ifstream inn(bookname);
    char con [200];
    inn.getline(con,200);
    while (!inn.eof()){
        inn.getline(con,200);
        in<<con<<endl;
    }
    in.close() ;
    inn.close();
    remove(bookname);
    rename("copy",bookname);
    cout<<"You have returned it successfully!"<<endl;
}
void user::book_read(char *bookname){
	ifstream in (bookname);
    while(!in){
        cout <<"The book you want to read is not exist!"<<endl;
        cout <<"Please enter the book again:"<<endl;
        cin >>bookname;
        in.open(bookname);
    }
    char show[200];
    while (!in.eof()){
        in.getline (show,200);
        cout <<show<<endl;
    }
    in.close();
}
void user::log_in(){
    cout <<"Please enter your ID:"<<endl;
    cin >>ID;
    ifstream in (ID);
    while(!in){ 
        cout <<"The ID is not exist!"<<endl;
        cout <<"Please enter the ID again:"<<endl;
        cin >>ID;
         in.open(ID) ;
    }
    cout <<"Please enter your password:"<<endl;
    cin >>password;
    char con[50];
    in.getline(con,50);
    in.getline(con,50);
    while (strcmp(password,con)!=0){
        cout <<"Please check your password!"<<endl;
        cin >>password;
    }
    cout <<"Welcome back "<<ID<<endl;
}
void user::user_delete(){
        cout<<"We will check your accont for security!"<<endl;
        cout<<"ID:"<<endl;
        cin>>ID;
        ifstream in (ID);
        while(!in){
            cout <<"The ID is not exist!"<<endl;
            cout <<"Please enter the ID again:"<<endl;
            cin >>ID;
            in.open (ID);
        }
        cout<<"Password:"<<endl;
        cin>>password;
        char pass[50];
        in.getline (pass,50);
        in.getline (pass,50);
        in.close();
        if(strcmp(pass,password)==0){
            if(remove(ID)==0)
            {
                cout<<"Successfully delete!"<<endl;
            }
            else
            {
                cout<<"Failed to delete!"<<endl;
            }  
        }else{
            cout<<"You cannot delete this account!"<<endl; 
        }
}
user::user(char *bookname)
{
	strcpy(name,bookname);
}
user::~user()
{

}
class useradministrator
{
public:
    useradministrator(char *username);
    void add_user(char *username);
    //void update_user();
    void delete_user(char *username);
    ~useradministrator();
private:
    char username[50];
    char password[50];
};
void useradministrator::add_user(char *username){
    ofstream enter (username);
    enter<<"user:"<<username<<endl;
    cout<<"Please enter your password:";
    cin>>password;
    enter<<password<<endl;
    enter.close();
}
void useradministrator::delete_user(char *username){
	 
    if(remove(username)==0)
    {
        cout<<"Successfully delete!"<<endl;
    }
    else
    {
        cout<<"Failed to delete!"<<endl;
    }
}
useradministrator::useradministrator(char *username)
{
}
useradministrator::~useradministrator()
{
}
int main(int argc, char *argv[])
{   
    int a,b;
    char password[50];
    ifstream in("booknames"); 
    if(!in){ 
    	ofstream out("booknames");
		out.close();	
	}
    else in.close();

    cout <<"Welcome to use this system!"<<endl;
    cout <<"Please choose your identity:"<<endl;
    cout <<"Please enter '1' for user,and '0' for administrator:"<<endl;
    cin >>a;
    while(a!=1&&a!=0){
        cout <<"You get the wrong number!"<<endl;
        cout <<"Please enter '1' for user,and '0' for administrator:"<<endl;
        cin >>a;
    }
    if (a==0){
        
       
       
        cout <<"hello,administrator."<<endl;
        cout <<"Please choose what you want to do."<<endl;
        cout <<"If you want to enter the book,choose 1."<<endl;
        cout <<"If you want to delete the book,choose 2."<<endl;
        cout <<"If you want to read the book,choose 3."<<endl;
        cout <<"If you want to search the book,choose 4."<<endl;
        cout <<"If you want to delete the user,choose 5."<<endl;
        cout <<"******************************************************************"<<endl; 
        int num;
        cin>> num;
        while(num!=1&&num!=2&&num!=3&&num!=4&&num!=5){
        		
                cout<<"You get the wrong number!"<<endl;
                cout<<"Please enter the number again:"<<endl;
                cin>>num;
        }
        switch(num){
            case 1:
                cout <<"If it is a paper-book,choose 1."<<endl;
                cout <<"If it is an ebook,choose 2."<<endl;
                cout <<"If it is a paper,choose 3."<<endl;
                cin >>a;
                while(a!=1&&a!=2&&a!=3){
                     cout<<"You get the wrong number!"<<endl;
                     cout<<"Please enter the number again:"<<endl;
                     cin>>a;
                }
                if (a==1){
                	cout <<"Please enter the book name:"<<endl;
    				char bookname[50];
    				cin >>bookname;
    				book mybook(bookname);
                    mybook.set_book(bookname);
                }else if (a==2){
                	cout <<"Please enter the bookname:"<<endl;
    				char bookname[50];
   					cin >>bookname;
   					ebook myebook(bookname);
                   	myebook.set_author(bookname);
                }else if (a==3){
                	cout <<"Please enter the paper name:"<<endl;
   					char bookname[50];
    				cin >>bookname;
    				paper mypaper(bookname);
                    mypaper.set_paper(bookname);
                }
                break;
            case 2:
			{
            	cout <<"Please enter the book you want to delete:"<<endl;
    			char bookname[50];
    			cin >>bookname;
    			database mydatabase(bookname);
                mydatabase.deletecontent(bookname);
				break;
			}	
            case 3:
			{
            	cout <<"PLease enter the book you want to view:"<<endl;
   				char bookname[50];
   				cin >>bookname;
   				database mydatabase(bookname);
                mydatabase.viewcontent(bookname);
                break;
			}
            case 4:
			{
            	char bookname[50];
            	database mydatabase(bookname);
            	mydatabase.research();
				break;
			}
            case 5:
            	cout<<"Please enter the user you want to delete:";
            	char username[50];
				cin>>username;
            	useradministrator myuseradministrator(username);
                myuseradministrator.delete_user(username);
                break;
        }
    }else{
        cout <<"If you have an account,please enter '1',"<<endl;
        cout <<"If you want to create  a new account,please enter'0'."<<endl;
        cin >>b;
        cout <<"******************************************************************"<<endl; 
        while (b!=0&&b!=1){
            cout <<"You get the wrong number!"<<endl;
            cout <<"If you have an account,please enter '1',"<<endl;
            cout <<"If you want to create  a new account,please enter'0'."<<endl;
            cin >>b;
            cout <<"******************************************************************"<<endl; 
        }
        if (b==0){
        	char username[50];
        	cout<<"Please enter your name:";
    		cin>>username;
    		useradministrator myuseradministrator(username);
            myuseradministrator.add_user(username);
        }else{
        	char bookname[50];
        	user myuser(bookname);
            myuser.log_in();
        }
        cout <<"******************************************************************"<<endl; 
        cout<<"If you want to read the book,choose 1;"<<endl;
        cout<<"If you want to borrow the book,choose 2;"<<endl;
        cout<<"If you want to return the book,choose 3;"<<endl;
        cout<<"If you are not quite sure with the book name,you can search the book by choosing 4;"<<endl;
        cout<<"If you want to delete your account,choose 5;"<<endl;
        cin >>a;
        while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5){//??????? 
            cout<<"You get the wrong number!"<<endl;
            cout<<"Please enter the number again:"<<endl;
            cin>>a;
        }
        switch (a){
            case 1:
   			{
   				cout <<"PLease enter the book you want to read:"<<endl;
    			char bookname[50];
    			cin >>bookname;
    			user myuser(bookname);
                myuser.book_read(bookname);
                break;	
			}
            case 2:
            {
            	cout <<"Please enter the book you want to borrow:"<<endl;
    			char bookname[50];
    			cin >>bookname;
    			user myuser(bookname);
                myuser.book_borrow(bookname);
                break;
			}
            case 3:
            {	
				cout <<"PLease enter the book you want to return:"<<endl;
    			char bookname[50];
   				cin >>bookname;
   				user myuser(bookname);
                myuser.book_return(bookname);
                break;
			}
            case 4:
			{	
				char bookname[50];
            	database mydatabase(bookname);
            	mydatabase.research();
				break;
			}
            case 5:
    		{	
    			char bookname[50];
				user myuser(bookname);
    			myuser.user_delete();
                break;
			}
        }
    }
    cout <<"******************************************************************"<<endl; 
    return 0;
} 



