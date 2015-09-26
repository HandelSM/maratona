#include <stdio.h>
#include <queue>
#include <climits>
#include <vector>
#include <string>
#include <iostream>
// #include <unordered_map>

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

vector< vector<Edge> > graph;

vector<int> custos;
vector<int> pais;
vector<string> vertices;
vector<bool> visinhos;


int main()
{
	int ne;
	scanf("%d", &ne);

	

	while(ne!=0)
	{
		for(int i = 0; i<ne; i++)
		{
			string langI;
			string langF;
			// scanf("%s %s", &langI, &langF);
			cin >> langI >> langF;
			Edge e1;
			Edge e2;
			string s1;
			string s2;
			string sc;
			// scanf("%s %s %s", &s1, &s2, &sc);
			cin >> s1 >> s2 >> sc;

			int custo = sc.length();
			int indice1;
			int indice2;

			bool ntem1 = true;
			bool ntem2 = true;
			unsigned int j;
			for (j = 0; j<vertices.size() && (ntem1 || ntem2); j++)
			{
				if(vertices[j]==s1)
				{
					ntem1 = false;
					indice1 = j;
				}
				else if(vertices[j]==s2)
				{
					
					ntem2 = false;
					indice2 = j;
				}
			}

			e1.v = indice1;
			e1.c = custo;
			e2.v = indice2;
			e2.c = custo;

			if(ntem1)
			{
				vertices.push_back(s1);
				e1.v++;
			}

			if (ntem2)
			{
				vertices.push_back(s2);
				if(ntem1)
					e2.v = e1.v+1;
				else
					e2.v++;
			}
			
			graph[e2.v].push_back(e1);
			graph[e1.v].push_back(e2);
		}

		for (unsigned int i = 0; i < graph.size(); ++i)
		{
			printf("%s\n", vertices[i].c_str());
			for (unsigned int j = 0; j < graph[i].size(); ++j)
			{
				printf(" %d %d\n", graph[i][j].v, graph[i][j].c);
			}
		}

		scanf("%d", &ne);
	}
	return 0;
}
