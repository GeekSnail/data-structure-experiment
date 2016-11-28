/**************************************************************
*** ����������ȣ����ڸ��ڵ��������������������Ƚϴ��ߵ���������ȼ�1
*** �ݹ鹫ʽ��
*** depth(tree) = 1;  treeΪ��
*** depth(tree) = max(depth(tree->Llink), depth(tree->Rlink))+1
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
*** ������int depth(btreetype &root)	������������
*** ������btreetype &root  ������ָ��
*** ����ֵ: ���������ڵ�ָ��
**************************************************************/
int depth(btreetype &root)
{
	btreetype p;
	//�洢��ǰ����ĸ��ڵ�
	p = root;
	int dep1, dep2;
	if(root==NULL){
		return 0;  //����ǰ�ڵ㲻���ڣ���ݹ���ڷ���0
	}
	else {
		dep1 = depth(p->Llink);  //�������������
		dep2 = depth(p->Rlink);  //�������������
		//�����������Ϊ���������������������ȼ�1
		if(dep1>dep2){
			return (dep1+1);
		}
		else{
			return (dep2+1);  //��һ���Ǽ�������Ҷ�ӽڵ�Ķȣ�����1
		}
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
	printf("�����Ķ����������Ϊ%d\n",depth(btree));
	return 0;
}
/** ���� ******************************************************
*** count = 9
*** ��������: 45 2 68 1 23 5 12 9 6
*** ��������������ȣ�7
**************************************************************/




