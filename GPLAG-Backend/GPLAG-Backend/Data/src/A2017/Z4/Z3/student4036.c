#include <stdio.h>

/*unos stringa*/
void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	i=0;
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

int Slovo(char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return 1;
	return 0;	
}

void najduzi_bp(char *s1, char *s2)
{
	int duzina=1, max=0, isti=1;
	char *p, *q, *poc2,*upisuj, temp1, temp2;
	*s2='\0';
	while(*s1!='\0' && *s1==' ')
		s1++;
	while(*s1!='\0')
	{
		if (Slovo(*s1))
		{
			poc2=s2;
			duzina=1;
			if (Slovo(*(s1+1)))
			{
				p=s1;
				p++;
				duzina=1;
				while(Slovo(*p))
				{
					isti=0;
					temp1=*p;
					/*pretvaranje malog slova u veliko*/
					if (temp1>='a' && temp1<='z')
						temp1-='a'-'A';
					q=s1;
					/*provjeravanje da li se ponavljaju slova*/
					while(q<p)
					{
						temp2=*q;
						if (temp2>='a' && temp2<='z')
							temp2-='a'-'A';
						if(temp2==temp1)
						{
							if(duzina>max)
							{
								max=duzina;
								upisuj=s1;
								/*upisivanje u string*/
								while(upisuj<p)
								{
									*poc2=*upisuj;
									poc2++;
									upisuj++;
								}
								*poc2='\0';
							}
							isti=1;
							break;
						}
						q++;
					}
					if (isti==1)
						break;
					p++;
					duzina++;
				}
				if (duzina>max)
				{
					max=duzina;
					upisuj=s1;
					while(upisuj<p)
					{
						*poc2=*upisuj;
						poc2++;
						upisuj++;
					}
					*poc2='\0';
				}
			}
			/*slucaj kada je jedno slovo*/
			else 
			{
				duzina=1;
				if (duzina>max)
				{
					*poc2=*s1;
					poc2++;
					*poc2='\0';
				}
			}
		}
		s1++;
	}
}


int main() {
	char recenica[100], ubacuj[100];
	
	printf("Unesite recenicu: ");
	unesi(recenica,100);
	
	najduzi_bp(recenica, ubacuj);
	
	printf("%s",ubacuj);
	
	return 0;
}




/* struct beba 
#include <stdio.h>
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