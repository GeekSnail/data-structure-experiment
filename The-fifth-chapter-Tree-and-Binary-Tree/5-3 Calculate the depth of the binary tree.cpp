/**************************************************************
*** 二叉树的深度：等于根节点的左子树和右子树中深度较大者的子树的深度加1
*** 递归公式：
*** depth(tree) = 1;  tree为空
*** depth(tree) = max(depth(tree->Llink), depth(tree->Rlink))+1
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
*** 函数：int depth(btreetype &root)	输出二叉树深度
*** 参数：btreetype &root  二叉树指针
*** 返回值: 二叉树根节点指针
**************************************************************/
int depth(btreetype &root)
{
	btreetype p;
	//存储当前传入的根节点
	p = root;
	int dep1, dep2;
	if(root==NULL){
		return 0;  //若当前节点不存在，则递归出口返回0
	}
	else {
		dep1 = depth(p->Llink);  //测左子树的深度
		dep2 = depth(p->Rlink);  //测右子树的深度
		//二叉树的深度为左子树或右子树的最大深度加1
		if(dep1>dep2){
			return (dep1+1);
		}
		else{
			return (dep2+1);  //第一次是计算最左叶子节点的度，返回1
		}
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
	printf("建立的二叉树的深度为%d\n",depth(btree));
	return 0;
}
/** 测试 ******************************************************
*** count = 9
*** 输入数据: 45 2 68 1 23 5 12 9 6
*** 二叉排序树的深度：7
**************************************************************/




