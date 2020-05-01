#include<iostream>
using namespace std;
#define stack_init_size 100
#define stackincrement 10
#define overflow 0
#define error 0
#define ok 1
#define empty 1
#define n_empty 0
typedef bool Status;
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}sqstack;
sqstack s;
//ջ�ĳ�ʼ������,ջ�������Ѹ���
Status InitStack(sqstack &s, int num)
{
	s.base = (int *)malloc(num * sizeof(int));
	if (!s.base)
		return overflow;
	s.top = s.base;
	s.stacksize = num;
	return ok;
}
//ȡջ��Ԫ��
Status gettop(sqstack s, int &e)
{
	if (s.top == s.base)
		return error;
	e = *(s.top - 1);
	return ok;
}
//��ջ����
Status push_stack(sqstack &s, int e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (int *)realloc(s.base, (s.stacksize + stackincrement) * sizeof(int));
		if (!s.base)
			return overflow;
		s.top = s.base + s.stacksize;
		s.stacksize += stackincrement;
	}
	*s.top++ = e;
	return ok;
}
//��ջ����
Status pop_stack(sqstack &s, int &e)
{
	if (s.top == s.base)
		return error;
	e = *--s.top;
	return ok;
}
//�ǵݹ����׳�
Status cacl(sqstack &s, int e,long &res)
{
	int k = 1;
	res = 1;
	while (k <= e)
	{
		push_stack(s, k);
		k++;
	}
	while (s.top != s.base)
	{
		pop_stack(s, k);
		res *= k;
	}
	return ok;
}
int main()
{	
	sqstack *s = (sqstack *)malloc(sizeof(sqstack));
	InitStack(*s, stack_init_size);
	long res;
	cacl(*s, 5900, res);
	return 0;
}