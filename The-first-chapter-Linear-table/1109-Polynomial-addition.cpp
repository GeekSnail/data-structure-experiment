#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct {
	int coef;  //系数：coefficient 
	int expn;    //指数: exponential 
}term;
typedef struct LNode
{
	term data;
	struct LNode * next;
 } LNode, *LinkList;
typedef LinkList polynomial;  //用带头结点的链表表示多项式

//快速排序，小的数据往前排，后的数据往后排  
LinkList sort(LinkList head)  
{  
    if (head == NULL)  
        return NULL;  
    LinkList p = head->next;  
    LinkList p_pre = p;  
    bool flag = false;   //用于标记是否有交换，当数组有序的时候，提高判断效率  
  
    while(p_pre->next != NULL)  
    {  
        term temp = p_pre->data;  
        p = p->next;  
        while (p)  
        {      
            if(temp.expn > (p->data.expn))  //递减排序 
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
	polynomial r, s;  //当前指针和下一个指针 
	term para;  //定义系数与指数结构类型变量para 
	P = (LNode*)malloc(sizeof(LNode));
	r = P;
	for(int i=0; i<m; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		//printf("输入系数c和指数e：");
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
	r = newp;           //r指向新多项式的头结点 
	while(p && q) //pa和pb均非空
	{
	 	switch(cmp(p->data, q->data))
		{
		case -1:
			s = (LNode*)malloc(sizeof(LNode));
			s->data.coef = q->data.coef;
			s->data.expn = q->data.expn;	
			r->next = s;     // 
			r = s;	    //r替代s的位置，向下传递 
			q = q->next;  //q往下一个结点找是否小于p结点指数 
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
			p = p->next;  //若系数之和也相同，则newp中不添加p、q任一结点 
			q = q->next;
			break;	
		case 1:
			s = (LNode*)malloc(sizeof(LNode));
			s->data.coef = p->data.coef;
			s->data.expn = p->data.expn;	
			r->next = s;  
			r = s;	
			p = p->next;   //p往下一个结点找是否小于q结点指数 
			break;			
		} 
	} 
	//链接pa中剩余节点
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
	 r->next = NULL;  //最后结点的置空，表示结束
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








