//---------库文件和预设定义
#include <stdlib.h>
#include <stdio.h>

#define OK    1
#define ERROR 0
#define OVERFLOW -1

#define List_INIT_SPACE   100   //存储空间初始化
#define List_INC_SPACE   100   //存储空间分配增量 

typedef struct
{
	int* elem;  //存储空间基址(也是数组名)
	int length;      //当前实际长度（可能会超出已分配容量） 
	int listsize;    //当前分配的存储容量（以sizeof(ElemType)为单位） 
 } Sq_List;
 
 /****************************************** 
 函数名： Sq_ListInit(Sq_List &L)
 参数：   （传入）SqList L，顺序表结构体L,存储线性表相关信息（&相当于传入L的地址） 
 返回值： int型，返回1表示创建成功，0表示失败
 功能：   初始化一个空顺序表
******************************************/ 
int Sq_ListInit(Sq_List &L)
{
	//在内存中分配空间
	L.elem = (int*)malloc(List_INIT_SPACE*sizeof(int));  // (int*)malloc(100*sizeof(int))	
	if(!L.elem) exit(OVERFLOW);  //若内存分配失败，则退出
	//构造一个空的线性表L
	L.length = 0;
	L.listsize = List_INC_SPACE; //初始化存储容量
	return OK; 
}

/*******************************************
 函数名： Sq_ListInsert(Sq_List &L, int i, ElemType e)
 参数：   （传入）SqList L顺序表，
 		  （传入）int i插入位置 
 		  （传入）ElemType e, 定位元素 
 返回值： 1表示失败，0表示失败
 功能：   在顺序表L中的第i个位置前插入新元素e
 备注：   i的合法值为 1<=i<= 线性表长度+1   (i为物理位置，即第i个元素的下标为 i-1)
*******************************************/ 
int Sq_ListInsert(Sq_List &L, int i, int e)
{
	//判断位置是否合法
	if(i<1 || i>L.length + 1)
	{
		printf("i的值不合法！\n");
		return 0;
	 } 
	//若长度超出空间已分配容量，则进行再分配
	if(L.length >= L.listsize) 
	{
		int *newspace;
		newspace = (int*)realloc(L.elem,(L.listsize+List_INC_SPACE)*sizeof(int));		
		if(!newspace) exit(OVERFLOW);   //若存储分配失败		
		L.elem = newspace;        //将元素指向新基址 		
		L.listsize += List_INC_SPACE;   //增加存储容量（多一倍） 
	} 
	
	int *p,*q;   	//定义指向线性表位置i和尾的指针 	 
	q = &(L.elem[i-1]);   //q指针指向插入位置i的前一个
	for(p = &(L.elem[L.length-1]); p>=q; --p)	
		*(p+1) = *p;  //插入元素之后的元素右移
	*q = e;
	++L.length;
	return OK; 
}

//功能：显示顺序表L中的各个元素值
void PrintList(Sq_List L)
{
	for(int i=0; i<L.length; i++) {
		printf("%d ",*L.elem++);
	}
	printf("\n");
 } 
 
/*******************************************
 函数名： Sq_ListMerge(Sq_List La, Sq_List Lb, Sq_List &Lc)
 参数：   （传入）Sq_List La    顺序表La
 		  （传入）Sq_List Lb    顺序表Lb 
 		  （传入）Sq_List Lc    合并后的顺序表Lc
 功能：   合并两项顺序表（顺序表数据元素按值非递减有序排列） 
*******************************************/ 
void Sq_ListMerge(Sq_List La, Sq_List Lb, Sq_List &Lc)
{
	int *pa, *pb, *pc;   
	int *qa, *qb;        
	pa = La.elem;   //定义指向顺序表头部的指针
	pb = Lb.elem;
	qa = La.elem + La.length - 1;  //定义指向顺序表尾部的指针
	qb = Lb.elem + Lb.length - 1;
	//分配合并后新顺序表的空间并定义其参数
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (int*)malloc(Lc.listsize*sizeof(int));
	if(!Lc.elem)
		exit(OVERFLOW);  //存储分配失败 
	
	while(pa<=qa && pb<=qb)  //两有序线性表从头指针一直遍历到尾指针 
	{
		if(*pa<=*pb)   //*pa和*pb可能相同，相同时只插入一次 
			*pc++ = *pa++;
		else 
			*pc++ = *pb++; 
	} 
	while(pa<=qa)    //插入La的剩余元素 
		*pc++ = *pa++;
	while(pb<=qb)    //插入Lb的剩余元素 
		*pc++ = *pb++;
 } 
/*******************************************
 函数名： DeleteEqual(Sq_List &Lc, int n)
 参数：   （传入）Sq_List Lc    合并后的顺序表Lc
 功能：   删除合并后的顺序表的多余的相同元素（顺序表数据元素按值非递减有序排列） 
*******************************************/ 
bool DeleteEqual(Sq_List &L)
{
	int i, j, k, t=L.length;
	for(i=0; i<L.length-1; i++) {
		for(j=i+1; j<L.length; j++) {
			if(L.elem[i] == L.elem[j]) {
				for(k=j; k<L.length; k++) {
					L.elem[k] = L.elem[k+1];
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
int main()
{    
	Sq_List La, Lb, Lc;
	//建立线性表La 
	if(Sq_ListInit(La))
	{                   
		Sq_ListInsert(La,1,3);
		Sq_ListInsert(La,2,5);
		Sq_ListInsert(La,3,8);
		Sq_ListInsert(La,4,11);
		PrintList(La);
	}
	else 
		printf("create failed!\n");
	//建立线性表Lb
	if(Sq_ListInit(Lb))
	{
		Sq_ListInsert(Lb,1,2);
		Sq_ListInsert(Lb,2,6);
		Sq_ListInsert(Lb,3,8);
		Sq_ListInsert(Lb,4,9);
		Sq_ListInsert(Lb,5,11);
		Sq_ListInsert(Lb,6,15);
		PrintList(Lb);
	}
	else 
		printf("create failed!\n");
	Sq_ListMerge(La,Lb,Lc);
	DeleteEqual(Lc);
	PrintList(Lc);
 } 






