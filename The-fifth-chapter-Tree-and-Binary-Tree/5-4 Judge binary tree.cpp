/**************************************************************
*** 1. 空的二叉树也是二叉排序树
*** 2. 非空二叉树：（要求）
*** (1) 若它的左子树非空，则左子树上所有结点的值均小于根节点的值
*** (2) 若它的右子树非空，则右子树上所有结点的值均小于根节点的值
*** (3) 左右子树本身又是一颗二叉排序树
*** 3. 采用递归，结束条件为：左右子树为空
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
*** 函数：btreetype CreateTree(int n)	建立二叉树
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
*** 函数：int Check(btreetype &root)	判定一棵二叉树是否是二叉排序树
*** 参数：btreetype &root  二叉树指针
*** 返回值: 二叉树根节点指针
**************************************************************/
int Check(btreetype &root)
{
	btreetype p;
	//存储当前传入的根节点
	p = root;
	//
	//若根节点为空或当前节点已经遍历到底（父节点的度为1或0），即局部满足二叉排序树
	if(p==NULL){
		return 1;  
	}
	//若当前节点的左子树存在，且左子树根节点的数值大于当前节点(父节点)的数值，则判定不满足
	if(p->Llink && (p->Llink->data > p->data)){
		return 0;
	}
	//若当前节点的左子树存在，且左子树根节点的数值大于当前节点(父节点)的数值，则判定不满足
	if(p->Rlink && (p->Rlink->data < p->data)){
		return 0;  //第一次是计算最左叶子节点的度，返回1
	}	
	return (Check(p->Llink) && Check(p->Rlink));  //递归左右子树进行判定
}
int main()
{
	btreetype btree;
	int count;
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input data(num=%d):\n",count);
	btree = CreateTree(count);
	if(Check(btree)){
		printf("建立的二叉树是二叉排序树\n");
	}
	else {
		printf("建立的二叉树不是二叉排序树\n");
	}	
	return 0;
}
/** 测试 ******************************************************
*** count = 9
*** 输入数据: 45 2 68 1 23 5 12 9 6
*** 二叉排序树的深度：7
*** 由于程序中创建的二叉树均为二叉排序树，所以都满足
**************************************************************/




