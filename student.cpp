#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class cstudent{
    public:
    cstudent(){};
    char name[20];
    int sore;
    ~cstudent(){};
};
int main()
{
cstudent c;
fstream file("student.txt",ios::binary|ios::out);                 //创建student.txt，以二进制形式，以添加方式写入；
while(cin>>c.name>>c.sore){
    if(strcmp(c.name,"exit")==0) break; 
file.write((char *)(&c),sizeof(c));                          //将类转化为字符写入sizeof（c）=24大小；20个char20字节，一个int4字节；
}
file.seekp(2*sizeof(c),ios::beg);
file.write("Mike",strlen("Mike")+1);                         //第三个student的name被Mike修改；
file.close();
fstream r("student.txt",ios::in|ios::binary);              //打开
if(!r){cerr<<"error"<<endl;}
while(r.read((char*)(&c),sizeof(c))){               //读取sizeof（c）大小字节到c中；
    int count=r.gcount();
cout<<count<<endl;
    cout<<c.name<<c.sore<<endl;                         //输出内容
}
r.close();
int j;
cin>>j;
}
