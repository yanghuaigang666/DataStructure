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
	ElemType data[MaxSize]; //����洢 
	int length; //���Ա��� 
}SqList;

//��ʼ�����Ա�
Status InitList(SqList *L) 
{
	L->length=0;
	return OK;
}

//�ж��Ƿ�Ϊ�ձ�
Status isEmpty(SqList *L)
{
	if(L->length==0)
		return TRUE;
	else
		return FALSE;
}

//�����б���
int ListLength(SqList L)
{
	return L.length;	
} 

//��ȡ��i��λ�õ�Ԫ��ֵ 
//��e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ
Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1]; //e�������Ԫ��ֵ 
	return OK;	
} 

//����e����Ԫ�����ڵ�λ�� 
int Find_pos(SqList L,ElemType e)
{
	int i; 
	if(L.length==0)
		return 0; //�����ڣ�����0 
	for(i=0;i<L.length;i++)
	{
		if(L.data[i]==e)
			break;
	}
	return i+1; //����λ��i+1 
} 

//��i��λ�ò�������Ԫ��e
void Insert(SqList *L, int i, ElemType e)
{
	int j;
	//У��
	if(L->length == MaxSize)
	{
		printf("���Ա�����");
		return;
	}
	if(i<1 || i>L->length+1)
	{
		printf("����λ�ò�����");
		return;
	}
	
	if(i<=L->length) //�����λ�ò��ڱ�β
	{
		for(j=L->length-1;j>=i-1;j--) 
			L->data[j+1] = L->data[j];
	} 
	L->data[i-1] = e;
	L->length++;
	return;
} 


//ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
void Delete(SqList *L,int i)
{
	if(L->length==0)
	{
		printf("��Ϊ��\n");
		return;
	}
	if(i<1 || i>L->length)
	{
		printf("λ�ò�����\n");
		return;
	}

	if(i<L->length)
	{
		for(int k=i;k<L->length;k++)
			L->data[k-1] = L->data[k];	
	} 
	L->length--;

} 

//�������Ա�
void Traverse(SqList L)
{
	for(int i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");	
} 

//�ϲ��������Ա�
void union_L(SqList *La,SqList Lb) 
{
	int La_len,Lb_len;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for(int i=1;i<=Lb_len;i++)
	{
		//��ȡLb��i��λ���ϵ�Ԫ��e
		GetElem(Lb,i,&e);
		//���뵽��a�ĺ���
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
	printf("��ʼ��L��L.length=%d\n",L.length);
	
	for(int j=1;j<=5;j++)
		Insert(&L,1,j);
		
	printf("�������ݺ�L.length=%d\n",L.length);
	printf("L�Ƿ�Ϊ��(1���ǣ�0����)%d\n",isEmpty(&L));
	Traverse(L);
	
	printf("%d\n",Find_pos(L,2));
	GetElem(L,1,&e);
	printf("%d\n",e);
	
	
	Delete(&L,6);
	printf("ɾ��һ�����ݺ�L.length=%d\n",L.length);
	Traverse(L);
	
	
	InitList(&Lb);
	for(int j=6;j<=15;j++)
		Insert(&Lb,1,j);
	Traverse(Lb);
	
	union_L(&L,Lb);
	Traverse(L);
	
	return 0;
}



