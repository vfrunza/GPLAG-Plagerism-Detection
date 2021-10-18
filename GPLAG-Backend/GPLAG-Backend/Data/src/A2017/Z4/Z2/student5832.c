#include <stdio.h>
#define velicina 100
void string(char niz[],int vel );
int provjeri_duzine(char *s1,int niz[],int vel);

int main()
{
	char a[velicina];
	int i,niz[velicina],vellicina;
	printf("Unesite string: ");
	string(a,velicina);
	printf("Unesite velicinu niza: ");
	scanf("%i",&vellicina);
	printf("Unesite niz brojeva: ");
	for(i=0; i<vellicina; i++) {
		scanf("%i",&niz[i]);
	}
	printf("%i",provjeri_duzine(a,niz,vellicina));
	return 0;
}
void string(char niz[],int vel)
{
	int i=0;
	char slovo=getchar();
	if(slovo=='\n')
		slovo=getchar();
	while(i<vel-1 && slovo !='\n') {
		niz[i]=slovo;
		slovo=getchar();
		i++;
	}
	niz[i]='\0';
}

int provjeri_duzine(char *s1,int niz[],int vel)
{
	int broj_r=0,broj_s=0;
	int nizz[velicina]= {0};
	int i=0,j=0,istina=1;
	int duzina=1;
	while(*s1!='\0') {
		if(!(*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z')) {
			duzina=1;
			if(broj_s!=0) {
				nizz[i++]=nizz[i]+broj_s;
				broj_s=0;
			}
		} else if(duzina==1) {
			duzina=0;
			broj_s=0;
			broj_r++;
		}
		if(duzina==0) {
			broj_s++;
		}
		s1++;
	}
	char *end=s1;
	while(*end !='\0')
		end++;
	if(*(end-1)>='A' && *(end-1)<='Z' || *(end-1)>='a' && *(end-1)<='z') {
		if(broj_s!=0) {
			nizz[i++]=nizz[i]+broj_s;
			broj_s=0;
		}
	}
	if(broj_r==i && broj_r==vel) {
		for(j=0; j<vel; j++)
			if(nizz[j] != niz [j]) {
				istina=0;
				break;
			}
	} else
		return 0;
	if(istina==1)
		return 1;
	else
		return 0;
}
