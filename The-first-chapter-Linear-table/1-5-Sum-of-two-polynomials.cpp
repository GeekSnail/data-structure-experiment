//---------库文件和预设定义
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	float coef;  //系数：coefficient 
	int expn;    //指数: exponential 
}term;
typedef struct LNode
{
	term data;
	struct LNode * next;
 } LNode, *LinkList;
typedef LinkList polynomial;  //用带头结点的链表表示多项式

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
//函数名：   CreatePolyn(polynomial &P, int m)
//参数：     (传入)int m, 多项式的系数 
//			 (传出)polynmial P 多项式链表 
//功能：     建立多项式链表
/********************************/
void CreatePolyn(polynomial &P, int m)
{
	polynomial r, s;  //当前指针和下一个指针 
	term para;  //定义系数与指数结构类型变量para 
	P = (LNode*)malloc(sizeof(LNode));
	r = P;
	for(int i=0; i<m; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		printf("输入系数c和指数e：");
		scanf("%f %d",&para.coef,&para.expn);
		s->data.coef = para.coef;
		s->data.expn = para.expn;	
		r->next = s;  
		r = s;
	}	
	r->next = NULL;
 } 
 
/********************************/
//函数名：   AddPolyn(polynomial &pa, polynomial &pb)
//参数：     (传入)polynmial &pa 多项式链表 
//			 (传出)polynmial &pb 多项式链表 
//功能：     多项式相加 
//返回值：   两多项式相加得到的新多项式 
/********************************/
polynomial AddPolyn(polynomial &pa, polynomial &pb)
{
	polynomial newp,p,q,s,r;
	float sum;
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
			if(sum != 0.0)
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
 
/********************************/
//函数名：   PrintPolyn(polynomial p)
//参数：     (传入)polynmial p 多项式链表 
//功能：     输出多项式链表 
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
	printf("请输入多项式pa的项数：");
	scanf("%d",&m);
	CreatePolyn(p,m);
	printf("请输入多项式pb的项数：");
	scanf("%d",&n);
	CreatePolyn(q,n);
	PrintPolyn(p);
	PrintPolyn(q);
	PrintPolyn(AddPolyn(p,q));	
}








