#include <stdio.h>
#include <stdlib.h>

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

int ucitaj_artikle (struct Artikal *niz, int kap);

int ucitaj_prodavnice (struct Prodavnica *niz, int kap);

int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na);

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke);

int main()
{

	return 0;
}

int ucitaj_artikle (struct Artikal *niz, int kap)
{
	int ucitano;
	FILE* registar;

	registar=fopen("artikli.bin","rb");
	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		exit(1);
	}
	///toliko je lahko unijeti niz struktura ove definicije
	//a ja kopao i kopao 
	ucitano = fread(niz,sizeof(struct Artikal),kap,registar);

	return ucitano;

}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
	int i,j,k;
	int id;
	char znak;
	char ime[100]="";
	FILE* lager;

	lager=fopen("prodavnice.txt","r");
	if(lager==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		exit(1);
	}


	for(k=0; k<kap; k++)
	{

		i=0;
		do
		{//ucitavanje imena 
			znak=fgetc(lager);
			if(znak==EOF)goto kraj;
			if(znak!=',')
			{
				ime[i]=znak;
				i++;
			}

		}
		while(znak!=','&&i<99);
		if(i==99)
		{
			if(znak!=',')
			{
				do
				{
					znak=fgetc(lager);
				}
				while(znak!=',');
			}
		}
		ime[i]='\0';
		for(j=0; j<=i; j++)
		{
			niz[k].naziv[j]=ime[j];
		}
		fscanf(lager,"%d\n",&id);
		niz[k].ID=id;

	}


kraj:
	return k;

}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE* lager;
	int i,j,k;
	int id;
	char name[100]="";

	lager=fopen(ime_datoteke,"wb");

	if(lager==NULL)
	{
		return 0;
	}


	for(k=0; k<n; k++)
	{
		for(i=0; i<100; i++)
		{
			name[i]=p[k].naziv[i];
		}
		id=p[k].ID;
		fwrite(name,1,100,lager);
		if(ferror(lager))return 0;
		fwrite(&id,4,1,lager);
		if(ferror(lager))return 0;
	}

	fclose(lager);

	return 1;
}

int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	int i,j,n;
	double suma=0;
	double prosjek=0;
	int *niz=(int*)malloc(sizeof(int)*(np));
	double *lager=(double*)malloc(sizeof(double)*(np));
	
	for(i=0;i<np;i++)
	{
		lager[i]=0;
	}
	for(i=0;i<np;i++)
	{
		niz[i]=p[i].ID;
	}
	for(i=0;i<na;i++)
	{
		for(j=0;j<np;j++)
		{
			if(a[i].prodavnica==niz[j])lager[j]+=a[i].cijena;
		}
		
	}

	//trazimo prosjeke prodavnica pojedinacno
	
	for(i=0;i<np;i++)
	{
		n=0;
		for(j=0;j<na;j++)
		{
		if(a[j].prodavnica==p[i].ID)n++;	
		}
		lager[i]/=(double)n;
	}
	
	for(i=0;i<np;i++)
	{
		suma+=lager[i];
	}
	prosjek=suma/(double)np;
	// IZBACIVANJE PRODAVNICA
	for(i=0;i<np;i++)
	{
		if(lager[i]>prosjek)
		{
			for(j=i+1;j<np;j++)
			{
				lager[j-1]=lager[j];
				niz[j-1]=niz[j];
				p[j-1]=p[j];
			}
			np--;
			i--;
		}
	}
	free(niz);
	free(lager);
	return np;
}