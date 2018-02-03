#include <bits/stdc++.h>

using namespace std;


#define pb push_back
int main(){
	int n;
	cin >> n;
	set<int> k;
	for(int i = 0; i < n ; ++i){
		int x;
		cin >> x;
		k.insert(x);
	}
	vector<int> t;
	for(const int& v : k) t.pb(v);
	if(n%2 == 0) reverse(t.begin(), t.end());
	for(const int& v : t) cout << v << endl;
	return 0;
}
