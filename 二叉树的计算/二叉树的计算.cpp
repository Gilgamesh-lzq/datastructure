#include<iostream>
using namespace std;
typedef bool Status;
typedef char telemtype;
#define ok 1
#define error 0
#define overflow 0


typedef struct bitnode
{
	telemtype data;
	struct bitnode *lchild, *rchild;
}bitnode, *bitree;
typedef bitnode* elemtype;
typedef struct QNode
{
	bitnode data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
	int num;
}linkqueue;

//�����г�ʼ��
Status initqueue(linkqueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front)
		return overflow;
	q.front->next = NULL;
	q.num = 0;
	return ok;
}

//�����е�����
Status destroyqueue(linkqueue &q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	q.num = 0;
	return ok;
}

//�����еĲ���
Status enqueue(linkqueue &q, bitnode e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return overflow;
	p->data.data = e.data;
	p->data.lchild = e.lchild;
	p->data.rchild = e.rchild;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.num++;
	return ok;
}

//�����е�ɾ��
Status dequeue(linkqueue &q, bitnode &e)
{
	QueuePtr p;
	if (q.front == q.rear)
		return error;
	p = q.front->next;
	e.data = p->data.data;
	e.lchild = p->data.lchild;
	e.rchild = p->data.rchild;
	q.front->next = p->next;
	if (q.rear == p)
		q.rear = q.front;
	free(p);
	q.num--;
	return ok;
}

//�ж��������Ƿ�Ϊ��
Status queueempty(linkqueue q)
{
	if (q.front == q.rear)
		return true;
	else
		return false;
}







//������������
Status createbitree(bitree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		if (!(t = (bitnode*)malloc(sizeof(bitnode))))
			return overflow;
		t->data = ch;
		createbitree(t->lchild);
		createbitree(t->rchild);
	}
	return ok;
}
//�������������
void preordertraverse(bitree t)
{
	if (t)
	{
		cout << t->data;
		preordertraverse(t->lchild);
		preordertraverse(t->rchild);
	}
}
//�������������
void inordertraverse(bitree t)
{
	if (t)
	{
		inordertraverse(t->lchild);
		cout << t->data;
		inordertraverse(t->rchild);
	}
}
//�������������
void postordertraverse(bitree t)
{
	if (t)
	{
		postordertraverse(t->lchild);
		postordertraverse(t->rchild);
		cout << t->data;
	}
}
//��α��������������У�
void levelordertraverse(bitree t)
{
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);
	bitnode a;
	if (t == NULL)
	{
		return;
	}
	enqueue(*q, *t);
	while (queueempty(*q) == error)
	{
		dequeue(*q, a);
		t = &a;
		cout << a.data;
		if (t->lchild != NULL)
		{
			enqueue(*q, *t->lchild);
		}
		if (t->rchild != NULL)
		{
			enqueue(*q, *t->rchild);
		}
	}

}
//������������������У����д�
void treeordertraverse(bitree t)
{
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);
	bitnode b;
	b.data = NULL;
	b.lchild = NULL;
	b.rchild = NULL;
	bitnode a;
	if (t == NULL)
	{
		return;
	}
	enqueue(*q, *t);
	while (queueempty(*q) == error)
	{
		dequeue(*q, a);
		t = &a;
		if (t == NULL)
			cout << ' ';
		else
			cout << a.data;
		if (t != NULL && t->lchild != NULL)
		{
			enqueue(*q, *t->lchild);
		}
		else if (t != NULL && t->lchild == NULL)
		{
			enqueue(*q, b);
		}
		if (t != NULL && t->rchild != NULL)
		{
			enqueue(*q, *t->rchild);
		}
		else if (t != NULL && t->rchild == NULL)
		{
			enqueue(*q, b);
		}
	}

}
void PrintBiTree(bitree T, int n)
{
	int i;
	char ch = ' ';
	if (T) {
		PrintBiTree(T->rchild, n + 1);
		for (i = 1; i <= n; ++i)
		{
			cout << "     ";
		}
		printf("%c\n", T->data);
		PrintBiTree(T->lchild, n + 1);
	}
}

//��������ܽ�����
int size(bitree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + size(t->lchild) + size(t->rchild);
 }

//��Ҷ�ӽ�����
int leafsize(bitree t)
{
	if (t == NULL)
		return 0;
	else if(t->lchild==0&&t->rchild==0)
		return 1 + leafsize(t->lchild) + leafsize(t->rchild);
	else
		return leafsize(t->lchild) + leafsize(t->rchild);
}

//������������
int Depth(bitree T) {
	int depl, depr;
	if (T) {
		depl = Depth(T->lchild);
		depr = Depth(T->rchild);
		if (depl >= depr) return (depl + 1);
		else return (depr + 1);
	}
	return 0;
}

//��ת����������������������
void Exchange(bitree &T)
{
	bitree S;
	if (T) {
		S = T->lchild;
		T->lchild = T->rchild;
		T->rchild = S;
		Exchange(T->lchild);
		Exchange(T->rchild);
	}
}

int main()
{
	bitree t;
	t = (bitree)malloc(sizeof(bitnode));
	createbitree(t);
	cout<<leafsize(t);
	cout << endl;
	cout << size(t);
	cout << endl;
	cout << Depth(t);
	cout << endl;
	PrintBiTree(t, 0);
	Exchange(t);
	PrintBiTree(t, 0);
	cout << endl;
	return 0;
}
//abc##d##ef###