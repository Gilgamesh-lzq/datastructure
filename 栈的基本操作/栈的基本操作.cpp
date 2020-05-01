#include<iostream>
#include<string>
using namespace std;
#define stackincrement 10
#define overflow 0
#define error 0
#define ok 1
typedef  bool Status;
//�������Ͷ���
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}sqstack;
sqstack s;
//ջ�ĳ�ʼ������,ջ�������Ѹ���
Status InitStack(sqstack &s,int num)
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
//		s.base = (int *)realloc(s.base, (s.stacksize + stackincrement) * sizeof(int));
//		if (!s.base)
			return overflow;
//		s.top = s.base + s.stacksize;
//		s.stacksize += stackincrement;
	}
	*s.top++ = e;
	return ok;
}
//��ջ����
Status pop_stack(sqstack &s,int &e)
{
	if (s.top == s.base)
		return error;
	e = *--s.top;
	return ok;
}
//�������
void show_all(sqstack &s)
{
	int content;
	while (s.top != s.base)
	{		
		pop_stack(s,content);
		cout << content<<' ';
	}
}
int main()
{
	int volume;
	int content;
	cin >> volume;
	sqstack *s =(sqstack *)malloc(sizeof(sqstack));
	string a;
	InitStack(*s,volume);
	while (1)
	{
		cin >> a;
		if (a == "pop")
			if (pop_stack(*s, content))
				cout << content << endl;
			else
				cout << "Stack is Empty" << endl;
		else if (a == "push")
		{
			cin >> content;
			if (push_stack(*s, content))
				;
			else
				cout << "Stack is Full" << endl;
		}
		else if (a == "quit")
		{
			show_all(*s);
			break;
		}
	}
	return 0;
}