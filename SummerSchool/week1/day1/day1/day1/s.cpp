#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define mt make_tuple
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	vector<pair<int, char> > segs;
	rep(i,0,n){
		int a,b;
		cin >> a >> b;
		segs.pb(mp(a, 'a'));
		segs.pb(mp(b, 'f'));
	}
	sort(all(segs));
	ll resposta = 0;
	int aberto = 1;
	int maisLeft = segs[0].fi;
	rep(i, 1, 2*n){
		auto v = segs[i];
		if(v.se == 'f'){
			if(aberto == 1){
				resposta += v.fi - maisLeft;
			}
			aberto--;
		}
		else{
			if(aberto == 0){
				maisLeft = v.fi;
			}
			aberto++;
		}
	}
	cout << resposta << endl;
	return 0;
}
