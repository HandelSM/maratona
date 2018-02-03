#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;

vector<ii> pts;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	pts.resize(n);
	rep(i,0,n){
		cin >> pts[i].fi >> pts[i].se;
	}


	sort(all(pts));

	
	stack< ii > myConvex;
	
	myConvex.push(pts[0]);
	myConvex.push(pts[1]);

	for(int i = 0; i<n; i++)
	{
		
	}
	


}



