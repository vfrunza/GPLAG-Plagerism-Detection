#include <stdio.h>
#include <string.h>

struct Par
{
    char rijec[10];
    int broj_ponavljanja;
};

void top_deset(struct Par* niz, int vel)
{
    int i = 0;
    int j = 0;
    int pozicija_najveceg = 0;
    int max_broj_ponavljanja = 0;
    for(j = 0; j < 10 && j < vel; j++)
    {
        for(i = j; i < vel; i++)
        {
            if(niz[i].broj_ponavljanja > max_broj_ponavljanja)
            {
                max_broj_ponavljanja = niz[i].broj_ponavljanja;
                pozicija_najveceg = i;
            }
        }
        struct Par temp = niz[pozicija_najveceg];
        niz[pozicija_najveceg] = niz[j];
        niz[j] = temp;
    }
}

int kompresuj(char* naziv_ulaza, char* naziv_izlaza)
{
    FILE* ulaz = fopen(naziv_ulaza,"r");

    if(ulaz == NULL)
    {
        printf("Otvaranje ulazne datoteke nije uspjelo");
        return 1;
    }

    struct Par sve_rijeci[1000];
    int broj_svih_rijeci = 0;
    char rijec_koja_se_cita[25];
    int i = 0;
    int j = 0;
    for(i = 0; i < 1000; i++)
    {
        sve_rijeci->broj_ponavljanja = 0;
    }

    i = 0;
    do
    {
        rijec_koja_se_cita[i] = fgetc(ulaz);
        if(rijec_koja_se_cita[i] == ' ')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < broj_svih_rijeci; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    sve_rijeci[j].broj_ponavljanja++;
                    postoji = 1;
                    break;
                }
            }
            if(postoji == 0 && strlen(rijec_koja_se_cita) > 1 && strlen(rijec_koja_se_cita) < 10)
            {
                strcpy(sve_rijeci[broj_svih_rijeci].rijec, rijec_koja_se_cita);
                sve_rijeci[broj_svih_rijeci].broj_ponavljanja++;
                broj_svih_rijeci++;
            }
            i = 0;
        } else if(rijec_koja_se_cita[i] == ',')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < broj_svih_rijeci; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    sve_rijeci[j].broj_ponavljanja++;
                    postoji = 1;
                    break;
                }
            }
            if(postoji == 0 && strlen(rijec_koja_se_cita) > 1 && strlen(rijec_koja_se_cita) < 10)
            {
                strcpy(sve_rijeci[broj_svih_rijeci].rijec, rijec_koja_se_cita);
                sve_rijeci[broj_svih_rijeci].broj_ponavljanja++;
                broj_svih_rijeci++;
            }
            i = 0;
            fgetc(ulaz);
        } else if(rijec_koja_se_cita[i] == '.')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < broj_svih_rijeci; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    sve_rijeci[j].broj_ponavljanja++;
                    postoji = 1;
                    break;
                }
            }
            if(postoji == 0 && strlen(rijec_koja_se_cita) > 1 && strlen(rijec_koja_se_cita) < 10)
            {
                strcpy(sve_rijeci[broj_svih_rijeci].rijec, rijec_koja_se_cita);
                sve_rijeci[broj_svih_rijeci].broj_ponavljanja++;
                broj_svih_rijeci++;
            }
            i = 0;
            fgetc(ulaz);
        } else if(rijec_koja_se_cita[i] == '\n')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < broj_svih_rijeci; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    sve_rijeci[j].broj_ponavljanja++;
                    postoji = 1;
                    break;
                }
            }
            if(postoji == 0 && strlen(rijec_koja_se_cita) > 1 && strlen(rijec_koja_se_cita) < 10)
            {
                strcpy(sve_rijeci[broj_svih_rijeci].rijec, rijec_koja_se_cita);
                sve_rijeci[broj_svih_rijeci].broj_ponavljanja++;
                broj_svih_rijeci++;
            }
            i = 0;
        } else
        {
            i++;
        }
    } while(!feof(ulaz));

    top_deset(sve_rijeci,broj_svih_rijeci);

    FILE* izlaz = fopen(naziv_izlaza,"w");

    if(izlaz == NULL)
    {
        printf("Otvaranje izlazne datoteke nije uspjelo!");
        return 2;
    }

    for(i = 0; i < 10 && i < broj_svih_rijeci; i++)
    {
        fprintf(izlaz,"%s %c\n",sve_rijeci[i].rijec,20+i);
    }
    if(broj_svih_rijeci < 10)
    {
        fputc('\n',izlaz);
    }
    fseek(ulaz, 0, SEEK_SET);

    i = 0;

    do
    {
        rijec_koja_se_cita[i] = fgetc(ulaz);
        if(rijec_koja_se_cita[i] == ' ')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < 10; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    fputc(20+j,izlaz);
                    postoji = 1;
                }
            }
            if(postoji == 0)
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            i = 0;
            fputc(' ',izlaz);
        } else if(rijec_koja_se_cita[i] == ',')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < 10; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    fputc(20+j,izlaz);
                    postoji = 1;
                }
            }
            if(postoji == 0)
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            i = 0;
            fputc(',',izlaz);
            fputc(' ',izlaz);
            fgetc(ulaz);
        } else if(rijec_koja_se_cita[i] == '.')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < 10; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    fputc(20+j,izlaz);
                    postoji = 1;
                }
            }
            if(postoji == 0)
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            i = 0;
            fputc('.',izlaz);
            fputc(' ',izlaz);
            fgetc(ulaz);
        } else if(rijec_koja_se_cita[i] == '\n')
        {
            rijec_koja_se_cita[i] = '\0';
            int postoji = 0;
            for(j = 0; j < 10; j++)
            {
                if(strcmp(rijec_koja_se_cita,sve_rijeci[j].rijec) == 0)
                {
                    fputc(20+j,izlaz);
                    postoji = 1;
                }
            }
            if(postoji == 0)
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            i = 0;
            fputc('\n',izlaz);
        } else
        {
            i++;
        }
    } while(!feof(ulaz));

    return  0;
}

