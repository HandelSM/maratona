#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F
#define INFLL 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define contOnes __builtin_popcountl
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define unico(x) x.erase(unique(all(x)), (x).end())

typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int,int> ii; 
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const double inf = 1.0/0.0;
const double pi = 3.14159265358979323846264338327950288419;

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
	return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}


vector< pair<int, int> > graphX[10010];
vector< pair<int, int> > graphY[10010];

vector< pair<int, int> > mapIndPoint;
vector<int> path;

int viz[10010] = {0};

int X, Y, N, x1, y1, x2, y2, c1, c2;


int dfsX(int v, int dest)
{
	if(viz[v] == 1)	return 0;
	viz[v] = 1;

	if(v==dest)
	{
		path.pb(dest);
		return 1;
	}

	int sz = graphX[v].size();
	for(int i = 0; i<sz; i++)
	{
		if(dfsX(graphX[v][i].fi, dest)==1)
		{
			path.pb(graphX[v][i].se);
			return 1;
		}
	}

	return 0;
}

int dfsY(int v, int dest)
{
	if(viz[v] == 1)	return 0;
	viz[v] = 1;

	if(v==dest)
	{
		path.pb(dest);
		return 1;
	}

	int sz = graphY[v].size();
	for(int i = 0; i<sz; i++)
	{
		if(dfsX(graphY[v][i].fi, dest)==1)
		{
			path.pb(graphY[v][i].se);
			return 1;
		}
	}
	
	return 0;
}

int main() {
	

	cin>>X>>Y;
	cin>>N;
	
	for(int i = 0; i<N; i++)
	{
		cin>>x1>>y1>>x2>>y2;
		mapIndPoint.pb(mp(x1, y1));
		graphX[x1].pb(mp(x2, i+1));
		graphY[y1].pb(mp(y2, i+1));
	}

	cin>>c1>>c2;

	if(mapIndPoint[c1-1].fi > mapIndPoint[c2-1].fi)
		swap(c1, c2);
	
	dfsX(0, c1);
	dfsX(c1, c2);
	dfsX(c2, 0);
	
	return 0;
}

