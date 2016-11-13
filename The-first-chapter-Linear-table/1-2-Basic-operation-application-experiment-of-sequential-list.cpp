#include <stdlib.h>
#include <stdio.h>

#define OVERFLOW -1
#define MAX 100

typedef struct
{
	int data[MAX];  //�洢�ռ��ʼ������Ϊ100���±����Ϊ1~100 
	int length;     //A[0]�洢˳���ĳ��� 
 } List;
 
int ListInit(List &L)
{
	int *p = L.data;
	p = (int*)malloc((MAX)*sizeof(int));  // (int*)malloc(100*sizeof(int))
	if(!L.data) exit(OVERFLOW);    //���ڴ����ʧ�ܣ����˳�
	L.length = 0;
	return true; 
}

int ListInsert(List &L, int i, int e)
{
	//�ж�λ���Ƿ�Ϸ�   i��ʾ��i��Ԫ�� 
	if(i<1 || i>L.length + 1)
	{
		printf("i��ֵ���Ϸ���\n");
		return 0;
	 } 
	//�����ȳ����ռ��ѷ���������������ٷ���
	if(L.length >= MAX) 
	{
		int *newspace;
		newspace = (int*)realloc(L.data,(2*MAX)*sizeof(int));
		//���洢����ʧ��
		if(!newspace) exit(OVERFLOW);
		//��Ԫ��ָ���»�ַ 
		int *d = L.data;
		d = newspace;
	} 
	//����ָ�����Ա�λ��i��β��ָ�� 
	int *p,*q; 
	//qָ��ָ�����λ��i��ǰһ�� 
	q = &(L.data[i-1]); 
	for(p = &(L.data[L.length-1]); p>=q; --p)
	//����Ԫ��֮���Ԫ������
		*(p+1) = *p;
	*q = e;
	++L.length;
	return true; 
}

/*******************************************
 �������� deleteEqual(List A, int n)
 ������   List A˳���int n˳����� 
 ����ֵ�� ��
 ���ܣ�   ɾ��˳����ж����ֵ��ͬԪ�� 
 ��ע��   ˳�����һά����ʵ�֣���List A�������Ϊ int A[N] 
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
				j--;   //���������Ͽ�����ͬ����� 
			}	
		}
	}
	if(L.length<t)
		return true;
	return false;
}

/*******************************************
 �������� maxMin(List A, int n)
 ������   List A˳���int n˳����� 
 ����ֵ�� ��
 ���ܣ�   �������ֵ����СֵԪ�� 
 ��ע��   ˳�����һά����ʵ�֣���List A�������Ϊ int A[N] 
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

/*************���Գ���*************/ 
int main()
{ 
	List L;
	int i=1;
	int elem; 
	if(!ListInit) 
		printf("��ʼ��ʧ��......");
	printf("input the 5 element:\n"); //�û�����Ԫ��
	for(i=1; i<=5; i++)
	{
		scanf("%d",&elem);
		if(ListInsert(L,i,elem))
			printf("succeed inserting %d\n",L.data[i-1]);
	}
	if(DeleteEqual(L))
	{
		printf("ɾ��˳����ж����ֵ��ͬԪ�أ�\n");
		for(i=0; i<L.length; i++)
		{
			printf("%d ",L.data[i]);
		}		
	}else{
		printf("��������ͬԪ�أ�\n");
	}
	maxMin(L);
}

















