#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE 100   //�����г���
typedef struct
{
	int *elem;  //���д洢�ռ�
	int front;  //ͷָ�룬ָ���ͷԪ��
	int rear;   //βָ�룬ָ���βԪ�ص���һ��λ�� 
 }SqQueue; 

/***********************************/
//��������  InitQueue(SqQueue &Q)
//������    (����)SqQueue &Q, ѭ������ 
//���ã�    ����һ���ն��� 
/***********************************/
int InitQueue(SqQueue &Q)
{
	Q.elem = (int *)malloc(MAXSIZE*sizeof(int));
	if(!Q.elem) 	
		exit(OVERFLOW);
	Q.front = Q.rear = -1;  //�趨ͷָ���βָ���ָ��Ϊ��
	for(int i=0; i<MAXSIZE; i++) {
		Q.elem[i] = -1;  //����������� 
	}
	return OK;
 } 
 
//����Q��Ԫ�ظ����������еĳ���
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
 } 
 
 void Display(SqQueue Q) 
 {
 	for(int i=0; i<=QueueLength(Q); i++) {
 		if(Q.elem[i]!=-1) {
 			printf("%d ",Q.elem[i]);
		}
	 } 
	 printf("\n");
 }

/******************************************/ 
//��������  EnQueue(SqQueue &Q, int e)
//������    (����)SqQueue &Q, ѭ������ 
//          (����)int e, ���Ԫ�� 
//���ã�    ������Ӳ��� 
/***********************************/ 
int EnQueue(SqQueue &Q, int e)
{
	Q.rear = (Q.rear+1)%MAXSIZE;  //rear��1��ʼ 
	if(Q.rear==Q.front) {
		return ERROR;   //�������Ƿ�����   
	}	
	Q.elem[Q.rear] = e;   //����Ԫ�ص���β
	return OK; 
}
 
/******************************************/ 
//��������  DeQueue(SqQueue &Q, int &e)
//������    (����)SqQueue &Q, ѭ������ 
//          (����)int &e, ����Ԫ�� 
//���ã�    ���г��Ӳ��� 
/***********************************/ 
int DeQueue(SqQueue &Q, int &e)
{
	if(Q.front==Q.rear) {
		return ERROR;   //�������Ƿ��ѿ�   
	}	
	e = Q.elem[Q.front+1];   //ɾ��Q�Ķ�ͷԪ�أ��������e�� 
	Q.elem[Q.front+1] = -1;
	Q.front = (Q.front+1)%MAXSIZE; 
	return OK; 
}
int main()
{
	SqQueue Q;
	InitQueue(Q);
	int elem, e;
	printf("Please input the data of queue (exit for 0):\n");
	scanf("%d",&elem);
	while(elem!=0) {
		EnQueue(Q,elem);
		scanf("%d",&elem);
	}	
	printf("The current queue is:\n");
	Display(Q);
	DeQueue(Q,e);
	printf("DeQueue() be excuted:");
	Display(Q);
}








 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
