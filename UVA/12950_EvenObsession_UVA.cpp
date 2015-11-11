#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>
#define N 20010

using namespace std;

typedef struct
{
	int v;
	int c;
}Edge;

typedef struct
{
	int v;
	int c;
	int pai;
}Path;

bool operator <(const Path& lhs, const Path& rhs){return lhs.c > rhs.c;}

void createEdge( int v1, int v2, int c, vector<Edge>* graph)
{
	Edge e1p;
	Edge e1i;
	Edge e2p;
	Edge e2i;

	e1p.c = c;
	e1i.c = c;
	e2p.c = c;
	e2i.c = c;

	e1p.v = v1 * 2;
	e1i.v = v1 * 2 - 1;
	e2p.v = v2 * 2;
	e2i.v = v2 * 2 - 1;

	graph[e1p.v].push_back(e2i);
	graph[e1i.v].push_back(e2p);
	graph[e2p.v].push_back(e1i);
	graph[e2i.v].push_back(e1p);
}



int main()
{
	int n, e;
	while(scanf("%d %d", &n, &e)!=EOF)
	{
		vector<Edge> graph[N];
		for (int i = 0; i < e; ++i)
		{
			int v1,v2,c;
			scanf("%d %d %d", &v1, &v2, &c);
			createEdge(v1, v2, c, graph);
		}

		static int custos[N];
		static bool visitados[N];
		static int pais[N];

		for (int i = 1; i <= n*2; ++i)
		{
			visitados[i] = false;
			pais[i] = -2;
			custos[i] = INT_MAX;
		}

		static priority_queue<Path> heap;
		Path p;
		p.c = 0;
		p.v = 2;
		p.pai = -1;
		heap.push(p);

		while(!heap.empty())
		{
			Path temp;
			temp = heap.top();
			heap.pop();

			if(visitados[temp.v])continue;

			custos[temp.v] = temp.c;
			visitados[temp.v] = true;
			pais[temp.v] = temp.pai;

			for (unsigned int i = 0; i < graph[temp.v].size(); ++i)
			{
				Path vis;
				vis.pai = temp.v;
				vis.c = temp.c + graph[temp.v][i].c;
				vis.v = graph[temp.v][i].v;
				heap.push(vis);
			}
		}
		if(visitados[2*n])
			printf("%d\n", custos[2*n]);
		else
			printf("-1\n");
	}
	return 0;
}
