#include <stdio.h>
#include <stdlib.h>

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

int ucitaj_artikle(struct Artikal *niz, int kap)
{
	FILE* reg = fopen("artikli.bin","rb");
	if(reg == NULL)
	{
		printf("Greska pri otvaranju datoteke!");
		exit(1);
	}
	return fread(niz,sizeof(struct Artikal),kap,reg);

}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap)
{
	int i=0,j,k=0;
	int id;
	int zavrsi ;
	char ime[100]="";
	FILE* prodavnice = fopen("prodavnice.txt","r");
	if(prodavnice==NULL)
	{
		printf("Greska pri otvaranju datoteke!");
		exit(1);
	}


	for(k=0; k<kap; k++) 	{
	char znak;
	
		do	{ 
			znak=fgetc(prodavnice);
			if(znak==EOF) {
				zavrsi = 1;
				break;
				};
			if(znak!=',') {
				ime[i]=znak;
				i++;
			}

		}
		
		
		while(znak!=',' && i<99);
		if(zavrsi == 1) break;
		if(i==99) {
			if(znak!=',') 	{
				do {
					znak=fgetc(prodavnice);
				}
				while(znak!=',');
			}
		}
		ime[i]='\0';
		for(j=0; j<=i; j++) {
			niz[k].naziv[j]=ime[j];
		}
		fscanf(prodavnice,"%d\n",&id);
		niz[k].ID=id;

	}

	return k;

}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	FILE* prodavnica=  fopen(ime_datoteke,"wb");
	int id;
	char name[100]="";
	if(prodavnica == NULL) 	{
		return 0;
	}
	int k;
	for(k=0; k<n; k++) 	{
		int i;
		for(i=0; i<100; i++) 	{
			name[i]=p[k].naziv[i];
		}
		id=p[k].ID;
		fwrite(name,1,100,prodavnica);
		if(ferror(prodavnica)) {
			return 0;
		}
		fwrite(&id,4,1,prodavnica);
		if(ferror(prodavnica)){
			return 0;
		}
	}

	fclose(prodavnica);
	return 1;
}

int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na)
{
	double suma=0, prosjek=0;
    double *prodavnica=(double*)malloc(sizeof(double)*(np));
	int *niz=(int*)malloc(sizeof(int)*(np));
	int i;
	for(i=0;i<np;i++) {
		niz[i]=p[i].ID;
	}
	for(i=0;i<np;i++)	{
		prodavnica[i]=0;
	}
	for(i=0;i<na;i++) {
		int j;
		for(j=0;j<np;j++)
		{
			if(a[i].prodavnica==niz[j]) {
				prodavnica[j]+=a[i].cijena;
			}
		}
		
	}
	for(i=0;i<np;i++) 	{
		int n=0;
		int j;
		for(j=0;j<na;j++)	{
		if(a[j].prodavnica==p[i].ID) {
			n++;	
		}
		}
		prodavnica[i]/=(double)n;
	}
	
	for(i=0;i<np;i++) 	{
		suma+=prodavnica[i];
	}
	prosjek=suma/(double)np;
	for(i=0;i<np;i++) {
		if(prodavnica[i]>prosjek) 	{
			int j;
			for(j=i+1;j<np;j++) 	{
				prodavnica[j-1]=prodavnica[j];
				niz[j-1]=niz[j];
				p[j-1]=p[j];
			}
			i--;
			np--;
		}
	}
	free(prodavnica);
	free(niz);
	
	return np;
}




int main()
{
printf("a");
	return 0;
}
