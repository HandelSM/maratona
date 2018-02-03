#include <bits/stdc++.h>

#define fi first
#define se second


#define PRECISION 60
using namespace std;

typedef long long ll;

map<int, int> myNums;



long double solve(map<int, int>::iterator  p, int counter)
{
	if(counter > PRECISION)
		return 0;
	if(p == myNums.end())
		return 0;
	int x = p->fi;
	long double k = p->se;

	return k/(k+1)*x + 1/(k+1)*solve(++p, ++counter);
}


int main()
{

	int n, num;
	cin>>n;


	char op;

	for(int i = 0; i<n; i++)
	{
		cin>>op>>num;


		auto it=myNums.find(num);

		if(it!=myNums.end())
		{
			if(op=='+')
				myNums[num] += 1;
			else if(myNums[num] > 1)
			{
				myNums[num] -= 1;
			}
			else
				myNums.erase(it);
		}
		else
		{
			if(op=='+')
				myNums[num] = 1;
		}

		long double avg = solve(myNums.begin(), 0);
		
		if(myNums.size()>PRECISION)
		{
			cout<<setprecision(18)<<avg<<endl;
		}
		else
		{
			long double D = 1;
			for(auto p : myNums)
			{
				D *= p.se+1;
			}

			long double ans = D/(D-1.0) * avg;

			cout<<setprecision(18)<<ans<<endl;
		}
	}
	return 0;
}


