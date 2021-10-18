#include <stdio.h>

int Duzina (char*s) {
	int i=0;
	while(*s!='\0') {
		s++;
		i++;
	}
	return i;
}

char* pomjeri(char* p, int k) {
	char* q=p;
	while(*p!='\0') p++;
	p--;
	while (Duzina(q)-Duzina(p)>0) {
		*(p+k)=*p;
		p--;
	}
	return q;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char* pomocni=tekst;
	char* pocetak=tekst;
	char* pomocni_rijec, *pomocni_zamjena;
	int i,iste=1,j=0,k=0,duzina=Duzina(tekst);
	while(k<duzina) {
		if(*tekst==' ') {
			tekst++;
			continue;
		}
		for(i=0;i<broj_rijeci;i++) {
			iste=1;
			pomocni_rijec=rijeci[i];
			pomocni_zamjena=zamjene[i];
			while(*pomocni_rijec!='\0') {
				if(*tekst==' ') break;
				if(*tekst!=*pomocni_rijec) {
					iste=0;
					break;
				}
				tekst++;
				k++;
				pomocni_rijec++;
			}
			if(iste==1) {
				j=0;
				pomocni=tekst-Duzina(rijeci[i]);
				if(Duzina(zamjene[i])-Duzina(rijeci[i])>0) tekst=pomjeri(tekst,Duzina(zamjene[i])-Duzina(rijeci[i]));
				while(j<Duzina(zamjene[i])) {
					*pomocni=*pomocni_zamjena;
					pomocni_zamjena++;
					pomocni++;
					j++;
				}
				*pomocni=' ';
			}
		}
		tekst++;
		k++;
	}
	return pocetak;
}

int main() {
	char* rijeci[2]={"beli", "sneg" };
	char* zamjene[2]={"bijeli", "snijeg"};
	char tekst[1000]="beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst,rijeci,zamjene,2));
	return 0;
}
