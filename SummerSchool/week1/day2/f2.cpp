#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, ll> pll;
// ordenar por x -> Eh easy
bool cmpY(const pll& p1, const pll& p2){
	if(p1.se != p2.se) return(p1.se < p2.se);
	return p1.fi < p2.fi;
}

bool cmpX(const pll& p1, const pll& p2){
	if(p1.fi != p2.fi) return p1.fi < p2.fi;
	return p1.se < p2.se;
}

int n;
vector<pair<ll, ll> > pts;
pair<ll, ll> p1, p2;
ll bestAns = 1e15;

long double dist(const pll& p1, const pll& p2){
	return sqrt((p1.fi-p2.fi)*(p1.fi-p2.fi) + (p1.se - p2.se)*(p1.se - p2.se));
}

bool operator<( pll& p1, pll& p2){
	if(p1.fi != p2.fi) return p1.fi < p2.fi;
	return p1.se < p2.se;
}
long double bruteForce(int a, int b){
	long double ans = 1e15;
	rep(i,a,b){
		rep(j, a+1, b+1){
			if(dist(pts[i], pts[j]) < ans){
				if(dist(pts[i], pts[j]) < bestAns){
					bestAns = dist(pts[i], pts[j]);
					p1 = pts[i];
					p2 = pts[j];
				}
				ans = min(ans, dist(pts[i], pts[j]));
			}
		}
	}
	return ans;
}

long double closest_pair(int left, int right){
	if(right - left + 1 <= 3){
		return bruteForce(left, right);	
	}
	int mid = (left + right) >> 1;
	ll d1 = closest_pair(left, mid), d2 = closest_pair(mid+1, right);
	ll d = min(d1, d2);
	int idx = lower_bound(all(pts), mp( pts[mid].fi-d , -10000000000)) - pts.begin();
	int idx2 = upper_bound(all(pts), mp(pts[mid].fi+d , 10000000000)) - pts.begin() - 1;
	vector<pair<ll, ll> > pontosPorY;
	rep(i, idx, idx2+1) pontosPorY.pb(mp(pts[i].se, pts[i].fi));
	sort(all(pontosPorY));
	int i = 1;
	int tam = (int) pontosPorY.size();
	for(int i = 1; i < tam; ++i){
		int j = i-1;
		while(pontosPorY[i].fi - pontosPorY[j].fi < d){
			long double dT = dist(pontosPorY[i], pontosPorY[j]);
			if(dT < d){
				if(dT < bestAns){
					bestAns = dT;
					p1 = {pontosPorY[i].se, pontosPorY[i].fi};
					p2 = {pontosPorY[j].se, pontosPorY[j].fi};
				}
				d = dT;
			}
		}
	}
	return d;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	pts.resize(n);
	rep(i,0,n){
		cin >> pts[i].fi >> pts[i].se;
	}
	sort(all(pts));
	closest_pair(0, n-1);
	cout << " A melhor distancia encontrada foi de " << bestAns << endl;
	printf("%d %d\n%d %d\n", (int)round(p1.fi), (int)round(p1.se), (int)round(p2.fi), (int) round(p2.se));
	return 0;
}
