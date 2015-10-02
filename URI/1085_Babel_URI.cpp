#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>
#include <vector>
#include <string>

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

int main()
{


	int ne;
	while(cin >> ne, ne!=0)
	{
		
		vector<vector<Edge>> graph;
		unordered_map<string, int> languages;
		int nLang = 0;
		
		auto createLang = [&](const string& ling)
	    {
	        for(int i = 0; i<26; i++)
	        {
	        	graph.push_back(vector<Edge>());
	        }
	        languages[ling] = nLang;
	        nLang += 1;
	    };

	    auto createEdge = [&](const string& v1, const string& v2, const string& word)
	    {
	    	int off = word[0] - 'a';
	    	int index1 = languages[v1] * 26;
	    	int index2 = languages[v2] * 26;
	    	int custo = word.length();

	    	for(int i = 0; i<26; i++)
	    	{
	    		if(i == off) continue;
	    		Edge e1;
	    		Edge e2;

	    		e1.c = custo;
	    		e2.c = custo;
	    		e1.v = index1 + off;
	    		e2.v = index2 + off;
	    		graph[index2 + i].push_back(e1);
	    		graph[index1 + i].push_back(e2);
	     	}
	    };

		string langI;
		string langF;
		cin >> langI >> langF;

		createLang(langI);
		createLang(langF);

		for(int a = 0; a<ne; a++)
		{
			string s1, s2, sc;
			cin >> s1 >> s2 >> sc;

			{
				auto search = languages.find(s1);
				if(search==languages.end())
				{
					createLang(s1);
				}
			}

			{
				auto search = languages.find(s2);
				if(search==languages.end())
				{
					createLang(s2);
				}
			}

			createEdge(s1, s2, sc);
		}

		graph.push_back( vector<Edge>() );
		graph.push_back( vector<Edge>() );
		int fonte = 26*nLang;
		int ralo = 26*nLang+1;

		for (int i = 0; i < 26; ++i)
		{
			Edge e;
			e.c = 0;
			e.v = 0 + i;
			graph[fonte].push_back(e);
		}

		for (int i = 0; i < 26; ++i)
		{
			Edge e;
			e.c = 0;
			e.v = ralo;
			graph[26+i].push_back(e);
		}

		vector<bool> visitados;
		vector<int> custos;
		vector<int> pais;
		priority_queue<Path> heap;
		for(int i = 0; i<=ralo; i++)
		{
			visitados.push_back(false);
			custos.push_back(INT_MAX);
			pais.push_back(-2);
		}

		Path root;
		root.c = 0;
		root.pai = -1;
		root.v = fonte;
		heap.push(root);

		while(!heap.empty())
		{
			Path p = heap.top();
			heap.pop();
			if(visitados[p.v])continue;
			
			custos[p.v] = p.c;
			pais[p.v] = p.pai;
			visitados[p.v] = true;

			for(const auto& e : graph[p.v])
			{
				Path visinho;
				visinho.v = e.v;
				visinho.c = p.c + e.c;
				visinho.pai = p.v;
				heap.push(visinho);
			}
		}
		if(!visitados[ralo])
		{
			cout<<"impossivel"<<"\n";
		}
		else
		{
			cout<<custos[ralo]<<"\n";
		}
	}
	return 0;
}