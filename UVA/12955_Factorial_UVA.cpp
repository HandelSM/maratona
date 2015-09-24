#include <stdio.h>


int base[8] = {40320, 5040, 720, 120, 24, 6, 2, 1};

int main()
{
	int n;
	
	while(scanf("%d", &n) != EOF)
	{
		int counter = 0;
		for(int i = 0; i<8 && n>0; i++)
		{
			counter+= n/base[i];
			n = n%base[i];
		}
		printf("%d\n", counter);
	}
		

	return 0;
}