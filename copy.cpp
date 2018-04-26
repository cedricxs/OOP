#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char**argv)
{char c;
    if(argc!=3){cerr<<"error"<<endl;return 0;}
fstream file(argv[1],ios::binary|ios::in);
if(!file){cerr<<"error"<<endl;return 0;}
fstream tar(argv[2],ios::binary|ios::out);
if(!tar){cerr<<"error"<<endl;return 0;}
while(file.get(c)){
    tar.write(&c,sizeof(char));
    //tar.put(c);}
}
file.close();
tar.close();
int j;
cin>>j;
}
