#include<iostream>
#include<math.h>
using namespace std;

int main()
{
int num;cin>>num;
float n=sqrt(num);
int m=ceil(n);
int a[m][m];
for(int i=0;i<m;i++)
for(int j=0;j<m;j++)
a[i][j]=-1;
int count=1;
int i=0;int j=0;
int r=m;int l=m;
int d=0;
while(count<=num)
{
if(d==0){if(j<l){cout<<i<<j<<endl;a[i][j]=count;j++;count++;}else {d=1;i++;j--;}} 
if(d==1){if(i<r){cout<<i<<j<<endl;a[i][j]=count;i++;count++;}else {d=2;i--;j--;}}
if(d==2){if(j>=m-l){cout<<i<<j<<endl;a[i][j]=count;j--;count++;}else {d=3;j++;i--;}}
if(d==3){if(i>m-r){cout<<i<<j<<endl;a[i][j]=count;i--;count++;}else {d=0;r--;l--;i=m-r;j=m-l;}}

}

for(int q=0;q<m;q++)
   {for(int w=0;w<m;w++)
      if(a[q][w]>0&&a[q][w]<=num)cout<<a[q][w]<<'\t';
      else cout<<'\t';
    cout<<endl<<endl;}

    return 0;
}
