#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, p, broj=0, broj2=0;
	int kontrolna = 0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n = abs(n);
	if(n/10==0)
	{
		printf("0");
		return 0;
	}
	while(n != 0)
	{
		broj = broj*10;
		m = n%10;
		n = n/10;
		p = n%10;
		broj = broj + abs(m - p);
		if(broj + abs(m - p) == 0)
			kontrolna = 1;
		if(n/10 == 0) n/= 10;
	}
	while(broj != 0)
	{
		broj2 = broj2*10;
		broj2 = broj2 + broj%10;
		broj = broj/10;
	}
	if(kontrolna)
		broj2 *= 10;
	printf("%d", broj2);
	return 0;
}
