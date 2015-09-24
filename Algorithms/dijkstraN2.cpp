#include <stdio.h>
#include <vector>
#include <climits>
#define N 510


using namespace std;

typedef struct 
{
	int v;
	int c;
}Edge;


vector<Edge> graph[N];
int custos[N];
int pais[N];
bool visitados[N];

int main()
{
	int nv,ne;
	scanf("%d %d", &nv, &ne);

	for (int i = 1; i <= nv; ++i)
	{
		custos[i] = INT_MAX;
		pais[i] = -1;
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

	custos[1] = 0;
	while(true)
	{
		int vmin = -1;
		int cmin = INT_MAX;
		for (int i = 1; i <= nv; ++i)
		{
			if(!visitados[i] && custos[i] < cmin) 
			{
				vmin = i;
				cmin = custos[i];
			}
		}
		if (cmin == INT_MAX) break;

		visitados[vmin] = true;

		for (unsigned int i = 0; i < graph[vmin].size(); ++i)
		{
			Edge e = graph[vmin][i];
			if (custos[e.v]>e.c + cmin)
			{
				custos[e.v] = e.c + cmin;
				pais[e.v] = vmin;
			}

		}

	}


	for (int i = 1; i <= nv; ++i)
	{
		printf("%d %d\n", custos[i], pais[i]);
	}

	return 0;
}