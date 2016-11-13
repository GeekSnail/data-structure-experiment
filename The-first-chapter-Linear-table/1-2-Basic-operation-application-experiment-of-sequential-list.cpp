#include <stdlib.h>
#include <stdio.h>

#define OVERFLOW -1
#define MAX 100

typedef struct
{
	int data[MAX];  //存储空间初始分配量为100，下标访问为1~100 
	int length;     //A[0]存储顺序表的长度 
 } List;
 
int ListInit(List &L)
{
	int *p = L.data;
	p = (int*)malloc((MAX)*sizeof(int));  // (int*)malloc(100*sizeof(int))
	if(!L.data) exit(OVERFLOW);    //若内存分配失败，则退出
	L.length = 0;
	return true; 
}

int ListInsert(List &L, int i, int e)
{
	//判断位置是否合法   i表示第i个元素 
	if(i<1 || i>L.length + 1)
	{
		printf("i的值不合法！\n");
		return 0;
	 } 
	//若长度超出空间已分配容量，则进行再分配
	if(L.length >= MAX) 
	{
		int *newspace;
		newspace = (int*)realloc(L.data,(2*MAX)*sizeof(int));
		//若存储分配失败
		if(!newspace) exit(OVERFLOW);
		//将元素指向新基址 
		int *d = L.data;
		d = newspace;
	} 
	//定义指向线性表位置i和尾的指针 
	int *p,*q; 
	//q指针指向插入位置i的前一个 
	q = &(L.data[i-1]); 
	for(p = &(L.data[L.length-1]); p>=q; --p)
	//插入元素之后的元素右移
		*(p+1) = *p;
	*q = e;
	++L.length;
	return true; 
}

/*******************************************
 函数名： deleteEqual(List A, int n)
 参数：   List A顺序表，int n顺序表长度 
 返回值： 无
 功能：   删除顺序表中多余的值相同元素 
 备注：   顺序表用一维数组实现，故List A可以理解为 int A[N] 
*******************************************/ 
bool DeleteEqual(List &L)
{
	int i, j, k, t=L.length;
	for(i=0; i<L.length-1; i++) {
		for(j=i+1; j<L.length; j++) {
			if(L.data[i] == L.data[j]) {
				for(k=j; k<L.length; k++) {
					L.data[k] = L.data[k+1];
				}
				L.length--;
				j--;   //三个及以上可能相同的情况 
			}	
		}
	}
	if(L.length<t)
		return true;
	return false;
}

/*******************************************
 函数名： maxMin(List A, int n)
 参数：   List A顺序表，int n顺序表长度 
 返回值： 无
 功能：   查找最大值和最小值元素 
 备注：   顺序表用一维数组实现，故List A可以理解为 int A[N] 
*******************************************/ 
void maxMin(List L)
{
	int max,min,i;
	max=L.data[0];
	min=L.data[0];
	for(i=1; i<L.length; i++) {
		if(L.data[i]>max) {
			max = L.data[i];
		}
		else if(L.data[i]<min) {
			min = L.data[i];
		}
	}
	printf("\nmax=%d, min=%d\n",max,min);	
} 

/*************测试程序*************/ 
int main()
{ 
	List L;
	int i=1;
	int elem; 
	if(!ListInit) 
		printf("初始化失败......");
	printf("input the 5 element:\n"); //用户输入元素
	for(i=1; i<=5; i++)
	{
		scanf("%d",&elem);
		if(ListInsert(L,i,elem))
			printf("succeed inserting %d\n",L.data[i-1]);
	}
	if(DeleteEqual(L))
	{
		printf("删除顺序表中多余的值相同元素：\n");
		for(i=0; i<L.length; i++)
		{
			printf("%d ",L.data[i]);
		}		
	}else{
		printf("不存在相同元素！\n");
	}
	maxMin(L);
}

















