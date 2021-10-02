#include<iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length()-1;
        int j = T.length()-1;
        int skipS = 0,skipT = 0;

        while (i>=0 || j>=0)
        {
            //判断S串
            while(i>=0)
            {
                if(S[i]=='#') //如果为#
                { 
                     skipS++; //数量自增
                     i--;
                }
                else if(skipS > 0)
                {
                    skipS--; //数量自减
                    i--;
                }
                else{ //如果不为“#”且skipS为0,
                    break;//跳出小循环，在大循环中与S比较
                }
            }
            
            //判断T串
            while(j>=0)
            {
                if(T[j]=='#') //如果为#
                { 
                     skipT++; //数量自增
                     j--;
                }
                else if(skipT > 0)
                {
                    skipT--; //数量自减
                    j--;
                }
                else{ //如果不为“#”且skipT为0,
                    break;//跳出小循环，在大循环中与T比较
                }
            }

            if (i>=0 && j>=0)
            {
                if (S[i]!=T[j])
                {
                    return false;
                }
                
            }
            else
            {
                if (i>=0 || j>=0)
                {
                    return false;
                }
                
            }
            i--;
            j--;
            
        }
        
        return true;
    }
};


int main()
{
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";
    if (sol.backspaceCompare(s,t))
    {
        cout<<"true";
    }
    
    return 0;
}