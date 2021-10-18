#include <stdio.h>
#include <math.h>

int main() {
	int inp, d, placeholder, brojcif, i, cifra, broj, prethodnik, SNEAKY=0;

	/* Input */
	printf("Unesite broj: ");
	scanf("%d", &inp);
	
	/* Konverzija negativnog cijelog broja u pozitivni */
	if (inp<0) inp*=(-1);
	
	/* Placeholder za testiranje koliko input ima cifara */
	placeholder = inp;
	
	for(i=1; ; i++) {
		d=pow(10, i);
		if (placeholder/d != 0) continue;
		else break;
	}
	
	brojcif=i;
	
	while (i>0) {
		/* Djelioc */
		d=pow(10, i);
		
		/* Trenutna cifra, pocevsi sa najvece ka najmanjoj */
		cifra = inp%d;
		cifra /= d/10;
		
		/* Ne ispisuje broj za prvu cifru jer nema prethodnika */
		if (i!=brojcif) {
			broj = cifra - prethodnik;
			if (broj < 0) broj*=(-1);
			if (broj != 0 || SNEAKY>0) {
				printf("%d", broj);
				SNEAKY++;
			}
		}
	/* Postavka trenutne cifre da djeluje kao clan koji ce se oduzeti od sljedece cifre */
	prethodnik=cifra;
		
	/* Dekrementovanje 'i' cime se izbjegava infinite loop i skeniraju sljedece cifre */
	i--;
	}

	/* Posebni slucaj kad je input jednocifren broj ili rezultuje nulom */
	if (SNEAKY==0) {
		printf("0");
	}
	
	return 0;
}