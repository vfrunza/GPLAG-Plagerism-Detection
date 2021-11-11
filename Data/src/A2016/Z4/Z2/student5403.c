#include <stdio.h>
#include <string.h>

void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if(znak=='\n')
		znak=getchar();
	i=0;
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* kodiraj (char *niz,char *niz1)
{
	int i,j,vel,velnova=0,k;
	char pom[256];
	char tmp;
	char *s;
	int brojac[256]= {0};
	int pon[256]= {0};
	int index[256];

	vel=strlen(niz);
	for(i=0; i<vel; i++)
		brojac[niz[i]-' ']++;

	/*Cuvanje vrijednosti pocetnog niza u pomocni zbog transformacija nad nizom*/
	for(i=0; i<vel; i++)
		pom[i]=niz[i];

	/*Sortiranje niza prema broju ponavljanja karaktera*/
	for(i=0; i<vel; i++) {
		for(j=i+1; j<vel; j++) {
			if(brojac[niz[j]-' ']>brojac[niz[i]-' ']) {
				tmp=niz[j];
				niz[j]=niz[i];
				niz[i]=tmp;
			}

			else if(brojac[niz[i]-' ']==brojac[niz[j]-' ']) {
				if(niz[i]>niz[j]) {
					tmp=niz[i];
					niz[i]=niz[j];
					niz[j]=tmp;
				}
			}
		}
	}

	k=0;
	i=0;
	/*Upisivanje vrijednosti u novi niz,odnosno tablicu*/
	while(k<vel) {
		if(pon[niz[k]-' ']==0) {
			niz1[i]=niz[k];
			index[niz[k]-' ']=i;
			pon[niz[k]-' ']++;
			i++;
			k++;
			velnova++;
		}

		else
			k++;
	}

	k=velnova;

	/*Ako se neki karakteri iz ASCII tablice ne nalaze u stringu,u tablicu sifrovanja ih upisujemo prema ASCII vrijednosti*/
	for(i=0; i<95; i++) {
		if(brojac[i]==0) {
			niz1[k]=i+' ';
			k++;
		}
	}

	niz1[k]='\0';

	for(i=0; i<vel; i++) {
		pom[i]=126-index[pom[i]-' '];
	}

	/*Kopiranje iz pomocnog niza*/
	for(i=0; i<vel; i++) {
		niz[i]=pom[i];
	}
	s=niz;
	return s;
}


char* dekodiraj(char *niz,char *niz1)
{

	char *p;
	int vel,i;
	char pom[256];
	vel=strlen(niz);
	for(i=0; i<vel; i++)
		pom[i]=niz1[126-niz[i]];
	for(i=0; i<vel; i++)
		niz[i]=pom[i];
	p=niz;

	return p;

}

int main()
{
	char niz[100];
	char niz1[100];
	printf("Unesi string");
	unesi(niz,100);
	kodiraj(niz,niz1);
	dekodiraj(niz,niz1);
	return 0;
}
