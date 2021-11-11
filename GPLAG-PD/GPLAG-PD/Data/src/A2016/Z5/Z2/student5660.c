#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int slovo(char slovo)
{
	if ((slovo >= 'a' && slovo <= 'z') || (slovo >= 'A' && slovo <= 'Z'))
		return 1;
	return 0;
}

void unesi(char ime[])
{
    int i = 0;
    char a = getchar();
    if (a == '\n') a = getchar();
    while (i < 1000 && a != '\n')
    {
        ime[i++] = a;
        a = getchar();
    }
    ime[i] = '\0';
}

int srediRjecnik(char* datoteka, char rjecnik[1000][10], int* brojaci)
{
    int znak, i, j, ukupnoRijeci = 0;
    char rijec[10];
    long pos;

    FILE* ulaz = fopen (datoteka, "r+");
	if (ulaz == NULL)
	{
		printf ("Greska pri otvaranju datoteke za citanje.\n");
		return 1;
	}

    while (!feof(ulaz))
    {
        znak = fgetc(ulaz);
        
        if (slovo(znak))
        {
            i = 0;
            do
            {
                rijec[i++] = znak;
                if (i == 10) break;
                znak = fgetc(ulaz);
            }while (slovo(znak));
            
            if (1 < i && i < 10)
            {
                rijec[i] = '\0';
                for (i = 0; i < ukupnoRijeci; i++)
                {
                    if (strcmp(rjecnik[i], rijec) == 0)
                    {
                        brojaci[i]++;
                        break;
                    }
                }
                if (i == ukupnoRijeci)
                {
                    strcpy (rjecnik[i], rijec);
                    ++brojaci[ukupnoRijeci++];
                }
            }
            else
            {
                while (slovo (znak))
                {
                    znak = fgetc (ulaz);
                }
            }
            
        }
        else
        {
            while (!slovo(znak))
    			{
    			    if (znak == EOF){ znak = 0; break;}
    				pos = ftell(ulaz);
    				znak = fgetc(ulaz);
    			}
    			if (znak == 0) break;
    			fseek(ulaz, pos, SEEK_SET);
        }
    }
    fclose(ulaz);
    for (i = 0; i < ukupnoRijeci-1; i++)
        for (j = i + 1; j < ukupnoRijeci; j++)
        {
            if (brojaci[i] < brojaci[j])
            {
                znak = brojaci[i];
                strcpy(rijec, rjecnik[i]);
                brojaci[i] = brojaci[j];
                strcpy(rjecnik[i], rjecnik[j]);
                brojaci[j] = znak;
                strcpy(rjecnik[j], rijec);
            }
            else if (brojaci[i] == brojaci[j])
            if (strcmp(rjecnik[i], rjecnik[j]) > 0)
            {
                strcpy(rijec, rjecnik[i]);
                strcpy(rjecnik[i], rjecnik[j]);
                strcpy(rjecnik[j], rijec);
            }
        }
    return ukupnoRijeci;
}

