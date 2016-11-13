#include <stdio.h> 
#include<malloc.h>
#include<stdlib.h>
typedef struct list
{
	int num;
	struct list *next;
}List;
int n=0;
List *create()
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
void print(List *head)
{
   List *p;
   p=head->next;
   for(;p!=head;)
   {
	   printf("%d ",p->num);
	   p=p->next;
   }
   printf("\n");
}
int main()
{ 
	List *head;
    head=create();
    print(head);
}
