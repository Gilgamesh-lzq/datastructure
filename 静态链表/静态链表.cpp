#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;
#define elem_max_num 200
#define ERROR 0
#define OK 1
typedef  bool Status;
typedef struct {
	string data;
	int cur;
}node1;
//������������
void reserveArr(node1 *array,int maxSize) 
{
	for (int i = 1; i < maxSize-1; i++) 
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
void initArr(node1 *array,int maxSize)
{
	reserveArr(array,maxSize);
	array[0].cur = -1;
	int body = mallocArr(array);
	for (int i = 0; i <maxSize; i++) 
	{
		array[i].data = "N/A";
	}
}
//��������ָ��λ�ò������ݣ�add��ʾ����Ԫ�ص�λ�ã�a��ʾҪ���������
Status insertArr(node1 * array, int add, string a)
{
	int tempBody= 0;
	int insert = mallocArr(array);
	if (insert == -1)
	{
		cout << "FULL" << endl;
		return ERROR;
	}
	if (array[0].cur == -1)
	{
		if (add > 0)
		{
			cout << "-1" << endl;
			return ERROR;
		}
		array[0].cur = array[1].cur;
		array[1].cur = array[array[1].cur].cur;
		array[array[0].cur].data = a;
		array[array[0].cur].cur = -1;
	}
	else
	{
		for (int i = 1; i < add; i++)
		{
			tempBody = array[tempBody].cur;
			if (array[tempBody].cur == -1)
			{
				cout << "-1" << endl;
				return ERROR;
			}
		}
	}	
	array[1].cur= array[insert].cur;
	array[insert].cur = array[tempBody].cur;
	array[insert].data = a;
	array[tempBody].cur = insert;
	return OK;
}
//�������β�������ݣ�a��ʾҪ���������
Status insertArr_tail(node1 * array, string a)
{
	if (array[1].cur == -1)
	{
		cout << "FULL"<<endl;
		return ERROR;
	}
	int temp1=array[0].cur;
	int temp2;
	if (temp1 == -1)
	{
		temp2 = array[1].cur;
		array[0].cur = array[1].cur;
		array[array[1].cur].data = a;
		array[1].cur = array[array[1].cur].cur;
		array[temp2].cur = -1;
	}
	else
	{
		temp2 = array[1].cur;
		while (array[temp1].cur != -1)
		{
			temp1 = array[temp1].cur;
		}
		array[array[1].cur].data = a;
		array[temp1].cur = array[1].cur;
		array[1].cur = array[array[1].cur].cur;
		array[temp2].cur = -1;
	}
	return OK;
}
//����������Ϊelem�Ľ���������е�λ��
int selectElem(node1 * array, string elem) 
{
	int tempBody =array[0].cur;
	//���α�ֵΪ0ʱ����ʾ�������
	while (array[tempBody].cur != -1) 
	{
		if (array[tempBody].data == elem) {
			return tempBody;
		}
		tempBody = array[tempBody].cur;
	}
	return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}
// ����������Ϊelem�Ľ����Ԫ���е�λ��
int selectElem1(node1 * array, string elem)
{
	int count1 = 1;
	int tempBody = array[0].cur;
	if (tempBody == -1)
		return -1;
	//���α�ֵΪ0ʱ����ʾ�������
	while (array[tempBody].cur != -1)
	{
		if (array[tempBody].data == elem)
		{
			return count1;
		}
		count1++;
		tempBody = array[tempBody].cur;
	}
	if (array[tempBody].data == elem)
	{
		return count1;
	}
	return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}
//ɾ����㺯����body��ʾ�ڼ���Ԫ��
Status deletArr_pos(node1 * array, int body,string &k) 
{
	if (array[0].cur == -1)
	{
		cout << "EMPTY" << endl;
		return ERROR;
	}
	if (body <= 0)
	{
		cout << "-1" << endl;
		return ERROR;
	}
	int count1 = 1;
	int tempBody =0;
	int temp2;
	while (count1 <= body)
	{
		if (array[tempBody].cur == -1)
		{
			cout << "-1" << endl;
			return ERROR;
		}
		temp2 = tempBody;
		tempBody = array[tempBody].cur;
		count1++;
	}
	//����ɾ�������α�ֱ�Ӹ���ɾ��������һ�����
	array[temp2].cur = array[tempBody].cur;
	k = array[tempBody].data;
	array[tempBody].data = "N/A";
	array[tempBody].cur = array[1].cur;
	array[1].cur = tempBody;
	return OK;
}
//���������̬����
void displayArr(node1 * array) {
	int tempBody=array[0].cur;//tempBody׼��������ʹ��
	while (array[tempBody].cur!=-1) 
	{
		cout << array[tempBody].data << ' ';
		tempBody = array[tempBody].cur;
	}
	cout << array[tempBody].data << ' ';
}
//��������ڴ����
void displaymem(node1 * array,int num)
{
	int count1 = 0;
	while (count1<num)
	{
		cout << count1 << " : " << array[count1].data << " : " << array[count1].cur << "\t\t";
		count1++;
		if (count1 % 3 == 0)
			cout << endl;
	}
	if (count1 % 3 != 0)
		cout << endl;
}

int main() 
{
	int temp1,i,j;
	string buffer2;
	node1 array[elem_max_num];
	string buffer;
	int maxsize;
	cin >> maxsize;
	initArr(array,maxsize);
	int num1;
	cin >> num1;
	temp1 =1;
	/*if (temp1 > maxsize - 2)
		temp1 = maxsize - 2;*/
	while (temp1 <= num1&&temp1 <=maxsize-2)
	{
		cin >> buffer;
		insertArr_tail(array, buffer);
		temp1++;
	}
	while (temp1 <= num1&&temp1 <= maxsize)
	{
		cin >> buffer;
		temp1++;
	}
	displaymem(array, maxsize);
	cin >> i >> buffer;
	if (insertArr(array, i, buffer) == ERROR)
		;
	else
	{
		displayArr(array);
		cout << endl;
	}
	cin >> j;
	if (deletArr_pos(array, j,buffer2)==ERROR)
		;
	else
	{
		cout << buffer2<<endl;
	}
	cin >> buffer;
	cout<<selectElem1(array, buffer)<<endl;
	cin >> buffer;
	if(insertArr_tail(array, buffer)==ERROR)
		;
	else
	{
		displayArr(array);
		cout << endl;
	}
	displaymem(array, maxsize);
	return 0;
}

/*
2 2
Jan Feb
1 Jun
7
May
Oct

9 5
Jan Feb Mar Apr May
7 Jun
1
Mar
Oct

9 0
7 Jun
1
Mar
Oct

9 2
Mar jam
7 Jun
1
jam
Oct

10 2
Mar jam
7 Jun
1
jam
Oct
*/