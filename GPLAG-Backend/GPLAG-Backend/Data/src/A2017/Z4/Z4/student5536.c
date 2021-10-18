#include <stdio.h>
//nema ne radi 

void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

int Slovo_broj(char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>=48 && c<=58))
		return 1;
	return 0;	
}

int provjeri(char *s)
{
	int zatvoren=1;
	char *p, *q, *poc;
	
	while(*s==' ')
		s++;
	while(*s!='\0')
	{
		if (*s=='<' && Slovo_broj(*(s+1)))
		{
			p=s;
			p++;
			while(Slovo_broj(*p))
				p++;
			p=s;
			p--;
		}
		
		s++;
	}
}

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}








/*#include <stdio.h>
#include <stdlib.h>
struct Beba
{
    char Ime[15] ;
    char Prezime[15] ;
    float prosjek;
};
struct Beba * sort_po_prosjeku(struct Beba niz[], int vel)
{
    int i,j;
    for (i = 0 ; i < ( vel - 1 ); i++)
    {
        for (j = 0 ; j < vel - i - 1; j++)
        {
            if (niz[i].prosjek > niz[i+1].prosjek)
            {
                struct Beba temp = niz[i];
                niz[i] = niz[j+1];
                niz[j+1] = temp;
            }
        }
    }
    return niz;
};
struct Beba * sort_po_prezimenu(struct Beba niz[], int vel)
{
    int i, j;
    char *p, *s;
    for(i=0; i<vel; i++)
    {
        for(j=i; j<vel; j++)
        {
            p=niz[i].Prezime;
            s=niz[j].Ime;
            if(*p > *s)
            {
                struct Beba temp=niz[i];
                niz[i]=niz[j];
                niz[j]=temp;
            }
        }
    }
};
float zajednicki_prosjek(struct Beba niz[], int vel)
{
    float prosjek=0;
    int i;
    for(i=0; i<vel; i++)
        prosjek+=niz[i].prosjek;
    return prosjek/vel;
}
void dodaj_clan(char ime[], char prezime[], float prosjek)
{
    FILE* izlaz;
    izlaz=fopen("datoteka.txt", "a");
    fprintf(izlaz, "%s %s %.1f\n", ime, prezime, prosjek);
}
void izbrisi_bebu(char ime[], struct Beba niz[],int vel)
{
    FILE* izlaz;
    int i;
    izlaz=fopen("datoteka.txt", "w");
    for(i=0; i<vel; i++)
    {
        if(niz[i].Ime==ime)
        {
            i++;
            vel--;
        }
        else
            fprintf(izlaz, "%s %s %.1f\n", niz[i].Ime, niz[i].Prezime, niz[i].prosjek);
    }
}
int main()
{
    FILE* ulaz;
    ulaz=fopen("datoteka.txt", "r");
    if(ulaz==NULL)
    {
        printf("Neuspjesno otvarannje datoteke");
        exit(1);
    }
    char znak;
    int vel=0, i;
    float prosjek;
    struct Beba niz_beba[10];
    struct Beba *p=niz_beba;
    while(fscanf(ulaz, "%s%c%s%c%f\n", &niz_beba[vel].Ime, &znak, &niz_beba[vel].Prezime, &znak,&niz_beba[vel++].prosjek)!=EOF);
    sort_po_prosjeku(niz_beba,vel);
    sort_po_prezimenu(niz_beba, vel);
    prosjek=zajednicki_prosjek(niz_beba, vel);
    dodaj_clan("Nova", "Beba", 8.3);
    izbrisi_bebu("Nova", niz_beba, vel);
}*/