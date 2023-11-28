******************* 最小生成树 ****************
最小生成树 有性质
设 G=(V, E) 是一个带权连通无向图 U是顶点集的一个非空子集.
若(u, v) 是一条具有最小权值的边(u∈U, v∈V-U), 则必存在一颗包含(u,v)的最小生成树

1 Prim Alg
从 某点v 开始依次加入 节点 构成最小生成树 (该节点应能够使得未加入树的节点到树的距离最小)


2 Kruskal Alg
对边按权值从小到大依次加入到生成树中 (该边应使树中无回路)


void Prim(G, T)
{
	T = 空集;			//初始化空树								
	U = {w};			//添加一个任意初始顶点
	while((V-U) != 空集){//当还有节点未加入树
		(u,v) = argmin(weight(u, v))  s.t u∈U, v∈V-U;
		T = T ∪ {(u, v)};
		U = U ∪ {v};
	}
}

void Kruskal(V, T)
{
	T = V;				//初始化树 T, 仅含定点
	numS = n;			//不连通分量数
	while(numS > 1){	//当不连通的分量数目大于 1
		从 E 中取出权值最小的边(v, u);
		if(v u 属于两个不同的连通分量){ //当不形成回路时将边加入MST
			T = T∪ {(u, v)}；
			numS --;
		}

	}
}