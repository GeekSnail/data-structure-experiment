#include <stdio.h>
#include <stdlib.h>
#define Stack_Length 6
#define OK 1
#define ERROR 0

typedef int SElemType;
//存储形式
typedef struct SNode{
	SElemType data;
	struct SNode *next; 
}SNode,*LinkStack;

/***********************************/
//函数名：  CreateTwo(LNode * head, int n)
//参数：    (传入)LNode* head 传入一个链表指针
//          (传入)int n,传入线性表节点数量
//作用：    (建立一个空栈)
//返回值：  无
/***********************************/
void CreateTwo(LinkStack &head, int n)
{
	int i;
	SNode *p; //定义新节点指针
	//建立带头结点的线性链表
	head = (LinkStack)malloc(sizeof(SNode));
	head->next = NULL;
	
	printf("Please input three data for LinkList Nodes:\n");
	for(i=n; i>0; --i) {
		p = (SNode*)malloc(sizeof(SNode));  //为新节点申请空间，即创建一新节点
		scanf("%d",&p->data);  //新节点赋值
		//新节点插入到表头
		p->next = head->next;  //把新节点的下一个指向首元节点 
		head->next = p;	       //再把头结点的下一个节点指向首元节点 
	} 
 } 
 
/*********************************************/
//函数名：  Push(LinkStack &top, SElemType e)
//参数：    (传入)LinkStack &top, 栈顶指针
//          (传入)SElemType e, 入栈元素
//作用：    入栈 
//返回值：  int型，返回1表示入栈成功，0表示失败
/*********************************************/ 
int Push(LinkStack &top, SElemType e)
{
	SNode *q;
	q = (LinkStack)malloc(sizeof(SNode));  //创建入栈元素节点
	//创建节点失败处理
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
//函数名：  Pop(LinkStack &top, SElemType e)
//参数：    (传入)LinkStack &top, 栈顶指针
//          (传入)SElemType e, 出栈元素
//作用：    入栈 
//返回值：  int型，返回1表示出栈成功，0表示失败
/*********************************************/ 
int Pop(LinkStack &top, SElemType e)
{
	SNode *q;   //定义临时存储栈顶节点的指针 
	if(!top->next) {
		printf("error!\n");
		return (ERROR);
	} 
	e = top->next->data;
	q = top->next;
	top->next = q->next;  //删除栈顶元素
	free(q); 
	return (OK);	
 } 
 
 //测试程序
 int main()
 {
 	int e;
 	LinkStack top; //建立一个栈
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


 
 
