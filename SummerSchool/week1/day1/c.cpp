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

vi dp[103][103];

vi max(vi& a, vi& b){
	if(sz(a) >= sz(b)) return a;
	return b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int ta = sz(a);
	int tb = sz(b);
    vi best = {0};
	rep(i, 1, ta+1){
		rep(j,1,tb+1){
			vi vec;
			if(a[i-1] == b[j-1]){
               	vec = dp[i-1][j-1];
				vec.pb(i);
                vec.pb(j);
            }
			vec = max(vec, dp[i][j-1]);
			vec = max(vec, dp[i-1][j]);
            dp[i][j] = vec;
            if(sz(dp[i][j]) > sz(best)){
                best = dp[i][j];
            }
		}
	}
	cout << sz(best)/2 << endl;
    rep(i,0,sz(best)/2) cout << best[i*2] << " ";
    cout << endl;
    rep(i,0,sz(best)/2) cout << best[i*2 + 1] << " ";
    cout << endl;
    return 0;
}
