#define init_size 100
#define listincrement 10
#define error 0
#define OK 1
typedef  bool Status;
typedef struct
{
	char no[8];
	char name[20];
	double score;
}Student;
typedef Student ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
ElemType a;
//������
Status InitList(Sqlist &stu, int num)
{
	
}
//����Ԫ��
void input_stu()
{
	
}
//�ڵ�i��Ԫ��ǰ����Ԫ��
Status listinsert(Sqlist &stu, int i, ElemType a)
{
	
}
//���ʼ��
Status Initinlist(int num, Sqlist &stu)
{
	
}
//ͨ�����ֲ���
Status searchByName(char *name, Sqlist &stu) {
	
}
//ͨ��λ�ò���
Status searchByPos(int i, Sqlist &stu) {
	
}
//����Ԫ��λ��ɾ��
Status deleteByPos(int i, Sqlist &stu) {
	
}
//����Ԫ�ظ���
void StuCount(Sqlist &stu) 
{
	
}
//ͨ����Ϣɾ��
Status deleteByStu(ElemType _delStu, Sqlist &stu) 
{
	
}
//ɾ���ظ�
void deleteDuplicate(Sqlist &stu) {
	
}
//�������
void show_all(Sqlist &stu)
{
	
}
