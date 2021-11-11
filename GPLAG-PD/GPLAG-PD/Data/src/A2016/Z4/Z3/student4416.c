/* Zadatak: zamijeniti rijeci jednog niza odgovarajucim rijecima drugog niza u stringu */
#include <stdio.h>
char*zamjena_rijeci(char*tekst,char**rijeci,char**zamjene,int broj_rijeci){
	char*p_tekst;
	char*a;
	char*p_a;
	char*kraj;
	char*p_kraj;
	char*b;
	char*zamjenska;
	char*trenutna;
	char*p_zamjenska;
	char*p_trenutna;
	int duzina,duzina_2,brojac,i,j;
	p_tekst=tekst;
	while(*tekst!=0){
		tekst++;
	}
	tekst--;
	kraj=tekst;
	tekst=p_tekst;
	p_kraj=kraj;
	for(j=0;j<broj_rijeci;j++){
/* Mjerenje duzine rijeci radi pomjeranja stringa */		
		tekst=p_tekst;
		duzina=0;
		trenutna=rijeci[j];
		p_trenutna=trenutna;
		while(*trenutna!=0){
			trenutna++;
			duzina++;
		}
		duzina_2=0;
		zamjenska=zamjene[j];
		p_zamjenska=zamjenska;
		while(*zamjenska!=0){
			zamjenska++;
			duzina_2++;
		}
		while(*tekst!=0){
			p_kraj=kraj;
			trenutna=p_trenutna;
			zamjenska=p_zamjenska;
			brojac=0;
			while(*tekst==' ') tekst++;
			a=tekst;
			while(*tekst!=' ' && *tekst!=0) tekst++;
			b=tekst;
			p_a=a;
			if(duzina==b-a){
/* Ispitivanje jednakosti rijeci u stringu i rijeci koju treba zamijeniti */				
				do{
					if(*a==*trenutna) brojac++;
					a++;
					trenutna++;
				} while(a!=b);
				a=p_a;
				if 	(brojac==duzina){
/* Zamjena rijeci u stringu */					
					if(duzina<=duzina_2){
						while(kraj>a){
							*(kraj+duzina_2-duzina)=*kraj;
							kraj--;
						}
						for(i=0;i<duzina_2;i++)
							*a++=*zamjenska++;
						kraj=p_kraj+duzina_2-duzina;
						tekst=tekst-duzina+duzina_2;
					}
					else {
						for(i=0;i<duzina_2;i++)
							*a++=*zamjenska++;
						do{
							*a=*(a+duzina-duzina_2);
							a++;
						} while (*a!=0);
					}
				}
			}
		}
	}
	return p_tekst;
}
int main() {
	char*rijeci[2]={"bijeli","sneg"};
	char*zamjene[2]={"beli","snijeg"};
	char tekst[100]={"bijeli sneg"};
	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
	return 0;
}
