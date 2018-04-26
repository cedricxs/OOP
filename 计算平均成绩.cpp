#include<iostream>
#include<string>
using namespace std;
class student
{
    public:
    int p;
    int num;
    student():p(0){};
string name;
double agr;
double sore[100];
double fen[100];
};

ostream&operator<<(ostream&o,student&a){
    
    for(int i=0;i<a.p;i++)o<<a.name<<" "<<a.fen[i]<<" "<<a.sore[i]<<endl;
    return o;
}
void average(student&a)
{
    double sum=0;
double ff=0;
for(int i=0;i<a.p;i++){if(a.sore[i]>=60){ff+=a.fen[i];sum+=a.sore[i]*a.fen[i];}}
a.agr=sum/ff;
}

int main()
{
student c[100];string n;
double s;double f;cin>>n>>s>>f;int r;
for(r=0;r<100;r++)
{
c[r].name=n;c[r].sore[0]=s;c[r].fen[0]=f;
int i=1;
while(cin>>n>>s>>f)
{
    if(c[r].name!=n){c[r].p=i;break;}
    c[r].sore[i]=s;c[r].fen[i]=f;
i++;
}
average(c[r]);
if(n=="exit")break;
}

for(int i=0;i<r;i++)
for(int j=0;j<r;j++)
{
   if(c[j].agr<c[j+1].agr) {
       student temp=c[j+1];
      c[j+1]=c[j];
       c[j]=temp;
}}
for(int i=0;i<=r;i++)
{
c[i].num=i+1;
}
for(int i=0;i<=r;i++){
    cout<<c[i].num<<" "<<c[i].name<<" "<<c[i].agr<<endl;
}
int k;cin>>k;
}
