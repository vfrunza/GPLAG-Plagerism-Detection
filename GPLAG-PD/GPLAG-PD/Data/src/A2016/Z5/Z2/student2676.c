#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void unesi(char niz[], int velicina) 
{
    int i=0;
    char znak = getchar();
    if(znak=='\n') znak=getchar();
    while(i<velicina-1 && znak!='\n') 
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

void kompresuj(char* udat, char* idat)
{
    char c, rijec[12], nizrijeci[1001][12], niz10[100][12];
    int i, j, k, brijeci=0, brputa[1001]={0}, maxindeks;
	FILE* ulaz=fopen(udat, "r");
	if(ulaz==NULL) exit(1);
	FILE* izlaz=fopen(idat, "w");
	if(izlaz==NULL) exit(1);
	c=fgetc(ulaz);
	while(!feof(ulaz))
	{
	    while(!feof(ulaz) && (c<'A' || (c>'Z' && c<'a') || c>'z')) c=fgetc(ulaz);
	    i=0;
	    
	    // Uzimamo rijec po rijec, uzimamo u obzir samo rijeci krace od 10 slova
	    
	    while(!feof(ulaz) && i<9 && ((c>='A' && c<='Z') || (c>='a' && c<='z')))
	    {
	        rijec[i]=c;
	        c=fgetc(ulaz);
	        i++;
	    }
	    if((c<'A' || (c>'Z' && c<'a') || c>'z') && i>1)
	    {
	        rijec[i]='\0';
	        for(j=0;j<brijeci;j++)
	        {
	            if(strcmp(*(nizrijeci+j), rijec)==0)
	            {
	                // Biljezimo koliko se puta svaka rijec ponavlja
	                brputa[j]++;
	                break;
	            }
	        }
	        if(j==brijeci)
	        {
	            // Dodajemo novu rijec u niz rijeci
	            for(k=0;rijec[k]!='\0';k++)
	            {
	                nizrijeci[brijeci][k]=rijec[k];
	            }
	            nizrijeci[brijeci][k]=rijec[k];
	            brputa[brijeci]++;
	            brijeci++;
	        }
	    } 
	    else
	    while(!feof(ulaz) && ((c>='A' && c<='Z') || (c>='a' && c<='z'))) c=fgetc(ulaz);
	}
	i=0;
	
	// Sada trazimo koje rijeci se najcesce pojavljuju
	
	while(i<10 && i<brijeci)
	{
	    maxindeks=0;
	    for(j=0;j<brijeci;j++)
	    {
	        if(brputa[j]>brputa[maxindeks]) maxindeks=j;
	        if(brputa[j]==brputa[maxindeks])
	        {
	            if(strcmp(*(nizrijeci+j), *(nizrijeci+maxindeks))<0) maxindeks=j;
	        }
	    }
	    j=0;
	    while(nizrijeci[maxindeks][j]!='\0')
	    {
	        niz10[i][j]=nizrijeci[maxindeks][j];
	        j++;
	    }
	    niz10[i][j]=nizrijeci[maxindeks][j];
	    brputa[maxindeks]=-1;
	    i++;
	}
	
	// Upisivanje tablice najcescih rijeci u izlaznu datoteku
	
	i=0;
	while(i<10 && i<brijeci)
	{
	    fprintf(izlaz, "%s\n", niz10[i]);
	    i++;
	}
	
	// Ako ih je manje od deset ide novi red
	if(brijeci<10) fprintf(izlaz, "\n");
	
	// Ponovo prolazimo kroz ulaznu datoteku i mijenjamo rijeci odgovarajucim ASCII znakovima
	
	fseek(ulaz, 0, SEEK_SET);
	c=fgetc(ulaz);
	while(!feof(ulaz))
	{
	    while(c<'A' || (c>'Z' && c<'a') || c>'z')
	    {
	        if(feof(ulaz)) break;
	        fprintf(izlaz, "%c", c);
	        c=fgetc(ulaz);
	    }
	    i=0;
	    while(!feof(ulaz) && ((c>='A' && c<='Z') || (c>='a' && c<='z')) && i<9)
	    {
	        rijec[i]=c;
	        c=fgetc(ulaz);
	        i++;
	    }
	    rijec[i]='\0';
	    if(i>1)
	    {
	        if(i<9 || (i==9 && (c<'A' || (c>'Z' && c<'a') || c>'z')))
	        {
	            j=0;
	            while(j<brijeci && j<10)
	            {
	                if(strcmp(rijec, niz10[j])==0)
	                {
	                    fprintf(izlaz,"%c", 20+j);
	                    break;
	                }
	                j++;
	            }
	            if(j==brijeci || j==10) fprintf(izlaz, "%s", rijec);
	        }
	    }
	    else
	    if(i==1) fprintf(izlaz, "%s", rijec);
	    else
	    {
	        fprintf(izlaz, "%s", rijec);
	        while((c>='A' && c<='Z') || (c>='a' && c<='z'))
	        {
	            if(feof(ulaz)) break;
	            fprintf(izlaz, "%c", c);
	            c=fgetc(ulaz);
	        }
	    }
	}
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka kompresovana.\n");
}



void dekompresuj(char* udat, char* idat)
{
    char niz10[12][12], c;
    int i, j;
    FILE* ulaz=fopen(udat, "r");
    if(ulaz==NULL) exit(1);
    FILE* izlaz=fopen(idat, "w");
    if(izlaz==NULL) exit(1);
    
    // Prvo ocitavamo tablicu
    
    c=fgetc(ulaz);
    for(i=0;i<10;i++)
    {
        if(c=='\n') 
        {
            c=fgetc(ulaz);
            break;
        }
        for(j=0;c!='\n';j++)
        {
            niz10[i][j]=c;
            c=fgetc(ulaz);
        }
        niz10[i][j]='\0';
        c=fgetc(ulaz);
    }
    
    // Upisujemo rijeci, odgovarajuce ASCII znakove zamijenjujemo rijecima iz tablice
    
    while(!feof(ulaz))
    {
        if(c>=20 && c<=29) fprintf(izlaz, "%s", niz10[c-20]);
        else fprintf(izlaz, "%c", c);
        c=fgetc(ulaz);
    }
    fclose(ulaz);
    fclose(izlaz);
    printf("Datoteka dekompresovana.\n");
}

int main() 
{
    char ulaz[1000], izlaz[1000];
    int biraj;
    do
    {
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf("%d", &biraj);
        if(biraj)
        {
            printf("Unesite ime ulazne datoteke: ");
            unesi(ulaz, 1000);
            printf("Unesite ime izlazne datoteke: ");
            unesi(izlaz, 1000);
        }
        if(biraj==1) kompresuj(ulaz, izlaz);
        if(biraj==2) dekompresuj(ulaz, izlaz);
    }while(biraj);
	return 0;
}
