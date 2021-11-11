#include <stdio.h>

int main() {
	int c1=0, b1=0, s1=0, v1=0, p1=0, brojac=0; 
	double cr=0, bi=0, si=0, crv=0, pl=0;
	char voz=0;
	printf("Unesite vozila: ");
	while(voz!='k' && voz!='K'){
		scanf("%c",&voz);
		if(voz=='c' || voz=='C'){
			c1++;
		}
		else if(voz=='b' || voz=='B'){
		b1++;
		}
		else if(voz=='s' || voz=='S'){
		s1++;
		}
		else if(voz=='v' || voz=='V'){
		v1++;
		}
		else if(voz=='p' || voz=='P'){
		p1++;
		}
		else if(voz=='k' || voz=='K')
		break; 
		else {
		printf("Neispravan unos\n");
		brojac--;
		}
				brojac++;
	}
printf("Ukupno evidentirano %d vozila.\n", brojac);
cr=((float)c1/brojac)*100;
bi=((float)b1/brojac)*100;
si=((float)s1/brojac)*100;
crv=((float)v1/brojac)*100;
pl=((float)p1/brojac)*100;
if(brojac==0){
	printf("Najpopularnija boja je crna (0.00%%).");
} else if(c1>=b1 && c1>=s1 && c1>=v1 && c1>=p1){
	printf("Najpopularnija boja je crna (%.2f%%).",cr);
} else if(b1>c1 && b1>=s1 && b1>=v1 && b1>=p1){
	printf("Najpopularnija boja je bijela (%.2f%%).",bi);
} else if(s1>c1 && s1>b1 && s1>=v1 && s1>=p1){
	printf("Najpopularnija boja je siva (%.2f%%).",si);
} else if(v1>c1 && v1>s1 && v1>s1 && v1>=p1){
	printf("Najpopularnija boja je crvena (%.2f%%).",crv);
} else if(p1>c1 && p1>s1 && p1>v1 && p1>s1){
	printf("Najpopularnija boja je plava (%.2f%%).",pl);
}
return 0;
}
