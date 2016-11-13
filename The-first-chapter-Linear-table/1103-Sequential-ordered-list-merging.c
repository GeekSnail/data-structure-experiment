#include <stdlib.h>
#include <stdio.h>
#define OK    1
#define ERROR 0
#define OVERFLOW -1
#define List_INIT_SPACE   100   //�洢�ռ��ʼ��
#define List_INC_SPACE   100   //�洢�ռ�������� 
typedef struct
{
	int* elem;  //�洢�ռ��ַ(Ҳ��������)
	int length;      //��ǰʵ�ʳ��ȣ����ܻᳬ���ѷ��������� 
	int listsize;    //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ�� 
 } Sq_List;

int Sq_ListInit(Sq_List* L)
{
	//���ڴ��з���ռ�
	L->elem = (int*)malloc(List_INIT_SPACE*sizeof(int));  // (int*)malloc(100*sizeof(int))	
	if(!L->elem) exit(OVERFLOW);  //���ڴ����ʧ�ܣ����˳�
	//����һ���յ����Ա�L
	L->length = 0;
	L->listsize = List_INC_SPACE; //��ʼ���洢����
	return OK; 
}

int Sq_ListInsert(Sq_List* L, int i, int e)
{
	//�ж�λ���Ƿ�Ϸ�
	if(i<1 || i>L->length + 1)
	{
		return 0;
	 } 
	//�����ȳ����ռ��ѷ���������������ٷ���
	if(L->length >= L->listsize) 
	{
		int *newspace;
		newspace = (int*)realloc(L->elem,(L->listsize+List_INC_SPACE)*sizeof(int));		
		if(!newspace) exit(OVERFLOW);   //���洢����ʧ��		
		L->elem = newspace;        //��Ԫ��ָ���»�ַ 		
		L->listsize += List_INC_SPACE;   //���Ӵ洢��������һ���� 
	} 
	int *p,*q;   	//����ָ�����Ա�λ��i��β��ָ�� 	 
	q = &(L->elem[i-1]);   //qָ��ָ�����λ��i��ǰһ��
	for(p = &(L->elem[L->length-1]); p>=q; --p)	
		*(p+1) = *p;  //����Ԫ��֮���Ԫ������
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
	pa = La.elem;   //����ָ��˳���ͷ����ָ��
	pb = Lb.elem;
	qa = La.elem + La.length - 1;  //����ָ��˳���β����ָ��
	qb = Lb.elem + Lb.length - 1;
	//����ϲ�����˳���Ŀռ䲢���������
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (int*)malloc(Lc->listsize*sizeof(int));
	if(!Lc->elem)
		exit(OVERFLOW);  //�洢����ʧ�� 
	
	while(pa<=qa && pb<=qb)  //���������Ա��ͷָ��һֱ������βָ�� 
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
	while(pa<=qa)    //����La��ʣ��Ԫ�� 
		*pc++ = *pa++;
	while(pb<=qb)    //����Lb��ʣ��Ԫ�� 
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
	//�������Ա�La 
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
	//�������Ա�Lb
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






