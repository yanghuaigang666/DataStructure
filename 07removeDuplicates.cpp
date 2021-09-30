#include<iostream>
#include<vector>
using namespace std;

class Solution1
{
private:
    /* data */
public:
    int removeDuplicates(vector<int> nums);
};

int Solution1::removeDuplicates(vector<int> nums)
{
    int j= 1;
    int n =nums.size();
    if(n==0)
        return 0;
    for (int i = 1; i < n; i++)
    {
        if(nums[i] != nums[i-1])
        {
            nums[j] = nums[i];
            j++;
            
        }
    }
    return j;
    
}


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int slow = 1;
        for (int fast = 1; fast < n; fast++)
        {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};






int main()
{
    vector<int> num = {1,2,2,3,3,3,5,6};
    Solution s;
    int len =s.removeDuplicates(num);
    cout<<len;
    for (int i = 0; i < len; i++)
    {
        cout<<num[i];
    }
    
    return 0;
}
