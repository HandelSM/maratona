#include <bits/stdc++.h>
using namespace std;
#define M 41234
#define fi first
#define se second


map<int, int> mapa;


typedef long long ll;
int p, x0, a, b, x;


ll fastPow(ll u, ll v)
{
	if(v==0) return 1;
	return fastPow(u*u%p, v/2)*(v%2==0?1:u)%p;
}

ll f(ll k, ll ini)
{
	if(k==0) return ini;
	return (fastPow(a, k)*ini + (b*(fastPow(a, k-1) -1)%p) * fastPow(a-1, p-2))%p;
}

int main()
{

	scanf("%d %d %d %d %d", &p, &x0, &a, &b, &x);
/*
	for(int i =0; i<10; i++)
	{
		cout<<i<<": "<<f(i, x0)<<endl;
	}
*/
	if(a==0)
	{
		if(x==x0)
			cout<<0<<endl;
		else if(x==b)
			cout<<1<<endl;
		else
			cout<<"NIE"<<endl;
	}
	else if(a==1)
	{
		cout<<((x-x0)*fastPow(b,p-2))%p<<endl;
	}
	else
	{
		for(int i = 0; i<M;i++)
		{
			mapa[f(i*M, x0)] = i;
			//cout<<i<<" "<< f(i*M, x0) <<endl;
		}


		
		for(int i=0; i<M; i++)
		{
			ll aj = fastPow(a, i);
			ll inva = fastPow(a-1, p-2); 
			ll invaj = fastPow(aj, p-2);
			ll xim = (x- (  (b*(aj-1) * inva)%p  )) * invaj %p;
			
			if(mapa.find(xim)!=mapa.end())
			{
				cout<<mapa[xim]*M+i<<endl;
				exit(0);
			}
		}

		cout<<"NIE"<<endl;
	}
	
	
	return 0;
}

