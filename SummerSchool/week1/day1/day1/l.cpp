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

int d[101][101];
int inf = 0x3f3f3f3f;

int main(){
	int n, k;
	cin >> n >> k;
	rep(i,0,n){
		rep(j,0,n){
			d[i][j] = inf;
			d[j][i] = inf;
		}
	}
	rep(i,0,k){
		int a, b, c;
		cin >> a >> b >> c;
		d[a-1][b-1] = c;
	}
	
	for(int z = 0; z < n; ++z){
		for(int x = 0; x < n; ++ x){
			for(int y = 0; y < n; ++y){
				d[x][y] = min(d[x][y], d[x][z] + d[z][y]);
			}
		}
	}
	double c = 0;
	double av = 0;
	rep(i,0,n){
		rep(j, i+1, n){
			if(d[i][j] != inf){
				av += (double)d[i][j];
				c += 1.0;
			}
			if(d[j][i] != inf){
				av += (double) d[j][i];
				c += 1.0;
			}
		}
	}
	printf("%.7lf\n", av/c);
	return 0;
}
