  public:
 class array{
public:
T*data;int a;int b;
array(){}
void init(int m,int n)
{
    data=new T[m*n];
    a=m;b=n;
}

T* operator[](int n)
{
    return data+n*b;
}
operator void*()
{
return data;
}
 };
 array* p;
CArray3D(int layer,int m,int n)
{
  
    p=new array[layer];
            for(int i=0;i<layer;i++)
          p[i].init(m,n);
}

array& operator[](int n)
{
    return p[n];
}
