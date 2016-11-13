//-----���ļ���Ԥ����
#include <stdlib.h>
#include <stdio.h>

#define OK    1
#define ERROR 0
#define OVERFLOW -1

#define List_INIT_SPACE   100   //�洢�ռ��ʼ��
#define List_INC_SPACE   100   //�洢�ռ�������� 

typedef int ElemType;   //ָ��˳����е���������

typedef struct
{
	ElemType* elem;  //�洢�ռ��ַ(Ҳ��������)
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
	L.elem = (ElemType*)malloc(List_INIT_SPACE*sizeof(ElemType));  // (int*)malloc(100*sizeof(int))
	//���ڴ����ʧ�ܣ����˳�
	if(!L.elem) exit(OVERFLOW);
	//����һ���յ����Ա�L
	L.length = 0;
	L.listsize = List_INC_SPACE; //��ʼ���洢����
	return OK; 
}

/*******************************************
 �������� LocateElem(Sq_List &L, ElemType e)
 ������   �����룩SqList L˳���
 		  �����룩ElemType e, ��λԪ�� 
 ����ֵ�� int�ͣ����ض�λλ�ã�0��ʾʧ��
 ���ܣ�   ��˳����ж�λԪ�� 
*******************************************/ 
int LocateElem(Sq_List &L, ElemType e)
{
	int i = 1;
	//�������Ա�ָ��
	int *p = L.elem;
	//����Ԫ��e
	while(i <= L.length && *p++ != e)  //important
		i++; 
	if(i < L.length)
		return i;
	else 
		return ERROR;
}

/*��˳���ĳ���*/
int GetListLength(Sq_List L)
{
	return L.length;
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
int Sq_ListInsert(Sq_List &L, int i, ElemType e)
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
		newspace = (ElemType*)realloc(L.elem,(L.listsize+List_INC_SPACE)*sizeof(ElemType));
		//���洢����ʧ��
		if(!newspace) exit(OVERFLOW);
		//��Ԫ��ָ���»�ַ 
		L.elem = newspace;
		//���Ӵ洢��������һ���� 
		L.listsize += List_INC_SPACE; 
	} 
	//����ָ�����Ա�λ��i��β��ָ�� 
	int *p,*q; 
	//qָ��ָ�����λ��i��ǰһ�� 
	q = &(L.elem[i-1]); 
	for(p = &(L.elem[L.length-1]); p>=q; --p)
	//����Ԫ��֮���Ԫ������
		*(p+1) = *p;
	*q = e;
	++L.length;
	return OK; 
}

/*******************************************
 �������� Sq_ListDelete(Sq_List &L, int i, ElemType e)
 ������   �����룩SqList L˳���
 		  �����룩int i ɾ��λ�� 
 		  �����룩ElemType e, ɾ��Ԫ�� 
 ����ֵ�� 1��ʾʧ�ܣ�0��ʾʧ��
 ���ܣ�   ��˳���L��ɾ����i��Ԫ�أ���e������ֵ 
 ��ע��   i�ĺϷ�ֵΪ 1<=i<= ���Ա��� 
*******************************************/ 
int Sq_ListDelete(Sq_List &L, int i, ElemType e)
{
	//�ж�λ���Ƿ�Ϸ�
	if(i<1 || i>L.length + 1)
	{
		printf("i��ֵ���Ϸ���\n");
		return 0;
	 }
	//����ָ�����Ա�λ��i��β��ָ��
	int *p,*q; 
	//pΪ��ɾ��Ԫ�ص�λ�� 
	p = &(L.elem[i-1]); 
	//ȡɾ��Ԫ�ص�ֵ
	e = *p;
	//qָ��ָ�����Ա����һ��Ԫ��
	q =L.elem + L.length - 1; 
	for(++p; p<=q; ++p)
		*(p-1) = *p;    //����Ԫ��֮���Ԫ������
	--L.length;
	return OK; 	 	
}

/*************���Գ���*************/ 
int main()
{ 
	Sq_List R;
	int flag;    //Ϊ���жϵ��óɹ���񣬿��Լ��flag��ֵ
	flag = Sq_ListInit(R);
	
	//���÷���
	int i = 1;
	int elem; 
	//���� GetListLength ������ȡ���� 
	printf("The length of current list is %d\n",GetListLength(R));
	printf("input the element:"); //�û�����Ԫ��
	scanf("%d",&elem);
	if(Sq_ListInsert(R,i,elem))
		printf("succeed inserting!\n");
	printf("The length of current list is %d\n",GetListLength(R));
}


















