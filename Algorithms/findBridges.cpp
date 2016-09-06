#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

vector<int> graph[100]; 
int tempo = 0;
bool visitados[100];
vector< pair<int, int> > pontes;
int d[100];
int low[100];

void dfs( int v, int p )
{
	visitados[v] = true;
	int nf = 0;
	d[v] = tempo;
	low[v] = tempo;
	tempo++;
	bool any = false;
	int size = graph[v].size();
	for(int i = 0; i<size; i++)
	{
		if(!visitados[graph[v][i]])
		{
			dfs(graph[v][i], v);
			nf++;
			if(low[v] >= d[graph[v][i]]) any = true;
			low[graph[v][i]] = min(low[graph[v][i]], low[v]);
			if(low[v] > low[graph[v][i]])
			{
				pontes.push_back(make_pair(v, graph[v][i]));
			}
		}
		else
		{
			low[v] = min(low[graph[v][i]], low[v]);
		}
	}
}

int main()
{
	int n, e;
	cin>>n>>e;
	int a,b;
	memset(visitados, 0, sizeof(visitados));

	for(int i = 0; i<e; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(0, -1);	

	for(int i = 0; i<pontes.size(); i++)
	{
		printf("%d %d\n", pontes[i].first, pontes[i].second);
	}
}

