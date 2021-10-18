#include <stdio.h>


int main() {
	float x[10], y[10];
	int n, i, j;
	
	for(;;)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		
		if(n>10 || n<0)
		{
			printf("Pogresan unos.\n ");
		}
		else{
			break;
		}
	}
	
	for(i=0;i<n;i++)
	{
		float a, b;
		printf("Unesite %d. tacku: ", i+1);
		scanf("%f%f", &a, &b);
		
		if(a<0 || b<0 || a>19 || b>19)
		{
			printf("Pogresan unos.\n");
			i--;
		}
		else {
			x[i]=a;
			y[i]=b;
			
		}
	}
	for (i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			int z,t=0;
			for(z=0;z<n;z++)
			{
				if(y[z]==i && x[z]==j)
				{
					t=1;
					break;
				}
			}
			if(t==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
