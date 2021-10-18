#include <stdio.h>
#include <math.h>

void unesi (char niz[], int vel)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while (i<vel-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

/*Prebroje se rijeci u recenici i ako se broj rijeci razlikuje od velicine niza onda se vraca nula iz funckije*/
int duzina(char* recenica1, int velicina)
{
	int brojac=0;
	while(*recenica1!='\0') {
		while((*recenica1<'A' || (*recenica1>'Z' && *recenica1<'a') || *recenica1>'z')&& *recenica1!='\0') recenica1++;
		/*Ako se naleti na znak koji nije slovo i koji nije kraj recenice tj ovo \0 povecaj pokazivac tj idi dalje*/
		if(*recenica1=='\0') break; /*Ako naleti na \0 onda prekidaj petlju jer nema vise potrebe sta da se radi u stringu*/
		while( ((*recenica1>='A' && *recenica1<='Z') || (*recenica1>='a' && *recenica1<='z')) && *recenica1!='\0') {
			recenica1++; /*Ako su znakovi u recenici slova onda pomjeraj recenicu tj pokazivac na nju naprijed da ide*/
		}
		brojac++; /*Povecava se brojac svaki put kad se nadje nova rijec*/
	}
	if(brojac!=velicina) return 0; /*Ako je broj rijeci razlicit od velicine niza vrati se nula*/
	else return 1;
}

int provjeri_duzine (char* recenica, int niz[], int velicina)
{
	int slova=0, i=0;
	char *p1=recenica;

	if(duzina(p1,velicina)==0) return 0;
	/*Provjera da li se velicina niza razlikuje od broja rijeci u recenici i ako je vraceno 0 onda i funkcija provjeri_duzine vraca nulu i prekida sa radom*/

	while(*recenica!='\0') {
		slova=0;
		while((*recenica<'A' || (*recenica>'Z' && *recenica<'a') || *recenica>'z')&& *recenica!='\0') recenica++;
		if(*recenica=='\0')break;
		while( ((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z')) && *recenica!='\0') {
			slova++;
			recenica++;
		}

		if(niz[i]==slova) {
			i++;
		} else return 0;
	}

	return 1;
}

int main()
{
	char recenica[1000];
	int niz[1000], velicina=0, a, i;
	printf("Unesite tekst: ");
	unesi(recenica,1000);
	printf("Unesite niz:");
	for(i=0; i<1000; i++) {
		scanf("%d", &a);
		if(a<0) break;
		else {
			niz[i]=a;
			velicina++;
		}
	}

	if(provjeri_duzine(recenica, niz, velicina)!=0) printf("Tacno!");
	else printf("Greska!");

	return 0;
}
