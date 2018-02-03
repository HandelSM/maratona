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

int main(){
	int n;
	cin >> n;
	vector<ii> pts(n);
	
	rep(i,0,n){
		cin >> pts[i].fi >> pts[i].se;
	}
	pts.pb(pts[0]);
	double abs = 0;
	rep(i,0,n){
		abs += pts[i].fi * pts[i+1].se;
	}
	rep(i,1,n+1){
		abs -= pts[i].fi * pts[i-1].se;		
	}
	printf("%.5lf\n", (abs > 0) ? abs/2.0 : (-abs)/2.0);
	return 0;
}
