#include <stdio.h>

int main()
{
	int len;
	int counter = 0;
	scanf("%d", &len);
	
	bool nfoi = true;
	bool voltando = false;
	int pos = 1;
	while(nfoi)
	{	
		if(voltando)
		{
			pos = 2*pos - len - 1;
			if(pos<1)
			{
				pos = (pos + len + 1)/2;
				voltando = false;
			}
			else
			{
				counter++;
			}
		}
		else
		{
			pos = pos * 2;
			if(pos>len)
			{
				pos = pos/2;
				voltando = true;
			}
			else
			{
				counter++;
			}
		}	
		
		if(pos==len/2+1)
		{
			nfoi = false;
		}
		
	}
	printf("%d\n", counter+1);
}