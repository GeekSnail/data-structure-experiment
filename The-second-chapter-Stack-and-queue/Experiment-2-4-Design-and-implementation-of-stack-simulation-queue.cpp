#include<stdio.h>
#include<stdlib.h>

#define Stack_Length 6
#define OK 1
#define ERROR 0

typedef struct SNode
{
	int data;
	struct SNode* next;
}SNode, *LinkStack;

void Create(LinkStack &head)
{
	head = (LinkStack)malloc(sizeof(SNode));
	head->next = NULL;
}

int Push(LinkStack &top, int e)
{
	SNode* q;
	q = (LinkStack)malloc(sizeof(SNode));
	if(!q){
		printf("Overflow!\n");
		return (ERROR);
	}
	q->data = e;
	q->next = top->next;
	top->next = q;
	return OK;
}

int Pop(LinkStack &top)
{
	int e;
	SNode *q;  //定义临时存储栈顶节点的指针
	if(!top->next){  //判断栈顶首元是否存在
		printf("error!");
		return (ERROR);
	}
	e = top->next->data;
	q = top->next;
	top->next = q->next;  //头结点指向次元
	free(q);
	return e;
}

int Empty(LinkStack &top)
{
	if(top->next != NULL){
		return OK;
	} else {
		return ERROR;
	}
}

void Display(LinkStack &top)
{
	SNode* temp;
	temp = top;
	while(temp->next){
		temp = temp->next;
		printf("%d ",temp->data);
	}
	printf("\n");
}

void EnQueue(LinkStack &s1, int e)
{
	Push(s1,e);	
}

//要删除队列的首元，而队列的首元在栈的底部，
//所以先全部取出到另一个临时栈，使首元位于栈顶，再删除，最后再放入原来的栈
void DeQueue(LinkStack &s1, LinkStack &s2, int &e)
{
	s2->next = NULL;
	while(Empty(s1)){
		Push(s2,Pop(s1));	//s1所有元素出栈并入栈s2		
	}
	e = Pop(s2);  //将s2的栈顶元素出栈并赋值给e
	while(Empty(s2)) {
		Push(s1,Pop(s2));   //s2所有元素出栈并入栈s1
	}
}

int main()
{	
	int elem;
	int e;
	LinkStack s1, s2;
	Create(s1);
	Create(s2);
	printf("Please input the data of queue(exit for 0):\n");
	scanf("%d",&elem);
	while(elem!=0) {
		EnQueue(s1, elem);
		scanf("%d",&elem);
	}
	printf("The current queue is:");
	Display(s1);
	DeQueue(s1,s2,e);
	printf("DeQueue() be excuted:");
	Display(s1);
	DeQueue(s1,s2,e);
	printf("DeQueue() be excuted:");
	Display(s1);
	return 0;
}






