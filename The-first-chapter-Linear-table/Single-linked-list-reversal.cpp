#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{
 	int i;
	List head;  //����ͷ���ָ��
	List p;     //�����½��ָ�� 
	head = (List)malloc(sizeof(Node));  //������ͷ������������
	head->Next = NULL;
	printf("Please input the data for LinkList Nodes:\n");
	for(i=5; i>0; i--)
	{
		p=(List)malloc(sizeof(Node));   //Ϊ�½������ռ䣬������һ�½��
		scanf("%d",&p->Data);   //�½�㸳ֵ
		p->Next = head->Next;   //ÿ�ζ�����ͷ���ĺ�һ��������ͷ 
		head->Next = p; 
	 } 
	 return head;   //����ͷ���ָ�룬�����Եõ�������ĵ�ַ 
} 
void Print( List L )
{
	List p = L;  //����һ��ָ����Ԫ����ָ��
	while(p != NULL)
	{
		printf("%d ",p->Data);
		p = p->Next;
	}
	printf("\n");
} 

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read(); 
	
    L2 = Reverse(L1);
    //Print(L1); 
    Print(L2);
    return 0;
}
List Reverse( List L )
{
	if(NULL == L){
    	return NULL;
  	}
    List p;
    List q;
    List r;
    p = L;
    q = L->Next;
    L->Next = NULL;
    while(q){
        r = q->Next;   //2 3 4 5 NULL
        q->Next = p;   //
        p = q;         //1 2 3 4 5
        q = r;         //2 3 4 5 NULL
    }
    L=p; 
    return L;	
} 
//List Reverse( List L )
//{
//	List p,r,s;
//	r = (List)malloc(sizeof(List));  
//	p=L->Next;
//	r->Next=NULL;
//	while(p) {
//		s = (List)malloc(sizeof(List));
//		s->Data=p->Data;
//		s->Next=r->Next;
//		r->Next=s;
//		p=p->Next;
//	}	
//	return r; 	
//} 

