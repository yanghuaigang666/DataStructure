#include<stdio.h>
/*ѡ������0,1��...i,i+1,.....n-1 
��0��i������б�������ģ���i��n-1��ѡ��һ����С�Ĳ��뵽ǰ���б���
*/
void SelectionSort(int List[], int n)
{
	for(int i=0;i<n;i++)
	{
		MinPosition = ScanForMin(List,i,n-1);  //ScanForMin()ɨ���i��n-1����Сֵ��λ��
		add(List[i],List[MinPosiion]);	 //��δ�����б�����СԪ����ӵ������б���� 
	}	
} 
