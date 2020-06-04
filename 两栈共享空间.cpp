#include<stdio.h>
#define MaxSize 20
//两栈共享空间存储结构
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top1;//栈1栈顶指针 
	int top2;//栈2栈顶指针 
}SqDoubleStack;

//构造一个空的共享栈 
void InitDoubleStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MaxSize;
}

//判断是否为空
int isEmpty(SqDoubleStack S)
{
	if(S.top1==-1 && S.top2==MaxSize)
		return 1;
	else
		return 0;
} 

//获取栈的长度
int getLength(SqDoubleStack S)
{
	return (S.top1+1)+(MaxSize-S.top2);
} 

//入栈
void Push(SqDoubleStack *S,ElemType e,int stackNum)
{
	//判断是否栈满
	if(S->top2 == S->top1+1)
	{
		printf("栈满\n");
		return;
	}
	if(stackNum==1)
	{
		S->data[++(S->top1)] = e;
	}
	else if(stackNum==2)
	{
		S->data[--(S->top2)] = e;
	}
	else
		printf("栈号错误\n");
}

//出栈
void Pop(SqDoubleStack *S,ElemType *e, int stackNum)
{
	if(stackNum == 1)
	{
		if(S->top1==-1)
		{
			printf("栈1为空栈\n");
			return;
		}
		*e = S->data[(S->top1)--];
	}
	else if(stackNum ==2)
	{
		if(S->top2==MaxSize)
		{
			printf("栈2为空栈\n");
			return;
		}
		*e = S->data[(S->top2)++];
	}
}

//遍历栈 
void Traverse(SqDoubleStack S)
{
	int i=0;
	while(i<=S.top1)
	{
		printf("%d ",S.data[i++]);
	}
	int j=S.top2;
	while(j<MaxSize)
	{
		printf("%d ",S.data[j++]);
	}
	printf("\n");
}

//获取栈顶元素
void GetTop(SqDoubleStack S,ElemType *e,int stackNum)
{
	if(stackNum==1)
	{
		if(S.top1==-1)
			return;
		*e = S.data[S.top1];
	}
	else if(stackNum==2)
	{
		if(S.top2==MaxSize)
			return;
		*e = S.data[S.top2];
	}
} 

int main()
{
	SqDoubleStack s;
	int e;
	InitDoubleStack(&s);
	for(int i=1;i<=5;i++)
		Push(&s,i,1);
	for(int i=6;i<=10;i++)
		Push(&s,i,2);
	Traverse(s);
	printf("栈的长度为%d\n",getLength(s));
	GetTop(s,&e,1);
	printf("栈1的栈顶元素为%d\n",e);
	GetTop(s,&e,2);
	printf("栈2的栈顶元素为%d\n",e);
	Pop(&s,&e,1);
	printf("栈1的出栈元素为%d\n",e);
	Pop(&s,&e,2);
	printf("栈2的出栈元素为%d\n",e);
	Traverse(s);
	return 0;
}




 

