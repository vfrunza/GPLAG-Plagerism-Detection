#include <stdio.h>

int main() {
	char slovo;
	int c=0,b=0,s=0,v=0,p=0, i=0, total=0;
	float prosjek;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &slovo);
		if(slovo=='\n'){
			continue;
		}
		if (slovo=='c' || slovo=='C')c++;
		else if(slovo=='b' || slovo=='B')b++;
		else if(slovo=='s'|| slovo=='S')s++;
		else if(slovo=='v'||slovo=='V')v++;
		else if(slovo=='p'||slovo=='P')p++;
		else if(slovo=='k' || slovo=='K') break;
		else{
			printf("Neispravan unos\n");
			total--;
		}
		
		total++;
		i++;
	}
	while (7); /*ne znam kako ovo uraditi petlju kako treba*/
	printf ("Ukupno evidentirano %d vozila.\n", total);
	if(total==0){
		printf ("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	float total1=total;
	if (c>=b && c>=s && c>=v && c>=p){
		prosjek=(c/total1)*100;
		printf ("Najpopularnija boja je crna (%.2f%%).", prosjek);
	}
	else if (b>=c && b>=s && b>=v && b>=p){
		prosjek=(b/total1)*100;
		printf ("Najpopularnija boja je bijela (%.2f%%).", prosjek);
	}
	else if (s>=c && s>=b && s>=v && s>=p){
		prosjek=(s/total1)*100;
		printf ("Najpopularnija boja je siva (%.2f%%).", prosjek);
	}
	else if (v>=c && v>=s && v>=b && v>=p){
		prosjek=(v/total1)*100;
		printf ("Najpopularnija boja je crvena (%.2f%%).", prosjek);
	}
	else if (p>=c && p>=s && p>=v && p>=b){
		prosjek=(p/total1)*100;
		printf ("Najpopularnija boja je plava (%.2f%%).", prosjek);
	}
	return 0;
}
