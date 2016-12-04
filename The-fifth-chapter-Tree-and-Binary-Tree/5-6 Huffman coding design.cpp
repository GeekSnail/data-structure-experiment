/**************************************************************
*** �������������
*** (1)��������n��Ȩֵ{W1,W2,...,Wn}��Ϊn�����ڵ��Ȩֵ����һ������n�ö�������ɭ��{T1,T2,...,Tn},
***     ����ÿ�ö�����ֻ��һ�����ڵ�
*** (2)��ɭ����ѡȡ���ø��ڵ�Ȩֵ��С�Ķ�������Ϊ��������������һ���¶�������
***     �¶������ĸ��ڵ�ȨֵΪ����������Ȩֵ֮�ͣ���Ҫ���n-1���ڵ㣻
*** (3)��ɭ���У�������ѡ��������ø�Ȩֵ��С�Ķ�������ɭ����ɾ����
***     �����ո��¹���Ķ��������뵽ɭ���У� 
*** (4)�ظ�����(2)��(3)��ֱ��ɭ����ֻ��һ�ö�����Ϊֹ����ö��������ǹ�������
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE 59
#define MAXBIT 10
//�����������Ĵ洢�ṹ
typedef struct btnode{
	int data;
	int Weight;  //Ȩ��
	int Flag;    //��ʶ�Ƿ������㣬����0��ʾ������1��ʾ
	int Parent;  //���ڵ㣬���ÿ������˫���������е���ţ���ʼΪ0
	int LChild, RChild;  //���ҽ�㣬���ÿ�����������Ů�������е���ţ���ʼΪ0
}hnodetype;

typedef struct{
	int Bit[MAXBIT];
	int Start;
}hcodetype;

/**************************************************************
*** ������void InitHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) ����������ʼ��
*** ������hnodetype HuffNode[]  �����������
***       hcodetype HuffCode[]  �����������������
***       int n  �������
*** ����ֵ: ��
**************************************************************/
void InitHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i;
	//�����ɵĽڵ��ʼ������ָ���׵�ָ�룬���ӡ��Һ��ӵ�ָ�붼���ÿ�
	for(i=0; i<2*n-1; i++){
		HuffNode[i].Weight = 0;
		HuffNode[i].Parent = 0;
		HuffNode[i].Flag = 0;
		HuffNode[i].LChild = -1;
		HuffNode[i].RChild = -1;
	}
	for(i=0; i<n; i++){
		getchar();
		printf("�����%d��Ҷ�ڵ�ֵ:",i+1);
		scanf("%c",&HuffNode[i].data);
		printf("�����Ӧ�ڵ�Ȩֵ:");
		scanf("%d",&HuffNode[i].Weight);
	}
}

/**************************************************************
*** ������void OutputHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) �������������
*** ������hnodetype HuffNode[]  �����������
***       hcodetype HuffCode[]  �����������������
***       int n  �������
*** ����ֵ: ��
**************************************************************/
void OutputHaffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i,j;
	printf("%d��Ҷ�ڵ��Ӧ����Ϊ��\n",n);
	for(i=0; i<n; i++){
		printf("%c----",HuffNode[i].data);
		for(j=HuffCode[i].Start; j<n; j++){
			printf("%d",HuffCode[i].Bit[j]);
		}
		printf("\n");
	}
}

