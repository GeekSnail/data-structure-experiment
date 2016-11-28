/**************************************************************
*** 1. �յĶ�����Ҳ�Ƕ���������
*** 2. �ǿն���������Ҫ��
*** (1) �������������ǿգ��������������н���ֵ��С�ڸ��ڵ��ֵ
*** (2) �������������ǿգ��������������н���ֵ��С�ڸ��ڵ��ֵ
*** (3) ����������������һ�Ŷ���������
*** 3. ���õݹ飬��������Ϊ����������Ϊ��
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//����������洢�ṹ
typedef struct btnode{
	int data;
	struct btnode *Llink;  //������ָ��
	struct btnode *Rlink;  //������ָ��
}btnode, *btreetype;

/**************************************************************
*** ������btreetype CreateTree(int n)	����������
*** ������int n  ������
*** ����ֵ: ���������ڵ�ָ��
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
		scanf("%d",&newNode->data);  
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
				//���½ڵ���ֵ���ڻ���ڵ�ǰ�ڵ���ֵ
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
*** ������int Check(btreetype &root)	�ж�һ�ö������Ƿ��Ƕ���������
*** ������btreetype &root  ������ָ��
*** ����ֵ: ���������ڵ�ָ��
**************************************************************/
int Check(btreetype &root)
{
	btreetype p;
	//�洢��ǰ����ĸ��ڵ�
	p = root;
	//
	//�����ڵ�Ϊ�ջ�ǰ�ڵ��Ѿ��������ף����ڵ�Ķ�Ϊ1��0�������ֲ��������������
	if(p==NULL){
		return 1;  
	}
	//����ǰ�ڵ�����������ڣ������������ڵ����ֵ���ڵ�ǰ�ڵ�(���ڵ�)����ֵ�����ж�������
	if(p->Llink && (p->Llink->data > p->data)){
		return 0;
	}
	//����ǰ�ڵ�����������ڣ������������ڵ����ֵ���ڵ�ǰ�ڵ�(���ڵ�)����ֵ�����ж�������
	if(p->Rlink && (p->Rlink->data < p->data)){
		return 0;  //��һ���Ǽ�������Ҷ�ӽڵ�Ķȣ�����1
	}	
	return (Check(p->Llink) && Check(p->Rlink));  //�ݹ��������������ж�
}
int main()
{
	btreetype btree;
	int count;
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input data(num=%d):\n",count);
	btree = CreateTree(count);
	if(Check(btree)){
		printf("�����Ķ������Ƕ���������\n");
	}
	else {
		printf("�����Ķ��������Ƕ���������\n");
	}	
	return 0;
}
/** ���� ******************************************************
*** count = 9
*** ��������: 45 2 68 1 23 5 12 9 6
*** ��������������ȣ�7
*** ���ڳ����д����Ķ�������Ϊ���������������Զ�����
**************************************************************/




