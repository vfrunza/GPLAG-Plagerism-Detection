#include <stdio.h>
void unesi(char niz[],int velicina)
{
	char znak =getchar();
	if(znak=='\n')znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!= '\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* tekst,int niz3[],int vel)
{
	int niz[100]= {0};
	int niz1[100];
	int i=0,k,j,pomak;
	int razmak,brojac_r=0;
	int brojac_slova=0;
	int istina;
	razmak=1;
	char *pok=tekst;
	while(*tekst !='\0') {
		if(!(*tekst>='A'&&*tekst<='Z' || *tekst>='a'&&*tekst<='z' ))
			razmak=1;
		else if(razmak==1) {
			razmak=0;
			brojac_r++;
		}
		tekst++;
	}
	pomak=1;
	while(*pok !='\0') {
		if(!(*pok>='A'&& *pok<='Z' || *pok>='a'&&*pok<='z' ))
			pomak=1;
		else if(pomak==1) {
			pomak=0;
			char *kraj=pok;
			brojac_slova=0;
			while(*kraj>='A'&& *kraj<='Z' || *kraj>='a' && *kraj<='z' ) {
				brojac_slova++;
				kraj++;

			}

			niz[i++]+=brojac_slova;
		}
		pok++;
	}

	for(k=0; k<brojac_r; k++)
		niz1[k]=niz[k];


	istina=1;
	if(vel==brojac_r) {
		for(j=0; j<vel; j++)

			if(niz3[j]!=niz1[j]) {
				istina=0;
				break;
			}
	} else return 0;

	if(istina==1)
		return 1;
	else return 0;

}

int main()
{
	char tekst[100];
	int niz[100],i,n;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
		scanf("%d",&niz[i]);

	printf("%d",provjeri_duzine(tekst,niz,n));
	return 0;
}
