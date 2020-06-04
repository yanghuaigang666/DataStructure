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

//��ʼ��˳��� 
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));  //����ͷ��㣬Lָ��ͷ���
	if(!(*L))
		return ERROR; //�ڴ����ʧ��
	(*L)->next = NULL; //����LΪͷ��㣬��ʼ�����Ա�Ϊ��
	return OK; 
}

//�ж��Ƿ�Ϊ�� 
Status isEmpty(LinkList L)
{
	if(L->next)	
		return FALSE;
	else
		return TRUE;
} 

//��ȡL�ĳ���
int ListLength(LinkList L)
{
	int len = 0;
	LinkList p = L->next; //pָ���һ���ڵ�
	while(p)
	{
		len++;
		p=p->next;
	} 
	return len;
} 

//��ȡL�е�i��λ������ֵ����e����
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j=1;  //������ 
	LinkList p; //����һ�ڵ�p 
	p = L->next;//pָ���һ���ڵ�
	while(p!=NULL && j<i)
	{
		p = p->next;
		j++;	
	} 
	if(!p || j>i)	 //�ڵ㲻�������� 
		return ERROR;
	*e = p->data; //�����i��λ�õ�����Ԫ��ֵ��e 
	return OK;
} 

//����e����Ԫ�����ڵ�λ�� 
int Find_pos(LinkList L,ElemType e)
{
	int i=0;
	LinkList p;
	p = L->next;  //pָ��L�ĵ�һ���ڵ� 
	while(p)
	{
		i++;
		if(p->data==e)
			return i; //�ҵ�����i 
		p = p->next;
	}
	
	return 0; //������������Ԫ�ز����ڣ��򷵻�ֵΪ0 
} 
 
//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e 
Status Insert(LinkList *L,int i,ElemType e)
{
	int j=1;
	LinkList p,s;
	p = *L; //pָ��ͷ���
	//1.���ҵ���i-1λ��
	while(p && j<i)
	{
		p = p->next;
		j++;
	}
	if(!p || j>i)
	{
		return ERROR;
	}
	//2.����s�ڵ� 
	s = (LinkList)malloc(sizeof(Node)); //����s�ڵ�
	s->data=e;
	s->next = p->next;
	p->next = s;
	return OK; 
} 

//���������ɾ��L�ĵ�i������Ԫ��,e������ֵ 
void Delete(LinkList *L,int i,ElemType *e)
{
	int j=1;
	LinkList p = *L; //pΪͷ���
	LinkList q; //q����ΪҪɾ���Ľڵ� 
	//1.�ҵ���i������Ԫ��
	while(p->next && j<i) //����Ѱ�ҵ�i��Ԫ�� 
	{
		p = p->next;
		j++;	
	} 
	if(!(p->next) || j>i)
	{
		return;
	}
	//2.ɾ������ 
 	q = p->next;
 	p->next = q->next;
 	*e = q->data; //ɾ�������ݸ�e 
 	free(q);  //�ͷ�q���ڴ�ռ� 
}

void Traverse(LinkList L)
{
	LinkList p = L->next; //pָ���һ���ڵ�
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;	
	} 
	printf("\n");	
}

//ͷ�巨��������ͷ�ڵ�ĵ�����L
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = i;            
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}

//β�巨��������ͷ�ڵ�ĵ�����L
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r=*L;                                /* rΪָ��β���Ľ�� */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data = i;           /*  �������100���ڵ����� */
		r->next=p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

int main()
{
	LinkList L,La,Lb;
	ElemType e;
	int pos;
	InitList(&L);
	printf("��ʼ��L֮��L�ĳ���=%d\n",ListLength(L));
	for(int i=1;i<=5;i++)
		Insert(&L,1,i);
	Traverse(L);
	printf("L�Ƿ�Ϊ��(1���ǣ�0����)%d\n",isEmpty(L));

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



