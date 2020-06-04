#include<stdio.h>
#include "stdlib.h" 


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

//初始化顺序表 
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));  //产生头结点，L指向头结点
	if(!(*L))
		return ERROR; //内存分配失败
	(*L)->next = NULL; //设置L为头结点，初始化线性表为空
	return OK; 
}

//判断是否为空 
Status isEmpty(LinkList L)
{
	if(L->next)	
		return FALSE;
	else
		return TRUE;
} 

//获取L的长度
int ListLength(LinkList L)
{
	int len = 0;
	LinkList p = L->next; //p指向第一个节点
	while(p)
	{
		len++;
		p=p->next;
	} 
	return len;
} 

//获取L中第i个位置数据值，用e保存
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j=1;  //计数器 
	LinkList p; //声明一节点p 
	p = L->next;//p指向第一个节点
	while(p!=NULL && j<i)
	{
		p = p->next;
		j++;	
	} 
	if(!p || j>i)	 //节点不存在条件 
		return ERROR;
	*e = p->data; //保存第i个位置的数据元素值到e 
	return OK;
} 

//查找e数据元素所在的位置 
int Find_pos(LinkList L,ElemType e)
{
	int i=0;
	LinkList p;
	p = L->next;  //p指向L的第一个节点 
	while(p)
	{
		i++;
		if(p->data==e)
			return i; //找到返回i 
		p = p->next;
	}
	
	return 0; //若这样的数据元素不存在，则返回值为0 
} 
 
//在L中第i个位置之前插入新的数据元素e 
Status Insert(LinkList *L,int i,ElemType e)
{
	int j=1;
	LinkList p,s;
	p = *L; //p指向头结点
	//1.先找到第i-1位置
	while(p && j<i)
	{
		p = p->next;
		j++;
	}
	if(!p || j>i)
	{
		return ERROR;
	}
	//2.插入s节点 
	s = (LinkList)malloc(sizeof(Node)); //生成s节点
	s->data=e;
	s->next = p->next;
	p->next = s;
	return OK; 
} 

//操作结果：删除L的第i个数据元素,e保存其值 
void Delete(LinkList *L,int i,ElemType *e)
{
	int j=1;
	LinkList p = *L; //p为头结点
	LinkList q; //q保存为要删除的节点 
	//1.找到第i个数据元素
	while(p->next && j<i) //遍历寻找第i个元素 
	{
		p = p->next;
		j++;	
	} 
	if(!(p->next) || j>i)
	{
		return;
	}
	//2.删除操作 
 	q = p->next;
 	p->next = q->next;
 	*e = q->data; //删除的数据给e 
 	free(q);  //释放q的内存空间 
}

void Traverse(LinkList L)
{
	LinkList p = L->next; //p指向第一个节点
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;	
	} 
	printf("\n");	
}

//头插法，建立带头节点的单链表L
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = i;            
		p->next = (*L)->next;    
		(*L)->next = p;						/*  插入到表头 */
	}
}

//尾插法，建立带头节点的单链表L
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r=*L;                                /* r为指向尾部的结点 */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = i;           /*  随机生成100以内的数字 */
		r->next=p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

int main()
{
	LinkList L,La,Lb;
	ElemType e;
	int pos;
	InitList(&L);
	printf("初始化L之后，L的长度=%d\n",ListLength(L));
	for(int i=1;i<=5;i++)
		Insert(&L,1,i);
	Traverse(L);
	printf("L是否为空(1：是，0：否)%d\n",isEmpty(L));

	pos = Find_pos(L,1);
	printf("%d\n",pos);
	
	GetElem(L,2,&e);
	printf("%d\n",e);
	
	Delete(&L,1,&e);
	Traverse(L);
	
	CreateListHead(&La,10);
	Traverse(La);
	CreateListTail(&Lb,10);
	Traverse(Lb);

	
}



