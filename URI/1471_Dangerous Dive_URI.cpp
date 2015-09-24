#include <stdio.h>

int main()
{
	int N,R;
	int rescued[10000];
	bool broke = false;
	while(scanf("%d %d", &N, &R) != EOF)
	{
		for(int i = 0; i<R; i++)
		{
			if(scanf("%d", &rescued[i]) == EOF)
			{
				broke = true;
				break;
			}		}
		if(broke)
		{
			break;
		}
		else
		{
			if( (N-R) > 0)
			{
				for(int i = 0; i<N;i++)
				{
					int print = true;
					for(int j = 0; j<R; j++)
					{
						if(rescued[j] == i+1)
						{
							print = false;
							break;
						}
					}
					if(print)
					{
						printf("%d ", i+1);
					}
				}
			}
			else
			{
				printf("*");
			}
			printf("\n");
			broke = false;	
		}
	}
	return 0;
}