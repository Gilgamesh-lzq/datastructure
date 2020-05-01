#include<iostream>
#include<string>
using namespace std;
typedef bool Status;
#define ok 1
#define error 0
#define overflow 0
typedef struct QNode
{
	int row;
	int column;
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
Status enqueue(linkqueue &q, int row2,int column2)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return overflow;
	p->row = row2;
	p->column = column2;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.num++;
	return ok;
}

//�����е�ɾ��
Status dequeue(linkqueue &q, int &row3,int &column3)
{
	QueuePtr p;
	if (q.front == q.rear)
		return error;
	p = q.front->next;
	row3 = p->row;
	column3 = p->column;
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
Status gethead(linkqueue q, int &row4,int &column4)
{
	if (queueempty(q))
		return error;
	row4 = q.front->next->row;
	column4 = q.front->next->column;
	return ok;
}

int main()
{
	linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
	initqueue(*q);

	//����ֵ����
	int row_num, column_num;
	cin >> row_num >> column_num;
	int **array1;
	array1 = new int* [row_num];
	for (int i = 0; i < row_num; i++)
		array1[i] = new int[column_num];
	for (int row1 = 0; row1 < row_num; row1++)
	{
		for (int column1 = 0; column1 < column_num; column1++)
		{
			int temp;
			cin >> temp;
			array1[row1][column1] = temp;
		}
	}



	//������ͨ�����
	int counter1 = 0;
	//��ȥ�߽���Ӱ���жϵĵ�
	int column1,row1;
	row1 = 0;
	for (column1 = 0; column1 < column_num; column1++)
	{
			array1[row1][column1] = 0;
	}
	row1 = row_num - 1;
	for (column1 = 0; column1 < column_num; column1++)
	{
		array1[row1][column1] = 0;
	}
	column1 = 0;
	for (row1 = 1; row1 < row_num-1; row1++)
	{
		array1[row1][column1] = 0;
	}
	column1 = column_num - 1;
	for (row1 = 1; row1 < row_num-1; row1++)
	{
		array1[row1][column1] = 0;
	}

	//�����м���ͨ��
	int row3, column3;
	for (row1 = 1; row1 < row_num - 1; row1++)
	{
		for (column1 = 1; column1 < column_num - 1; column1++)		
		{
			while (queueempty(*q) == false)
			{
				dequeue(*q, row3, column3);
				if ((row3 - 1) != 0&& array1[row3 - 1][column3] == 1)
				{
					enqueue(*q, row3 - 1, column3);
					array1[row3 - 1][column3] = 0;
				}
				if ((row3 + 1) != row_num - 1 && array1[row3 + 1][column3] == 1)
				{
					enqueue(*q, row3 + 1, column3);
					array1[row3 + 1][column3] = 0;
				}
				if((column3-1)!=0 && array1[row3][column3-1] == 1)
				{
					enqueue(*q, row3, column3 - 1);
					array1[row3][column3-1] = 0;
				}
				if((column3+1)!=column_num-1 && array1[row3][column3 + 1] == 1)
				{
					enqueue(*q, row3, column3 + 1);
					array1[row3][column3+1] = 0;
				}
			}
			if (array1[row1][column1] == 1)
			{
				counter1++;
				enqueue(*q, row1, column1);
				array1[row1][column1] = 0;
			}
			else
				;
		}
	}
	cout << counter1 << endl;

	return 0;
}