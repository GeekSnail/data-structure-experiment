//---------���ļ���Ԥ�趨��
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
 
 /****************************************** 
 �������� Sq_ListInit(Sq_List &L)
 ������   �����룩SqList L��˳���ṹ��L,�洢���Ա������Ϣ��&�൱�ڴ���L�ĵ�ַ�� 
 ����ֵ�� int�ͣ�����1��ʾ�����ɹ���0��ʾʧ��
 ���ܣ�   ��ʼ��һ����˳���
******************************************/ 
int Sq_ListInit(Sq_List &L)
{
	//���ڴ��з���ռ�
	L.elem = (int*)malloc(List_INIT_SPACE*sizeof(int));  // (int*)malloc(100*sizeof(int))	
	if(!L.elem) exit(OVERFLOW);  //���ڴ����ʧ�ܣ����˳�
	//����һ���յ����Ա�L
	L.length = 0;
	L.listsize = List_INC_SPACE; //��ʼ���洢����
	return OK; 
}

/*******************************************
 �������� Sq_ListInsert(Sq_List &L, int i, ElemType e)
 ������   �����룩SqList L˳���
 		  �����룩int i����λ�� 
 		  �����룩ElemType e, ��λԪ�� 
 ����ֵ�� 1��ʾʧ�ܣ�0��ʾʧ��
 ���ܣ�   ��˳���L�еĵ�i��λ��ǰ������Ԫ��e
 ��ע��   i�ĺϷ�ֵΪ 1<=i<= ���Ա���+1   (iΪ����λ�ã�����i��Ԫ�ص��±�Ϊ i-1)
*******************************************/ 
int Sq_ListInsert(Sq_List &L, int i, int e)
{
	//�ж�λ���Ƿ�Ϸ�
	if(i<1 || i>L.length + 1)
	{
		printf("i��ֵ���Ϸ���\n");
		return 0;
	 } 
	//�����ȳ����ռ��ѷ���������������ٷ���
	if(L.length >= L.listsize) 
	{
		int *newspace;
		newspace = (int*)realloc(L.elem,(L.listsize+List_INC_SPACE)*sizeof(int));		
		if(!newspace) exit(OVERFLOW);   //���洢����ʧ��		
		L.elem = newspace;        //��Ԫ��ָ���»�ַ 		
		L.listsize += List_INC_SPACE;   //���Ӵ洢��������һ���� 
	} 
	
	int *p,*q;   	//����ָ�����Ա�λ��i��β��ָ�� 	 
	q = &(L.elem[i-1]);   //qָ��ָ�����λ��i��ǰһ��
	for(p = &(L.elem[L.length-1]); p>=q; --p)	
		*(p+1) = *p;  //����Ԫ��֮���Ԫ������
	*q = e;
	++L.length;
	return OK; 
}

//���ܣ���ʾ˳���L�еĸ���Ԫ��ֵ
void PrintList(Sq_List L)
{
	for(int i=0; i<L.length; i++) {
		printf("%d ",*L.elem++);
	}
	printf("\n");
 } 
 
/*******************************************
 �������� Sq_ListMerge(Sq_List La, Sq_List Lb, Sq_List &Lc)
 ������   �����룩Sq_List La    ˳���La
 		  �����룩Sq_List Lb    ˳���Lb 
 		  �����룩Sq_List Lc    �ϲ����˳���Lc
 ���ܣ�   �ϲ�����˳���˳�������Ԫ�ذ�ֵ�ǵݼ��������У� 
*******************************************/ 
void Sq_ListMerge(Sq_List La, Sq_List Lb, Sq_List &Lc)
{
	int *pa, *pb, *pc;   
	int *qa, *qb;        
	pa = La.elem;   //����ָ��˳���ͷ����ָ��
	pb = Lb.elem;
	qa = La.elem + La.length - 1;  //����ָ��˳���β����ָ��
	qb = Lb.elem + Lb.length - 1;
	//����ϲ�����˳���Ŀռ䲢���������
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (int*)malloc(Lc.listsize*sizeof(int));
	if(!Lc.elem)
		exit(OVERFLOW);  //�洢����ʧ�� 
	
	while(pa<=qa && pb<=qb)  //���������Ա��ͷָ��һֱ������βָ�� 
	{
		if(*pa<=*pb)   //*pa��*pb������ͬ����ͬʱֻ����һ�� 
			*pc++ = *pa++;
		else 
			*pc++ = *pb++; 
	} 
	while(pa<=qa)    //����La��ʣ��Ԫ�� 
		*pc++ = *pa++;
	while(pb<=qb)    //����Lb��ʣ��Ԫ�� 
		*pc++ = *pb++;
 } 
/*******************************************
 �������� DeleteEqual(Sq_List &Lc, int n)
 ������   �����룩Sq_List Lc    �ϲ����˳���Lc
 ���ܣ�   ɾ���ϲ����˳���Ķ������ͬԪ�أ�˳�������Ԫ�ذ�ֵ�ǵݼ��������У� 
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
				j--;   //���������Ͽ�����ͬ����� 
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
	//�������Ա�La 
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
	//�������Ա�Lb
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






