#include <stdio.h>

int fixo[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
int v[26] =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int printVec[10000];
int main()
{
	int n;
	int a;
	int counter=1;
	char helper;
	scanf("%d", &n);
	while(n!=0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			printVec[i] = v[a-1];
			helper = v[a-1];
			for (int i = a-1; i > 0; i--)
			{
				v[i] = v[i-1];
			}
			v[0]=helper;
		}
		printf("Instancia %d\n", counter);
		for (int i = 0; i < n; ++i)
		{
			printf("%c", printVec[i]);
		}
		printf("\n\n");
		counter++;
		for (int i = 0; i < 26; ++i)
		{
			v[i] = fixo[i];
		}
		scanf("%d", &n);
	}

	return 0;
}