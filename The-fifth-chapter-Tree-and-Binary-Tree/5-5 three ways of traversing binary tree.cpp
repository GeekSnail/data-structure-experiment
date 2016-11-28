/**************************************************************
*** �������������������ͺ�����������������ǡ�
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
*** ������btreetype CreateTree(int n)	��������������
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
*** ������void InOrder(btreetype &root)  ����������������ݹ飩
*** ������btreetype &root  ������ָ��
*** ����ֵ: ��
**************************************************************/
void PreOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if(p!=NULL){
		printf("%d ",p->data);
		PreOrder(p->Llink);  //�ݹ鴦��������
		PreOrder(p->Rlink);  //�ݹ鴦��������
	}
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
}
/**************************************************************
*** ������void InOrder_Norecursion(btreetype &root)  ����������������ǵݹ飩
*** ������btreetype &root  ������ָ��
*** ����ֵ: ��
**************************************************************/
void InOrder_Norecursion(btreetype &root)
{
	btreetype stack[MAX];  //��ջ�洢����ʽ�洢�������
	btreetype p;
	int top=0;
	p = root;
	do{
		//��������������������ֱ����ǰ�ڵ�Ϊ��
		while(p!=NULL){
			top++;
			//������±�1��ʼ�洢���ڵ㼰���������������ڵ㣬��ջ
			stack[top] = p;
			p = p->Llink;
		}
		//ջ��Ԫ�ؼ���ǰ��˵����
		if(top>0){
			//�ݴ���˵�
			p = stack[top];
			//��ջ
			top--;
			printf("%d ",p->data);  //���ʵ�ǰ��˵�
			//��ʼָ������������һ��ѭ��ʱ������
			p = p->Rlink;
		}
	}while(p!=NULL || top!=0);
}

/**************************************************************
*** ������void PostOrder(btreetype &root)  ����������������ݹ飩
*** ������btreetype &root  ������ָ��
*** ����ֵ: ��
**************************************************************/
void PostOrder(btreetype &root)
{
	btreetype p;
	p = root;
	if(p!=NULL){
		PostOrder(p->Llink);  //�ݹ鴦��������
		PostOrder(p->Rlink);  //�ݹ鴦��������
		printf("%d ",p->data);
	}
}

int main()
{
	btreetype btree;
	int count;
	printf("input the number of elements(n<50):\n");
	scanf("%d",&count);
	printf("input data(num=%d):\n",count);
	btree = CreateTree(count);
	printf("���������������");
	PreOrder(btree);
	printf("\n����������������ݹ飩��");
	InOrder(btree);
	printf("\n����������������ǵݹ飩��");
	InOrder_Norecursion(btree);
	printf("\n���������������");
	PostOrder(btree);
	printf("\n");
	return 0;
}
/** ���� ******************************************************
*** count = 9
*** ��������: 45 2 68 1 23 5 12 9 6
**************************************************************/




