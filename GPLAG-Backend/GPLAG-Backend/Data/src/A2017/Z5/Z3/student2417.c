#include <stdio.h>
struct Oblik { char naziv[20]; int br_stranica; double stranice[300];};

struct Oblik daj_najveci()
{
	int ocitano=0,i=0,j=0;
	double obim=0;
	double pom=0;
	struct Oblik oblic[2000];
	struct Oblik oblik;
	FILE* dat;
	oblik.br_stranica=2;
	oblik.stranice[0]=1;
	dat=fopen("oblici.dat","rb");
	if(dat==NULL)
	{
		printf("Greska pri otvaranju datoteke.\n");
		return oblik;
	}
	ocitano=fread(&oblic,sizeof(struct Oblik),2000,dat);
	printf("%d",ocitano);
	fclose(dat);
	if(ocitano==0) return oblik;
	oblik=oblic[0];
	for(j=0;j<oblic[0].br_stranica;j++)
	obim+=oblic[0].stranice[j];
	for(i=0;i<ocitano;i++)
	{
		pom=0;
		for(j=0;j<oblic[i].br_stranica;j++)
		{
			pom+=oblic[i].stranice[j];
		}
		if(pom>obim) {oblik=oblic[i]; obim=pom;}
	}
	return oblik;
}
void dodaj_oblik(struct Oblik oblik)
{
	int k;
	FILE* dat=fopen("oblici.dat","ab");
	if(dat==NULL)
	{
		printf("Greska pri otvaranju datoteke.\n");
		return;
	}
	k=fwrite(&oblik,sizeof(struct Oblik),1,dat);
	if(ferror(dat))
	{
		printf("Greska pri zapisivanju.\n");
	}
	fclose(dat);
}
int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}
