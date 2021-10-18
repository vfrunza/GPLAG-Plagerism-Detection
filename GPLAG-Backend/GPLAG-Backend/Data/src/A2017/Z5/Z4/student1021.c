#include <stdio.h>
struct Prodavnica {char naziv[100]; int ID;};
struct Artikal{char naziv[100]; double cijena; int prodavnica;};
int ucitaj_artikle (struct Artikal *niz, int kap)
{
	FILE* dat;
	int ocitano=0;
	dat=fopen("artikli.bin","rb");
	if(dat==NULL)
	{
		printf("Greska pri otvaranju binarne datoteke arikli.bin.\n");
		return 0;
	}
	ocitano=fread(niz,sizeof(struct Artikal),kap,dat);
	fclose(dat);
	return ocitano;
}
int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
	FILE* dat;
	int ocitano=0;
	dat=fopen("prodavnice.txt","r");
	if(dat==NULL)
	{
		printf("Greska pri otvaranju tekstualne datoteke prodavnice.txt.\n");
		return 0;
	}
	while(fscanf(dat,"%100s,%d\n",niz[ocitano].naziv,&(niz[ocitano].ID))==2 && ocitano<kap)
	ocitano++;
	fclose(dat);
	return ocitano;
}
int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}
