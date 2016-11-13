#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE 100   //最大队列长度
typedef struct
{
	int *elem;  //队列存储空间
	int front;  //头指针，指向对头元素
	int rear;   //尾指针，指向队尾元素的下一个位置 
 }SqQueue; 

/***********************************/
//函数名：  InitQueue(SqQueue &Q)
//参数：    (传入)SqQueue &Q, 循环队列 
//作用：    构造一个空队列 
/***********************************/
int InitQueue(SqQueue &Q)
{
	Q.elem = (int *)malloc(MAXSIZE*sizeof(int));
	if(!Q.elem) 	
		exit(OVERFLOW);
	Q.front = Q.rear = -1;  //设定头指针和尾指针的指向为空
	for(int i=0; i<MAXSIZE; i++) {
		Q.elem[i] = -1;  //清除数组内容 
	}
	return OK;
 } 
 
//返回Q的元素个数，即队列的长度
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
//函数名：  EnQueue(SqQueue &Q, int e)
//参数：    (传入)SqQueue &Q, 循环队列 
//          (传入)int e, 入队元素 
//作用：    队列入队操作 
/***********************************/ 
int EnQueue(SqQueue &Q, int e)
{
	Q.rear = (Q.rear+1)%MAXSIZE;  //rear从1开始 
	if(Q.rear==Q.front) {
		return ERROR;   //检查队列是否已满   
	}	
	Q.elem[Q.rear] = e;   //插入元素到队尾
	return OK; 
}
 
/******************************************/ 
//函数名：  DeQueue(SqQueue &Q, int &e)
//参数：    (传入)SqQueue &Q, 循环队列 
//          (传入)int &e, 出队元素 
//作用：    队列出队操作 
/***********************************/ 
int DeQueue(SqQueue &Q, int &e)
{
	if(Q.front==Q.rear) {
		return ERROR;   //检查队列是否已空   
	}	
	e = Q.elem[Q.front+1];   //删除Q的对头元素，并存放在e中 
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








 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
