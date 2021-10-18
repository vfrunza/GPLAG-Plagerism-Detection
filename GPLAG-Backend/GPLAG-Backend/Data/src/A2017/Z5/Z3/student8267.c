#include <stdio.h>

int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}
/*#include <stdio.h>
#define PI 3.14159265

struct Tijelo
{
	char vrsta;
	
	//krug
	double r; //poluprecnik
	
	//trougao
	double b; //baza
	double h; //visina
	
	//pravougaonik
	double s; //sirina
	double v; //visina
	
	double P;
};

int ucitaj(struct Tijelo niz[], int n)
{
	int j;
	FILE* fp;
	int i=0;
	char c;
	fp=fopen("geometrija.txt","a+");
	if(fp==NULL)
	{
		printf("Neuspjesno otvaranje datoteke geometrija.txt");
		return 2;
	}
	do
	{
		c=fgetc(fp);
		if(c=='K') 
		{
			niz[i].vrsta='K';
			fscanf(fp,"%lf",&niz[i].r);
			niz[i].P=niz[i].r*niz[i].r*PI;
			i++;
		}
		else if(c=='P')
		{
			niz[i].vrsta='P';
			fscanf(fp,"%lf,%lf",&niz[i].s,&niz[i].v);
			niz[i].P=niz[i].s*niz[i].v;
			i++;
			
		}
		else if(c=='T')
		{
			niz[i].vrsta='T';
			fscanf(fp,"%lf,%lf",&niz[i].b,&niz[i].h);
			niz[i].P=(niz[i].b*niz[i].h)/2;
			i++;
		}
		
	}while(c!=EOF && i<n);
	fclose(fp);
	return i;
}

void zapisi(struct Tijelo niz[], int n)
{
	FILE* izlaz;
	izlaz=fopen("geometrija-sortirano.txt","w"); //brisemo sve sta ima u datoteci
	if(izlaz==NULL)
	{
		printf("Neuspjesno otvaranje datoteke geometrija-sortirano.txt");
		return 3;
	}
	fclose(izlaz);
	izlaz=fopen("geometrija-sortirano.txt","a+");
	struct Tijelo temp;
	int i,j;
	int broj;
	int maxbr;
	double max=0;
	for (i=0; i<n; i++) 
    {
        maxbr=i;
        for (j=i+1; j<n; j++) 
            if (niz[j].P > niz[maxbr].P) maxbr = j;
    	temp = niz[i];
        niz[i] = niz[maxbr];
        niz[maxbr] = temp;
    }
	for(i=0;i<n;i++)
	{
		if(niz[i].vrsta=='K')
		{
			fprintf(izlaz,"Krug %.2f\n",niz[i].r);
		}
		else if(niz[i].vrsta=='T')
		{
			fprintf(izlaz,"Trougao %.2f %.2f\n",niz[i].b,niz[i].h);
		}
		else if(niz[i].vrsta=='P')
		{
			fprintf(izlaz,"Pravougaonik %.2f %.2f\n",niz[i].s,niz[i].v);
		}
	}
	fclose(izlaz);
}

double povrsina(struct Tijelo niz[], int n)
{
	double P=0;
	int i;
	for(i=0;i<n;i++) P+=niz[i].P;
	return P;
}

int main() {
	struct Tijelo niz[100];
	
	int br_tijela = ucitaj(niz, 100);
	printf("Broj tijela: %d\n", br_tijela);
	zapisi(niz, br_tijela);
	printf("Povrsina svih tijela je %.2f\n", povrsina(niz, br_tijela));
	return 0;
}*/