void kompresuj (char* imeUlazne, char* imeIzlazne)
{
    char rjecnik[1000][10], rijec[10];
    int brojaci[1000] = {0}, i = 0, znak, ukupnoRijeci;
    long pos, pos2;
    FILE* ulaz = fopen (imeUlazne, "r+");
    if (!ulaz)
    {
        printf ("Otvaranje ulazne datoteke nije uspjelo.\n"); return;
    }
    FILE* izlaz = fopen (imeIzlazne, "w");
    if (!izlaz)
    {
        fclose(ulaz);
        printf ("Otvaranje izlazne datoteke nije uspjelo.\n"); return;
    }
    
    ukupnoRijeci = srediRjecnik(imeUlazne, rjecnik, brojaci);

    if (ukupnoRijeci > 10) 
    ukupnoRijeci = 10;
    
    while (i < ukupnoRijeci)
    {
        fputs(rjecnik[i], izlaz);
        fputs("\n", izlaz);
        i++;
    }
    if (i < 10)
        fputs("\n", izlaz);
        
    while (!feof(ulaz))
    {
        pos = ftell(ulaz);
        pos2 = pos;
        znak = fgetc(ulaz);
        if (znak == EOF) break;
        
        if (slovo(znak))
        {
            i = 0;
            do
            {
                if (i == 10) break;
                rijec[i++] = znak;
                pos = ftell(ulaz);
                znak = fgetc(ulaz);
            }while (slovo(znak));
            fseek(ulaz, pos, SEEK_SET);
            
            if (1 < i && i < 10)
            {
                rijec[i] = '\0';
                /* Ako rijec ima dovoljan broj slova 1 < brSlova < 10, prodje kroz rjecnik najcescih
                i ako je u rjecniku stavi znak koji treba da stavi*/
                for (i = 0; i < ukupnoRijeci; i++)
                {
                    char trenutna[10];
                    strcpy(trenutna, rjecnik[i]);
                    if (strcmp(trenutna, rijec) == 0)
                    {
                        fputc((char)(20 + i), izlaz);
                        break;
                    }
                }
                /* Ako i dodje do kraja to znaci da ona nije u prvih top10 najcescih i
                treba da je upise u datoteku onakvu kakva jeste bez zamjene sa drugim znakom.*/
                if(i == ukupnoRijeci)
                {
                    fseek(ulaz, pos, SEEK_SET);
                    znak = fgetc(ulaz);
                    do
                    {
                        pos = ftell(ulaz);
                        fputc(znak, izlaz);
                        znak = fgetc(ulaz);
                    }while (slovo(znak));
                    fseek(ulaz, pos, SEEK_SET);
                }
            }
            else
            {
                fseek(ulaz, pos2, SEEK_SET);
                znak = fgetc(ulaz);
                do
                {
                    pos = ftell(ulaz);
                    fputc(znak, izlaz);
                    znak = fgetc(ulaz);
                }while (slovo(znak));
                fseek(ulaz, pos, SEEK_SET);
            }
        }
        else
        {
            do
            {
                if (znak == EOF) break;
                pos = ftell(ulaz);
                fputc(znak, izlaz);
                znak = fgetc(ulaz);
            }while(!slovo(znak));
            fseek(ulaz, pos, SEEK_SET);
        }
    }
    printf ("Datoteka kompresovana.\n");
    fclose(ulaz);
    fclose(izlaz);
}

void dekompresuj (char* imeUlazne, char* imeIzlazne)
{
    char rjecnik[10][10];
    int i = 0, brRijeci = 0, znak;
    char trenutna[10];

    FILE* ulaz = fopen(imeUlazne, "r+");
    if (!ulaz)
    {
        printf ("Otvaranje ulazne datoteke nije uspjelo.\n");
        return;
    }
    FILE* izlaz = fopen(imeIzlazne, "w");
    if (!izlaz)
    {
        printf ("Otvaranje ulazne datoteke nije uspjelo.\n");
        fclose(ulaz);
        return;
    }

    while (!feof(ulaz))
    {
        i = 0;
        do
        {
            znak =fgetc(ulaz);
            trenutna[i++] = znak;
        }while (znak != '\n');
        trenutna[i-1] = '\0';
        strcpy (rjecnik[brRijeci++], trenutna);
        znak = fgetc(ulaz);
        if (znak == '\n') break;
        if (brRijeci == 10) { ungetc(znak, ulaz); break;}
        ungetc(znak, ulaz);
    }

    do
    {
        znak = fgetc(ulaz);
        if (znak == EOF) break;
        i = (int)znak - 20;
        if(i < brRijeci)
            fputs(rjecnik[i], izlaz);
        else
            fputc(znak, izlaz);
    }while (!feof(ulaz));

    printf ("Datoteka dekompresovana.\n");
    fclose(ulaz);
    fclose(izlaz);
}

int main()
{
    int n;
    char ulazna[1000], izlazna[1000];
	do
    {
        printf ("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
            {
                printf ("Unesite ime ulazne datoteke: ");
                unesi(ulazna);
                printf ("Unesite ime izlazne datoteke: ");
                unesi(izlazna);
                kompresuj(ulazna,izlazna);
                break;
            }
            case 2:
            {
                printf ("Unesite ime ulazne datoteke: ");
                unesi(ulazna);
                printf ("Unesite ime izlazne datoteke: ");
                unesi(izlazna);
                /*dekompresuj (ulazna, izlazna); */
                printf ("Datoteka dekompresovana.\n");
                break;
            }
            case 0 : break;
       }
    }while (n != 0);

    return 0;
}
