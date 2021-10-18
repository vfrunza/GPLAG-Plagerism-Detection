#include <stdio.h>
#include <stdlib.h>

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

struct Prodavnica {
	char naziv[100];
	int ID;
};

int ucitaj_artikle(struct Artikal *niz,int kap)
{
	int broj_ucitanih=0;
	FILE *ulaz=fopen("artikli.bin","rb");
	{
		if(ulaz == NULL) {
			printf("Greska");
			return -1;
		}
	}
	broj_ucitanih=fread(niz,sizeof(struct Artikal),kap,ulaz);
	fclose(ulaz);
	return broj_ucitanih;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	int i=0,brojac=0;
	char znak='\0';
	FILE *prodavnica=fopen("prodavnice.txt","r");
	{
		if(prodavnica==NULL) {
			printf("Greska");
			return -1;
		}
	}
	for(i = 0; i < kap; i++) {
		znak = fgetc(prodavnica);
		if(znak == EOF) break;
		brojac=0;
		do {
			niz[i].naziv[brojac++] = znak;
		} while((znak = fgetc(prodavnica))!=',' && brojac < 99);
		/*Citamo preostale znakove do zareza u slucaju da ih ima*/
		if(brojac == 99 && znak != ',')
		{
			while((znak = fgetc(prodavnica)) != ',');
		}
		niz[i].naziv[brojac] = 0;
		fscanf(prodavnica,"%d",&niz[i].ID);
		//Ucitamo novi red da ne bi ucitao ime artikla//
		znak = fgetc(prodavnica);
	}
	return i;
}
double Prosjek(struct Artikal *niz, int ID_prod, int kapacitet)
{
	int i,nadjeni=0;
	double rezultat,suma=0;
	for(i = 0; i < kapacitet; i++)
	{
		if(niz[i].prodavnica == ID_prod)
		{
			suma += niz[i].cijena;
			nadjeni++;
		}
	}
	if(nadjeni == 0) return 0;
	else 
		return suma/nadjeni;
}
void izbaci(struct Prodavnica *niz,int indeks, int kapacitet)
{
	int i= indeks;
	for(i = indeks; i < kapacitet-1; i++)
	{
		niz[i] = niz[i+1];
	}
	kapacitet--;
	
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	int i;
	double suma = 0,prosjek,temp;
	if(na == 0 || np == 0) return np;
	for(i = 0; i < na; i++)
	{
		suma += a[i].cijena;
	}
	prosjek = suma /na;
	for(i = 0; i < np; i++)
	{
		temp = Prosjek(a,p[i].ID,na);
		if(temp > prosjek)
		{
			izbaci(p,i,np);
			np--;
		}
	}
	return np;
}

int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE *izlaz=fopen(ime_datoteke,"wb");
	if(izlaz == NULL)
	{
		printf("Greska");
		return 0;
	}
	int ucitano = fwrite(p,sizeof(struct Prodavnica),n,izlaz);
	if(ferror(izlaz))
	{
		printf("Greska");
		return 0;
	}
	fclose(izlaz);
	return 1;
}


int main()
{
	/*	int i;   
	struct Prodavnica prodavnice[10];
	int n = ucitaj_prodavnice(prodavnice,10);
	printf("n = %d\n",n);

	for(i = 0; i < n; i++)
	{
		printf("%s, %d ",prodavnice[i].naziv,prodavnice[i].ID);
	}*/
	struct Prodavnica p[] = {
	{"Amko", 1},
	{"Bingo", 2},
	{"Konzum", 3},
};
struct Artikal a[] = {
	{"Kiseli kupus", 10, 4},
	{"Bickl", 1000, 5},
	{"Krastavci", 2, 4}
};
int i = izbaci_skupe(p, 3, a, 0), j;
for (j = 0; j < i; ++j)
	printf ("%s, ID: %d\n", p[j].naziv, p[j].ID);
i = izbaci_skupe(p, 0, a, 0);
for (j = 0; j < 3; ++j)
	printf ("%s, ID: %d\n", p[j].naziv, p[j].ID);
i = izbaci_skupe(p, 0, a, 3);
for (j = 0; j < 3; ++j)
	printf ("%s, ID: %d\n", p[j].naziv, p[j].ID);	
	return 0;
}
