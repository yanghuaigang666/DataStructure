#include<iostream>
#include<cmath>
using namespace std;

class Solution{
    public:
        bool isPerfectSquare(int num)
        {
            int left = 0;
            int right= num;
            int mid;
            if(num == 0 || num == 1)
                return true;
            while (left<=right)
            {
                mid = left + ((right - left) / 2 );
                if(num  > (long) mid*mid)
                {
                    left = mid + 1;
                }
                else if (num < (long)mid * mid)
                {
                    right = mid - 1;
                }
                else
                    return true;
                
            }
            return false;
            
        }
};

int main()
{
    Solution sol;
    cout<<sol.isPerfectSquare(2);
    return 0;
}