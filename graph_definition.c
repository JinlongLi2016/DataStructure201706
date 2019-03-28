#include<stdio.h>

#define MaxVertexNum 100
typedef int VertexType;

typedef struct ArcNode{ //弧节点 (弧表节点)
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode{ //顶点节点 (顶点表节点)
	VertexType data;
	ArcNode *first;
}VNode, AdjList[MaxVertexNum];

typedef struct{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

void BFSTraverse(Graph G);

int main(void)
{
	printf("hello world");
	return 0;
}

// Analyse performance?
void BFSTraverse(Graph G)
{
	for(int i=0; i<G.vexnum; i++)
		visited[i] = FALSE;
	InitQueue(Q);
	for(i = 0; i< G.vexnum; i++)
		if(!visited[i])
			BFS(G, i)
}

void BFS(Graph G, int v)
{
	visit(v);
	visited[v] = TRUE;
	Enqueue(Q, v);
	while(!isEmpty(Q)){
		DeQueue(Q, v);
		for(w = FirstNeighbor(G, v); w>=0; w = NextNeighbor(G, v, w))
			if(!visited[w]){
				visit(w);
				visited[w]=TRUE;
				Enqueue(Q, w);
			}
	}//while
}

void BFS_MIN_Distance(Graph G, int u)
{//d[i] represents the distance from u to i
	for(i = 0; i < G.vexnum; ++i)
		d[i] = infinite;
	visited[u] = TRUE; d[u] = 0;
	Enqueue(Q, u);
	while(!isEmpty(Q)){
		DeQueue(Q, u);
		for(w = FirstNeighbor(G, u); w>=0; w = NextNeighbor(G, u, w))
			if(!visited[w]){
				visited[w] = True;
				d[w] = d[u] + 1;
				Enqueue(Q, w);
			}//if
	}//while
}

void DFSTraverse(Graph G)
{// 对图G进行深度优先遍历，访问函数为visit()
	for(v = 0; v < G.vexnum; ++v)
		visited[v] = FALSE;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])
			DFS(G, v)
}
void DFS(Graph G, v)
{//从 节点v 出发 递归遍历整个图
	visit(v);
	visited[v] = True;//访问 v 并置访问标志

	for(w = FirstNeighbor(G, u); w>=0; w = NextNeighbor(G, v, W))
		if(!visited[W])
			DFS(G, w)
		//if

}