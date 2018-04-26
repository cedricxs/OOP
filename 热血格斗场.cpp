#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class beater
{
    public:
    beater(int time,int _force):num(time),force(_force){};
int num;
int force;
~beater(){
    cout<<"destructor";
    delete &num;
    delete &force;}
};
int enterevent(vector<beater*>&b)
{
vector<beater*>::iterator it; 
int t=1000000000;beater *last=b[b.size()-1];
for(it=b.begin();it!=b.end()-1;it++)
{
   beater* temp=*it;
   if(t>abs(temp->force-last->force))
   t=abs(temp->force-last->force);

}
return t;
}
int chongfu(vector<beater*>&b,int t)
{
    vector<beater*>::iterator it; beater *last=b[b.size()-1];int res;
for(it=b.begin();it!=b.end();it++)
{
   beater* temp=*it;
   if(t==abs(temp->force-last->force))
   {res=it-b.begin();
   if(last->force>temp->force)
    {   
     break;
   }}
}
return res+1;
}
int main()
{
int num=1;int _force;int time;cin>>time;
vector<beater*> b;
beater*facer=new beater(num,1000000000);
b.push_back(facer);
while(time--)
{
cin>>num>>_force;
beater*p=new beater(num,_force);
b.push_back(p);
int t= enterevent(b);
int res=chongfu(b,t);
cout<<num<<" "<<res<<endl;
}


}

