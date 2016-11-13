/*	
	������������ظ���ջ��ջ�����Լ���С�Ƚϣ����ʺ���Ƴɵݹ���̣�
 	�Ƚ�����Ԫ��a��ջ��Ԫ��b
 	��a>b, ջ��Ԫ�س�ջ;
		��ջ��Ϊ�գ����ٱȽ�����Ԫ�غ�ջ��Ԫ��;
	����aԪ����ջ;
	�ݹ����������
	��ջΪ��ʱ, ���鵱ǰԪ����ջ�������ݹ����
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack* link;
}sStack,*sNode;

sStack* createStack()
{
	sStack* p;
	p = (sStack*)malloc(sizeof(sStack));
	p->link = NULL; 
	return p;
}

void push(sNode &head, int e)
{
	sStack* p;
	p = (sStack*)malloc(sizeof(sStack));
	p->data = e;
	p->link = head;  //��һ����ջʱ��p->link=head=NULL; 
	head = p;
}

void pop(sNode &head)
{
	sStack* p;
	int e;
	if(head==NULL){ //ָ�����Ԫ�ǿ� 
		exit(0);
	}
	e = head->data;  //�ݴ���Ԫ���� 
	p = head;  //�ݴ���Ԫ 
	head = head->link;  //�Ѵ�Ԫ��ֵΪ��Ԫ 
	free(p);  //�ͷ���Ԫ 
}

int getStackTop(sNode &head) 
{
	return head->data;
}

int Empty(sNode &head)
{
	if(head == NULL){
		return 0;
	} else {
		return 1;
	}
}
/*
�����ֱȽ��������� 
������  sNode &head��������ջ
		int a, ���Ƚ�����Ԫ��
		int b, ջ��Ԫ��
*/	
void compare(sNode &head, int a, int b)
{
	int t;
	if(a>b){
		pop(head);  //����Ԫ�ش���ջ��Ԫ�أ�ջ��Ԫ�أ���С����ջ
		if(Empty(head)){
			t = getStackTop(head);  //ȡ��һ��ջ��Ԫ��
			compare(head,a,t); //�µ�ջ��Ԫ�أ��ϴ󣩼�����֮ǰ������Ԫ����Ƚ� 
		} 
		else {
			push(head,a);  //Ԫ�ض���ջ��ջΪ��ʱ����ʱ��ջ��Ԫ�������bΪ�δ�
		}
		push(head,b); //�δ�Ԫ����ջ
	}
	else {
		push(head,a);  //����Ԫ��С��ջ��Ԫ�أ�����Ԫ����ջ
	}
}

int main()
{	
	int temp;
	int a[100];
	int num;
	sNode pStack;  //��Ԫ 
	sNode head;    //
	printf("Please input the number of array:\n");
	scanf("%d",&num);
	printf("Please input the value of %d number of array:\n",num);
	for(int i=0; i<num; i++){
		scanf("%d",&a[i]);	
	}
	pStack = createStack();
	head = pStack->link; //��ʱheadΪ�� 
	for(int j=0; j<num; j++){
		if(Empty(head)){
			//ȡջ��Ԫ�أ���δ�������һԪ�ؽ�������
			temp = getStackTop(head);  //ȡջ��Ԫ��ȥ�Ƚ�
			compare(head,a[j],temp); 
		}
		else{
			push(head,a[j]);  //��һ��ִ��ʱʹ�����һ��Ԫ����ջ����������head(�����λ��)
		}
	}
	printf("sort by ascend:\n");
	for(int k=0; head!=NULL; k++,head=head->link){
		printf("%d ",head->data);	
	}
	return 0;
}
