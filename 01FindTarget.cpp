#include<iostream>
#include<vector>
using namespace std;


//暴力法
int search_1(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)      
    {
        if(nums[i] == target)
            return i;
    }
    return -1;
}

//二分法
int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize -1;
    int mid;
    while (left<=right)
    {
        mid = (left + right)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(target < nums[mid])
        {
            right = mid -1;
        }
        else if(target > nums[mid])
        {
            left = mid +1;
        }
    }
    
    return -1;
}

//递归
// int search_recur(int* nums,int left,int right,int target)
// {
//     int mid = (left + right)/2;
//     if(nums[mid]==target)
//         return mid;
//     else if(target < nums[mid])
//     {
//         return search_recur(nums,left,mid-1,target);
//     }
//     else if(target > nums[mid])
//     {
//         return search_recur(nums,mid+1,right,target);
//     }
// }

//用c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int mid = (left + right)/2;   
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(target < nums[mid])
        {
            right = mid -1;
        }
        else if(target > nums[mid])
        {
            left = mid +1;
        }
        }
        return -1;
        
    }
};


int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int num[] = {-1,0,3,5,9,12};
    int target = 10;
    Solution solu;
    cout<<solu.search(nums,target)<<endl;
    // cout<<search_recur(num,0,6,target);

    return 0;
}