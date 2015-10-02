#include <stdio.h>

int sum[510];

int main()
{
	int j, r;
	
	while(scanf("%d %d", &j, &r)!= EOF)
	{
		for (int i = 1; i < j+1; ++i)
		{
			sum[i] = 0;
		}

		int next = 1;
		for (int i = 1; i < j*r+1; ++i)
		{
			if(next>j)
			{
				next = 1;
			}
			
			int game;
			scanf("%d", &game);
			sum[next] = sum[next] + game;
			next++;
		}

		int maior = -1;
		int indice;
		for (int i = 1; i < j+1; i++)
		{
			if(sum[i]>=maior)
			{
				maior = sum[i];
				indice = i;
			}
		}
		
		printf("%d\n", indice );
	}
	return 0;
}