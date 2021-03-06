#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
const int MAXM = 1001;
const int INF = 0x3f3f3f3f;
// Vertices em g1 de 1 a n. Vertices em g2 de n+1 a n+m.
int n, m, e; 
vector<int> g1[MAXN]; 
int pair_g1[MAXN], pair_g2[MAXM], dist[MAXN]; 
vector<pair<int, int> > res;
bool bfs() { 
    queue<int> q; 
    for (int u = 1; u <= n; u++) { 
        dist[u] = INF; 
        if (pair_g1[u] == 0) { 
            dist[u] = 0; 
            q.push(u); 
        } 
    } 
    dist[0] = INF; 
    while (!q.empty()) { 
        int u = q.front(); q.pop(); 
        for (int i = 0; i < g1[u].size(); i++) { 
            int v = g1[u][i]; 
            if (dist[pair_g2[v]] == INF) { 
                dist[pair_g2[v]] = dist[u] + 1; 
                q.push(pair_g2[v]); 
            } 
        } 
    } 
    return dist[0] != INF; 
}
bool dfs(int u) { 
    if (u == 0) 
        return 1; 
    for (int i = 0; i < g1[u].size(); i++) { 
        int v = g1[u][i]; 
        if (dist[pair_g2[v]] == dist[u] + 1 && dfs(pair_g2[v])) { 
            pair_g1[u] = v; 
            pair_g2[v] = u;
			res.push_back(make_pair(u, v-n));
			return 1; 
        } 
    } 
    dist[u] = INF; 
    return 0;
} 
int hk() { 
    memset(pair_g1, 0, sizeof(pair_g1)); 
    memset(pair_g2, 0, sizeof(pair_g2)); 
    int matching = 0; 
    while (bfs()) 
        for (int u = 1; u <= n; u++) 
            if (pair_g1[u] == 0 && dfs(u)) 
                matching++; 
    return matching; 
}
int main() {
    cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		int dest;
		cin >> dest;
		while(dest){
			g1[i].push_back(n+dest);
			cin >> dest;
		}
	}
	/*for (int i = 0, u, v; i < e; ++i) {
        scanf("%d %d", &u, &v);
        g1[u].push_back(n+v);
    }*/
    cout << hk() << endl;
    for(auto& v : res){
		cout << v.first << " " << v.second << endl;
	}
	return 0;
}
