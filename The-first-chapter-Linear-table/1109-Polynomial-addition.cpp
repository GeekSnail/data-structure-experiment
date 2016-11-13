#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct {
	int coef;  //ϵ����coefficient 
	int expn;    //ָ��: exponential 
}term;
typedef struct LNode
{
	term data;
	struct LNode * next;
 } LNode, *LinkList;
typedef LinkList polynomial;  //�ô�ͷ���������ʾ����ʽ

//��������С��������ǰ�ţ��������������  
LinkList sort(LinkList head)  
{  
    if (head == NULL)  
        return NULL;  
    LinkList p = head->next;  
    LinkList p_pre = p;  
    bool flag = false;   //���ڱ���Ƿ��н����������������ʱ������ж�Ч��  
  
    while(p_pre->next != NULL)  
    {  
        term temp = p_pre->data;  
        p = p->next;  
        while (p)  
        {      
            if(temp.expn > (p->data.expn))  //�ݼ����� 
            {  
                p = p->next;  
                continue;  
            }  
            else  
            {  
                term temp_change;  
                temp_change = p->data;  
                p->data = p_pre->data;  
                p_pre->data = temp_change;  
                p = p->next;   // 
                flag = true;  
            }  
            if (flag == false)  
            {  
                return head;  
            }  
        }         
        p_pre = p_pre->next;  //
        p = p_pre;  
    }  
    return head;  
}
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

void CreatePolyn(polynomial &P, int m)
{
	polynomial r, s;  //��ǰָ�����һ��ָ�� 
	term para;  //����ϵ����ָ���ṹ���ͱ���para 
	P = (LNode*)malloc(sizeof(LNode));
	r = P;
	for(int i=0; i<m; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		//printf("����ϵ��c��ָ��e��");
		cin>>para.coef>>para.expn;
		s->data.coef = para.coef;
		s->data.expn = para.expn;	
		r->next = s;  
		r = s;
	}	
	r->next = NULL;
 } 

polynomial AddPolyn(polynomial &pa, polynomial &pb)
{
	polynomial newp,p,q,s,r;
	int sum;
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
			if(sum != 0)
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
 
void PrintPolyn(polynomial p)
{
	polynomial s;
	s = p->next;
	while(s)
	{
		cout << s->data.coef <<" "<< s->data.expn << endl;
		s = s->next;   
	}
}
int main()
{
	int m,n;
	polynomial p, q;
	cin>>m>>n;
	CreatePolyn(p,m);
	CreatePolyn(q,n);
	p = sort(p);
	q = sort(q);
	PrintPolyn(AddPolyn(p,q));	
}








