#include <stdio.h>
#include <stdlib.h>
#define Stack_Length 6
#define OK 1
#define ERROR 0

typedef int SElemType;
//�洢��ʽ
typedef struct SNode{
	SElemType data;
	struct SNode *next; 
}SNode,*LinkStack;

/***********************************/
//��������  CreateTwo(LNode * head, int n)
//������    (����)LNode* head ����һ������ָ��
//          (����)int n,�������Ա�ڵ�����
//���ã�    (����һ����ջ)
//����ֵ��  ��
/***********************************/
void CreateTwo(LinkStack &head, int n)
{
	int i;
	SNode *p; //�����½ڵ�ָ��
	//������ͷ������������
	head = (LinkStack)malloc(sizeof(SNode));
	head->next = NULL;
	
	printf("Please input three data for LinkList Nodes:\n");
	for(i=n; i>0; --i) {
		p = (SNode*)malloc(sizeof(SNode));  //Ϊ�½ڵ�����ռ䣬������һ�½ڵ�
		scanf("%d",&p->data);  //�½ڵ㸳ֵ
		//�½ڵ���뵽��ͷ
		p->next = head->next;  //���½ڵ����һ��ָ����Ԫ�ڵ� 
		head->next = p;	       //�ٰ�ͷ������һ���ڵ�ָ����Ԫ�ڵ� 
	} 
 } 
 
/*********************************************/
//��������  Push(LinkStack &top, SElemType e)
//������    (����)LinkStack &top, ջ��ָ��
//          (����)SElemType e, ��ջԪ��
//���ã�    ��ջ 
//����ֵ��  int�ͣ�����1��ʾ��ջ�ɹ���0��ʾʧ��
/*********************************************/ 
int Push(LinkStack &top, SElemType e)
{
	SNode *q;
	q = (LinkStack)malloc(sizeof(SNode));  //������ջԪ�ؽڵ�
	//�����ڵ�ʧ�ܴ���
	if(!q) {
		printf("Overfolow!\n");
		return (ERROR);
	} 
	q->data = e;
	q->next = top->next;
	top->next = q;
	return (OK);
 } 
 
 /*********************************************/
//��������  Pop(LinkStack &top, SElemType e)
//������    (����)LinkStack &top, ջ��ָ��
//          (����)SElemType e, ��ջԪ��
//���ã�    ��ջ 
//����ֵ��  int�ͣ�����1��ʾ��ջ�ɹ���0��ʾʧ��
/*********************************************/ 
int Pop(LinkStack &top, SElemType e)
{
	SNode *q;   //������ʱ�洢ջ���ڵ��ָ�� 
	if(!top->next) {
		printf("error!\n");
		return (ERROR);
	} 
	e = top->next->data;
	q = top->next;
	top->next = q->next;  //ɾ��ջ��Ԫ��
	free(q); 
	return (OK);	
 } 
 
 //���Գ���
 int main()
 {
 	int e;
 	LinkStack top; //����һ��ջ
	CreateTwo(top,3); 
	
	LinkStack p;
	printf("The old LinkStack is (top to bottom):\n");
	p = top;
	while(p->next) {
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n\nPlease input one data for new LinkList Nodes:\n");
	scanf("%d",&e); 
	
	if(!Push(top,e)) {
		printf("success to push");
	}
	if(!Pop(top,e)) {
		printf("success to pop");
	}
	printf("The new LinkStack is:\n");
	while(top->next) {
		top = top->next;
		printf("%d ",top->data);
	}
} 


 
 
