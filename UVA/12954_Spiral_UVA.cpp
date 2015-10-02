#include <stdio.h>

long n, f;
long Fp;

long makeCount(long p)
{
	return 2*(p-1)*n-(p-1)*(p-1)-(p-1)+n;
}

long getParede(long b)
{
	long cur = n/2;
	long maior = n;
	long menor = 0;
	while(maior-menor>1)
	{
		Fp = makeCount(cur);
		if(Fp<b)
		{
			menor = cur;
			cur = (cur+maior)/2;
		}
		else
		{
			maior = cur;
			cur = (cur+menor)/2;
		}
	}
	return cur;
}

int main()
{
	while(scanf("%Ld %Ld", &n, &f)!=EOF)
	{
		long lastP = getParede(f);
		long Bp = makeCount(lastP);
		long nextBp = makeCount(lastP+1);
		long parede = lastP*2-1;

		int fSobrou = f-Bp;
		int x,y;
		if(lastP==-1)
		{
			x = f;
			y = 1;
		}
		else
		{
			int descBatida = (nextBp - Bp)/2;
			if(fSobrou>descBatida)
			{
				fSobrou -= descBatida;
				parede++;
			}
			int dir = parede%4;
			long t = parede/4;
			if(dir==0)
			{
				x = fSobrou+t;
				y = t+1;
			}
			else if(dir==1)
			{
				x = n-t;
				y = fSobrou+t+1;
			}
			else if(dir==2)
			{
				x = n-fSobrou-t;
				y=n-t;
			}
			else if(dir==3)
			{
				x = t+1;
				y = n-fSobrou-t;
			}
		}
		printf("%d %d\n", y, x);
	}
	return 0;
}