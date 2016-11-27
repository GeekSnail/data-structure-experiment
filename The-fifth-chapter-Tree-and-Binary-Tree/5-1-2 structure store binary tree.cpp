#include <stdio.h>
#define MAX 32
//�������ṹ
typedef struct btree{
	int data;
	int left;   //���������λ�� 
	int right;  //���������λ��
}BtreeNode;
//����������ṹ����
BtreeNode btree[MAX];

//int* bt ������, int list[] ��������, n ��������
void CreateTree(BtreeNode* bt, int list[], int n)
{
	int i;
	int level;  //��¼�浱ǰ�ڵ��left��rightֵ
	int pos;  //��־��������1��������-1

	bt[0].data = list[0]; //�������������ڵ�
	bt[0].left = -1;  //������λ�ó�ʼ��
	bt[0].right = -1;  //������λ�ó�ʼ��
	for(i=1; i<n; i++){
		bt[i].data = list[i];  //Ԫ�ش���ڵ�
		bt[i].left = -1;
		bt[i].right = -1;
		level=0;  //�Ӹ��ڵ㿪ʼ
		pos = 0;  //����ÿ���ڵ�ʱ��posֵ����
		while(pos == 0){
			//���ڵ��ֵС�ڵ�ǰֵ����ǰֵ����������
			if(bt[level].data<list[i]){
				//�Ƿ�����һ��
				if(bt[level].right != -1){
					level = bt[level].right;
				}
				else{
					pos = -1;  //��Ϊ������
				}
			}
			//����������
			else{
				//�Ƿ�����һ��
				if(bt[level].left != -1){
					level = bt[level].left;
				}
				else{
					pos = 1;  //��Ϊ������
				}
			}
		}
		//��������������pos=1,λ��i�����ڵ��left
		if(pos==1){
			bt[level].left=i;
		}
		//pos=-1,λ��i�����ڵ��right
		else{
			bt[level].right=i;
		}
	}
}
void main()
{
	int count, i;
	BtreeNode btree[MAX];
	int nodelist[MAX];
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input %d elements:\n",count);
	for(i=0; i<count; i++){
		scanf("%d",&nodelist[i]);
	}
	CreateTree(btree,nodelist,count);
	printf("the binary tree is:\n%s%6s%7s\n","data","left","right");
	for(i=0; i<count; i++){
		printf("%4d%6d%7d\n",btree[i].data,btree[i].left,btree[i].right);
	}
	printf("\n");
}