#include <stdio.h>
#include <stdlib.h>
#define MOD (1000000000+7)

int fat(int n)
{
	if(n==1 || n==0)
		return 1;
	return (n * fat(n-1))%(MOD);
}

int dist(int xi, int yi, int xf, int yf)
{
	return abs(yf-yi) + abs(xf-xi);
}

int makeCount(int xi, int yi, int xf, int yf)
{
	return (fat(dist(xi, yi, xf, yf))/(fat(xf-xi)*fat(yf-yi)))%(MOD);
}

int main()
{
	int N, M, H, Q;
	while(scanf("%d %d %d", &N, &M, &H)!=EOF)
	{
		scanf("%d", &Q);
		int holes[110][4];

		for(int i = 0; i<H; i++)
			scanf("%d %d %d %d", &holes[i][0], &holes[i][1], &holes[i][2], &holes[i][3]);

		for (int i = 0; i < Q; ++i)
		{
			int xi,xf,yi,yf, result;
			scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
			result = makeCount(xi, yi, xf, yf);
			for (int j = 0; j < H; ++j)
			{
				//int lado1 = holes[j][3]-holes[j][1], lado2 = holes[j][2]-holes[j][0];
				for(int y = holes[j][1]+1; y<holes[j][3]; y++)
				{
					for (int x2 = holes[j][0]+1; x2 < holes[j][2]; ++x2)
					{
						result -= ((makeCount(xi, yi, xi, y) * makeCount(x2, yf, xf, yf))%(MOD));
					}

					for (int y2 = y; y2 < holes[j][3]; ++y2)
					{
						result -= ((makeCount(xi, yi, xi, y) * makeCount(xf, y2, xf, yf))%(MOD));
					}
				}

				for(int x = holes[j][0]+1; x<holes[j][2]; x++)
				{
					for (int x2 = x; x2 < holes[j][2]; ++x2)
					{
						result -= ((makeCount(xi, yi, x, yi) * makeCount(x2, yf, xf, yf))%(MOD));
					}

					for (int y2 = holes[j][1]+1; y2 < holes[j][3]; ++y2)
					{
						result -= ((makeCount(xi, yi, x, yi) * makeCount(xf, y2, xf, yf))%(MOD));
					}
				}

			}

			printf("%d\n", result);

		}
	}
}