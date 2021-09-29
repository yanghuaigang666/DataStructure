#include<iostream>
#include<cmath>
using namespace std;

// class Solution {
// public:
//     int mySqrt(int x) {
//         return (int)sqrt(x);
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
       int left = 0;
       int right = x;
       int mid;
       if(x == 0 || x == 1)
            return x;
       while (left<=right)
       {
           mid = left + ((right - left) / 2);
           if(mid > x / mid)
           {
               right = mid - 1;
           }
           else if( mid < x / mid)
           {
               left = mid +1;
           }
           else
            {
                return mid;
            }
       }
       return right;
       
    }
};

int main()
{
    Solution sol;
    cout<<sol.mySqrt(15000000);
    return 0;
}