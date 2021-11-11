#include <stdio.h>

int main() {
	char boja;
	int c=0, b=0, s=0, v=0, p=0, ukupno;
	float procenti;
	printf("Unesite vozila: ");
	while(1)  {
		scanf("%c", &boja);
		
		if(boja=='K' || boja=='k')
		break;
		else if(boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='P'){
		printf("Neispravan unos\n");
		continue;
		}
		else {
			if(boja==67 || boja==99)
			c++;
			else if(boja==66 || boja==98)
			b++;
			else if(boja==83 || boja==115)
			s++;
			else if(boja==86 || boja==118)
			v++;
			else if(boja==80 || boja==112)
			p++;
		}
	}
	ukupno=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.", ukupno);
	if(ukupno==0)
	printf("\nNajpopularnija boja je crna (0.00%%).");
	else if(c>=b && c>=s && c>=v && c>=p) {
		procenti=((float)c/ukupno)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).", procenti);
	}
	else if(b>=c && b>=s &&b>=v && b>=p) {
		procenti=((float)b/ukupno)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", procenti);
	}
	else if(s>=c && s>=b && s>=v && s>=p) {
		procenti=((float)s/ukupno)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).", procenti);
	}
	else if(v>=c && v>=b && v>=s && v>=p) {
		procenti=((float)v/ukupno)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).", procenti);
	}
	else if(p>=c && p>=b && p>=s && p>=v) {
		procenti=((float)p/ukupno)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).", procenti);
	}
	
	return 0;
}
