#include <stdio.h>
#include <math.h>

int duzina_broja(int broj) {
	int duz=0;
	while(broj) {
		broj/=10;
		duz++;
	}
	return duz;
}

int obrnut(int n)
{
    int obr=0, pom;
    while(n!=0) {
        pom=n%10;
        n/=10;
        obr+=pom;
        obr*=10;
    }
    return obr/10;
}

char *ubaci_broj(char *tekst, int broj) {
	char *pocetak=tekst, *kraj, *pom;
	int duzina=duzina_broja(broj)+1, br, t, duzina_br, duzina_obr, razlika_duz, tmp, t2;
	duzina_br=duzina_broja(broj);
	duzina_obr=duzina_broja(obrnut(broj));
	razlika_duz=fabs(duzina_obr-duzina_br);
	if (broj<0) duzina++;
	if(razlika_duz!=0) duzina--;
	while(*tekst!='\0') {
		t=0;
		pom=tekst;
		while(*pom!='\0') {
			if(*(pom+1)!='\0' && *pom!=' ') {
				t=1;
				break;
			}
			pom++;
		}
		if(*tekst==' ' && tekst!=pocetak && t==1 && ((*(tekst-1)>='A' && *(tekst-1)<='Z') || (*(tekst-1)>='a' && *(tekst-1)<='z'))) {
			t2=0;
			if(razlika_duz!=0 && *(tekst+1)!=' ') {
				t2=1;
			duzina++;
			}
			kraj=tekst;
			while(*kraj!='\0') kraj++;
			while(kraj>tekst) {
				*(kraj+duzina)=*kraj;
				kraj--;
			}
			*tekst=' ';
			tekst++;
			br=obrnut(broj);
			if(broj<0) {
				*tekst='-';
				tekst++;
				br*=-1;
			}
			while(br!=0) {
				*tekst='0'+br%10;
				tekst++;
				br/=10;
			}
			tmp=razlika_duz;
			if(tmp!=0) {
				while(tmp!=0) {
					*tekst='0';
					tmp--;
					tekst++;
				}
			}
			if(t2==1) {
				*tekst=' '; 
				tekst++;
				duzina--;
			}
			if(razlika_duz==0)
			*tekst=' '; 
			tekst++;
		}
		tekst++;
	}
	return pocetak;
}

int main() {
/*	printf("Zadaća 4, Zadatak 1");*/
	return 0;
}