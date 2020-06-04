#include<stdio.h> 
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int top; //ջ��ָ�� 
}SqStack;

//����һ����ջS
int InitStack(SqStack *S)
{
	S->top=-1;
	return 1;
} 

//�ж��Ƿ�Ϊ�� 
int isEmpty(SqStack S)
{
//	if(S.top==-1)
//		return 1;
//	else
//		return 0;
	return (S.top==-1);
}

//��ȡջ�ĳ��� 
int getLength(SqStack S)
{
	return S.top+1;
}

//��ȡջ��Ԫ�أ���ջ��Ԫ�ر��浽e��
void GetTop(SqStack S,ElemType *e)
{
	if(S.top==-1)
		return;
	else
		*e = S.data[S.top];
} 

//��ջ 
void Push(SqStack *S,ElemType e)
{
	if(S->top == MAXSIZE-1)  //�ж�ջ�� 
		return;
//	S->top++;
//	S->data[S->top]=e; 
	S->data[++(S->top)]=e;
} 

//��ջ 
void Pop(SqStack *S,ElemType *e)
{
	if(S->top==-1)
		return;  //�ж�ջ��
//	*e = S->data[S->top];
//	S->top--; 
	*e = S->data[(S->top)--];
} 

//����ջ����ջ�׵�ջ��
void Traverse(SqStack S)
{
	int i=0;
	while(i<=S.top)
	{
		printf("%d ",S.data[i++]);
	}
	printf("\n");
} 

int main()
{
	SqStack s;
	int e;
	if(InitStack(&s))
		for(int i=1;i<=10;i++)
			Push(&s,i);
	Traverse(s);
	GetTop(s,&e);
	printf("ջ��Ԫ��%d\n",e);
	Pop(&s,&e);
	printf("��ջ��Ԫ��Ϊ%d\n",e);
	Traverse(s);
	printf("�������ȣ�%d\n",getLength(s));
	printf("---->%d",isEmpty(s));
	return 0;
} 

