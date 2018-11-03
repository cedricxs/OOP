#include<iostream>
#include<string>
using namespace std;
string e[11]={"zero","one","two","three","four","five","six","seven","eight","nine","double"};
int ee[11]={4,3,3,5,4,4,3,5,5,4,6};
string c[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int cc[10]={4,2,2,3,2,2,3,2,2,3};
bool isenglish(string x)
{
int pos;
for(int i=0;i<11;i++)
    {pos=x.find(e[i]);
    while(pos!=string::npos)
    {
    x.erase(pos,ee[i]);
    pos=x.find(e[i]);
    } 
    }
if(x.empty())return true;
else return false;    
} 
bool ischinese(string x)
{
int pos;
for(int i=0;i<10;i++)
    {pos=x.find(c[i]);
    while(pos!=string::npos)
    {
    x.erase(pos,cc[i]);
    pos=x.find(c[i]);
    } 
    }
if(x.empty())return true;
else return false;  
}
int main()

{
string x;
cin>>x;string r;bool isd=false;
if(isenglish(x)&&ischinese(x)) {cout<<"ERROR"<<endl;return 0;}
if(isenglish(x)==false&&ischinese(x)==false){cout<<"ERROR";return 0;}
if(isenglish(x)) 
  while(x.length()>0)
{
    int p;
    if(x[0]=='o')p=1;
    if(x[0]=='t'&&x[1]=='w')p=2;
    if(x[0]=='t'&&x[1]=='h')p=3;
    if(x[0]=='f'&&x[1]=='o')p=4;
    if(x[0]=='f'&&x[1]=='i')p=5;
    if(x[0]=='s'&&x[1]=='i')p=6;
    if(x[0]=='s'&&x[1]=='e')p=7;
    if(x[0]=='e')p=8;
    if(x[0]=='n')p=9;
    if(x[0]=='z')p=0;
    if(x[0]=='d'){x.erase(0,6);isd=true;continue;}
    if(isd==false)r+=c[p];
    else {r+=c[p];r+=c[p];isd=false;}
    x.erase(0,ee[p]);
  }
else
  while(x.length()>0) 
  {int p;
    if(x[0]=='y')p=1;
    if(x[0]=='e')p=2;
    if(x[0]=='s'&&x[1]=='a')p=3;
    if(x[0]=='s'&&x[1]=='i')p=4;
    if(x[0]=='w')p=5;
    if(x[0]=='l'&&x[2]=='u')p=6;
    if(x[0]=='q')p=7;
    if(x[0]=='b')p=8;
    if(x[0]=='j')p=9;
    if(x[0]=='l'&&x[2]=='n')p=0;
    r+=e[p];
    x.erase(0,cc[p]);
  }
  cout<<r;
return 0;
}