int dekompresuj(char* naziv_ulaza, char* naziv_izlaza)
{
    FILE* ulaz = fopen(naziv_ulaza,"r");

    if(ulaz == NULL)
    {
        printf("Otvaranje ulazne datoteke nije uspjelo");
        return 1;
    }

    FILE* izlaz = fopen(naziv_izlaza,"w");

    if(izlaz == NULL)
    {
        printf("Otvaranje izlazne datoteke nije uspjelo");
        return 2;
    }

    struct Par sve_rijeci[10];
    int i = 0;
    int broj_top_rijeci = 0;
    char rijec_koja_se_cita[25];
    char neki_znak;

    do
    {
        rijec_koja_se_cita[i] = fgetc(ulaz);
        if(rijec_koja_se_cita[i] == ' ')
        {
            rijec_koja_se_cita[i] = '\0';
            strcpy(sve_rijeci[broj_top_rijeci].rijec,rijec_koja_se_cita);
            broj_top_rijeci++;
            i = -1;
            fgetc(ulaz);
            fgetc(ulaz);
        }
        if(rijec_koja_se_cita[i] == '\n')
        {
            break;
        }
        i++;
    } while(!feof(ulaz));

    i = 0;

    do
    {
        rijec_koja_se_cita[i] = fgetc(ulaz);
        if(rijec_koja_se_cita[i] == ' ')
        {
            rijec_koja_se_cita[i] = '\0';

            if(rijec_koja_se_cita[i-1] >= 20 && rijec_koja_se_cita[i-1] <= 29)
            {
                fputs(sve_rijeci[rijec_koja_se_cita[i-1]-20].rijec,izlaz);
            } else
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            fputc(' ',izlaz);
            i = 0;
        } else if(rijec_koja_se_cita[i] == ',')
        {
            rijec_koja_se_cita[i] = '\0';

            if(rijec_koja_se_cita[i-1] >= 20 && rijec_koja_se_cita[i-1] <= 29)
            {
                fputs(sve_rijeci[rijec_koja_se_cita[i-1]-20].rijec,izlaz);
            } else
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            fputc(',',izlaz);
            fgetc(ulaz);
            fputc(' ',izlaz);
            i = 0;
        } else if(rijec_koja_se_cita[i] == '.')
        {
            rijec_koja_se_cita[i] = '\0';

            if(rijec_koja_se_cita[i-1] >= 20 && rijec_koja_se_cita[i-1] <= 29)
            {
                fputs(sve_rijeci[rijec_koja_se_cita[i-1]-20].rijec,izlaz);
            } else
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            fputc('.',izlaz);
            fgetc(ulaz);
            fputc(' ',izlaz);
            i = 0;
        } else if(rijec_koja_se_cita[i] == '\n')
        {
            rijec_koja_se_cita[i] = '\0';

            if(rijec_koja_se_cita[i-1] >= 20 && rijec_koja_se_cita[i-1] <= 29)
            {
                fputs(sve_rijeci[rijec_koja_se_cita[i-1]-20].rijec,izlaz);
            } else
            {
                fputs(rijec_koja_se_cita,izlaz);
            }
            fputc('\n',izlaz);
            i = 0;
        } else
        {
            i++;
        }
    } while(!feof(ulaz));

    return  0;
}

int main() {

    printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");

    int unos;
    char ulaz[50];
    char izlaz[50];
    scanf("%d",&unos);
    if(unos == 0)
    {
        return 0;
    }

    printf("Unesite naziv ulazne datoteke: ");
    scanf("%s",ulaz);
    printf("Unesite naziv izlazne datoteke: ");
    scanf("%s",izlaz);

    if(unos == 1)
    {
        kompresuj(ulaz,izlaz);
        printf("Datoteka kompresovana");
    } else if(unos == 2)
    {
        dekompresuj(ulaz,izlaz);
        printf("Datoteka dekompresovana");
    }

    return 0;
}
