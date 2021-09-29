#include<iostream>
#include<vector>
using namespace std;

/*
    1、元素在数组中
    2、元素不在数组中
        2-1、元素需要插入最前面
        2—2、元素需要插入到最后面
        2-3、元素插入数组中间
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1; //左闭右闭
        int mid;
        while (left<=right)
        {
            mid = left + ((right - left) / 2);  //防止溢出
            if(nums[mid]==target)
            {
                return mid;//找到了pos
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid -1;
            }
        }
        return right+1; //元素targrt插入的pos
    }
};

int main()
{
    vector<int> a = {1,3,5,6};
    int x;
    cin>>x;
    Solution sol;
    cout<<sol.searchInsert(a,x);
    
    return 0;
}
