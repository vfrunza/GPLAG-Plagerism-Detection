#include <stdio.h>
#include <math.h>

int main() {
	int broj, c=0, brojac=1, c1=0;
	long rezultat=0, krajnji_rezultat=0;
	printf("Unesite broj: ");
	scanf ("%d", &broj);
	if (broj<0)
	broj=broj*(-1);

	while (broj!=0)
	{
		c1=c;
		c=broj%10;
		rezultat=rezultat+fabs(c1-c)*brojac;
		broj=broj/10;
		brojac=brojac*10;
		
	}
	krajnji_rezultat=rezultat/10;
	printf ("%li", krajnji_rezultat);
	return 0;
}
