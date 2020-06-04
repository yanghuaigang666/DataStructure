#include<stdio.h>
#define MaxSize 20
//��ջ����ռ�洢�ṹ
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top1;//ջ1ջ��ָ�� 
	int top2;//ջ2ջ��ָ�� 
}SqDoubleStack;

//����һ���յĹ���ջ 
void InitDoubleStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MaxSize;
}

//�ж��Ƿ�Ϊ��
int isEmpty(SqDoubleStack S)
{
	if(S.top1==-1 && S.top2==MaxSize)
		return 1;
	else
		return 0;
} 

//��ȡջ�ĳ���
int getLength(SqDoubleStack S)
{
	return (S.top1+1)+(MaxSize-S.top2);
} 

//��ջ
void Push(SqDoubleStack *S,ElemType e,int stackNum)
{
	//�ж��Ƿ�ջ��
	if(S->top2 == S->top1+1)
	{
		printf("ջ��\n");
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
		printf("ջ�Ŵ���\n");
}

//��ջ
void Pop(SqDoubleStack *S,ElemType *e, int stackNum)
{
	if(stackNum == 1)
	{
		if(S->top1==-1)
		{
			printf("ջ1Ϊ��ջ\n");
			return;
		}
		*e = S->data[(S->top1)--];
	}
	else if(stackNum ==2)
	{
		if(S->top2==MaxSize)
		{
			printf("ջ2Ϊ��ջ\n");
			return;
		}
		*e = S->data[(S->top2)++];
	}
}

//����ջ 
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

//��ȡջ��Ԫ��
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
	printf("ջ�ĳ���Ϊ%d\n",getLength(s));
	GetTop(s,&e,1);
	printf("ջ1��ջ��Ԫ��Ϊ%d\n",e);
	GetTop(s,&e,2);
	printf("ջ2��ջ��Ԫ��Ϊ%d\n",e);
	Pop(&s,&e,1);
	printf("ջ1�ĳ�ջԪ��Ϊ%d\n",e);
	Pop(&s,&e,2);
	printf("ջ2�ĳ�ջԪ��Ϊ%d\n",e);
	Traverse(s);
	return 0;
}




 

