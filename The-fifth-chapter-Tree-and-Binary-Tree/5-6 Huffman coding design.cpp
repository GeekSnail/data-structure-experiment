/**************************************************************
*** 构造哈夫曼树：
*** (1)将给定的n个权值{W1,W2,...,Wn}作为n个根节点的权值构造一个具有n棵二叉树的森林{T1,T2,...,Tn},
***     其中每棵二叉树只有一个根节点
*** (2)在森林中选取两棵根节点权值最小的二叉树作为左右子树，构造一颗新二叉树，
***     新二叉树的根节点权值为两棵树根的权值之和，需要多加n-1个节点；
*** (3)在森林中，将上面选择的这两棵根权值最小的二叉树从森林中删除，
***     并将刚刚新构造的二叉树加入到森林中； 
*** (4)重复上面(2)和(3)，直到森林中只有一棵二叉树为止。这棵二叉树就是哈夫曼树
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE 59
#define MAXBIT 10
//哈夫曼树结点的存储结构
typedef struct btnode{
	int data;
	int Weight;  //权重
	int Flag;    //标识是否待构结点，是用0表示，否用1表示
	int Parent;  //父节点，存放每个结点的双亲在数组中的序号，初始为0
	int LChild, RChild;  //左右结点，存放每个结点左右子女在数组中的序号，初始为0
}hnodetype;

typedef struct{
	int Bit[MAXBIT];
	int Start;
}hcodetype;

/**************************************************************
*** 函数：void InitHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) 哈夫曼结点初始化
*** 参数：hnodetype HuffNode[]  哈夫曼树结点
***       hcodetype HuffCode[]  哈夫曼树编码树结点
***       int n  结点数量
*** 返回值: 无
**************************************************************/
void InitHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i;
	//把生成的节点初始化，把指向父亲的指针，左孩子、右孩子的指针都先置空
	for(i=0; i<2*n-1; i++){
		HuffNode[i].Weight = 0;
		HuffNode[i].Parent = 0;
		HuffNode[i].Flag = 0;
		HuffNode[i].LChild = -1;
		HuffNode[i].RChild = -1;
	}
	for(i=0; i<n; i++){
		getchar();
		printf("输入第%d个叶节点值:",i+1);
		scanf("%c",&HuffNode[i].data);
		printf("输入对应节点权值:");
		scanf("%d",&HuffNode[i].Weight);
	}
}

/**************************************************************
*** 函数：void OutputHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) 输出哈夫曼编码
*** 参数：hnodetype HuffNode[]  哈夫曼树结点
***       hcodetype HuffCode[]  哈夫曼树编码树结点
***       int n  结点数量
*** 返回值: 无
**************************************************************/
void OutputHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i,j;
	printf("%d个叶节点对应编码为：\n",n);
	for(i=0; i<n; i++){
		printf("%c----",HuffNode[i].data);
		for(j=HuffCode[i].Start; j<n; j++){
			printf("%d",HuffCode[i].Bit[j]);
		}
		printf("\n");
	}
}

/**************************************************************
*** 函数：void Huffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
***       构造哈夫曼树，根据树生成哈夫曼编码
*** 参数：hnodetype HuffNode[]  哈夫曼树结点
***       hcodetype HuffCode[]  哈夫曼树编码树结点
***       int n  结点数量
*** 返回值: 无
**************************************************************/
void Haffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i,j,m1,m2,x1,x2,c,p;
	hcodetype cd;  //定义结构体暂存编码
	for(i=0; i<n-1; i++){  //构造哈夫曼树，自底向上添加n-1个根节点
		//根据哈夫曼树的构成过程，始终选择最小权值的两个节点构成一棵二叉树
		m1 = m2 = MAXVALUE;  //记录最小的两个权值，每次循环重置10000
		//x1和x2为最小权重的两个节点位置
		x1 = x2 = 0;
		//循环从flag=0（待构）的节点(包括新增)中找两个最小权值的节点
		for(j=0; j<n+i; j++){
			if(HuffNode[j].Weight<m1 && HuffNode[j].Flag==0){
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].Weight;  //更新最小权值
				x1 = j;  //记下x1的地址
			}
			else if(HuffNode[j].Weight<m2 && HuffNode[j].Flag==0){
				m2 = HuffNode[j].Weight;  //更新次小权值
				x2 = j;  //记下x2的地址
			}
		}
		//把找到的两个节点按照哈夫曼树的规则构建成一个二叉树，x1为左孩子，x2为右孩子
		HuffNode[x1].Parent = n+i;
		HuffNode[x2].Parent = n+i;
		HuffNode[x1].Flag = 1;  //将x1的标志置1，即已构
		HuffNode[x2].Flag = 1;  //将x2的标志置1，即已构
		HuffNode[n+i].Weight = HuffNode[x1].Weight + HuffNode[x2].Weight;
		HuffNode[n+i].LChild = x1;
		HuffNode[n+i].RChild = x2;
	}
	
	//根据哈夫曼树自底向上生成哈夫曼编码
	for(i=0; i<n; i++){
		cd.Start = n-1;  //哈夫曼编码最后位置
		c = i;  //孩子节点位置
		p = HuffNode[c].Parent;  //取当前节点的父节点位置

		while(p!=0){  //当父节点不为根节点的时候，逆序往上找
			//如果当前是左孩子，则编码为0
			if(HuffNode[p].LChild==c) {
				cd.Bit[cd.Start] = 0;
			}
			//当前是右孩子的话编码为1
			else{
				cd.Bit[cd.Start] = 1;
			}
			cd.Start--;
			c = p;  //把父节点作为上一级孩子节点
			p = HuffNode[c].Parent;  //取当前节点的父节点位置
		}
		for(j=cd.Start+1; j<n; j++){
			HuffCode[i].Bit[j] = cd.Bit[j];
			HuffCode[i].Start = cd.Start+1;
		}
	}
}

int main()
{
	hnodetype HuffNode[MAXNODE];
	hcodetype HuffCode[MAXLEAF];
	int n;
	printf("input the number of leaves(n<30):\n");
	scanf("%d",&n);

	InitHaffman(HuffNode, HuffCode, n);
	Haffman(HuffNode, HuffCode, n);
	OutputHaffman(HuffNode, HuffCode, n);
	return 0;
}
/** 测试 ******************************************************
*** n = 6
*** 输入数据: a b c d e f
*** 对应权值: 3 9 12 3 2 71
*** 输出：
	input the number of leaves(n<30):
	6
	输入第1个叶节点值:a
	输入对应节点权值:3
	输入第2个叶节点值:b
	输入对应节点权值:9
	输入第3个叶节点值:c
	输入对应节点权值:12
	输入第4个叶节点值:d
	输入对应节点权值:3
	输入第5个叶节点值:e
	输入对应节点权值:2
	输入第6个叶节点值:f
	输入对应节点权值:71
	6个叶节点对应编码为：
	a----01011
	b----011
	c----00
	d----0100
	e----01010
	f----1
**************************************************************/




