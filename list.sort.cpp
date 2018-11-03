/*priority queue练习题
Description
我们定义一个正整数a比正整数b优先的含义是： 
a的质因数数目（不包括自身）比b的质因数数目多； 
当两者质因数数目相等时，数值较大者优先级高。 
现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。
Input
第一行: num (添加元素次数，num <= 30)
下面10*num行，每行一个正整数n（n < 10000000).
Output
每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。
Sample Input 1 
1
10 7 66 4 5 30 91 100 8 9
Sample Output 1
66 5
Hint
行尾无空格*/
#include<iostream>
#include<list>
#include <algorithm>
using namespace std;
int zhiyinshumu(int m)
{
    list<int> yinzi;int t=m;
    for(int i=2;t>1&&m!=i;i++)
    {
        if(t%i==0)
        {
            yinzi.push_back(i);
            t=t/i;
            i=1;
        }
    }
    //for(list<int>::iterator ii=yinzi.begin();ii!=yinzi.end();ii++)cout<<*ii<<" ";
    yinzi.unique();
    if(yinzi.empty())return 0;
    return yinzi.size();
}
template<class T>
class judge
{
    public:
bool operator()(T m,T n){
    if(zhiyinshumu(m)==zhiyinshumu(n))return m>n;
    else return (zhiyinshumu(m)>zhiyinshumu(n));
}
};
int main()
{
int t;
cin>>t;list<int>a;
while(t--)
{
    int temp;
    for(int i=0;i<10;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    list<int>::iterator it;
    a.sort(judge<int>());
cout<<a.front()<<" "<<a.back()<<endl;
a.pop_front();a.pop_back();
//for(list<int>::iterator ii=a.begin();ii!=a.end();ii++)cout<<*ii<<" ";
}
cout<<a.size();
return 0;
}

/*template<class T>
class mycompare
{public:
    bool operator()(T m,T n)
    {
        return m<n;
    }
};
int main()
{
list<int> a;int temp;
for(int i=0;i<10;i++)
{cin>>temp;
    a.push_back(temp);
}
a.sort(mycompare<int>());
for(list<int>::iterator ii=a.begin();ii!=a.end();ii++)
cout<<zhiyinshumu(*ii)<<" ";

cin>>temp;
}
int main()
{
    cout<<zhiyinshumu(7);
    int t;cin>>t;
}*/
