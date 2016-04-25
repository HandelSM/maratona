#include <stdio.h>
#include <vector>
#include <climits>
#include <queue>
#include <utility>
#define VMAX 1000

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


int knapsack(int vida)
{

}

int main()
{
	int M,N,G,K;

	while(scanf("%d %d %d %d", &M, &N, &G, &K), M!=0 && N!=0 && G!=0 && K!=0) 
	{
		pair<int,int> spells[1000];	
		vector<Edge> graph[VMAX];
		int custos[VMAX];
		int pais[VMAX];
		bool visitados[VMAX];
		priority_queue<Path> priorityTree;
		pair <int, int> monstros[1000];
		int matrix[1000][1000];
		int vida[VMAX];
		
		vector<int> mapMontroSala[1000];

		for (int i = 0; i < M; ++i)
		{
			scanf("%d %d", &spells[i].first, &spells[i].second)
		}
		for (int i = 0; i < G; ++i)
		{
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			Edge e1, e2;
			e1.v = v2;
			e2.v = v1;
			graph[v1].push_back(e1);
			graph[v2].push_back(e2);
		}
		for (int i = 0; i < K; ++i)
		{
			int sala, vida;
			scanf("%d %d", sala, vida);
			mapMonstroSala[sala].push_back(vida);
		}

		for (int v = 0; v < N; ++v)
		{
			int custo = 0;
			for (int monstro = 0; monstro < mapMonstroSala[v].size(); ++monstro)
			{
				custo += knapsack( mapMonstroSala[v][monstro] );
			}
			//colocar que o custo para chegar em v é custo
		}

	}

	return 0;
}
