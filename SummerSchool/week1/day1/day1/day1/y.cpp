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
	vector<ll> f{0,1,1};
	rep(i,3, 10001){
		f.pb(f[i-1] + f[i-3]);
	}
	int n;
	cin >> n;
	cout << f[n] << endl;
	return 0;
}
