#include <stdio.h>
struct Oblik 
{
	char naziv[20];
	int br_stranica;
	double stranice[300];
} o;
int dodaj_oblik(struct Oblik o)
{
	int duzina,pisi;
	struct Oblik ob[1000];
	FILE *ulaz=fopen("oblici.dat","rb");
	if(ulaz==NULL) 
	{
		printf("Greska prilikom otvaranja datoteke");
		return 1;
	}
	duzina=fread(ob,sizeof(struct Oblik),1000,ulaz);
	pisi=fwrite(ob,sizeof(struct Oblik),duzina,ulaz);
	fclose(ulaz);
	return pisi;
}
int izbaci_duple(struct Oblik *o,int velicina)
{
	int i,j;
	for(i=0;i<velicina;i++)
	{
		for(j=i+1;j<velicina;j++)
		{
			if(o[i].naziv==o[j].naziv)
				o[i]=o[i+1];
		}
		i--;
		velicina--;
	}
	return velicina;
}
struct Oblik daj_najveci(struct Oblik o,int velicina)
{
	int i,j,maxi;
	float max,obim;
	for(j=0;j<o.br_stranica;j++)
		max+=o.stranice[j];
	for(i=0;i<velicina;i++)
	{
	for(j=0;j<o[i+1].br_stranica;j++)
	{
		obim+=o[i].stranice[j];
		if(obim>max)
		{
			max=obim;
			maxi=i;
		}	
	}
	}
	printf("Ime: %s",o.naziv);
	printf("Broj stranica: %d",o.br_stranica);
	return o[maxi];
}
int main() {
	int i;
 o.naziv[6]="Oblik1";
 o.br_stranica=4;
 for(i=0;i<6;i++)
 {
 	scanf("%f",o.stranice[i]);
 }
 daj_najveci(o,1);
 dodaj_oblik(o);
}
