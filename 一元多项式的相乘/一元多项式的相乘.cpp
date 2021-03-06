#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct data1
{
	double coef;//系数
	int index;//次数
	data1* next;
}data1, *linklist;
typedef data1 ElemType;
data1 buffer1;

//输入元素
void input_stu()
{
	cin >> buffer1.coef >> buffer1.index;
}
//在第i个元素后插入元素
Status linkinsert(linklist &l, int i, data1 e)
{
	linklist p, s;
	p = l;
	int j = 0;
	while (j != i && p != NULL)
	{
		p = p->next;
		++j;
	}
	if (p == NULL)
		return ERROR;
	s = (linklist)malloc(sizeof(data1));
	s->coef = e.coef;
	s->index = e.index;
	s->next = p->next;
	p->next = s;
	return OK;
}
//在链表尾插入元素
void linkinsert1(linklist &l, data1 e)
{
	linklist p, q, s;
	p = l;
	q = p;
	while (p != NULL)
	{
		q = p;
		p = p->next;
	}
	s = (linklist)malloc(sizeof(data1));
	s->coef = e.coef;
	s->index = e.index;
	s->next = NULL;
	q->next = s;
	return;
}
//以确定的元素个数建立链表
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





void show_all(linklist &l)
{
	linklist p;
	p = l->next;
	while (p)
	{
		cout << p->coef << ' ' << p->index << endl;
		p = p->next;
	}
}
int Destory_List(linklist* L) {
	linklist q, p = *L; //指向首元

	/* 整个链表(含头结点)依次释放 */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		free(p);
		p = q;
	}

	*L = NULL;    //头指针置NULL
	return OK;
}
//void operating1(linklist a, linklist b,linklist c)
//{
//	linklist temp1=a->next, temp2=b->next;
//	linklist temp3=(linklist)malloc(sizeof(data1));
//	int count1=0;
//	while (temp1 != NULL && temp2 != NULL)
//	{
//		if (temp1->index < temp2->index)
//		{
//			temp3->coef = temp1->coef;
//			temp3->index = temp1->index;
//			temp3->next = NULL;
//			linkinsert(c, count1, *temp3);
//			count1++;
//			temp1 = temp1->next;
//		}
//		else if (temp1->index > temp2->index)
//		{
//			temp3->coef = temp2->coef;
//			temp3->index = temp2->index;
//			temp3->next = NULL;
//			linkinsert(c, count1, *temp3);
//			count1++;
//			temp2 = temp2->next;
//		}
//		else
//		{
//			temp3->coef = temp1->coef + temp2->coef;
//			temp3->index = temp1->index;
//			temp3->next = NULL;
//			linkinsert(c, count1, *temp3);
//			count1++;
//			temp1 = temp1->next;
//			temp2 = temp2->next;
//		}
//	}
//	while (temp1 != NULL)
//	{
//		linkinsert(c, count1, *temp1);
//		temp1 = temp1->next;
//	}
//	while (temp2 != NULL)
//	{
//		linkinsert(c, count1, *temp2);
//		temp2 = temp2->next;
//	}
//}

//查找（按值查找）
int locate_elem(linklist &l, int i)
{
	int j = 1;
	linklist p;
	p = l->next;
	while (p != NULL && p->index != i)
	{
		p = p->next;
		j++;;
	}
	if (p == NULL)
		return -1;
	else
		return j;
}
//返回第i个元素前一个结点地址
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
//删除第i个元素
Status delete_elem(linklist &l, int i)
{
	if (i == 0)
		return ERROR;
	linklist p, s;
	p = locate_el(l, i);
	s = p->next;
	p->next = s->next;
	delete(s);
	return OK;
}
//在第i个元素前插入元素
Status linkinsert_before(linklist &l, int i, ElemType e)
{
	linklist p, s;
	p = locate_el(l, i);
	s = (linklist)malloc(sizeof(data1));
	s->coef = e.coef;
	s->index = e.index;
	s->next = p->next;
	p->next = s;
	return OK;
}
void operating1(linklist a, linklist b, linklist c)
{
	linklist temp1, temp2,temp3, temp4;
	temp4 = (linklist)malloc(sizeof(data1));
	for(temp1=a->next;temp1 != NULL;temp1=temp1->next)
	{
		for (temp2=b->next; temp2 != NULL; temp2 = temp2->next)
		{
			temp3 = c->next;
			temp4->coef = temp1->coef*temp2->coef;
			temp4->index = temp1->index + temp2->index;
			while (temp3 != NULL&&temp3->index<=temp4->index)
			{
				if (temp3->index != temp4->index)
				{
					temp3 = temp3->next;
				}
				else
				{
					temp3->coef += temp4->coef;
					if (temp3->coef == 0)
					{
						delete_elem(c, locate_elem(c, temp3->index));
					}
					break;
				}
			}
			if (temp3==NULL||temp3->index > temp4->index)
			{
				if (temp3 == NULL)
				{
					temp4->next = NULL;
					linkinsert1(c, *temp4);
				}
				else
					linkinsert_before(c, locate_elem(c, temp3->index), *temp4);
			}
		}
	}
}
int main()
{
	int num;
	linklist l1;
	l1 = (linklist)malloc(sizeof(data1));
	l1->next = NULL;
	cin >> num;
	create_list_num(l1, num);
	linklist l2;
	l2 = (linklist)malloc(sizeof(data1));
	l2->next = NULL;
	cin >> num;
	create_list_num(l2, num);
	linklist res;
	res = (linklist)malloc(sizeof(data1));
	res->next = NULL;
	operating1(l1, l2, res);
	show_all(res);
	Destory_List(&l1);
	Destory_List(&l2);
	return 0;
}


/*
2
7 0
3 1
2
8 9
3 5

*/