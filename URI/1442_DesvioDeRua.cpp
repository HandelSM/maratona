#include <stdio.h>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#define fi first
#define se second
#define pb push_back
#define TRACE(x...)

using namespace std;

vector<pair<int, int> > graph[1010];
vector<pair<int, int> > hparg[1010];
bool visitados[1010];
vector<pair<int, int> > bridges;
int tempo = 0;
int d[1010];
int low[1010];

void dfsBrid(int v)
{
	visitados[v] = true;
	d[v] = tempo;
	low[v] = tempo;
	tempo++;
	int size = graph[v].size();
	for(int i = 0; i < size; i++)
	{
		int u = graph[v][i].fi;
		if(!visitados[u])
		{
			dfsBrid(u);
			low[v] = min(low[v], low[u]);
			if(low[v] < low[u] && graph[v][i].se != 2)
				bridges.pb(make_pair(v, u));
		}
		else
		{
			low[v] = min(d[u], low[v]);
		}
	}

}

void dfs1(int v)
{
	visitados[v] = true;
	int size = graph[v].size();
	for(int i = 0; i < size; i++)
	{
		if(!visitados[graph[v][i].fi])
			dfs1(graph[v][i].fi);
	}
}

void dfs2(int v)
{
	visitados[v] = true;
	int size = hparg[v].size();
	for(int i = 0; i < size; i++)
	{
		if(!visitados[hparg[v][i].fi])
			dfs2(hparg[v][i].fi);
	}
}

int main()
{
	int n, e;
	while(scanf("%d %d", &n, &e) != EOF)
	{
		bool df1 = true, df2 = true;
		
		for(int i = 1; i<=n; i++)
		{
			graph[i].clear();
			hparg[i].clear();
		}

		for(int i = 0; i<e; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if(i!=0)
			{
				graph[a].pb( make_pair(b, c) );
				hparg[b].pb( make_pair(a, c) );
				if(c==2)
				{
					graph[b].pb( make_pair(a, c) );
					hparg[a].pb( make_pair(b, c) );
				}
			}
		}

		memset(visitados, 0, sizeof(visitados));
		dfs1(1);
		for(int i = 1; i<=n;i++)
		{
			if(!visitados[i])
			{
				df1 = false;
			}
		}

		memset(visitados, 0, sizeof(visitados));
		dfs2(1);
		for(int i = 1; i<=n;i++)
		{
			if(!visitados[i])
			{
				df2 = false;
			}
		}

		if(df1 && df2)
		{
			printf("-\n");
		}
		else if( (!df1) && (!df2) )
		{
			printf("*\n");
		}
		else
		{
			tempo = 0;
			memset(visitados, 0, sizeof(visitados));
			bridges.clear();
			dfsBrid(1);

TRACE(			
			for(int i = 0; i<bridges.size(); i++)
			{
				printf("%d %d\n", bridges[i].first, bridges[i].second);
			}
)
			if(bridges.size() > 0)
				printf("2\n");
			else
				printf("1\n");
		}
	}
}

