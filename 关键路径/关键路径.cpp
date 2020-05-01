#include<iostream>
using namespace std;
typedef bool Status;
#define OK 1
#define ERROR 0



#define MAX_VERTEX_NUM 1000
typedef int VertexType;
typedef struct ArcNode
{//ͼ���ڽӱ�Ķ���
	int adjvex;
	struct ArcNode *nextarc;
	int info;//Ȩ��
}ArcNode;
typedef struct VNode
{
	VertexType data;
	int indegree;
	int order;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

int LocateVex(ALGraph G, char u)
{
	int i;
	for (i = 1; i < G.vexnum + 1; i++)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	if (i == G.vexnum)
	{
		printf("Error u!\n");
		exit(1);
	}
	return 0;
}
void CreateALGraph(ALGraph &g)
{
	int i, j, k;
	int v1, v2, weight;
	cin >> g.vexnum >> g.arcnum;
	ArcNode *p;
	for (i = 1; i < g.vexnum + 1; i++)
	{
		g.vertices[i].data = i;
		g.vertices[i].firstarc = NULL;
		g.vertices[i].indegree = 0;
	}
	for (k = 0; k < g.arcnum; k++)
	{
		cin >> v1 >> v2 >> weight;
		i = LocateVex(g, v1);
		j = LocateVex(g, v2);
		g.vertices[j].indegree++;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g.vertices[i].firstarc;
		p->info = weight;
		g.vertices[i].firstarc = p;
	}
	return;
}
Status ToplogicalSort(ALGraph &G)
{
	ArcNode *p;
	int k;
	int top = -1; //���Ϊ��Ķ���ջ��ʼ��
	for (int i = 1; i < G.vexnum; ++i)
		if (G.vertices[i].indegree == 0)
		{
			G.vertices[i].order = 1;
			G.vertices[i].indegree = top;
			top = i; //���Ϊ�㶥���ջ
		}
	int count = 0;
	int i;
	int count1 = 1;
	while (top + 1)//˵��ջ�ǿ�
	{
		i = top;
		G.vertices[i].order = count1;
		count1++;
		top = G.vertices[top].indegree;
		++count;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{//ɨ��ö���ĳ��߱�
			k = p->adjvex; //�ߵ���һ����
			G.vertices[k].indegree--; //������ȼ�1
			if (G.vertices[k].indegree == 0)
			{
				G.vertices[k].indegree = top;
				top = k;
			}//���Ϊ0��ջ
		}
	}
	if (count < G.vexnum)
		return ERROR;//����
	else return OK;
}

void CriticalPath(ALGraph G) {
	int i, k, e, l;
	int *Ve, *Vl;
	ArcNode *p;
	Ve = new(int[G.vexnum + 1]);
	Vl = new(int[G.vexnum + 1]);
	for (i = 1; i < G.vexnum + 1; i++)
		Ve[i] = 0;
	for (i = 1; i < G.vexnum + 1; i++)
	{
		int m;
		for (m = 1; m < G.vexnum + 1; m++)
		{
			if (G.vertices[m].order == i)
				break;
		}
		p = G.vertices[m].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			if (Ve[m] + p->info > Ve[k])
				Ve[k] = Ve[m] + p->info;
			p = p->nextarc;
		}
	}
	for (i = 1; i < G.vexnum + 1; i++)
		Vl[i] = Ve[G.vexnum];
	for (i = G.vexnum - 1; i - 1; i--)
	{
		int m;
		for (m = G.vexnum; m >= 1; m--)
		{
			if (G.vertices[m].order == i)
				break;
		}
		p = G.vertices[m].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			if (Vl[k] - p->info < Vl[m])
				Vl[m] = Vl[k] - p->info;
			p = p->nextarc;
		}
	}
	cout << Vl[G.vexnum] << endl;
	for (i = 1; i < G.vexnum + 1; i++)
	{
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;
			e = Ve[i];
			l = Vl[k] - p->info;
			if (e == l)
				cout << G.vertices[i].data << "->" << G.vertices[k].data << endl;;
			p = p->nextarc;
		}
	}
}


int main()
{
	ALGraph a1;
	CreateALGraph(a1);
	if (ToplogicalSort(a1) == ERROR)
		cout << 0;
	else
		CriticalPath(a1);
	return 0;
}

/*
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
4 6 6
5 7 5
6 7 2
*/