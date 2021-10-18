#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	int br2=0,br=0, c=0, c2=0,pozicija=0,duzina=0,i;
	
	printf("Unesite broj: ");
	scanf("%d", &br);
	if(br > -10 && br<10)
	{
		printf("0");
		return 0;
	}
	br2 = br;
	
	do
	{
		duzina++;
		br/=10;
	}
	while(br != 0);

	for(i=1; i < duzina; i++)
	{
		c = br2/pow(10, duzina-i);
		
		c2 = br2/pow(10, duzina-i-1);
	
		
		if(!(pozicija ==0 && (abs(c%10 - c2%10) == 0)))
		{
			printf("%d", abs(c%10 - c2%10));
			pozicija++;
		}	
		
		if(i == duzina-1 && pozicija ==0)
		{
			printf("0");
		}
	}
	return 0;
}
