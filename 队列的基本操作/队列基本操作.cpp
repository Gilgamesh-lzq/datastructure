#include<iostream>
#include<string>
using namespace std;
typedef bool Status;
typedef int QElemType;//Ԫ����������
#define ok 1
#define error 0
#define overflow 0
typedef struct QNode
{
	QElemType data;
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
Status enqueue(linkqueue &q, QElemType e,int queue_max_length)
{
	QueuePtr p;
	if (queue_max_length == q.num)
		return error;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return overflow;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.num++;
	return ok;
}

//�����е�ɾ��
Status dequeue(linkqueue &q, QElemType &e)
{
	QueuePtr p;
	if (q.front == q.rear)
		return error;
	p = q.front->next;
	e = p->data;
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


//ȡ�����е�һ��Ԫ�ؽ��
Status gethead(linkqueue q, QElemType &e)
{
	if (queueempty(q))
		return error;
	e = q.front->next->data;
	return ok;
}

//�����������������Ԫ��
Status show_all(linkqueue q)
{
	QueuePtr k = q.front->next;
	while (k != NULL)
	{
		cout << k->data << ' ';
		k = k->next;
	}
	return ok;
}

int main()
{
	int queue_length;
	QElemType temp;
	string a;
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);
	cin >> queue_length;
	while (1)
	{
		cin >> a;
		if (a == "dequeue")
			if (dequeue(*q,temp))
				cout << temp << endl;
			else
				cout << "Queue is Empty" << endl;
		else if (a == "enqueue")
		{
			cin >> temp;
			if (enqueue(*q,temp,queue_length))
				;
			else
				cout << "Queue is Full" << endl;
		}
		else if (a == "quit")
		{
			show_all(*q);
			break;
		}
	}
	return 0;
}