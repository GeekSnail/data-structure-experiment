#include <stdio.h>
#define MAX 32

//int* bt ������, int list[] ��������, n ��������
void CreateTree(int* bt, int list[], int n)
{
	int i;
	int level;  //��
	for(i=0; i<MAX; i++){
		bt[i]=0;
	}
	bt[0]=list[0]; //�������������ڵ�
	for(i=0; i<n; i++){
		level=1;  //�ӵ�һ�㿪ʼ����
		//�ж��Ƿ�����������
		while(bt[level]!=0){
			//����������
			if(list[i]<bt[level]){
				level = level * 2;
			}
			//����������
			else{
				level = level * 2 + 1;
			}
		}
		bt[level] = list[i];  //�ڵ㸳ֵ
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