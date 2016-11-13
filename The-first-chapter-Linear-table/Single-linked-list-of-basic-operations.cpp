//---------���ļ���Ԥ�趨��
#include <stdlib.h>
#include <stdio.h>
#define NULL 0

typedef int ElemType;  

//������洢�ṹ����
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
 } LNode, *LinkList;

/********************************/
//������������һ�������÷���ֵ�õ���ͷָ�룩
//��������   CreateOne(int n)
//������     (����)int n, �������Ա�������
//���ã�     ����һ�����Ա����ٰ���һ����㡪����Ԫ��㣩
//����ֵ��   LNode* ���ؽṹ��ָ�룬�����������Ա�ͷָ��
/********************************/
LNode* CreateOne(int n)
{
	int i;
	LNode* head;  //����ͷ���ָ��
	LNode *p;     //�����½��ָ�� 
	head = (LNode*)malloc(sizeof(LNode));  //������ͷ������������
	head->next = NULL;
	printf("Please input the data for LinkList Nodes:\n");
	for(i=n; i>0; i--)
	{
		p=(LNode*)malloc(sizeof(LNode));   //Ϊ�½������ռ䣬������һ�½��
		scanf("%d",&p->data);   //�½�㸳ֵ
		p->next = head->next;   //ÿ�ζ�����ͷ���ĺ�һ��������ͷ 
		head->next = p; 
	 } 
	 return head;   //����ͷ���ָ�룬�����Եõ�������ĵ�ַ 
 } 
 
/********************************/
//���������������������޷���ֵ��
//��������   CreateTwo(LNode*head, int n)
//������     (����)LNode* head����һ������ָ�� 
//			 (����)int n, �������Ա�������
//���ã�     ����һ�����Ա����ٰ���һ����㡪����Ԫ��㣩 
//����ֵ��   ��
/********************************/
void CreateTwo(LinkList &head, int n)
{
	int i;
	LNode *p;  //�����½��ָ��
	head = (LNode*)malloc(sizeof(LNode));  //������ͷ������������
	head->next = NULL;
	printf("Please input the data for LinkList Nodes:\n");
	for(i=n; i>0; i--)
	{
		p=(LNode*)malloc(sizeof(LNode));   //Ϊ�½������ռ䣬������һ�½��
		scanf("%d",&p->data);   //�½�㸳ֵ
		p->next = head->next;   //ÿ�ζ�����ͷ���ĺ�һ��������ͷ 
		head->next = p; 
	 } 	
}

/********************************/
//��������   InsertNode(LNode* L, int i; ElemType e)
//������     (����)LNode* L������Ԫ���ָ�� 
//			 (����)int i, ����λ�ã�i>1 
//			 �����룩ElemType e����Ԫ�� 
//���ã�     ���Ա��в���һ��Ԫ�� 
//����ֵ��   int�ͣ�����1��ʾ�����ɹ���0��ʾʧ�� 
/********************************/
int InsertNode(LNode* L, int i, ElemType e)
{
	LNode* p = L;  //����һ��ָ���һ������Ԫ������ָ��
	int j = 0;
	while(p && j<i-1)  //�ӵ�һ��ָ�������ң�ֱ��pָ���i����� 
	{
		p = p->next;
		++j;
	 }
	if(!p || i-1<=j)   //����λ�úϷ����ж�(p�����ڻ�i<=1)
	{
	 	printf("Error! The location is illegal");
	 	return 0;
	} 
	LNode *s;
	s = (LNode*)malloc(sizeof(LNode));  //�����½��
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1; 
 } 
 
 /********************************/
//��������   DeleteNode(LinkList &L, int i; ElemType &e)
//������     (����)LinkList &L�����Ա�ͷ���ָ��L�ĵ�ַ 
//			 (����)int i, ɾ��λ�� 
//			 �����룩ElemType &e �洢ɾ�����Ԫ��ֵ 
//���ã�     ���Ա���ɾ��һ��Ԫ�� 
//����ֵ��   ElemType�ͷ���ɾ�����Ԫ�ص�ֵ 
/********************************/
ElemType DeleteNode(LinkList &L, int i, ElemType &e)
{
	LNode *prev = L;  //����һ��ָ��ͷ��㡿��ָ��
	LNode *q;      //��ʱ��Ŵ�ɾ�����
	int j=0;
	while(prev->next && j<i-1)  //˳ָ�������ң�ֱ��pָ���i-1����� 
	{
		prev = prev->next;
		++j;
	 } 
	if(!prev || i-1<=j)   //����λ�úϷ����ж�(p�����ڻ�i<=1)
	{
	 	printf("Error! The location is illegal\n");
	 	return 0;
	} 
	q = prev->next;
	prev->next = q->next;
	e = q->data;
	return (e); 
 }
 
/********************************/
//��������   DisplayList(LinkList &L)
//������     (����)LinkList &L�����Ա�ͷ���ָ��L�ĵ�ַ
//���ã�     ��ʾ���Ա�������Ԫ�� 
//����ֵ��   ��
/********************************/ 
void DisplayList(LinkList &L)
{
	LNode *p = L;  //����һ��ָ��ͷ��㡿��ָ��
	while(p != NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

//���Գ���
int main()
{
	LNode *L1;
	int NodeNum;
	printf("Please input the LinkNode Number:\n");
	scanf("%d",&NodeNum);
	L1 = CreateOne(NodeNum);
	//�����ǰ����������
	printf("the current L1 is :");
	DisplayList(L1);
	//����
	if(InsertNode(L1,2,88))
		printf("Succeed inserting!\n");
	//�����ǰ����������
	printf("the current L1 is :");
	DisplayList(L1);	 
	 
 } 



















