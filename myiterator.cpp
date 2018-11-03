#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
    for(; s != e; ++s,++x)
        *x = *s;
}

template<class T>
class myostream_iteraotr
{
// 在此处补充你的代码
public:
string str;
T b;
myostream_iteraotr(ostream&o,const char*a):str(a){}
T &operator *()
{
return b;
}
myostream_iterator&operator ++()
{
std::cout<<b<<str;
return *this;
}
};

int main()
{    const int SIZE = 5;
    int a[SIZE] = {5,21,14,2,3};
    double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
    list<int> lst(a,a+SIZE);
    myostream_iterator<int> output(cout,",");
    Copy( lst.begin(),lst.end(),output); 
    cout << endl;
    myostream_iterator<double> output2(cout,"--");
    Copy(b,b+SIZE,output2);
    return 0;
    
}
/*Input
无
Output
5,21,14,2,3,
1.4--5.56--3.2--98.3--3.3--
Sample Input 1 
None
Sample Output 1
5,21,14,2,3,
1.4--5.56--3.2--98.3--3.3--*/
