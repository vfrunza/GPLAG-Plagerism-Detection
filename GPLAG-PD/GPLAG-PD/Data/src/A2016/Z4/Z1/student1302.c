#include <stdio.h>
/*
void PreskociZadanuRijec(char *p, char *rijec, int broj) {
	int duzina_izbacene = 0, duzina_rijeci, broj_preklapanja, brojac = 0;
	int limit = 0;
	char *p1=p;
	char *p2 = rijec;
	while(*p2!='\0'){
		duzina_izbacene++;
		p2++;
	}
	p2 = rijec;
	while(*p!='\0'){
		if(*p!=' ' && *p!=',' && *p!='.' && *p!='!' && *p!='?' && *p!='-'){
			duzina_rijeci = 0;
			while (*p!=' ' && *p!=',' && *p!='.' && *p!='!' && *p!='?' && *p!='-'){
				duzina_rijeci++;
				p++;
				brojac++;
			}
			if(duzina_rijeci==duzina_izbacene){
				broj_preklapanja = 0;
				p = p- duzina_rijeci;
				while(*rijec!='\0') {
					if(*p==*rijec) broj_preklapanja++;
						p++;
						rijec++;
				}
				rijec = p2;
				if(broj_preklapanja == duzina_izbacene){
					limit++;
					p = p-duzina_rijeci;
					while(*p!='\0'){
						*p=*(p+duzina_rijeci+1);
						p++;
					}
					if(limit==broj) break;
					else p=p1;
				}
			}
		}
		brojac++;
		p++;
	}
	p=p1;
}*/
char* izbaci_najcescu(char* s){
	/*char *vrati;
	char *pok = s;
	char *p1;
	char *pocetna;
	char trazena[50];
	char konacna[50];
	char zadnja[50];
	int duzina_poredbene, max = 0, broj_ponavljanja, duzina, i, duzina_max, k, j;
	while(*s!='\0'){
		if(*s!=' ' && *s!=',' && *s!='.' && *s!='!' && *s!='?'&& *s!='-'){
			broj_ponavljanja = 1;
			duzina_poredbene = 0;
			i = 0;
			while(*s!=' ' && *s!=',' && *s!='.' && *s!='!' && *s!='?' && *s!='-'){
			duzina_poredbene++;
			trazena[i] = *s;
			s++;
			i++;
		}
		p1=s;
		pocetna = trazena;
		while(*s!='\0'){
			if(*s == *pocetna){
				duzina = 0;
				while(*s!=' ' && *s!=',' && *s!='.' && *s!='!' && *s!='?'&& *s!='-'){
					if(*s==*pocetna) duzina++;
						pocetna++;
						s++;
				}
				if(duzina == duzina_poredbene){
					broj_ponavljanja++;
				}
			}
			s++;
		}
		if(broj_ponavljanja > max){
			duzina_max = duzina;
			max=broj_ponavljanja;
			for(j=0;j<duzina_poredbene;j++){
				konacna[j] = trazena[j];
			}
			konacna[j]='\0';
		}
	}
	s = p1;
	s++;
	
}

for(k=0; k<duzina_max;k++){
	zadnja[k] = konacna[k];
}
zadnja[k]='\0';
s=pok;
PreskociZadanuRijec(s, konacna, max);
return s;*/
}
int main() {
	//printf("Zadaća 4, Zadatak 1");
	char niz[100] = "Izbaciti rijec koja se zada rijec.";
	printf("Novi string glasi: %s", izbaci_najcescu(niz));
	return 0;
}
