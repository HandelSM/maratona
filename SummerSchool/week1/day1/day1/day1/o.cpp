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
typedef unsigned long long ll;
ll lcm(ll a, ll b){
	return a*b / __gcd(a,b);
}

int main(){
	ll ans = 1;
	int n;
	cin >> n;
	rep(i,1,n+1) ans = lcm(ans, i * 1ll);
	cout << ans << endl;

	return 0;
}
