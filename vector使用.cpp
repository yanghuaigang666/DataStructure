#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    //1、基本操作
    vector<int> test;
    for (int i = 0; i < 10; i++)
    {
        test.push_back(i);  //添加数据到向量容器test中
        cout<<test[i]<<",";
    }

    for (int i = 0; i < 5; i++)
    {
        test.pop_back(); //去掉数组中的最后一个元素
    }
    cout<<endl;

    for (int i = 0; i < test.size(); i++)
    {
        cout<<test[i]<<" ";
    }
    cout<<endl;
    /* 
        test.clear(); //清空数组
    */

    vector<int> t = {1,3,5,7,34,12}; //初始化vector
    for (int i = 0; i < t.size(); i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;

    sort(t.begin(),t.end()); //从小到大
    /*
         reverse(obj.begin(),obj.end());//从大到小 
    */
        for (int i = 0; i < t.size(); i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;


    // 2、访问数组元素
    vector<int> r;
    for (int i = 0; i < 10; i++)
    {
        r.push_back(i);
    }

    vector<int>::iterator it;  //申明一个迭代器，来访问vector容器,用来遍历访问vector中的元素
    for (it = r.begin(); it != r.end(); it++ )
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // 3、创建二维数组

    int m = 3, n = 4;
    vector<vector<int> > marix(n,vector<int>(m));  //创建一个 m * n 大小的矩阵
    for (int i = 0; i < marix.size(); i++)
    {
        for (int j = 0; j < marix[i].size(); j++)
        {
            cout<<marix[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    

    

    




    
    
    return 0;
}