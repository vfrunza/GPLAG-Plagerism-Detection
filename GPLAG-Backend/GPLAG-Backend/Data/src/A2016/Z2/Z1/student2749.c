#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int a,i=1,cifra,dcifra,o=0,brojkec = 0;

		printf("Unesite broj: ");
		scanf("%d",&a);
		if(a <= 0) a = abs(a);
		while(a  > 10){
		cifra = a % 10;
		dcifra = (a/10)%10;
		o = o + abs(cifra-dcifra)*i;
		i *= 10;
		/*printf("%d",(int)fabs(cifra-l));*/
		a = a/10;
		brojkec++;
	}
	if(brojkec == 1) printf("0");
	else printf("%d",o);
	return 0;
}
