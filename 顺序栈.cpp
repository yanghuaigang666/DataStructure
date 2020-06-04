#include<stdio.h> 
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int top; //栈顶指针 
}SqStack;

//构造一个空栈S
int InitStack(SqStack *S)
{
	S->top=-1;
	return 1;
} 

//判断是否为空 
int isEmpty(SqStack S)
{
//	if(S.top==-1)
//		return 1;
//	else
//		return 0;
	return (S.top==-1);
}

//获取栈的长度 
int getLength(SqStack S)
{
	return S.top+1;
}

//获取栈顶元素，将栈顶元素保存到e中
void GetTop(SqStack S,ElemType *e)
{
	if(S.top==-1)
		return;
	else
		*e = S.data[S.top];
} 

//入栈 
void Push(SqStack *S,ElemType e)
{
	if(S->top == MAXSIZE-1)  //判断栈满 
		return;
//	S->top++;
//	S->data[S->top]=e; 
	S->data[++(S->top)]=e;
} 

//出栈 
void Pop(SqStack *S,ElemType *e)
{
	if(S->top==-1)
		return;  //判断栈空
//	*e = S->data[S->top];
//	S->top--; 
	*e = S->data[(S->top)--];
} 

//遍历栈，从栈底到栈顶
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
	printf("栈顶元素%d\n",e);
	Pop(&s,&e);
	printf("出栈的元素为%d\n",e);
	Traverse(s);
	printf("单链表长度：%d\n",getLength(s));
	printf("---->%d",isEmpty(s));
	return 0;
} 

