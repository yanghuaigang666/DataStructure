#include<stdio.h> 
#include<stdlib.h>
typedef int ElemType;

//��ջ�洢�ṹ 
typedef struct StackNode *Stack;
struct StackNode{
	ElemType data;
	struct StackNode *next;
};

//����һ����ջ 
Stack CreateStack()
{
	Stack S;//Sָ���ջ��ͷ��� 
	S = (Stack)malloc(sizeof(struct StackNode));
	S->next = NULL; //ͷ���S��ʵ����ջ��ָ�� 
	return S;
} 

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack S)
{
	return (S->next==NULL);	//	���Ϊ�գ�����1 
} 

//��ջ(�뵥�����ͷ�巨����)
void Push(Stack S,ElemType e)
{
	//��ʽ�ṹ���������Ƿ�ջ�� 
	struct StackNode *p;//����һ���½ڵ� 
	p = (struct StackNode *)malloc(sizeof(struct StackNode));
	p->data = e;
	p->next = S->next;
	S->next = p;	
} 

//��ջ 
ElemType Pop(Stack S)
{
	struct StackNode *q;//����һ��Ҫɾ���Ľڵ� 
	ElemType e;
	//�ж�ջ�Ƿ�Ϊ�� 
	if(isEmpty(S))
	{ 
		printf("ջΪ��"); 
		return NULL;
	} 
	else
	{
		q = S->next;
		S->next = q->next;
		e = q->data;
		free(q);
		return e;	
	}
}

//��ȡջ�ĳ���
int getLength(Stack S)
{
	int len=0;
	struct StackNode *p;
	p = S->next;
	while(p)
	{
		len++;
		p = p->next;	
	}	
	return len;
} 
//����ջ 
void Traverse(Stack S)
{
	struct StackNode *p;
	p = S->next; //pָ���һ���ڵ� 
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;	
	} 
	printf("\n");
}
//��ȡջ��Ԫ�� 
int GetTop(Stack S)
{
	struct StackNode *p;
	p = S->next;
	return p->data;		
} 

int main()
{	
	Stack S;
	S = CreateStack();
	for(int i=1;i<=10;i++)
		Push(S,i);
	Traverse(S);
	printf("ջ��Ԫ��Ϊ%d\n",GetTop(S));
	printf("��ջ��Ԫ��%d\n",Pop(S));
	Traverse(S);
	printf("ջ��Ԫ��Ϊ%d\n",GetTop(S));
	printf("--->%d\n",isEmpty(S));
	printf("ջ�ĳ���%d\n",getLength(S));
	return 0;
}


