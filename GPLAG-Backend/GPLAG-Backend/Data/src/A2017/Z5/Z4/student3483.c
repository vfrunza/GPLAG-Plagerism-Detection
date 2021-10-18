#include <stdio.h>


struct Prodavnica{
	char naziv[100];
	int ID;
};

struct Artikal{
	char naziv[100];
	double cijena;
	int prodavnica;
};


int ucitaj_artikle(struct Artikal* niz,int kap) {
	int ucitano;
   FILE* dat = fopen("artikli.bin", "rb");
   if (dat == NULL) {
   printf("Greska pri otvaranju datoteke.\n");
   return 0;
   }
   ucitano = fread(niz, sizeof(niz[0]),kap, dat);
   fclose(dat);
        
return ucitano;
}




int ucitaj_prodavnice(struct Prodavnica *niz,int kap)
{
	int i=0,j=0;
	FILE* ulaz=fopen("prodavnice.txt","r");
	while(1>0)
	{
		char znak=fgetc(ulaz);
		if(znak==EOF)
		break;
		if(znak!=',' && j==99)
		{
			while((znak=fgetc(ulaz))!=',');
		}
		if(znak!=',')
		niz[i].naziv[j++]=znak;
		else
		{
			niz[i].naziv[j]='\0';
			j=0;
			if(fscanf(ulaz,"%d\n",&niz[i].ID)==1)
			i++;
			else
			break;
			if(i==kap)
			break;
		}
		
		
	}
	fclose(ulaz);
	return i;
}




int izbaci_skupe(struct Prodavnica *p,int np,struct Artikal *a,int na)
{
	float prosjek_svi=0,prosjek=0;
	int i=0,j=0,k=0,m;
	for(i=0;i<np;i++)
	{
		for(j=0;j<na;j++)
		{
			if(a[j].prodavnica==p[i].ID)
			{k++;prosjek_svi+=a[j].cijena;}
		}
	}
	for(i=0;i<np;i++)
	{
		prosjek=0;k=0;
		for(j=0;j<na;j++)
		{
			if(a[j].prodavnica==p[i].ID)
			{k++;prosjek+=a[j].cijena;}
		}
		prosjek=prosjek/k;
		if(prosjek>prosjek_svi)
		{
			for(m=i;m<np-1;m++)
			p[m]=p[m+1];
			np--;
			i--;
		}
		
	}
	
	
	return np;
}

int sacuvaj(struct Prodavnica *p,int n,const char *ime_datoteke)
{
	
	return 0;
}

int main() {
	struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;
for (i = 0; i < n; ++i)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);
	return 0;
}
