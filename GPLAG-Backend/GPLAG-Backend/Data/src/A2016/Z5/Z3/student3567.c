#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KAPACITET 200

void unesi(char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i<velicina-1 && znak != '\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

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

int ucitaj_datoteku(struct Cas raspored[])
{
	struct Cas cas;
	FILE* dat = fopen("raspored.dat", "rb");
	if(dat == NULL)
	{
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int ucitano = fread(raspored, sizeof(cas), KAPACITET, dat);
	fclose(dat);
	
	return ucitano;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
	int z = 0;
	struct Cas cas;
	FILE* dat = fopen("raspored.dat", "wb");
	if(dat == NULL)
	{
		printf("Greska pri otvaranju datoteke.\n");
		exit(1);
	}
	int zapisano = fwrite(raspored, sizeof(cas), broj_casova, dat);
	if(ferror(dat))
	{
		printf("Greska prilikom pisanja u datoteke.\n");
		printf("Zapisano je samo %d casova.\n", zapisano);
	}
	fclose(dat);
	
	if(zapisano == broj_casova)
		z = 1;
	
	return z;
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje)
{	
	int temp[60] = { 0 }; // 10casova max na dan * 6 dana
	int i, index, tr = 0, j = 0, dodano = 0;
	
	for(i = 0; i < broj_casova; i++)
	{
		index = (raspored[i].dan_u_sedmici - 1) * 10 + (raspored[i].pocetak.sati - 9);
		tr = raspored[i].kraj.sati - raspored[i].pocetak.sati;
		if(((raspored[i].kraj.sati - raspored[i].pocetak.sati) * 10 + raspored[i].kraj.minute) % 10 != 0)
			tr++;
		
		for(j = index; j < index + tr; j++)
		{
			temp[j] = 1;
		}
	}
	
	j = 0;
	index = -1;
	for(i = 0; i < 60; i++)
	{
		if(temp[i] == 0)
		{
			j++;
			if(i % 10 == 0)
			{
				index = i;
				j = 1;
			}
			if(index == -1)
				index = i;
			if(j == trajanje)
			{
				dodano = 1;
				break;
			}
		}
		else
		{
			j = 0;
			index = -1;
		}
	}
	
	if(dodano == 1)
	{
		strcpy(raspored[broj_casova].predmet, predmet);
		raspored[broj_casova].dan_u_sedmici = index / 10 + 1;
		raspored[broj_casova].pocetak.sati = index % 10 + 9;
		raspored[broj_casova].pocetak.minute = 0;
		raspored[broj_casova].pocetak.sekunde = 0;
		raspored[broj_casova].kraj.sati = raspored[broj_casova].pocetak.sati + trajanje;
		raspored[broj_casova].kraj.minute = 0;
		raspored[broj_casova].kraj.sekunde = 0;
	}
	
	
	return dodano;
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas)
{
	int p = 0, i;
	
	for(i = 0; i < broj_casova; i++)
	{
		if(raspored[i].dan_u_sedmici == cas.dan_u_sedmici)
		{
			if(raspored[i].kraj.sati > cas.pocetak.sati && raspored[i].pocetak.sati != cas.pocetak.sati && cas.pocetak.sati != 0)
				p = 1;
			else if(raspored[i].kraj.sati > cas.pocetak.sati && raspored[i].pocetak.sati == cas.pocetak.sati &&
					raspored[i].pocetak.minute > cas.pocetak.minute && cas.pocetak.sati != 0)
				p = 1;
			else if(raspored[i].kraj.sati == cas.pocetak.sati && raspored[i].kraj.minute > cas.pocetak.minute)
				p = 1;
		}
	}
	return p;

	/*for(i = 0; i < broj_casova; i++)
	{
		if(raspored[i].dan_u_sedmici == cas.dan_u_sedmici)
		{
			int kraj_i = raspored[i].kraj.sati + (raspored[i].kraj.minute > 0 ? 1 : 0);
			int kraj_c = cas.kraj.sati + (cas.kraj.minute > 0 ? 1 : 0);
			
			if((kraj_c > raspored[i].pocetak.sati && cas.pocetak.sati < kraj_i) ||
			   (kraj_i > cas.pocetak.sati && raspored[i].pocetak.sati < kraj_c))
			{
				p = 1;
				break;
			}
		}
	}*/
	
	return p;
}

// void ispis_rasporeda(struct Cas raspored[], int broj_casova)
// {
//  	char *dani[] = { "", "PON", "UTO", "SRI", "CET", "PET", "SUB" };
//  	int i;
 	
//  	for(i = 0; i < 7; i++)
//  	{
//  		if(i == 0)
//  			printf("%-6s", dani[i]);
//  		else
//  			printf("%-9s", dani[i]);
//  	}
//  	printf("\n");
// }

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)
{
	int i, j = 1;
	printf("Uneseni su casovi: \n");
	for(i = 0; i < broj_casova; i++)
	{
		if(raspored[i].dan_u_sedmici == dan)
		{
			printf("%d) %s (%02d:%02d-%02d:%02d)\n", j++, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
		}
	}
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena)
{
	int indexi[10] = { 0 };
	
	int i, brCasova = 0;
	
	for(i = 0; i < broj_casova; i++)
	{
		if(raspored[i].dan_u_sedmici == dan)
		{
			indexi[brCasova] = i;
			brCasova++;
		}
	}
	
	raspored[indexi[redni_broj - 1]] = promjena;
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj)
{
	int indexi[10] = { 0 }, i, brCasova = 0;
	
	for(i = 0; i < broj_casova; i++)
	{
		if(raspored[i].dan_u_sedmici == dan)
		{
			indexi[brCasova] = i;
			brCasova++;
		}
	}
	
	for(i = indexi[redni_broj - 1]; i < brCasova - 1; i++)
		raspored[i] = raspored[i + 1];
}

int brojCasovaTogDana(struct Cas raspored[], int broj_casova, int dan)
{
	int i, brCasova = 0;
	
	for(i = 0; i < broj_casova; i++)
	{
		if(raspored[i].dan_u_sedmici == dan)
		{
			brCasova++;
		}
	}
	
	return brCasova;
}

int main() 
{
	struct Cas raspored[KAPACITET], cas;
    char imePredmeta[10], test[100];
    int opcija, brojRegistrovanihCasova = 0, trajanjeCasa = 0, dan = 0, promjenaCasa = 0;
    struct Vrijeme p, k;
    for(;;)
    {
        printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
        scanf("%d", &opcija);
        if(opcija == 0)
        {
        	zapisi_datoteku(raspored, brojRegistrovanihCasova);
        	break;
        }
        // else if(opcija == 1)
        // {
        // 	ispis_rasporeda(raspored, brojRegistrovanihCasova);
        // }
        else if(opcija == 2)
        {
            printf("Unesite naziv predmeta: ");
            unesi(test, 100);
            strncpy(imePredmeta, test, 9);
            imePredmeta[9] = '\0';
            printf("Unesite broj casova: ");
            scanf("%d", &trajanjeCasa);
            if(dodaj_cas(raspored, brojRegistrovanihCasova++, imePredmeta, trajanjeCasa) == 0)
                printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", trajanjeCasa);
        }
        else if(opcija == 3)
        {
            for(;;)
            {
                printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
                scanf("%d", &dan);
                ispisi_dan(raspored, brojRegistrovanihCasova, dan);
                printf("Izaberite koji cas zelite promijeniti: ");
                scanf("%d", &promjenaCasa);
                int a = brojCasovaTogDana(raspored, brojRegistrovanihCasova, dan);
                if(promjenaCasa > a)
                	printf("Neispravan redni broj casa.\n");
                else
                {
                	printf("Naziv predmeta: ");
             		unesi(test, 100);
            		strncpy(imePredmeta, test, 9);
            		imePredmeta[9] = '\0';
                	printf("Vrijeme pocetka: ");
                	scanf("%d:%d", &p.sati, &p.minute);
                	p.sekunde = 0;
                	printf("Vrijeme zavrsetka: ");
                	scanf("%d:%d", &k.sati, &k.minute);
                	k.sekunde = 0;
                	strcpy(cas.predmet, imePredmeta);
                	cas.dan_u_sedmici = dan;
                	cas.pocetak = p;
                	cas.kraj = k;
                	
                	if(preklapanje(raspored, brojRegistrovanihCasova, cas) == 0)
                	{
                    	promijeni_cas(raspored, brojRegistrovanihCasova, dan, promjenaCasa, cas);
                    	break;
                	}
					else
                    	printf("Promjena nije moguca jer dovodi do preklapanja\n");
                }
            }
        }
        else if(opcija == 4)
        {
            printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
            scanf("%d", &dan);
            ispisi_dan(raspored, brojRegistrovanihCasova, dan);
            printf("Izaberite koji cas zelite obrisati: ");
            scanf("%d", &promjenaCasa);
            obrisi_cas(raspored, brojRegistrovanihCasova, dan, promjenaCasa);
            brojRegistrovanihCasova--;
            printf("Cas obrisan\n");
        }
    }
	
	return 0;
}
