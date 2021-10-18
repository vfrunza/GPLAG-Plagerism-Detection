#include <stdio.h>

struct Prodavnica
{
	char naziv[100];
	int ID;
};

struct Artikal
{
	char naziv[100];
	double cijena;
	int prodavnica;
};

void unesi(char niz[], int vel)
{
	char znak=getchar();
	int i;
	if (znak=='\n')
		znak=getchar();
	i=0;
	while(i<vel-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}
/*funkcija za unos stringa iz datoteke*/
void unesi_dat(FILE* dat, char niz[], int vel)
{
	char znak=fgetc(dat);
	int i;
	if (znak=='\n')
		znak=fgetc(dat);
	i=0;
	while(i<vel-1 && znak!=EOF && znak!='\n' && znak!=',')
	{
		niz[i]=znak;
		znak=fgetc(dat);
		i++;
	}
	niz[i]='\0';
}

int ucitaj_artikle(struct Artikal* niz, int kap)
{
	int ucitano=0;
	FILE* ulaz=fopen("artikli.bin", "rb");
	if (ulaz==NULL)
	{
		printf("Doslo je do greske prilikom otvaranja datoteke artikli.bin.");
		return 1;
	}
	ucitano=fread(niz, sizeof(struct Artikal), kap, ulaz);
	fclose(ulaz);
	return ucitano;
}
int ucitaj_prodavnice(struct Prodavnica* niz, int kap)
{
	int i;
	FILE* ulaz=fopen("prodavnice.txt","r");
	if (ulaz==NULL)
	{
		printf("Doslo je do greske pri otvaranju datoteke prodavnice.txt.");
		return 1;
	}
	i=0;
	while(i<kap && !feof(ulaz))
	{
		unesi_dat(ulaz,niz[i].naziv,100);
		fscanf(ulaz,"%d", &niz[i].ID);
		i++;
	}

	fclose(ulaz);
	return i;
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	int br_art[100]={0}, i, j;
	double suma_cijena[100]={0}, suma=0, pr1, pr2;
	
	/*racunanje suma*/
	for(i=0; i<na; i++)
	{
		suma+=a[i].cijena;
		for(j=0; j<np; j++)
		{
			if (p[j].ID==a[i].prodavnica)
			{
				br_art[j]++;
				suma_cijena[j]+=a[i].cijena;
				break;
			}
		}
	}
	pr1=suma/na;
	/*izbacivanje iz niza*/
	for(i=0; i<np; i++)
	{
		if (br_art[i]>0)
		{
			pr2=suma_cijena[i]/br_art[i];
			if (pr2>pr1)
			{
				for(j=i; j<np; j++)
					p[j]=p[j+1];
				np--;
				i--;
			}
		}
	}
	return np;	
}

int sacuvaj (struct Prodavnica *p, int n, const char*ime_datoteke)
{
	int ucitano;
	FILE* ulaz=fopen(" *ime_datoteke", "wb");
	if (ulaz==NULL)
	{
		printf("Doslo je do greske pri otvaranju datoteke.");
		return 0;;
	}
	
	ucitano=fwrite(p, sizeof(struct Prodavnica), n, ulaz);
	if (ferror(ulaz))
		return 0;
	else 
		return 1;	
	fclose(ulaz);
}


int main() {
	
	struct Artikal niz[1];
	ucitaj_artikle(niz, 1);
	
	struct Prodavnica nizp[1];
	ucitaj_prodavnice(nizp, 1);
	
	printf("%s ",nizp[0].naziv);
	
	return 0;
}
