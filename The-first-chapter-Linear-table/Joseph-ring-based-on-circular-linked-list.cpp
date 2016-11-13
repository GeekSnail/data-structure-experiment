#include <stdio.h> 
#include<malloc.h>
#include<stdlib.h>
typedef struct list
{
	int num;
	struct list *next;
}List;
int n=0;
List *Create()
{
   List *head,*p1,*p2;
   int i;
   if((head=(List *)malloc(sizeof(List)))==NULL)
   {
	   exit(0);
   }
   p1=p2=head;
   scanf("%d",&head->num);//创建列表，带头结点，头结点数据域表示输入的个数
   if(head->num==0)
   {
	   head->next=NULL;
   }
   else
   {
      for(i=0;i<head->num;i++)
	  {
	      if((p1=(List *)malloc(sizeof(List)))==NULL)
		  {
	         //printf("Error");
	         exit(0);
		  }
          p1->num=i+1;
		  p2->next=p1;
		  p2=p1;
	  }
	  p1->next=head;
   }
    return(head);
}
Joseph(List *head)
{
 	List *p = head;  
	List *q; 
 	int count=0;
 	while(p->next) {
 		if(p->next==head) {
 			p=head;   //不到5的时候 
 			continue;
		}
 		++count;	
 		if(count%5==0) {
			q = p->next;       
			p->next = q->next; 	
			free(q); 
			continue;		
		}
 		if(p->next==head) {
 			p=head;   //5的时候，next为head时 
 			continue;
		}	
		p=p->next;
		if(p->next==head && head->next==p) {
			return p->num;
		}				
	}
}
//void print(List *head)
//{
//   List *p;
//   p=head->next;
//   for(;p!=head;)
//   {
//	   printf("%d ",p->num);
//	   p=p->next;
//   }
//   printf("\n");
//}
int main()
{ 
	int i=1,e=0;
	List *head,*p;
    head=Create();
    p=head->next;
	printf("%d\n",Joseph(head));
}



