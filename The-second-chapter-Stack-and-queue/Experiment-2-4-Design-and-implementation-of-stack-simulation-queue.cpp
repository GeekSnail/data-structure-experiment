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
	SNode *q;  //������ʱ�洢ջ���ڵ��ָ��
	if(!top->next){  //�ж�ջ����Ԫ�Ƿ����
		printf("error!");
		return (ERROR);
	}
	e = top->next->data;
	q = top->next;
	top->next = q->next;  //ͷ���ָ���Ԫ
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

//Ҫɾ�����е���Ԫ�������е���Ԫ��ջ�ĵײ���
//������ȫ��ȡ������һ����ʱջ��ʹ��Ԫλ��ջ������ɾ��������ٷ���ԭ����ջ
void DeQueue(LinkStack &s1, LinkStack &s2, int &e)
{
	s2->next = NULL;
	while(Empty(s1)){
		Push(s2,Pop(s1));	//s1����Ԫ�س�ջ����ջs2		
	}
	e = Pop(s2);  //��s2��ջ��Ԫ�س�ջ����ֵ��e
	while(Empty(s2)) {
		Push(s1,Pop(s2));   //s2����Ԫ�س�ջ����ջs1
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






