#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct data1
{
	int no;
	data1* next;
}data1, *linklist;
data1 buffer1;
typedef data1 ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}Sqlist;
ElemType a;
//����Ԫ��
int input_stu()
{
	cin >> buffer1.no;
	return buffer1.no;
}
//�ڵ�i��Ԫ�غ����Ԫ��
Status linkinsert(linklist &l, int i, ElemType e)
{

	linklist p, s;
	p = l;
	int j = 0;
	while (j != i)
	{
		p = p->next;
		++j;
	}
	s = (linklist)malloc(sizeof(data1));
	s->no = e.no;
	s->next = p->next;
	p->next = s;
	return OK;
}
//�ҳ����ȵ�ǰԪ�ش�����Ԫ�����
int getelem_notless(linklist l, int e)
{
	linklist p;
	p = l->next;
	int j = 0;
	if (!p)
		return j;
	while (p && (p->no <= e))
	{
		p = p->next;
		j++;
	}
	return j;
}
//��0������������
void create_list(linklist &l)
{
	int k;
	while (input_stu() != 0)
	{
		k = getelem_notless(l, buffer1.no);
		linkinsert(l, k, buffer1);
	}
}
//��ȷ����Ԫ�ظ�����������
void create_list_num(linklist &l, int a)
{
	int k = 0;
	while (a != 0)
	{
		input_stu();
		linkinsert(l, k, buffer1);
		k++;
		a--;
	}
}
void Duplicate_removal_1(linklist &l, int a)
{
	linklist p,k,j;
	p = l->next;
	while (p)
	{
		k = p;
		while (k->next)
		{
			if (k->next->no == p->no&&k->next!=p)
			{
				j = k->next;
				k->next = k->next->next;
				delete(j);
			}
			else
				k = k->next;
		}
		p = p->next;
	}
}
void show_all(linklist &l)
{
	linklist p;
	p = l->next;
	while (p)
	{
		cout << p->no << ' ';
		p = p->next;
	}
}
int main()
{
	linklist l;
	l = (linklist)malloc(sizeof(data1));
	l->next = NULL;
	int num;
	cin >> num;
	create_list_num(l, num);
	Duplicate_removal_1(l, num);
	show_all(l);
	return 0;
}