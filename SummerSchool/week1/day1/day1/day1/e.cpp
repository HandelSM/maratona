#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define mt make_tuple
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define sz(a) (int)((a).size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

bool cmp(const vi& a, const vi& b){
	int k = min(sz(a), sz(b));
	rep(i,0,k){
		if(a[i] != b[i]) return a[i] > b[i];
	}
}

int main(){
	int n;
	cin >> n;
	vector< set < multiset< int > > > ways(31);
	ways[1].insert({1});
	rep(i, 2, n+1){
		ways[i].insert({i});
		
		for(int j = i-1; j > 0; --j){
			for(const multiset<int>& x : ways[i-j]){
				multiset<int> tmp = x;
				tmp.insert(j);
				ways[i].insert(tmp);
			}
		}
	}
	vector<vector<int> > tmp;	
	for(const auto& k : ways[n]){
		vi q;
		for(const int& v : k) q.pb(v);
		reverse(all(q));
		tmp.pb(q);

	}
	sort(tmp.begin(), tmp.end(), cmp);
	for(auto& k : tmp){
	
		int sz = (int) k.size();
		int cnt = 0;
		vi t;
		reverse(all(k));
		for(const int& v : k) t.pb(v);
		for(int i = sz-1; i > 0; --i) cout << t[i] << "+";
		cout << t[0] << endl;
	}

	return 0;
}
