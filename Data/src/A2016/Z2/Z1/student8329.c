#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int x,y,broj,novi_broj=0,z,stepen;
	stepen=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	if(broj<10)
	{
		novi_broj=0;
		printf("%d",novi_broj);
	}
	else
	{
		do
		{
			x=broj%10;
			broj=broj/10;
			if(broj!=0)
			{
				y=broj%10;
			    z=abs(y-x);
			    novi_broj=novi_broj+z*pow(10,stepen);
			    stepen++;
		    }
		} 
		while(broj!=0);
		printf("%d",novi_broj);
	}
	return 0;
	
}
