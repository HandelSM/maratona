#include <stdio.h>
 
 
int main() 
{
    
    int r;
    scanf("%d", &r);
 	long result = 1;
 	for(int i =0 ; i<r; i++)
 	{
 		result = result * 3;
 	}

 	printf("%lu\n", result);
    return 0;
}