/**************************************************************
*** ������void Huffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
***       ����������������������ɹ���������
*** ������hnodetype HuffNode[]  �����������
***       hcodetype HuffCode[]  �����������������
***       int n  �������
*** ����ֵ: ��
**************************************************************/
void Haffman(hnodetype HuffNode[], hcodetype HuffCode[], int n)
{
	int i,j,m1,m2,x1,x2,c,p;
	hcodetype cd;  //����ṹ���ݴ����
	for(i=0; i<n-1; i++){  //��������������Ե��������n-1�����ڵ�
		//���ݹ��������Ĺ��ɹ��̣�ʼ��ѡ����СȨֵ�������ڵ㹹��һ�ö�����
		m1 = m2 = MAXVALUE;  //��¼��С������Ȩֵ��ÿ��ѭ������10000
		//x1��x2Ϊ��СȨ�ص������ڵ�λ��
		x1 = x2 = 0;
		//ѭ����flag=0���������Ľڵ�(��������)����������СȨֵ�Ľڵ�
		for(j=0; j<n+i; j++){
			if(HuffNode[j].Weight<m1 && HuffNode[j].Flag==0){
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].Weight;  //������СȨֵ
				x1 = j;  //����x1�ĵ�ַ
			}
			else if(HuffNode[j].Weight<m2 && HuffNode[j].Flag==0){
				m2 = HuffNode[j].Weight;  //���´�СȨֵ
				x2 = j;  //����x2�ĵ�ַ
			}
		}
		//���ҵ��������ڵ㰴�չ��������Ĺ��򹹽���һ����������x1Ϊ���ӣ�x2Ϊ�Һ���
		HuffNode[x1].Parent = n+i;
		HuffNode[x2].Parent = n+i;
		HuffNode[x1].Flag = 1;  //��x1�ı�־��1�����ѹ�
		HuffNode[x2].Flag = 1;  //��x2�ı�־��1�����ѹ�
		HuffNode[n+i].Weight = HuffNode[x1].Weight + HuffNode[x2].Weight;
		HuffNode[n+i].LChild = x1;
		HuffNode[n+i].RChild = x2;
	}
	
	//���ݹ��������Ե��������ɹ���������
	for(i=0; i<n; i++){
		cd.Start = n-1;  //�������������λ��
		c = i;  //���ӽڵ�λ��
		p = HuffNode[c].Parent;  //ȡ��ǰ�ڵ�ĸ��ڵ�λ��

		while(p!=0){  //�����ڵ㲻Ϊ���ڵ��ʱ������������
			//�����ǰ�����ӣ������Ϊ0
			if(HuffNode[p].LChild==c) {
				cd.Bit[cd.Start] = 0;
			}
			//��ǰ���Һ��ӵĻ�����Ϊ1
			else{
				cd.Bit[cd.Start] = 1;
			}
			cd.Start--;
			c = p;  //�Ѹ��ڵ���Ϊ��һ�����ӽڵ�
			p = HuffNode[c].Parent;  //ȡ��ǰ�ڵ�ĸ��ڵ�λ��
		}
		for(j=cd.Start+1; j<n; j++){
			HuffCode[i].Bit[j] = cd.Bit[j];
			HuffCode[i].Start = cd.Start+1;
		}
	}
}

int main()
{
	hnodetype HuffNode[MAXNODE];
	hcodetype HuffCode[MAXLEAF];
	int n;
	printf("input the number of leaves(n<30):\n");
	scanf("%d",&n);

	InitHaffman(HuffNode, HuffCode, n);
	Haffman(HuffNode, HuffCode, n);
	OutputHaffman(HuffNode, HuffCode, n);
	return 0;
}
/** ���� ******************************************************
*** n = 6
*** ��������: a b c d e f
*** ��ӦȨֵ: 3 9 12 3 2 71
*** �����
	input the number of leaves(n<30):
	6
	�����1��Ҷ�ڵ�ֵ:a
	�����Ӧ�ڵ�Ȩֵ:3
	�����2��Ҷ�ڵ�ֵ:b
	�����Ӧ�ڵ�Ȩֵ:9
	�����3��Ҷ�ڵ�ֵ:c
	�����Ӧ�ڵ�Ȩֵ:12
	�����4��Ҷ�ڵ�ֵ:d
	�����Ӧ�ڵ�Ȩֵ:3
	�����5��Ҷ�ڵ�ֵ:e
	�����Ӧ�ڵ�Ȩֵ:2
	�����6��Ҷ�ڵ�ֵ:f
	�����Ӧ�ڵ�Ȩֵ:71
	6��Ҷ�ڵ��Ӧ����Ϊ��
	a----01011
	b----011
	c----00
	d----0100
	e----01010
	f----1
**************************************************************/




