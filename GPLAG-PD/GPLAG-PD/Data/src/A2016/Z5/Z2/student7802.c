#include <stdio.h>
#include <string.h>
void unesi(char niz[], int velicina)
{
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i = 0;
    while (i<velicina-1 && znak!='\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}
/*vraca 1 ako je znak slovo*/
int slovo(int c)
{
    if(c>='A' && c<='Z' || c>='a' && c<='z')
        return 1;
    return 0;
}
/*funkcija prima 2 stringa i zamijeni ih*/
void swap(char *p, char *q)
{
    char temp[100];
    strcpy(temp,p);
    strcpy(p,q);
    strcpy(q,temp);
}
void kompresuj(char* naziv,char* naziv1)
{
    FILE *ulaz=fopen(naziv,"r");
    FILE *ulaz1=fopen(naziv,"r");
    FILE *izlaz=fopen(naziv1,"w");
    char rijeci[1000][1000]={0};
    /*brojac za svaku rijec*/
    int brojac[1000]={0};
    int i, broj_rijeci=0;
    char rijec[1000];
    int duzina;
    char znak=fgetc(ulaz);
    /*dok ne dodjemo do kraja 
    datoteke uzimamo znak po znak*/
    while(znak!=EOF)
    {
        duzina=0;
        /*dok je znak slovo znaci da smo na rijeci
        pa uzmemo sva slova i ubacimo u trenutnu rijeci*/
        while(slovo(znak))
        {
            rijec[duzina++]=znak;
            znak=fgetc(ulaz);
        }
        rijec[duzina]='\0';
        if(duzina < 10 && duzina !=0)
        {
            int ima=0,j;
            /*prolazimo kroz rijeci koje smo do sada upisali*/
            for(j=0;j<broj_rijeci;j++)
            {
                /*ako se rijec vec nalazi tu 
                povecavamo broj ponavljanja*/
                if(strcmp(rijeci[j],rijec)==0)
                {
                    ima=1;
                    brojac[j]++;
                    break;
                }
            }
            /*ako je nema dodajemo je i 
            brojac postavljamo na 1*/
            if(ima!=1)
            {
                strcpy(rijeci[broj_rijeci],rijec);
                brojac[broj_rijeci++]=1;
            }
        }
        znak=fgetc(ulaz);
    }
    /*unijeli smo sve rijeci sada ih 
    sortiramo po broju ponavljanja i leksikografski*/
    int j;
    for(i=0;i<broj_rijeci;i++)
    {
        for(j=i+1;j<broj_rijeci;j++)
        {
            if(brojac[j]>brojac[i] || (brojac[j]==brojac[i] && strcmp(rijeci[i],rijeci[j])==1))
            {
                int temp=brojac[j];
                brojac[j]=brojac[i];
                brojac[i]=temp;
                swap(rijeci[i],rijeci[j]);
            }
        }
    }
    int kraj=10;
    char novired='\n';
    /*treba nam 10 rijeci ako ih 
    ima manje onda to koristim*/
    if(broj_rijeci<10)
        kraj=broj_rijeci;
    /*prvo unosimo u izlaz 
    rijeci koje su u nizu*/
    for(i=0;i<kraj;i++)
    {
        fputs(rijeci[i],izlaz);
        fputc(novired,izlaz);
    }
    char c=fgetc(ulaz1);
    while(c!=EOF)
    {
        duzina=0;
        /*uzimamo rijec po rijec*/
        while(slovo(c))
        {
            rijec[duzina++]=c;
            c=fgetc(ulaz1);
        }
        rijec[duzina]='\0';
        int kontrola=0;
        if(duzina<10 && duzina!=0)
        {
            for(j=0;j<kraj;j++)
            {   
                /*ako nalazi u nizu mijenjamo 
                odgovarajucim znakom*/
                if(strcmp(rijeci[j],rijec)==0)
                {
                    char znk=j+20;
                    kontrola=1;
                    fputc(znk,izlaz);
                    fputc(c,izlaz);
                    break;
                }
            }
        }
        if(kontrola==0)
        {
            char *r=rijec;
            while(*r!='\0')
            {
                fputc(*r,izlaz);
                r++;
            }
            fputc(c,izlaz);
        }
        c=fgetc(ulaz1);
    }
    printf("Datoteka kompresovana.\n");
    fclose(ulaz);
    fclose(ulaz1);
    fclose(izlaz);
}
void dekompresuj(char *naziv, char *naziv1)
{
    FILE *ulaz=fopen(naziv,"r");
    FILE *ulaz1=fopen(naziv,"r");
    FILE *izlaz=fopen(naziv1,"w");
    char rijeci[1000][1000]={0},rijec[1000];
    int broj_rijeci=0,duzina=0,brojackrajeva=0;
    char znak=fgetc(ulaz);
    int kontrola=0;
    while(znak!=EOF)
    {
        duzina=0;
        kontrola=0;
        while(slovo(znak))
        {
            rijec[duzina++]=znak;
            znak=fgetc(ulaz);
        }
        rijec[duzina]='\0';
        if(duzina<10 && duzina!=0)
        {
            strcpy(rijeci[broj_rijeci],rijec);
            int j;
            for(j=0;j<broj_rijeci;j++)
            {
                if(strcmp(rijeci[j],rijec)==0)
                {
                    kontrola=1;
                    break;
                }
            }
            if(kontrola)
                break;
            broj_rijeci++;
        }
        znak=fgetc(ulaz);
    }
    /*prebrojimo koliko ima rijeci*/
    brojackrajeva=0;
    char c=fgetc(ulaz1);
    while(c!=EOF)
    {
        /*brojimo nova mjesta*/
        if(c=='\n')
            brojackrajeva++;
        /*kad dodjemo do zadnje rijeci prekidamo*/
        if(brojackrajeva==broj_rijeci)
            break;
        c=fgetc(ulaz1);
    }
    c=fgetc(ulaz1);
        while(c!=EOF)
        {
            int n=0;
            /*sve znakove od 20 do 30 mijenjamo rijecima*/
            if(c>=20 && c<=30)
            {
                char *p=rijeci[c-20];
                n=1;
                /*ubacujemo rijec*/
                while(*p!='\0')
                {
                    fputc(*p,izlaz);
                    p++;
                }
            }
            /*ako nije znak prepisujem rijeci*/
            if(n==0)
                fputc(c,izlaz);
            c=fgetc(ulaz1);
        }
    printf("Datoteka dekompresovana.\n");
    fclose(ulaz);
    fclose(izlaz);
    fclose(ulaz1);
    
}
int main() {
    int opcija;
    char s[100], p[100];
    do
    {
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        scanf("%d",&opcija);
        switch(opcija)
        {
            /*unosim datoteke i vrsim kompresiju/dekompresiju*/
            case 1:
                printf("Unesite ime ulazne datoteke: ");
                unesi(s,40);
                printf("Unesite ime izlazne datoteke: ");
                unesi(p,40);
                kompresuj(s,p);
                break;
            case 2:
                printf("Unesite ime ulazne datoteke: ");
                unesi(s,40);
                printf("Unesite ime izlazne datoteke: ");
                unesi(p,40);
                dekompresuj(s,p);
        }
    }while(opcija!=0);
	return 0;
}
