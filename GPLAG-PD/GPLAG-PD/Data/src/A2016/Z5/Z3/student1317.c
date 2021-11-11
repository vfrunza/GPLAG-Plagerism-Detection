#include <stdio.h>
#define KAPACITET 200

struct Vrijeme
{
	int sati, minute, sekunde;
};

struct Cas
{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
	int zapisano=0;
	FILE* izlaz=fopen("raspored.dat", "wb");
	if(izlaz==NULL)
	{
		printf("Otvaranje izlazne datoteke nije uspjelo.\n");
		return 1;
	}
	
	zapisano=fwrite(raspored, sizeof(raspored[0]), broj_casova, izlaz);
	if(ferror(izlaz))
	{
		printf("\nGreska u pisanju u izlaznu datoteku.\n");
		printf("U izlaznu datoteku zapisano samo %d casova.\n", zapisano);
		fclose(izlaz);
		return 2;
	}
	if(zapisano<broj_casova)
	{
		printf("\nU izlaznu datoteku nisu upisani svi casovi.\n");
		fclose(izlaz);
		return 0;
	}
	fclose(izlaz);
	
	return 1;
}

int ucitaj_datoteku(struct Cas raspored[])
{
	int ucitano=0;
	FILE* ulaz=fopen("raspored.dat", "rb");
	if(ulaz==NULL) return ucitano;
	else
	{
		ucitano=fread(raspored, sizeof(raspored[0]), KAPACITET, ulaz);
		if(ferror(ulaz))
		{
			printf("\nGreska u citanju ulazne datoteke.\n");
			printf("Iz ulazne datoteke ucitano samo %d casova.\n", ucitano);
			fclose(ulaz);
			return -1;
		}
	}
	if(ucitano==0) printf("\nIz ulazne datoteke ucitano 0 casova.\n");
	fclose(ulaz);
	return ucitano;
}

void meni(struct Cas raspored[], int broj_casova)
{
	int opcija=0;
	do
	{
		printf("\n1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &opcija);
		switch(opcija)
		{
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 0: if(zapisi_datoteku(raspored, broj_casova))
						printf("\nZapisivanje rasporeda u izlaznu datoteku nije uspjesno.\n");
					break;
			default: printf("Nepoznata opcija.\n");
		}
	} while(opcija!=0);
}

int main() 
{
	int broj_casova=0;
	struct Cas raspored[100*KAPACITET]={{{""}, 0, {0, 0 ,0}, {0,0,0}}};
	
	broj_casova=ucitaj_datoteku(raspored);
	if(broj_casova<0) return -1;
	
	meni(raspored, broj_casova);
	
	return 0;
}
