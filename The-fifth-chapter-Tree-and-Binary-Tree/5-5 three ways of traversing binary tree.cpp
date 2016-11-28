/**************************************************************
*** 分先序遍历、中序遍历和后续遍历三种情况考虑。
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//二叉树链表存储结构
typedef struct btnode{
	int data;
	struct btnode *Llink;  //左子树指针
	struct btnode *Rlink;  //右子树指针
}btnode, *btreetype;

/**************************************************************
*** 函数：btreetype CreateTree(int n)	建立二叉排序树
*** 参数：int n  数据量
*** 返回值: 二叉树根节点指针
**************************************************************/
btreetype CreateTree(int n)
{
	int i;
	btreetype root = NULL;
	for(i=0; i<n; i++){
		btreetype newNode;
		btreetype currentNode;
		btreetype parentNode;
		//建立新节点
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf("%d",&newNode->data);  
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;  //存储当前节点指针
		if(currentNode==NULL){  //若指向根节点的指针为空（第一次循环）
			root = newNode;
		}
		else {  
			//先通过遍历来找新节点的父节点
			//若指向当前节点的指针不为空，从根节点开始
			while(currentNode!=NULL){  
				//存储当前节点作为父节点，出循环会用到
				parentNode = currentNode;  
				//若新节点数值小于当前节点数值
				if(newNode->data < currentNode->data){
					//当前节点指向其左子树
					currentNode = currentNode->Llink;
				}
				//若新节点数值大于或等于当前节点数值
				else {  
					//当前节点指向其右子树
					currentNode = currentNode->Rlink;
				}
			}
			//若新节点数值小于父节点数值
			if(newNode->data < parentNode->data){
				//父节点的左子树指针指向新节点
				parentNode->Llink = newNode;
			}
			else {
				parentNode->Rlink = newNode;
			}
		}
	}
	return root;
}

/**************************************************************
*** 函数：void InOrder(btreetype &root)  先序遍历二叉树（递归）
*** 参数：btreetype &root  二叉树指针
*** 返回值: 无
**************************************************************/
void PreOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if(p!=NULL){
		printf("%d ",p->data);
		PreOrder(p->Llink);  //递归处理左子树
		PreOrder(p->Rlink);  //递归处理右子树
	}
}

/**************************************************************
*** 函数：void InOrder(btreetype &root)  中序遍历二叉树（递归）
*** 参数：btreetype &root  二叉树指针
*** 返回值: 无
**************************************************************/
void InOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if(p!=NULL){
		InOrder(p->Llink);  //递归处理左子树
		printf("%d ",p->data);
		InOrder(p->Rlink);  //递归处理右子树
	}
}
/**************************************************************
*** 函数：void InOrder_Norecursion(btreetype &root)  中序遍历二叉树（非递归）
*** 参数：btreetype &root  二叉树指针
*** 返回值: 无
**************************************************************/
void InOrder_Norecursion(btreetype &root)
{
	btreetype stack[MAX];  //以栈存储的形式存储结点数组
	btreetype p;
	int top=0;
	p = root;
	do{
		//遍历左子树或右子树，直到当前节点为空
		while(p!=NULL){
			top++;
			//数组从下标1开始存储根节点及左子树或右子树节点，入栈
			stack[top] = p;
			p = p->Llink;
		}
		//栈顶元素即当前左端点存在
		if(top>0){
			//暂存左端点
			p = stack[top];
			//出栈
			top--;
			printf("%d ",p->data);  //访问当前左端点
			//开始指向右子树，下一次循环时将遍历
			p = p->Rlink;
		}
	}while(p!=NULL || top!=0);
}

/**************************************************************
*** 函数：void PostOrder(btreetype &root)  后序遍历二叉树（递归）
*** 参数：btreetype &root  二叉树指针
*** 返回值: 无
**************************************************************/
void PostOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if(p!=NULL){
		PostOrder(p->Llink);  //递归处理左子树
		PostOrder(p->Rlink);  //递归处理右子树
		printf("%d ",p->data);
	}
}

int main()
{
	btreetype btree;
	int count;
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input data(num=%d):\n",count);
	btree = CreateTree(count);
	printf("先序遍历二叉树：");
	PreOrder(btree);
	printf("\n中序遍历二叉树（递归）：");
	InOrder(btree);
	printf("\n中序遍历二叉树（非递归）：");
	InOrder_Norecursion(btree);
	printf("\n后序遍历二叉树：");
	PostOrder(btree);
	printf("\n");
	return 0;
}
/** 测试 ******************************************************
*** count = 9
*** 输入数据: 45 2 68 1 23 5 12 9 6
**************************************************************/




