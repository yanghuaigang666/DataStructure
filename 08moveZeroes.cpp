#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //双指针 模拟
    void moveZeroes1(vector<int>& nums) {
        int size = nums.size();
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex <size ; fastIndex++)
        {
            if(nums[fastIndex]!=0) //先把不为0的元素提前到数组前面
            {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        while (slowIndex<size) //从slow位置，设置后面元素全为0
        {
            nums[slowIndex++] = 0;
        }
        
        for (int i = 0; i < size; i++)
        {
            cout<<nums[i]<<" ";
        }
        
        
    }

    //双指针 交换元素的方法
    void moveZeros(vector<int>& nums){
        int size = nums.size();
        int slow = 0, fast = 0;
        while (fast<size)
        {
            if(nums[fast]!=0)
            {
                swap(nums[slow],nums[fast]);
                slow++;
            }
            fast++;
        }
        
    }
};

int main()
{
    Solution sol;
    vector <int> num = {0,1,0,3,12};
    sol.moveZeros(num);
    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    
    return 0;
}