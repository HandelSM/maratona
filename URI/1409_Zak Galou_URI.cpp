#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>
#define fi first
#define se second
#define pb push_back

using namespace std;

long long graph[1010][1010];

class Compare
{
public:
    bool operator() (pair<long long, long long> a, pair<long long, long long> b)
    {
        return a.fi > b.fi;
    }
};


int main()
{
	int M,N,G,K;

	while(scanf("%d %d %d %d", &M, &N, &G, &K), M!=0 || N!=0 || G!=0 || K!=0)
	{

		pair<int, int> spells[1010];
		
		for (int i = 0; i <= N; ++i)
		{
			for (int j = 0; j <= N; ++j)
			{
				graph[i][j] = -2;
			}
		}


		long long knap[1001];
		memset(knap, -1, sizeof(knap));
		for (int i = 0; i < M; ++i)
		{
			scanf("%d %d", &spells[i].fi, &spells[i].se);
		}

		knap[0] = 0;
		for (int vida = 1; vida < 1001; vida++)
		{
			for (int i = 0; i < M; i++)
			{
				pair<long long,long long> magia = spells[i];
				int remLif = vida - magia.se;
				if( remLif < 0 )
				{
					if(knap[vida]!=-1)
						knap[vida] = min(magia.fi, knap[vida]);
					else
						knap[vida] = magia.fi;
				}
				else
				{
					if(knap[vida]!=-1)
						knap[vida] = min(knap[remLif]+magia.fi, knap[vida]);
					else
						knap[vida] = knap[remLif]+magia.fi;
				}
			}
		}

		for (int i = 0; i < G; ++i)
		{
			int a,b;
			cin>>a>>b;
			graph[a][b] = 0;
			graph[b][a] = 0;
		}
		graph[0][1] = 0;

		for (int i = 0; i < K; ++i)
		{
			int room, life;
			cin>>room>>life;
			for (int j = 0; j <= N; ++j)
			{
				if(graph[j][room] != -2)
					graph[j][room] += knap[life];
			}
		}
		priority_queue< pair<long long, long long>, vector<pair<long long, long long> >,Compare> pq;
		long long custos[1010];
		bool visitados[1010];
		memset(visitados, false, sizeof(visitados));
		memset(custos, -1, sizeof(custos));

		pq.push(make_pair(0,0));
		while(!pq.empty())
		{
			pair<long long, long long> v = pq.top();
			pq.pop();
			if(visitados[v.se])continue;
			visitados[v.se] = true;
			custos[v.se] = v.fi;

			for (int i = 0; i <= N; ++i)
			{
				if(graph[v.se][i] == -2)continue;
				pair<long long, long long> s;
				s.fi = v.fi + graph[v.se][i];
				s.se = i;
				pq.push(s);
			}
			
		}
		
		cout<<custos[N]<<endl;
	}
}
