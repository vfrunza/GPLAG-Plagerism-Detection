#include <stdio.h>
#include <math.h>

int main() 
{
	int n, x, cif, i, A, q;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n < 10 && n > -10)
	{
		printf("0");
		return 0;
	}
	else if(n < 0)
	{
		n = fabs(n);
	}
	
	x = n;
	cif = 0;
	while(x != 0)
	{
		x /= 10;
		cif++;
	}
	
	A = 0;
	i = 0;
	while(i < cif - 1)
	{
		q = n%10 - ((n%100 - n%10) / 10);
		if(q < 0)
		  q = fabs(q);
		
		A += (q * pow(10, i));
		n /= 10;
		i++;
	}
	printf("%d", A);
	
	return 0;
}
