#include <stdio.h>
#define MAX 32

//int* bt 二叉树, int list[] 数据数组, n 数据数量
void CreateTree(int* bt, int list[], int n)
{
	int i;
	int level;  //层
	for(i=0; i<MAX; i++){
		bt[i]=0;
	}
	bt[0]=list[0]; //建立二叉树根节点
	for(i=0; i<n; i++){
		level=1;  //从第一层开始建立
		//判断是否有子树存在
		while(bt[level]!=0){
			//建立左子树
			if(list[i]<bt[level]){
				level = level * 2;
			}
			//建立右子树
			else{
				level = level * 2 + 1;
			}
		}
		bt[level] = list[i];  //节点赋值
	}
}
void main()
{
	int count, i;
	int btree[MAX];
	int nodelist[MAX];
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input elements:\n");
	for(i=0; i<count; i++){
		scanf("%d",&nodelist[i]);
	}
	CreateTree(btree,nodelist,count);
	printf("the binary tree is:\n");
	for(i=0; i<MAX; i++){
		printf("%d ",btree[i]);
	}
	printf("\n");
}