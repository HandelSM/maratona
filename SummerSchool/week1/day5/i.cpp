#include <bits/stdc++.h>
using namespace std;

#define TRACE(X)

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

string s;
void p_f(int *pi) {
    int n = s.size();
    for(int i = 2; i < n; i++) {
        pi[i]=pi[i-1];
        while(pi[i]>0 and s[pi[i]]!=s[i])
            pi[i]=pi[pi[i]];
        if(s[pi[i]]==s[i-1])
            pi[i]++;
    }
}


void z_algorithm(int *z) {
    int l = 0, r = 0;
    for (int i = 0; s[i]; i++) {
        if (i > r) {
            l = r = i;
            for (; s[r] == s[r-l]; r++);
            z[i] = r-- - l;
        }
        else if (z[i-l] < r-i+1) {
            z[i] = z[i-l];
        }
        else {
            l = i;
            for (r++; s[r] == s[r-l]; r++);
            z[i] = r-- - l;
        }
    }
}

string myWord;
string text = "";

char caracter;

int pArr[300010];

int main() 
{
	cin.tie(); ios_base::sync_with_stdio(false);	
	while(cin>>caracter>>myWord)
	{
		for(auto &c : myWord)
			if(c > 'Z') c = c - 'a' + 'A'; 

		if(caracter=='?')
		{
			//cout<<"myword: "<< myWord <<endl;
			s = myWord + "#" + text;
			//cout<<s<<endl;
			z_algorithm(pArr);
TRACE(	
			for(int i = 0; i<s.size(); i++)
			{
				cout<<pArr[i]<<endl;
			}
)
			int sz =s.size();
			int szMw = myWord.size();
			bool resp = false;
			for(int i=0; i<sz; i++)
			{
				if(pArr[i] == szMw)
				{
					resp = true;
				}
			}
			if(resp)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			text = text + myWord;
			//cout<<text<<endl;
		}
	}
	
	
}

