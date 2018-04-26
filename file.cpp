#include<fstream>
#include<iostream>
using namespace std;          //打开文件->读/写文件->关闭文件
int main()
{int x=46;
ofstream outfile("1.txt",ios::out|ios::binary);
outfile.write((const char*)(&x),sizeof(int));    //write
ifstream in("1.txt");                             
in.seekg(0,ios::beg);
char y;
in.read(&y,sizeof(int));               //在0字节处读取sizeof（int）大小字节的数存于y中；但读取的形式是字符型；
cout<<x;
int j;
cin>>j;
in.close();                                 //只有当文件close时，才会真正讲数据写入；否则不
}
