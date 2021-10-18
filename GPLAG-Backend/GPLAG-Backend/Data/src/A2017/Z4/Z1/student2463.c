#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
/*int br_mjesta(int broj){
	int brojac={0}, cifra=0, x=0;
	if(broj<0){
		brojac=1;
	}
	else{
		brojac=0;
	}
	while(broj!=0){
		cifra=broj%10;
		x=(int)broj/10;
		broj=x;
		brojac++;
	}
	return brojac;
}*/
char *ubaci_broj(char *tekst, int broj)
{	
	while(*tekst!='\0'){
		if(*tekst=' '){
			char *pom1=tekst;
			pom1++;
			if(*pom1!=' '){
				char *pom2=pom1;
				while (*pom2!='\0') { pom2++;
				*(pom2+1)=pom2;
					
				}
			}
		}
		tekst++;
	}
}

int main()
{

	char tekst[100];
	int n;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	printf("Unesite broj koji ce se ubaciti: ");
	scanf("%d", &n);
	printf("Modifikovani string glasi %s.", ubaci_broj(tekst, n));

	return 0;
}
