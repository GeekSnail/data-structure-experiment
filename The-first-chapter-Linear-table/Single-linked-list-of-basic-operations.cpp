//---------库文件和预设定义
#include <stdlib.h>
#include <stdio.h>
#define NULL 0

typedef int ElemType;  

//单链表存储结构定义
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
 } LNode, *LinkList;

/********************************/
//单链表建立方法一（函数用返回值得到表头指针）
//函数名：   CreateOne(int n)
//参数：     (传入)int n, 传入线性表结点数量
//作用：     建立一个线性表（至少包含一个结点——首元结点）
//返回值：   LNode* 返回结构体指针，即建立的线性表头指针
/********************************/
LNode* CreateOne(int n)
{
	int i;
	LNode* head;  //定义头结点指针
	LNode *p;     //定义新结点指针 
	head = (LNode*)malloc(sizeof(LNode));  //建立带头结点的线性链表
	head->next = NULL;
	printf("Please input the data for LinkList Nodes:\n");
	for(i=n; i>0; i--)
	{
		p=(LNode*)malloc(sizeof(LNode));   //为新结点申请空间，即创建一新结点
		scanf("%d",&p->data);   //新结点赋值
		p->next = head->next;   //每次都插在头结点的后一个，即表头 
		head->next = p; 
	 } 
	 return head;   //返回头结点指针，即可以得到单链表的地址 
 } 
 
/********************************/
//单链表建立方法二（函数无返回值）
//函数名：   CreateTwo(LNode*head, int n)
//参数：     (传入)LNode* head传入一个链表指针 
//			 (传入)int n, 传入线性表结点数量
//作用：     建立一个线性表（至少包含一个结点——首元结点） 
//返回值：   无
/********************************/
void CreateTwo(LinkList &head, int n)
{
	int i;
	LNode *p;  //定义新结点指针
	head = (LNode*)malloc(sizeof(LNode));  //建立带头结点的线性链表
	head->next = NULL;
	printf("Please input the data for LinkList Nodes:\n");
	for(i=n; i>0; i--)
	{
		p=(LNode*)malloc(sizeof(LNode));   //为新结点申请空间，即创建一新结点
		scanf("%d",&p->data);   //新结点赋值
		p->next = head->next;   //每次都插在头结点的后一个，即表头 
		head->next = p; 
	 } 	
}

/********************************/
//函数名：   InsertNode(LNode* L, int i; ElemType e)
//参数：     (传入)LNode* L传入首元结点指针 
//			 (传入)int i, 插入位置，i>1 
//			 （传入）ElemType e插入元素 
//作用：     线性表中插入一个元素 
//返回值：   int型，返回1表示操作成功，0表示失败 
/********************************/
int InsertNode(LNode* L, int i, ElemType e)
{
	LNode* p = L;  //定义一个指向第一个（首元）结点的指针
	int j = 0;
	while(p && j<i-1)  //从第一个指针向后查找，直到p指向第i个结点 
	{
		p = p->next;
		++j;
	 }
	if(!p || i-1<=j)   //插入位置合法性判断(p不存在或i<=1)
	{
	 	printf("Error! The location is illegal");
	 	return 0;
	} 
	LNode *s;
	s = (LNode*)malloc(sizeof(LNode));  //建立新结点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1; 
 } 
 
 /********************************/
//函数名：   DeleteNode(LinkList &L, int i; ElemType &e)
//参数：     (传入)LinkList &L，线性表头结点指针L的地址 
//			 (传入)int i, 删除位置 
//			 （传入）ElemType &e 存储删除结点元素值 
//作用：     线性表中删除一个元素 
//返回值：   ElemType型返回删除结点元素的值 
/********************************/
ElemType DeleteNode(LinkList &L, int i, ElemType &e)
{
	LNode *prev = L;  //定义一个指向【头结点】的指针
	LNode *q;      //暂时存放待删除结点
	int j=0;
	while(prev->next && j<i-1)  //顺指针向后查找，直到p指向第i-1个结点 
	{
		prev = prev->next;
		++j;
	 } 
	if(!prev || i-1<=j)   //插入位置合法性判断(p不存在或i<=1)
	{
	 	printf("Error! The location is illegal\n");
	 	return 0;
	} 
	q = prev->next;
	prev->next = q->next;
	e = q->data;
	return (e); 
 }
 
/********************************/
//函数名：   DisplayList(LinkList &L)
//参数：     (传入)LinkList &L，线性表头结点指针L的地址
//作用：     显示线性表中所有元素 
//返回值：   无
/********************************/ 
void DisplayList(LinkList &L)
{
	LNode *p = L;  //定义一个指向【头结点】的指针
	while(p != NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

//测试程序
int main()
{
	LNode *L1;
	int NodeNum;
	printf("Please input the LinkNode Number:\n");
	scanf("%d",&NodeNum);
	L1 = CreateOne(NodeNum);
	//输出当前单链表内容
	printf("the current L1 is :");
	DisplayList(L1);
	//调用
	if(InsertNode(L1,2,88))
		printf("Succeed inserting!\n");
	//输出当前单链表内容
	printf("the current L1 is :");
	DisplayList(L1);	 
	 
 } 



















