#include "rdatabase.h"

rdatabase::rdatabase()
{
    reader b;
    top=-1;
    fstream rfile("D//library//reader.txt", ios::in);    //打开文件
    while (1)
    {
     rfile.read((char *)&b, sizeof(b));
     if (!rfile) break;
     top++;
     rtarray[top] = b;
    }
    rfile.close();     //关闭文件
}
rdatabase::~rdatabase()
{
    fstream file("D//library//reader.txt", ios::out);
      for (int i = 0; i <top; i++)
      {
        if(i==delereader) break;
        file.write((char *)&rtarray[i], sizeof(rtarray[i]));
      }
      file.close();
}
reader *rdatabase::addraeders()
{
    int a;
    string i;
    string c;
    string d;
    cout<<"are you the administrator? Y(0) or N(1)"<<endl;
    cin>>a;
    cout<<"please input your id:"<<endl;
    cin>>i;
    cout << "please input your name:" << endl;
    string Name;
    cin >> Name;
    while(1)
    {
        cout<<"please input your code:"<<endl;
        cin>>c;
        cout<<"please input your code again:"<<endl;
        cin>>d;
        if(c==d)
        {
            cout<<"code set successfully!"<<endl;
            break;
        }
        else
        {
            cout<<"the two code is diffierent!"<<endl;
            cout<<"please try again"<<endl;
        }
    }

    top++;
    rtarray[top].addreader(i,c,Name,a);
    return &(rtarray[top]);

}


reader *rdatabase::check(string name,string code,string id)
{
   for(int i=0;i<top;i++)
   {

     if(rtarray[i].getcode()==code&&rtarray[i].getname()==name&&rtarray[i].getid()==id)
      {
         return &(rtarray[i]);
      }
    }
    return NULL;
}
reader *rdatabase ::identity()
{
    reader *an;
    string a;
    string b;
    string c;
    cout<<"please input your id:"<<endl;
    cin>>a;
    cout<<"please input your name:"<<endl;
    cin>>b;
    cout<<"please input your code:"<<endl;
    cin>>c;
    an=check(b,c,a);
    if(an==NULL)
    {
        cout<<"error!the code or the id is wrong!"<<endl;
        return NULL;
    }
    else
    {
        cout<<"successfully"<<endl;
        return  an;
    }
}
void rdatabase::deletreadrs(string nam)
{
    for(int i=0;i<top;i++)
    {
        if(rtarray[i].getname()==nam)
        delereader=i;
     return;
    }
}

