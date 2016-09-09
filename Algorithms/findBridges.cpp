#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>

#define TRACE(x...) 

using namespace std;

vector<vector<int> > graph(100);
int tempo = 0;
bool visitados[100];
vector< pair<int, int> > pontes;
vector<int> arcPoints;
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
		int u = graph[v][i];
		if(u == p) continue;
		if(!visitados[u])
		{
			dfs(u, v);
			nf++;
			if(d[v] <= low[u])
				any = true;	
			low[v] = min(low[u], low[v]);
			if(low[v] < low[u])
			{
				pontes.push_back(make_pair(v, graph[v][i]));
			}
		}
		else
		{
			low[v] = min(low[v], d[u]);
		}
		if(v==p && nf>1)
		{
			arcPoints.push_back(v);
		}
		else if(p!=-1 && any)
		{	
			arcPoints.push_back(v); 
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

	dfs(1, -1);	
	
	cout<< "Bridges:"<<endl;
	for(unsigned int i = 0; i<pontes.size(); i++)
	{
		printf("%d-%d\n", pontes[i].first, pontes[i].second);
	}

	cout<<endl;
	
	cout<<"Articulation points: "<<endl;
	for(unsigned int i = 0; i<arcPoints.size(); i++)
	{
		cout<<arcPoints[i]<<endl;
	}	


TRACE
(
	for(int i = 1; i<=n; i++)
	{
		cout<<"Vertice: " << i<<endl;
		cout<< "d: " << d[i] << " " << "low: " << low[i] << endl;
		cout<<endl;
	}	
)
}

