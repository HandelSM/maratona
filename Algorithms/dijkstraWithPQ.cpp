#include <stdio.h>
#include <vector>
#include <climits>
#include <queue>
#define N 510

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

bool operator< (const Path& lhs, const Path& rhs){return rhs.c < lhs.c;}

vector<Edge> graph[N];
int custos[N];
int pais[N];
bool visitados[N];

priority_queue<Path> priorityTree;

int main()
{
	int nv,ne;
	scanf("%d %d", &nv, &ne);

	for (int i = 0; i < nv; ++i)
	{
		custos[i] = INT_MAX;
		pais[i] = -2;
		visitados[i] = false;
	}

	for (int i = 0; i < ne; ++i)
	{
		int v1, v2, c;
		scanf("%d %d %d", &v1, &v2, &c);
		Edge e1;
		e1.v = v1;
		e1.c = c;
		Edge e2;
		e2.v = v2;
		e2.c = c;
		graph[v1].push_back(e2);
		graph[v2].push_back(e1);
	}
	Path root = {0,0,-1};//v c pai
	priorityTree.push(root);
	
	while( !priorityTree.empty() )
	{
		Path p = priorityTree.top();
		priorityTree.pop();
		if(visitados[p.v]) continue;
		
		custos[p.v] = p.c;
		pais[p.v] = p.pai;
		visitados[p.v] = true;
		
		for (unsigned int i = 0; i < graph[p.v].size(); i++)
		{
			Path borhood;
			borhood.v = graph[p.v][i].v;
			borhood.c = p.c + graph[p.v][i].c;
			borhood.pai = p.v;
			priorityTree.push(borhood);
		}
	}
	
	for (int i = 0; i < nv; ++i)
	{
		printf("v=%d c= %d pai=%d\n", i, custos[i], pais[i]);
	}

	return 0;
}
