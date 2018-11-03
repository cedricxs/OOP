#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1,class T2>
class Closer {
// 在此处补充你的代码
public:
T1 x;T2 y;
Closer(T1 a,T2 b):x(a),y(b){}
bool operator()(T1 _a,T1 _b)
{
if((*y)(x,_a)==(*y)(x,_b))return _a<_b;
return (*y)(x,_a)<(*y)(x,_b);
}
};
int Distance1(int n1,int n2) {
    return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
    return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
    int n;string s;
    while( cin >> n >> s ) {
        sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
        for(int i = 0;i < 10; ++i)
            cout << a[i] << "," ;
        cout << endl;
        sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2)); 
        for(int i = 0;i < 6; ++i)
            cout << b[i] << "," ;
        cout << endl;
    }
    cin>>n;
    return 0;
}
/*Input
多组数据
每组数据一行
一个整数n和一个字符串s
Output
对每组数据，输出两行
第一行，按到n的距离(元素与n的差值)为序将a数组中元素排序输出第二行，按到s的距离(元素长度与s长度的差值)为序将b数组中元素排序输出
Sample Input 1 
4 jfaksldfj
Sample Output 1
4,3,1,7,0,8,9,10,15,20,
123456789,American,Peking,Jack,To,abcdefghijklmnop,*/
