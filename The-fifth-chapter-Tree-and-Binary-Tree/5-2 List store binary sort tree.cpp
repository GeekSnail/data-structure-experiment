/**************************************************************
*** ����ṹ��������������(��С�Ҵ����Բ������������������)
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//����������洢�ṹ
typedef struct btnode{
	int data;
	struct btnode *Llink;   //���������λ�� 
	struct btnode *Rlink;  //���������λ��
}btnode, *btreetype;

/**************************************************************
*** ������btreetype CreateTree(int n)	����������
*** ������int n
*** ����ֵ: �����������ڵ㣩ָ��
**************************************************************/
btreetype CreateTree(int n)
{
	int i;
	btreetype root = NULL;

	for(i=0; i<n; i++){
		btreetype newNode;
		btreetype currentNode;
		btreetype parentNode;

		//�����½ڵ�
		newNode = (btreetype)malloc(sizeof(btnode));
		scanf("%d",&newNode->data);  //�½ڵ㸳ֵ, ��ֵ��˳��Ҳ�ǰ��������˳��
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		currentNode = root;  //�洢��ǰ�ڵ�ָ��
		if(currentNode==NULL){  //��ָ����ڵ��ָ��Ϊ�գ���һ��ѭ����
			root = newNode;
		}
		else {  
			//��ͨ�����������½ڵ�ĸ��ڵ�
			//��ָ��ǰ�ڵ��ָ�벻Ϊ�գ��Ӹ��ڵ㿪ʼ
			while(currentNode!=NULL){  
				//�洢��ǰ�ڵ���Ϊ���ڵ㣬��ѭ�����õ�
				parentNode = currentNode;  
				//���½ڵ���ֵС�ڵ�ǰ�ڵ���ֵ
				if(newNode->data < currentNode->data){
					//��ǰ�ڵ�ָ����������
					currentNode = currentNode->Llink;
				}
				else {
					//��ǰ�ڵ�ָ����������
					currentNode = currentNode->Rlink;
				}
			}
			//���½ڵ���ֵС�ڸ��ڵ���ֵ
			if(newNode->data < parentNode->data){
				//���ڵ��������ָ��ָ���½ڵ�
				parentNode->Llink = newNode;
			}
			else {
				parentNode->Rlink = newNode;
			}
		}
	}
	return root;
}
/**************************************************************
*** ������void InOrder(btreetype &root)  ����������������ݹ飩
*** ������btreetype &root  ������ָ��
*** ����ֵ: ��
**************************************************************/
void InOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if(p!=NULL){
		InOrder(p->Llink);  //�ݹ鴦��������
		printf("%d ",p->data);
		InOrder(p->Rlink);  //�ݹ鴦��������
	}
	printf("\n");
}
void main()
{
	btreetype btree;
	int count;
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input data(n=%d):\n",count);
	btree = CreateTree(count);
	printf("�����Ķ���������Ϊ��\n");
	InOrder(btree);
}
/** ���� ******************************************************
*** count = 9
*** ��������: 45 2 68 1 23 5 12 9 6
*** ��������: ��ͼ
**************************************************************/