//---------���ļ���Ԥ�趨��
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	float coef;  //ϵ����coefficient 
	int expn;    //ָ��: exponential 
}term;
typedef struct LNode
{
	term data;
	struct LNode * next;
 } LNode, *LinkList;
typedef LinkList polynomial;  //�ô�ͷ���������ʾ����ʽ

int cmp(term a, term b)
{
	int flag;
	if(a.expn < b.expn)
		flag = -1;
	else if(a.expn == b.expn)
		flag = 0;
	else 
		flag = 1;
	return flag;	
} 

/********************************/
//��������   CreatePolyn(polynomial &P, int m)
//������     (����)int m, ����ʽ��ϵ�� 
//			 (����)polynmial P ����ʽ���� 
//���ܣ�     ��������ʽ����
/********************************/
void CreatePolyn(polynomial &P, int m)
{
	polynomial r, s;  //��ǰָ�����һ��ָ�� 
	term para;  //����ϵ����ָ���ṹ���ͱ���para 
	P = (LNode*)malloc(sizeof(LNode));
	r = P;
	for(int i=0; i<m; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		printf("����ϵ��c��ָ��e��");
		scanf("%f %d",&para.coef,&para.expn);
		s->data.coef = para.coef;
		s->data.expn = para.expn;	
		r->next = s;  
		r = s;
	}	
	r->next = NULL;
 } 
 
/********************************/
//��������   AddPolyn(polynomial &pa, polynomial &pb)
//������     (����)polynmial &pa ����ʽ���� 
//			 (����)polynmial &pb ����ʽ���� 
//���ܣ�     ����ʽ��� 
//����ֵ��   ������ʽ��ӵõ����¶���ʽ 
/********************************/
polynomial AddPolyn(polynomial &pa, polynomial &pb)
{
	polynomial newp,p,q,s,r;
	float sum;
	p = pa->next;
	q = pb->next;
	newp = (LNode*)malloc(sizeof(LNode));
	r = newp;           //rָ���¶���ʽ��ͷ��� 
	while(p && q) //pa��pb���ǿ�
	{
	 	switch(cmp(p->data, q->data))
		{
		case -1:
			s = (LNode*)malloc(sizeof(LNode));
			s->data.coef = q->data.coef;
			s->data.expn = q->data.expn;	
			r->next = s;     // 
			r = s;	    //r���s��λ�ã����´��� 
			q = q->next;  //q����һ��������Ƿ�С��p���ָ�� 
			break;
		case 0:
			sum = p->data.coef + q->data.coef;
			if(sum != 0.0)
			{
				s = (LNode*)malloc(sizeof(LNode));
				s->data.coef = sum;
				s->data.expn = p->data.expn;	
				r->next = s;  
				r = s;
			}
			p = p->next;  //��ϵ��֮��Ҳ��ͬ����newp�в����p��q��һ��� 
			q = q->next;
			break;	
		case 1:
			s = (LNode*)malloc(sizeof(LNode));
			s->data.coef = p->data.coef;
			s->data.expn = p->data.expn;	
			r->next = s;  
			r = s;	
			p = p->next;   //p����һ��������Ƿ�С��q���ָ�� 
			break;			
		} 
	} 
	//����pa��ʣ��ڵ�
	while(p)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data.coef = p->data.coef;
		s->data.expn = p->data.expn;	
		r->next = s;  
		r = s;	
		p = p->next; 
	 } 
	while(q)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data.coef = q->data.coef;
		s->data.expn = q->data.expn;	
		r->next = s;  
		r = s;	
		q = q->next; 
	 } 
	 r->next = NULL;  //�������ÿգ���ʾ����
	 return newp; 
}
 
/********************************/
//��������   PrintPolyn(polynomial p)
//������     (����)polynmial p ����ʽ���� 
//���ܣ�     �������ʽ���� 
/********************************/
void PrintPolyn(polynomial p)
{
	polynomial s;
	s = p->next;
	while(s)
	{
		printf("%.2f(%d) ",s->data.coef,s->data.expn);
		s = s->next;   
	}
	printf("\n");
}
int main()
{
	int m,n;
	polynomial p, q;
	printf("���������ʽpa��������");
	scanf("%d",&m);
	CreatePolyn(p,m);
	printf("���������ʽpb��������");
	scanf("%d",&n);
	CreatePolyn(q,n);
	PrintPolyn(p);
	PrintPolyn(q);
	PrintPolyn(AddPolyn(p,q));	
}








