#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;
#define elem_max_num 1000
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct
{
	string data;
	int cur;
}node1;
//������������
void reserveArr(node1 *array, int maxSize)
{
	for (int i = 1; i < maxSize - 1; i++)
	{
		array[i].cur = i + 1;//��ÿ������������ӵ�һ��
	}
	array[maxSize - 1].cur = -1;//�������һ�������α�ֵΪ-1
}
//��ȡ����ռ�,����������ǿգ��򷵻ط���Ľ���±꣬���򷵻�-1�����������һ�����ʱ���ý����α�ֵΪ-1��
int mallocArr(node1 * array)
{
	return array[1].cur;
}
//��ʼ����̬����
void initArr(node1 *array, int maxSize)
{
	reserveArr(array, maxSize);
	array[0].cur = -1;
	int body = mallocArr(array);
	for (int i = 0; i < maxSize; i++)
	{
		array[i].data = "N/A";
	}
}


int main()
{
	node1 array1[elem_max_num];
	string buffer;
	int maxsize;
	cin >> maxsize;
	initArr(array1, maxsize);
	int num1;
	cin >> num1;
	while (num1 > 0)
	{
		cin >> buffer;
		num1--;
	}
	return 0;
}