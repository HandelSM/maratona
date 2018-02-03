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

	ll x1 = -10000, y1 = -10000, x2 = 10000, y2 = 10000;
	rep(i,0,n){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		x1 = max(x1, a);
		y1 = max(y1, b);
		x2 = min(x2, c);
		y2 = min(y2, d);
	}
	cout << max(max((y2-y1),0ll) * max(0ll,(x2 - x1)),0ll) << endl;
	return 0;
}
