#include<iostream>
#define MAXK 10
using namespace std;
//从1-n中取k个数的全排列
int n,k;
int a[MAXK];  //存储全排列组合，默认为递增序列

void display()
{
    for (int i = 0; i < k; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

void display1(int *a,int n)
{
    for (int i = 0; i < n-1; i++)
    {
        cout<<a[i];
    }
    cout<<a[n-1]<<" ";
    
}


void comb(int n,int k)
{
    if(k==0)
        display();
    else
    {
        for (int i = k ; i <= n; i++)
        {
            a[k-1] = i;//k-1的位置只能取k~n
            comb(i-1,k-1);//从剩下的k-1个数中取值，范围为0~i-1
        }
        
    }
}

void swap(int x,int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void dfs(int a[],int n,int i)
{
    if(i>=n)
        display1(a,n);
    else
    {
        for (int j = i; j < n; j++)
        {
            swap(a[i],a[j]);
            dfs(a,n,i+1);
            swap(a[i],a[j]);
        }
        
    }
}

int main()
{
    n = 5;
    k = 3;
    int b[] = {1,2,3};
    int x = sizeof(b) / sizeof(b[0]); 
    dfs(b,x,0);
    return 0;
}