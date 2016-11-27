/**************************************************************
*** 链表结构建立二叉排序树(左小右大，所以采用中序遍历—左中右)
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//二叉树链表存储结构
typedef struct btnode{
	int data;
	struct btnode *Llink;   //存放左子树位置 
	struct btnode *Rlink;  //存放右子树位置
}btnode, *btreetype;

/**************************************************************
*** 函数：btreetype CreateTree(int n)	建立二叉树
*** 参数：int n
*** 返回值: 二叉树（根节点）指针
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
		scanf("%d",&newNode->data);  //新节点赋值, 赋值的顺序也是按层遍历的顺序
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
	printf("\n");
}
void main()
{
	btreetype btree;
	int count;
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input data(n=%d):\n",count);
	btree = CreateTree(count);
	printf("建立的二叉排序树为：\n");
	InOrder(btree);
}
/** 测试 ******************************************************
*** count = 9
*** 输入数据: 45 2 68 1 23 5 12 9 6
*** 建立过程: 见图
**************************************************************/