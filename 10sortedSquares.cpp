#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> //pow(nums[i],2)
using namespace std;

class Solution {
public:
    vector<int> sortedSquares1(vector<int>& nums) {
        /*
        暴力法
        */
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(),ans.end());

        return ans;
        
    }

    vector<int> sortedSquares(vector<int>& nums) {
        /*
            双指针：考虑到数组为非递减排序,可以先找到负数和非负数的分界线neg，然后分别进行比较
        */
        vector<int> ans;
        int size = nums.size();
        int neg = -1; //初始化分界线为-1
        for (int i = 0; i < size; i++)
        {
            if(nums[i] < 0)
                neg = i;
            else
                break;
        }
        cout<<neg<<endl;

        int i = neg; //用于负数遍历
        int j = neg + 1; //用于非负数遍历
        while (i >= 0 || j < size) {
            if (i < 0) {//边界i
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
            else if (j == size) {//边界j
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }
        return ans;
        
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {-11,-4,-1,0,3,10};
    nums = sol.sortedSquares(nums);
    vector<int> :: iterator it;
    for (it = nums.begin(); it!=nums.end(); it++)
    {
        cout<<*it<<" ";
    }
    
    
    return 0;
}