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
const ll maxn = 10001000;
vector<bool> prime(10001000, true);

vi p;

int main(){
	prime[0] = prime[1] = false;
	for(ll i = 2; i*i < maxn; ++i){
		if(prime[i]){
			p.pb(i);
			for(ll j = i*i; j < maxn; j += i){
				prime[j] = false;
			}
		}
		if((int)p.size() > 10002) break;
	}
	cout << p.size() << endl;
	int n;
	cin >> n;
	cout << p[n-1] << endl;
	return 0;
}
