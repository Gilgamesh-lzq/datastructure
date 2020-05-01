#include<iostream>
using namespace std;
typedef bool Status;
typedef char telemtype;
#define ok 1
#define error 0
#define overflow 0
typedef enum { Link, Thread }PointerTag;
//Link==0��ָ�룬ָ���ӽ��
//Thread==1��������ָ��ǰ�����̽��
typedef struct bithrnode {
	char data;
	struct bithrnode *lchild, *rchild;
	PointerTag LTag, RTag;
}bithrnode, *bithrtree;
bithrtree T;
bithrnode *pre=NULL;

//������������������������ͷ��㣩
void preorder_Thr(bithrtree T)
{
	bithrtree p = T;
	cout<<p->data;
	while (p->rchild)
	{
		if (p->LTag == Link) 
			p = p->lchild;
		else 
			p = p->rchild;
		cout << p->data;
	}
}

//������������
Status createbithrtree(bithrtree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		if (!(t = (bithrnode*)malloc(sizeof(bithrnode))))
			return overflow;
		t->data = ch;
		t->LTag = Link;
		t->RTag = Link;
		createbithrtree(t->lchild);
		createbithrtree(t->rchild);
	}
	return ok;
}

//����������
void PreThreading(bithrtree P)
{
	if (P)
	{
		if (!P->lchild)
		{
			P->LTag = Thread;
			P->lchild = pre;
		}
		if (!P->rchild) 
			P->RTag = Thread;
		if (pre && pre->RTag == Thread) 
			pre->rchild = P;
		pre = P;
		if (P->LTag == Link)
			PreThreading(P->lchild);
		if (P->RTag == Link) 
			PreThreading(P->rchild);
	}
}
//���δ�ӡ����������
void PrintBithrTree(bithrtree T, int n)
{
	int i;
	char ch = ' ';
	if (T) {
		if(T->RTag==Link)
			PrintBithrTree(T->rchild, n + 1);
		for (i = 1; i <= n; ++i)
		{
			cout << "     ";
		}
		cout << T->data << T->LTag << T->RTag << endl;
		if (T->LTag == Link)
			PrintBithrTree(T->lchild, n + 1);
	}
}
int main()
{
	bithrtree t;
	t = (bithrtree)malloc(sizeof(bithrnode));
	createbithrtree(t);
	PreThreading(t);
	PrintBithrTree(t,0);
	preorder_Thr(t);
	return 0;
}
//abc##d##ef###