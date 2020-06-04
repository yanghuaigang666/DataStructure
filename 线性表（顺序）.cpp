#include<stdio.h>
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; 


typedef int ElemType;
#define MaxSize 20
typedef struct
{
	ElemType data[MaxSize]; //数组存储 
	int length; //线性表长度 
}SqList;

//初始化线性表
Status InitList(SqList *L) 
{
	L->length=0;
	return OK;
}

//判断是否为空表
Status isEmpty(SqList *L)
{
	if(L->length==0)
		return TRUE;
	else
		return FALSE;
}

//返回列表长度
int ListLength(SqList L)
{
	return L.length;	
} 

//获取第i个位置的元素值 
//用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始
Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1]; //e保存的是元素值 
	return OK;	
} 

//查找e数据元素所在的位置 
int Find_pos(SqList L,ElemType e)
{
	int i; 
	if(L.length==0)
		return 0; //不存在，返回0 
	for(i=0;i<L.length;i++)
	{
		if(L.data[i]==e)
			break;
	}
	return i+1; //返回位置i+1 
} 

//第i个位置插入数据元素e
void Insert(SqList *L, int i, ElemType e)
{
	int j;
	//校验
	if(L->length == MaxSize)
	{
		printf("线性表已满");
		return;
	}
	if(i<1 || i>L->length+1)
	{
		printf("插入位置不符合");
		return;
	}
	
	if(i<=L->length) //插入的位置不在表尾
	{
		for(j=L->length-1;j>=i-1;j--) 
			L->data[j+1] = L->data[j];
	} 
	L->data[i-1] = e;
	L->length++;
	return;
} 


//删除L的第i个数据元素，并用e返回其值，L的长度减1
void Delete(SqList *L,int i)
{
	if(L->length==0)
	{
		printf("表为空\n");
		return;
	}
	if(i<1 || i>L->length)
	{
		printf("位置不符合\n");
		return;
	}

	if(i<L->length)
	{
		for(int k=i;k<L->length;k++)
			L->data[k-1] = L->data[k];	
	} 
	L->length--;

} 

//遍历线性表
void Traverse(SqList L)
{
	for(int i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");	
} 

//合并两张线性表
void union_L(SqList *La,SqList Lb) 
{
	int La_len,Lb_len;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for(int i=1;i<=Lb_len;i++)
	{
		//获取Lb第i个位置上的元素e
		GetElem(Lb,i,&e);
		//插入到表a的后面
		Insert(La,++La_len,e);
	}
}
int main()
{
	SqList L,Lb;
	Status i;
	ElemType e;
	
	i = InitList(&L);
	printf("%d\n",i);
	printf("初始化L后：L.length=%d\n",L.length);
	
	for(int j=1;j<=5;j++)
		Insert(&L,1,j);
		
	printf("插入数据后：L.length=%d\n",L.length);
	printf("L是否为空(1：是，0：否)%d\n",isEmpty(&L));
	Traverse(L);
	
	printf("%d\n",Find_pos(L,2));
	GetElem(L,1,&e);
	printf("%d\n",e);
	
	
	Delete(&L,6);
	printf("删除一个数据后：L.length=%d\n",L.length);
	Traverse(L);
	
	
	InitList(&Lb);
	for(int j=6;j<=15;j++)
		Insert(&Lb,1,j);
	Traverse(Lb);
	
	union_L(&L,Lb);
	Traverse(L);
	
	return 0;
}



