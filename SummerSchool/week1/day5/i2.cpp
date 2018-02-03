#include<bits/stdc++.h>
using namespace std;

// Suffix Automaton Construction - O(n)
typedef long long ll;

const int N = 1e6+1, K = 26;
int sl[2*N], len[2*N], sz, last;
ll cnt[2*N];
map<int, int> adj[2*N];

void add(int c) {
	int u = sz++;
	len[u] = len[last] + 1;
	cnt[u] = 1;

	int p = last;
	while(p != -1 and !adj[p][c])
		adj[p][c] = u, p = sl[p];

	if (p == -1) sl[u] = 0;
	else {
		int q = adj[p][c];
		if (len[p] + 1 == len[q]) sl[u] = q;
		else {
			int r = sz++;
			len[r] = len[p] + 1;
			sl[r] = sl[q];
			adj[r] = adj[q];
			while(p != -1 and adj[p][c] == q)
				adj[p][c] = r, p = sl[p];
			sl[q] = sl[u] = r;
		}
	}

	last = u;
}

void clear() {
	for(int i=0; i<=sz; ++i) adj[i].clear();
	last = 0;
	sz = 1;
	sl[0] = -1;
}

void build(const char *s) {
	clear();
	for(int i=0; s[i]; ++i) add(s[i]);
}

// Pattern matching - O(|p|)
bool check(const char *p, int sz) {
	int u = 0, ok = 1;
	for(int i=0; i < sz; ++i) {
		u = adj[u][p[i]];
		if (!u) ok = 0;
	}
	return ok;
}

int main(){
	cin.tie(); ios_base::sync_with_stdio(false);	
	char caracter;
	string myWord;
	while(cin>>caracter>>myWord)
	{
		for(auto &c : myWord)
			if(c > 'Z') c = c - 'a' + 'A'; 

		if(caracter=='?'){
			if(check(myWord.c_str(), myWord.size())) cout << "YES/n";
			else cout << "NO/n";
		}
		else{
		build(myWord.c_str());
		}
	}



}
