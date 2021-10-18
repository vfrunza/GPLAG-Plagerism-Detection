#include <stdio.h>
#include <math.h>

int main() {
	int n, m, x=0, y=0, i=0, k=0, j=0, rez, q=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	m = fabs(n);
	if (m==1 || m==2 || m==3 || m==4 || m==5 || m==6 || m==7 || m==8 || m==9 || m==0)
	printf("0");
	else 
	{
		while (m!=0)
		{	
			x = m % 10;
			m = m / 10;
			if(i!=0)
			k = k*10 + fabs(y - x);
			if(k==0 && i==1)
			q++;
			
			y = x;
			
			
		i++;	
		}
		if (k == 0) 
		printf("0");
		else
		{
		while(k!=0)
		{	
			rez = k % 10;
			k = k / 10;

			if(j == 0 && rez == 0 )
			continue;

			printf("%d", rez);
		
			j++;
		}
		
			if(q>0)
			printf("0");
		}
	
	}
	
	return 0;
}
