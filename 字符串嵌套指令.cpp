#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


bool judgeifint(string p1,string p2)
{
    int t1=atoi(p1.c_str());int t2=atoi(p2.c_str());
    int c1=0;int c2=0;
    while(t1>0)
    {
        c1++;
    t1=t1/10;
    }
     while(t2>0)
    {
        c2++;
    t2=t2/10;
    }
if(c1==p1.size()&&c2==p2.size())
return true;
else return false;
}


void fenge(vector<string>&com,string temp)
{int count =0;
for(int i=temp.length()-1;i>=0;i--)
{
if(temp[i]==' ')
{com.push_back(temp.substr(i+1,count));count=0;}
else count++;
}
com.push_back(temp.substr(0,count));
}


void myop(vector<string>&com,vector<string>&sum)
{
    if(com.size()==1&&com[0]=="printall")
        {
            for(int j=0;j<sum.size();j++)
            cout<<sum[j]<<endl;
            return ;
        }
    while(com.size()>1){
    for(int i=0;i<com.size();i++)
    {
        if(com[i]=="copy") 
        {
            string temp=sum[atoi(com[i-1].c_str())].substr(atoi(com[i-2].c_str()),atoi(com[i-3].c_str()));
        com.erase(com.begin()+i-3,com.begin()+i+1);
        com.insert(com.begin()+i-3,temp);
        break;
        }
          if(com[i]=="add") 
        {
            string p1=com[i-1];string p2=com[i-2];string temp;
            bool r=judgeifint(p1,p2);
            if(r){temp=atoi(p1.c_str())+atoi(p2.c_str());}
            else {   temp=p1+p2;  }
        com.erase(com.begin()+i-2,com.begin()+i+1);
        com.insert(com.begin()+i-2,temp);
        break;
        }
        if(com[i]=="find") 
        {string temp;
            int r=sum[atoi(com[i-2].c_str())].find(com[i-1]);
            if(r==string::npos) 
            temp=sum[atoi(com[i-2].c_str())].size();
            else temp=r;
        com.erase(com.begin()+i-2,com.begin()+i+1);
        com.insert(com.begin()+i-2,temp);
        break;
        }
        if(com[i]=="rfind") 
        {string temp;
            int r=sum[atoi(com[i-2].c_str())].rfind(com[i-1]);
            if(r==string::npos) 
            temp=sum[atoi(com[i-2].c_str())].size();
            else temp=r;
        com.erase(com.begin()+i-2,com.begin()+i+1);
        com.insert(com.begin()+i-2,temp);
        break;
        }
        if(com[i]=="insert") 
        {
        sum[atoi(com[i-2].c_str())].insert(atoi(com[i-3].c_str()),com[i-1]);     
        com.erase(com.begin()+i-3,com.begin()+i+1);
        com.insert(com.begin()+i-2,"haveinsert");
        break;
        }
        if(com[i]=="reset")
        {
            sum[atoi(com[i-2].c_str())]=com[i-1];
            com.erase(com.begin()+i-2,com.begin()+i+1);
            com.insert(com.begin()+i-2,"haveresert");
            break;
        }
        if(com[i]=="print")
        {
            cout<<sum[atoi(com[i-1].c_str())];
           com.erase(com.begin()+i-1,com.begin()+i+1);
           com.insert(com.begin()+i-1,"haveprint");
           break;
        }
        
        
    }
}
}



int main()
{
int t;
cin>>t;
vector<string> sum;
string temp;
for(int i=0;i<t;i++)   
    {
        cin>>temp;
        sum.push_back(temp);
    }
vector<string> com;
    string r;
   getline(cin,r);
    while(temp!="over")
    {  
    getline(cin,temp);   
    fenge(com,temp);
    for(int j=0;j<com.size();j++)
            cout<<com[j];  
    myop(com,sum);
    com.clear();
    }









while(1)
{
 int x;cin>>x;   
}

}
