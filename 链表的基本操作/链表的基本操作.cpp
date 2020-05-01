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
//����Ԫ�ظ���
int linklength(linklist l)
{
	int j = 0;
	linklist p;
	p = l->next;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}
//���ң���ֵ���ң�
int locate_elem(linklist &l, int i)
{
	int j = 1;
	linklist p;
	p = l->next;
	while (p != NULL && p->no != i)
	{
		p = p->next;
		j++;;
	}
	if (p == NULL)
		return -1;
	else
		return j;
}
//���ص�i��Ԫ��ǰһ������ַ
linklist locate_el(linklist &l, int i)
{
	linklist p = l;
	while (i != 1)
	{
		p = p->next;
		i--;
	}
	return p;
}
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
//�ڵ�i��Ԫ��ǰ����Ԫ��
Status linkinsert_before(linklist &l, int i, ElemType e)
{
	if (linklength(l) < i||i==0)
		return ERROR;
	linklist p, s;
	p=locate_el(l, i);
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
//ͷ�巨��������(ȷ����Ԫ�ظ���)
void create_list_headinsert(linklist &l, int a)
{
	int k = 0;
	while (a != 0)
	{
		input_stu();
		linkinsert(l, 0, buffer1);
		a--;
	}
}
//ȥ���㷨
void Duplicate_removal_1(linklist &l, int a)
{
	linklist p, k, j;
	p = l->next;
	while (p)
	{
		k = p;
		while (k->next)
		{
			if (k->next->no == p->no&&k->next != p)
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
//��������
void list_inversion(linklist &l)
{
	linklist p, q;
	p = l->next;
	l->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = l->next;
		l->next = q;
	}
}
//����Ԫ����3�ı���
void third_removal(linklist &l)
{
	linklist p, j;
	p = l;
	while (p->next)
	{
		if (p->next->no % 3 != 0)
		{
			j = p->next;
			p->next = p->next->next;
			free(j);
		}
		else
			p = p->next;
	}
}
//ɾ����i��Ԫ��
Status delete_elem(linklist &l, int i)
{
	if (i == 0||linklength(l) < i)
		return ERROR;
	linklist p, s;
	p=locate_el(l, i);
	s = p->next;
	p->next = s->next;
	delete(s);
	return OK;
}
//������ʾ����Ԫ��
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
//����Ĵݻ�
int Destory_List(linklist* L) {
	linklist q, p = *L; //ָ����Ԫ

	/* ��������(��ͷ���)�����ͷ� */
	while (p) {    //������Ϊ�գ���ѭ����ִ��
		q = p->next; //ץס�������һ�����
		free(p);
		p = q;
	}

	*L = NULL;    //ͷָ����NULL
	return OK;
}
int main()
{
	linklist l;
	l = (linklist)malloc(sizeof(data1));
	l->next = NULL;
	int num;
	int pos;
	cout << "�����봴���ĵ�����Ԫ�ظ���"<<endl;
	cin >> num;
	cout << "�����������Ԫ�أ��Կո�ָ�(ͷ�巨��" << endl;
	create_list_headinsert(l, num);
	cout << "��Ϊ������Ԫ��" << endl;
	show_all(l);
	cout << endl;
	cout << "���������λ�ü�Ԫ��" << endl;
	cin >> pos >> buffer1.no;
	if (linkinsert_before(l, pos, buffer1) == ERROR)
		cout << "����λ�÷Ƿ�";
	else
	{
		cout << "��Ϊ������Ԫ��" << endl;
		show_all(l);
	}
	cout << endl;
	cout << "������ɾ��Ԫ��λ��" << endl;
	cin >> pos;
	if (delete_elem(l, pos) == ERROR)
	{
		cout << "ɾ��λ�÷Ƿ�";
	}
	else
	{
		cout << "��Ϊ������Ԫ��" << endl;
		show_all(l);
	}
	cout << endl;
	int numb;
	cout << "���������Ԫ��" << endl;
	cin >> numb;
	int temp;
	if ((temp=locate_elem(l, numb) )>= 1)
	{
		cout << "����Ԫ��λ��Ϊ" << endl;
		cout << temp << endl;
	}
	else
		cout << "δ�ҵ���Ԫ��" << endl;;
	cout << "������Ϊ" << endl;
	cout << linklength(l);
	return 0;
}