#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n, br, broj1, broj2, malirez, i, rez=0, brcifara=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	br=n;
	for (;;)
	{
		br/=10;
		if (br==0) break;
		brcifara++;
	}
	if (n/10==0)
	{
		printf("%d", rez);
		return 0;
	}
	else 
	{
		for (i=1;i<=brcifara;i++)
		{
			broj1=n%10;
			n/=10;
			broj2=n%10;
			malirez=abs(broj1-broj2);
			rez+=pow(10,i)*malirez;
		}
		rez/=10;
	}
	printf("%d", rez);
	return 0;
}