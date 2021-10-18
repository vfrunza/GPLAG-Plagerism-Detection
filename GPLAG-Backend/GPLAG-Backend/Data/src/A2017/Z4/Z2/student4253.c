#include <stdio.h>

void unesi(char niz[],int velicina);

/*funkcija koja provjerava da li niz predstavlja niz duzina rijeci u recenici*/
char provjeri_duzine (char* s,int* niz,int vel)
{
	int br=0,i=0;
	while(*s!='\0' && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))  {
		s++;

	}

	/*provjera duzine rijeci u recenici*/
	while(*s!='\0') {
		br=0;
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			br++;
			s++;
		}


		if (niz[i]!=br) {
			
			return 0;
		}
		vel--;
		i++;

		while(*s!='\0' && !((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))  {
			s++;

		}
		

	}
	if(vel==0) return 1;
	else {
		return 0;
	}
}

void unesi(char niz[],int velicina) /*funkcija za unos recenice*/
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


int main()
{

	char a[100];
	int niz[100],i,vel;
	printf("Unesite neku recenicu (ENTER ZA KRAJ): ");
	unesi(a,100);
	printf("Unesite niz cijelih brojeva (-1 ZA KRAJ): \n");

	for(i=0; i<100; i++) {
		scanf("%d",&niz[i]);
		if(niz[i]==-1) break;
	}

	vel=i;
	printf("%d ", provjeri_duzine(a, niz, vel)); /*poziv funkcije*/


	return 0;
}
