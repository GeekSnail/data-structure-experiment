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

int Sq_ListInit(Sq_List* L)
{
	//在内存中分配空间
	L->elem = (int*)malloc(List_INIT_SPACE*sizeof(int));  // (int*)malloc(100*sizeof(int))	
	if(!L->elem) exit(OVERFLOW);  //若内存分配失败，则退出
	//构造一个空的线性表L
	L->length = 0;
	L->listsize = List_INC_SPACE; //初始化存储容量
	return OK; 
}

int Sq_ListInsert(Sq_List* L, int i, int e)
{
	//判断位置是否合法
	if(i<1 || i>L->length + 1)
	{
		return 0;
	 } 
	//若长度超出空间已分配容量，则进行再分配
	if(L->length >= L->listsize) 
	{
		int *newspace;
		newspace = (int*)realloc(L->elem,(L->listsize+List_INC_SPACE)*sizeof(int));		
		if(!newspace) exit(OVERFLOW);   //若存储分配失败		
		L->elem = newspace;        //将元素指向新基址 		
		L->listsize += List_INC_SPACE;   //增加存储容量（多一倍） 
	} 
	int *p,*q;   	//定义指向线性表位置i和尾的指针 	 
	q = &(L->elem[i-1]);   //q指针指向插入位置i的前一个
	for(p = &(L->elem[L->length-1]); p>=q; --p)	
		*(p+1) = *p;  //插入元素之后的元素右移
	*q = e;
	++L->length;
	return OK; 
}

void PrintList(Sq_List L)
{
	int i;
	for(i=0; i<L.length; i++) {
		printf("%d\n",*L.elem++);
	}
 } 

void Sq_ListMerge(Sq_List La, Sq_List Lb, Sq_List *Lc)
{
	int *pa, *pb, *pc;   
	int *qa, *qb;        
	pa = La.elem;   //定义指向顺序表头部的指针
	pb = Lb.elem;
	qa = La.elem + La.length - 1;  //定义指向顺序表尾部的指针
	qb = Lb.elem + Lb.length - 1;
	//分配合并后新顺序表的空间并定义其参数
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (int*)malloc(Lc->listsize*sizeof(int));
	if(!Lc->elem)
		exit(OVERFLOW);  //存储分配失败 
	
	while(pa<=qa && pb<=qb)  //两有序线性表从头指针一直遍历到尾指针 
	{
		if(*pa<*pb){
			*pc++ = *pa++;
		}
//		else if(*pa=*pb){
//			*pc++ = *pa++; 
//			pb++; Lc->length--; 
//		}	
		else 
			*pc++ = *pb++; 
	} 
	while(pa<=qa)    //插入La的剩余元素 
		*pc++ = *pa++;
	while(pb<=qb)    //插入Lb的剩余元素 
		*pc++ = *pb++;
 } 
int main()
{
	int i=0,n;
	Sq_List La, Lb, Lc;
	Sq_List *pa, *pb, *pc;
	pa=&La;
	pb=&Lb;
	pc=&Lc; 
	//建立线性表La 
	if(Sq_ListInit(pa))
	{
		scanf("%d",&n);
		while(n!=0) {
			i++;
			Sq_ListInsert(pa,i,n);
			scanf("%d",&n);	
		} 
		//PrintList(La);
	}
	else 
		exit(1);
	i=0;
	//建立线性表Lb
	if(Sq_ListInit(pb))
	{
		scanf("%d",&n);
		while(n!=0) {
			i++;
			Sq_ListInsert(pb,i,n);	
			scanf("%d",&n);
		} 
		//PrintList(Lb);
	}
	else 
		exit(1);
	Sq_ListMerge(La,Lb,pc);
	//DeleteEqual(pc);
	PrintList(Lc);
 } 






