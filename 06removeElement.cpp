#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(val != nums[i])
                nums[j++] = nums[i]; //将不相等的元素重新赋值
                
        }
        return j; //返回最后赋值位置
        
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int len = sol.removeElement(nums,val);
    // cout<<len;
    for (int i = 0; i < len; i++)
    {
        cout<<nums[i]<<" ";
    }
    
 
    return 0;
}
