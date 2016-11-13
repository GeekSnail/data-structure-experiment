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
	List head;  //定义头结点指针
	List p;     //定义新结点指针 
	head = (List)malloc(sizeof(Node));  //建立带头结点的线性链表
	head->Next = NULL;
	printf("Please input the data for LinkList Nodes:\n");
	for(i=5; i>0; i--)
	{
		p=(List)malloc(sizeof(Node));   //为新结点申请空间，即创建一新结点
		scanf("%d",&p->Data);   //新结点赋值
		p->Next = head->Next;   //每次都插在头结点的后一个，即表头 
		head->Next = p; 
	 } 
	 return head;   //返回头结点指针，即可以得到单链表的地址 
} 
void Print( List L )
{
	List p = L;  //定义一个指向首元结点的指针
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

