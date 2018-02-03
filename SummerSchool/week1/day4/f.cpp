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


ll F[85];
ll A[85];
ll B[85];


void gofibs()
{
	for(int i = 2; i<84; i++)
	{
		F[i] = F[i-1] + F[i-2];
	}
}


void goAB()
{

	for(int i = 3; i<84; i++)
	{
		A[i] = F[i] + B[i-2];
		B[i] = B[i-1] + A[i];
	}
}


ll solve(ll ene)
{
	ll pos = 0;
	while(F[pos] < ene)
	{
		pos++;
	}

	if(F[pos] == ene)
	{
		return B[pos];
	}

	
	ll resta = ene - F[pos-1];

	return resta + solve(resta);
	

}


ll resolve(ll myNum, ll myResto)
{
	int resultado = 0;
	int i = 80;
	bool flag = 0;
	while(myNum != 0)
	{
		if(myNum > F[i])
		{
			myNum -= F[i];
			resultado++;
			flag = 1;
		}
		if(flag) myResto--;
		i--;
		if(i<0) break;
		if(myResto==0)break;
	}
	return resultado;
}

int main()
{
	ll N;
	ifstream in("fibonacci.in", ifstream::in);
	ofstream out("fibonacci.out", ofstream::out);


	cin>>N;

	F[0] = 0;
	F[1] = 1;
	A[1] = 1;
	A[2] = 1;
	B[1] = 1;
	B[2] = 2;

	gofibs();
	goAB();

	ll sum = 0;
	int nDig = 1;
	while(sum<N)
	{
		sum += nDig*F[nDig];
		nDig++;
	}
	nDig--;

	if(sum==N)
	{
		cout<<B[nDig]<<endl;
		return 0;
	}

	sum -= nDig*F[nDig];

	ll result = B[nDig];
	ll resta = N - sum;

	ll numsPassados = resta/nDig;
	ll restinho = resta%nDig;


	result += numsPassados + solve(numsPassados);

	ll VAI = resolve(F[nDig] + numsPassados, restinho);		
	
	
	result += VAI;
	cout<<result<<endl;
}

