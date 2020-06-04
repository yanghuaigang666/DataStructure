#include<stdio.h>
/*选择排序：0,1，...i,i+1,.....n-1 
从0到i这个子列表是有序的，从i到n-1中选择一个最小的插入到前面列表中
*/
void SelectionSort(int List[], int n)
{
	for(int i=0;i<n;i++)
	{
		MinPosition = ScanForMin(List,i,n-1);  //ScanForMin()扫描从i到n-1的最小值的位置
		add(List[i],List[MinPosiion]);	 //把未排序列表中最小元素添加到有序列表后面 
	}	
} 
