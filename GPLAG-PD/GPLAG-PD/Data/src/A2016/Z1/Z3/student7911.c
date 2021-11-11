#include <stdio.h>
int main(){
	char slovo;
	float c=0,b=0,s=0,v=0,p=0,k=0;
	float ukupno;
	float crna,bijela,siva,crvena,plava;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&slovo);
		if (slovo=='c' || slovo=='C') c++;

		else if (slovo=='B' || slovo=='b') b++;
		else if(slovo=='S' || slovo=='s') s++;
		else if(slovo=='V' || slovo=='v') v++;
		else if(slovo=='P' || slovo=='p') p++;
		else if(slovo=='K' || slovo=='k') k++;
		else { printf("Neispravan unos\n");}
	} while (slovo!='K' && slovo!='k');
	ukupno=c+b+s+v+p;
	printf("Ukupno evidentirano %g vozila.\n",ukupno);
	crna=(c/ukupno)*100;
	bijela=(b/ukupno)*100;
	siva=(s/ukupno)*100;
	crvena=(v/ukupno)*100;
	plava=(p/ukupno)*100;
	
	if(ukupno==0)
	printf("Najpopularnija boja je crna (0.00%).");
	else if(c>=b && c>=s && c>=v && c>=p)
	printf("Najpopularnija boja je crna (%.2f%).",crna);
	else if(b>=s && b>=v && b>=p)
	printf("Najpopularnija boja je bijela (%.2f%).",bijela);
	else if(s>=v && s>=p)
	printf("Najpopularnija boja je siva (%.2f%).",siva);
	else if(v>=p)
	printf("Najpopularnija boja je crvena (%.2f%).",crvena);
	else 
	printf("Najpopularnija boja je plava (%.2f%).",plava);
	
	
	return 0;
}