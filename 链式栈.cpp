#include<stdio.h> 
#include<stdlib.h>
typedef int ElemType;

//链栈存储结构 
typedef struct StackNode *Stack;
struct StackNode{
	ElemType data;
	struct StackNode *next;
};

//构建一个空栈 
Stack CreateStack()
{
	Stack S;//S指向堆栈的头结点 
	S = (Stack)malloc(sizeof(struct StackNode));
	S->next = NULL; //头结点S其实就是栈顶指针 
	return S;
} 

//判断栈是否为空
int isEmpty(Stack S)
{
	return (S->next==NULL);	//	如果为空，返回1 
} 

//入栈(与单链表的头插法相似)
void Push(Stack S,ElemType e)
{
	//链式结构，不考虑是否栈满 
	struct StackNode *p;//创建一个新节点 
	p = (struct StackNode *)malloc(sizeof(struct StackNode));
	p->data = e;
	p->next = S->next;
	S->next = p;	
} 

//出栈 
ElemType Pop(Stack S)
{
	struct StackNode *q;//声明一个要删除的节点 
	ElemType e;
	//判断栈是否为空 
	if(isEmpty(S))
	{ 
		printf("栈为空"); 
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

//获取栈的长度
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
//遍历栈 
void Traverse(Stack S)
{
	struct StackNode *p;
	p = S->next; //p指向第一个节点 
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;	
	} 
	printf("\n");
}
//获取栈顶元素 
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
	printf("栈顶元素为%d\n",GetTop(S));
	printf("出栈的元素%d\n",Pop(S));
	Traverse(S);
	printf("栈顶元素为%d\n",GetTop(S));
	printf("--->%d\n",isEmpty(S));
	printf("栈的长度%d\n",getLength(S));
	return 0;
}


