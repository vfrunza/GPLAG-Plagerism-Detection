#include <stdio.h>

int duzina(char *s)
{
	int br=0;
	while(*s!='\0') {
		br++;
		s++;
	}
	return br;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	int i,razmak,zamijeni,br,duz;
	char *poctekst=tekst,*rec,*pocrijeci,*pocrec,*u,*v,*poczam;
	for(i=0; i<broj_rijeci; i++) {
		duz=duzina(zamjene[i]);
		poczam=zamjene[i];
		razmak=1;
		while(*tekst!='\0') {
			if(*tekst==' ')
				razmak=1;
			else if(razmak==1) {
				razmak=0;
				rec=tekst;
				zamijeni=1;
				pocrijeci=rijeci[i];
				pocrec=rec;
				
				/*Provjeravanje da li je rijec koja se treba zamijeniti*/
				while(*rec!=' ' && *rec!='\0') {

					if(*rec!=*rijeci[i]) {
						zamijeni=0;
						break;
					}
					rec++;
					rijeci[i]++;
				}
				
				if(*rijeci[i]!='\0')
					zamijeni=0;
					
				rijeci[i]=pocrijeci;
				rec=pocrec;
				
				if(zamijeni==1) {
					br=0;
					
					/*Rijec koja se treba zamijeniti se izbaci, na njeno mjesto se upise rijec koja je mijenja*/
					while(*rec!=' ' && *rec!='\0') {
						br++;
						rec++;
					}
					
					u=pocrec;
					v=pocrec+br;
					while(*v!='\0') {
						*u=*v;
						u++;
						v++;
					}
					
					*u='\0';
					v=u;
					u=pocrec;
					while(v>=u) {
						*(v+duz)=*v;
						v--;
					}

					v=u+duz;
					while(u<v) {
						*u=*zamjene[i];
						u++;
						zamjene[i]++;
					}
					
					zamjene[i]=poczam;
				}

			}
			tekst++;
		}
		tekst=poctekst;

	}

	return poctekst;
}

int main()
{

	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
