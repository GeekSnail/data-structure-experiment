/*	
	由于排序过程重复出栈入栈操作以及大小比较，故适合设计成递归过程：
 	比较数组元素a和栈顶元素b
 	若a>b, 栈顶元素出栈;
		若栈不为空，则再比较数组元素和栈顶元素;
	否则a元素入栈;
	递归结束条件：
	当栈为空时, 数组当前元素入栈，结束递归调用
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
	p->link = head;  //第一次入栈时，p->link=head=NULL; 
	head = p;
}

void pop(sNode &head)
{
	sStack* p;
	int e;
	if(head==NULL){ //指向的首元非空 
		exit(0);
	}
	e = head->data;  //暂存首元数据 
	p = head;  //暂存首元 
	head = head->link;  //把次元赋值为首元 
	free(p);  //释放首元 
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
两数字比较排序（升序） 
参数：  sNode &head，排序用栈
		int a, 待比较数组元素
		int b, 栈顶元素
*/	
void compare(sNode &head, int a, int b)
{
	int t;
	if(a>b){
		pop(head);  //数组元素大于栈顶元素，栈顶元素（较小）出栈
		if(Empty(head)){
			t = getStackTop(head);  //取下一个栈顶元素
			compare(head,a,t); //新的栈顶元素（较大）继续和之前的数组元素相比较 
		} 
		else {
			push(head,a);  //元素都出栈，栈为空时，此时入栈的元素是最大，b为次大
		}
		push(head,b); //次大元素入栈
	}
	else {
		push(head,a);  //数组元素小于栈顶元素，数组元素入栈
	}
}

int main()
{	
	int temp;
	int a[100];
	int num;
	sNode pStack;  //首元 
	sNode head;    //
	printf("Please input the number of array:\n");
	scanf("%d",&num);
	printf("Please input the value of %d number of array:\n",num);
	for(int i=0; i<num; i++){
		scanf("%d",&a[i]);	
	}
	pStack = createStack();
	head = pStack->link; //此时head为空 
	for(int j=0; j<num; j++){
		if(Empty(head)){
			//取栈顶元素，和未排序的下一元素进行排序、
			temp = getStackTop(head);  //取栈顶元素去比较
			compare(head,a[j],temp); 
		}
		else{
			push(head,a[j]);  //第一次执行时使数组第一个元素入栈，整个过程head(相对左位移)
		}
	}
	printf("sort by ascend:\n");
	for(int k=0; head!=NULL; k++,head=head->link){
		printf("%d ",head->data);	
	}
	return 0;
}
