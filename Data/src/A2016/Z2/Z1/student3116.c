#include <stdio.h>

int main() {
	int UlazniBroj=0, Broj1=0, Broj2=0, I=0, IzlazniBroj=0, dec=1;
	printf("Unesite broj: ");
	scanf("%d", &UlazniBroj);
	if (UlazniBroj<0) UlazniBroj*=-1;
	
	Broj2=UlazniBroj%10;
	
	while (UlazniBroj>9)
	{
		UlazniBroj-=Broj2;
		UlazniBroj/=10;
		Broj1=UlazniBroj%10;
		I=Broj2-Broj1;
		if (I<0) I*=-1;
		IzlazniBroj+=dec*I;
		dec*=10;
		Broj2=Broj1;
	}
	printf("%d", IzlazniBroj);
	
	return 0;
}
