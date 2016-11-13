//-----库文件和预定义
#include <stdlib.h>
#include <stdio.h>

#define OK    1
#define ERROR 0
#define OVERFLOW -1

#define List_INIT_SPACE   100   //存储空间初始化
#define List_INC_SPACE   100   //存储空间分配增量 

typedef int ElemType;   //指定顺序表中的数据类型

typedef struct
{
	ElemType* elem;  //存储空间基址(也是数组名)
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
	L.elem = (ElemType*)malloc(List_INIT_SPACE*sizeof(ElemType));  // (int*)malloc(100*sizeof(int))
	//若内存分配失败，则退出
	if(!L.elem) exit(OVERFLOW);
	//构造一个空的线性表L
	L.length = 0;
	L.listsize = List_INC_SPACE; //初始化存储容量
	return OK; 
}

/*******************************************
 函数名： LocateElem(Sq_List &L, ElemType e)
 参数：   （传入）SqList L顺序表，
 		  （传入）ElemType e, 定位元素 
 返回值： int型，返回定位位置，0表示失败
 功能：   在顺序表中定位元素 
*******************************************/ 
int LocateElem(Sq_List &L, ElemType e)
{
	int i = 1;
	//定义线性表指针
	int *p = L.elem;
	//查找元素e
	while(i <= L.length && *p++ != e)  //important
		i++; 
	if(i < L.length)
		return i;
	else 
		return ERROR;
}

/*求顺序表的长度*/
int GetListLength(Sq_List L)
{
	return L.length;
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
int Sq_ListInsert(Sq_List &L, int i, ElemType e)
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
		newspace = (ElemType*)realloc(L.elem,(L.listsize+List_INC_SPACE)*sizeof(ElemType));
		//若存储分配失败
		if(!newspace) exit(OVERFLOW);
		//将元素指向新基址 
		L.elem = newspace;
		//增加存储容量（多一倍） 
		L.listsize += List_INC_SPACE; 
	} 
	//定义指向线性表位置i和尾的指针 
	int *p,*q; 
	//q指针指向插入位置i的前一个 
	q = &(L.elem[i-1]); 
	for(p = &(L.elem[L.length-1]); p>=q; --p)
	//插入元素之后的元素右移
		*(p+1) = *p;
	*q = e;
	++L.length;
	return OK; 
}

/*******************************************
 函数名： Sq_ListDelete(Sq_List &L, int i, ElemType e)
 参数：   （传入）SqList L顺序表，
 		  （传入）int i 删除位置 
 		  （传入）ElemType e, 删除元素 
 返回值： 1表示失败，0表示失败
 功能：   在顺序表L中删除第i个元素，用e返回其值 
 备注：   i的合法值为 1<=i<= 线性表长度 
*******************************************/ 
int Sq_ListDelete(Sq_List &L, int i, ElemType e)
{
	//判断位置是否合法
	if(i<1 || i>L.length + 1)
	{
		printf("i的值不合法！\n");
		return 0;
	 }
	//定义指向线性表位置i和尾的指针
	int *p,*q; 
	//p为被删除元素的位置 
	p = &(L.elem[i-1]); 
	//取删除元素的值
	e = *p;
	//q指针指向线性表最后一个元素
	q =L.elem + L.length - 1; 
	for(++p; p<=q; ++p)
		*(p-1) = *p;    //插入元素之后的元素右移
	--L.length;
	return OK; 	 	
}

/*************测试程序*************/ 
int main()
{ 
	Sq_List R;
	int flag;    //为了判断调用成功与否，可以检查flag的值
	flag = Sq_ListInit(R);
	
	//调用方法
	int i = 1;
	int elem; 
	//调用 GetListLength 方法获取长度 
	printf("The length of current list is %d\n",GetListLength(R));
	printf("input the element:"); //用户输入元素
	scanf("%d",&elem);
	if(Sq_ListInsert(R,i,elem))
		printf("succeed inserting!\n");
	printf("The length of current list is %d\n",GetListLength(R));
}


















