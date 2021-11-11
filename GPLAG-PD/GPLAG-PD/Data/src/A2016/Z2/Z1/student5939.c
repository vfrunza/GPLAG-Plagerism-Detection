#include <stdio.h>
#include <math.h>

int main() {
	int n,rezultat=0,faktor=1,zadnja_cifra,predzadnja_cifra;
	printf("Unesite broj: ");
	scanf ("%d",&n);
	
	while (n/10!=0)
	{
		zadnja_cifra=n%10;
		n=n/10;
		predzadnja_cifra=n%10;
		
			rezultat=rezultat+(fabs(predzadnja_cifra-zadnja_cifra))*faktor;
		

		
		faktor=faktor*10;
	}
	printf ("%d",rezultat);
	return 0;
}
