#include <stdio.h>
#define MAX 32
//二叉树结构
typedef struct btree{
	int data;
	int left;   //存放左子树位置 
	int right;  //存放右子树位置
}BtreeNode;
//定义二叉树结构数组
BtreeNode btree[MAX];

//int* bt 二叉树, int list[] 数据数组, n 数据数量
void CreateTree(BtreeNode* bt, int list[], int n)
{
	int i;
	int level;  //记录存当前节点的left或right值
	int pos;  //标志，左子树1，右子树-1

	bt[0].data = list[0]; //建立二叉树根节点
	bt[0].left = -1;  //左子树位置初始化
	bt[0].right = -1;  //又子树位置初始化
	for(i=1; i<n; i++){
		bt[i].data = list[i];  //元素存入节点
		bt[i].left = -1;
		bt[i].right = -1;
		level=0;  //从根节点开始
		pos = 0;  //遍历每个节点时，pos值置零
		while(pos == 0){
			//根节点的值小于当前值，当前值就在右子树
			if(bt[level].data<list[i]){
				//是否有下一层
				if(bt[level].right != -1){
					level = bt[level].right;
				}
				else{
					pos = -1;  //设为右子树
				}
			}
			//是在左子树
			else{
				//是否有下一层
				if(bt[level].left != -1){
					level = bt[level].left;
				}
				else{
					pos = 1;  //设为左子树
				}
			}
		}
		//连接左右子树，pos=1,位置i赋给节点的left
		if(pos==1){
			bt[level].left=i;
		}
		//pos=-1,位置i赋给节点的right
		else{
			bt[level].right=i;
		}
	}
}
void main()
{
	int count, i;
	BtreeNode btree[MAX];
	int nodelist[MAX];
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input %d elements:\n",count);
	for(i=0; i<count; i++){
		scanf("%d",&nodelist[i]);
	}
	CreateTree(btree,nodelist,count);
	printf("the binary tree is:\n%s%6s%7s\n","data","left","right");
	for(i=0; i<count; i++){
		printf("%4d%6d%7d\n",btree[i].data,btree[i].left,btree[i].right);
	}
	printf("\n");
}