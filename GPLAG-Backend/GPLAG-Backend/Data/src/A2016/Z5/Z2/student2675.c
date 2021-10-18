#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prepisi(char *prva,char* druga)
{
	while(*prva!='\0')
	{
		*druga=*prva;
		druga++;
		prva++;
	}
	*druga='\0';
}

void dekompresuj(char *upis,char* ispis)
{
    FILE *ulaz,*izlaz;
    char z[2000],c,rijeci[10][2000];
    int i,broj,t;
    if ((ulaz = fopen(upis,"r")) == NULL) {
        printf("Greska pri otvaranju datoteke %s ik",upis);
        exit(1);
    }
    broj=0;
    //ucitava rijeci koje su zamijenjene
    while ((c=fgetc(ulaz))!=EOF)
    {
        if(c=='\n') break;
        i=0;
        while(((c>='A'&&c<='Z')||(c>='a'&&c<='z'))&&i<10)
        {
            z[i]=c;
            c=fgetc(ulaz);
            i++;
        }
        z[i]='\0';
        prepisi(z,rijeci[broj]);
        broj++;
    }
    if ((izlaz = fopen(ispis,"w")) == NULL) {
        printf("Greska pri otvaranju datoteke %s id",ispis);
        exit(1);
    }
    while((c=fgetc(ulaz))!=EOF)
    {
        t=1;
        //ako naidje na karakter izmedju 20 i 29 mijenja ga sa odgovarajucom rijeci
        for(i=0;i<broj;i++)
        {
            if(c==i+20)
            {
                fprintf(izlaz,"%s",rijeci[i]);
                t=0;
            }
        }
        if(t) fprintf(izlaz,"%c",c);
    }
    fclose(ulaz);
    fclose(izlaz);
    printf("Datoteka dekompresovana.\n");
}

void kompresuj(char *upis,char* ispis)
{
	FILE *ulaz,*izlaz;
	char z[20],z2[20],rijeci[10][20]={{0}},c;
	int broj,ponavljanja[10]={0},i,j,t,k,loc;
	if ((ulaz = fopen(upis,"r")) == NULL) {
        printf("Greska pri otvaranju datoteke %s uk",upis);
        exit(1);
    }
    while ((c=fgetc(ulaz))!=EOF)
    {
        i=0;
        t=0;
        //ucita rijec
        while(((c>='A'&&c<='Z')||(c>='a'&&c<='z'))&&i<10)
        {
            z[i]=c;
            c=fgetc(ulaz);
            i++;
            t=1;
        }
        if(i>=10) continue;
        z[i]='\0';
    	broj=0;
    	//ako je ta rijec vec ucitana preskace je
        for(j=0;j<10;j++)
        {
        	if(strcmp(z,rijeci[j])==0)
        	{
        		t=0;
        		break;
        	}
        }
        if(t==0)
        {
        	continue;
        }
        loc=ftell(ulaz);
        fseek(ulaz,0,SEEK_SET);
        //broji koliko se puta ta rijec pojavljuje u teksstu
        while ((c=fgetc(ulaz))!=EOF)
        {
            i=0;
            t=0;
            while((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
            {
                z2[i]=c;
                c=fgetc(ulaz);
                i++;
                t=1;
            }
            z2[i]='\0';
        	if(strcmp(z,z2)==0 &&t)
        	{
        		broj++;
        	}
        }
        fseek(ulaz,loc,SEEK_SET);
        //gleda da li je ta rijec treba biti na listi i ako treba stavlja je 
        for(j=0;j<10;j++)
        {
        	if(broj>ponavljanja[j] ||(broj==ponavljanja[j]&&strcmp(z,rijeci[j])<0))
        	{
        		for(k=9;k>j;k--)
        		{
        			ponavljanja[k]=ponavljanja[k-1];
        			prepisi(rijeci[k-1],rijeci[k]);
        		}
        		ponavljanja[j]=broj;
        		prepisi(z,rijeci[j]);
        		break;
        	}
        }
    }
    fseek(ulaz, 0, SEEK_SET);
    if ((izlaz = fopen(ispis,"w")) == NULL) {
        printf("Greska pri otvaranju datoteke %s ik",ispis);
        exit(1);
    }
    //pise listu
   	for(i=0;i<10;i++)
   	{
   		if(ponavljanja[i]!=0)
   		{
   			fprintf(izlaz,"%s\n",rijeci[i]);
   		}
   		if(ponavljanja[i]==0)
   		{
   			fprintf(izlaz,"\n");
   			break;
   		}
   	}
   	while ((c=fgetc(ulaz))!=EOF)
    {
        i=0;
        t=0;
        while((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        {
            z[i]=c;
            c=fgetc(ulaz);
            i++;
            t=1;
        }
        z[i]='\0';
        //umijesto rijeci sa liste pise odgovarajuci karakter
   		for(i=0;i<10 &&t;i++)
   		{
   			if(strcmp(z,rijeci[i])==0)
   			{
   				fprintf(izlaz,"%c",i+20);
   				t=0;
   				break;
   			}
   		}
   		//ostale znakove prepisuje
   		if(t)
   		{
   			fprintf(izlaz,"%s",z);
   		}
   		if(c==EOF) break;
   		fprintf(izlaz,"%c",c);
   	}
    fclose(izlaz);
    fclose(ulaz);
    printf("Datoteka kompresovana.\n");
}

int main()
{
    int n;
    char upis[200],ispis[200];
    do
    {
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
	    scanf("%d",&n);
	    if(n==1)
	    {
	        printf("Unesite ime ulazne datoteke: ");
	        scanf("%s",upis);
	        printf("Unesite ime izlazne datoteke: ");
	        scanf("%s",ispis);
	        kompresuj(upis,ispis);
	    }
	    if(n==2)
	    {
	        printf("Unesite ime ulazne datoteke: ");
	        scanf("%s",upis);
	        printf("Unesite ime izlazne datoteke: ");
	        scanf("%s",ispis);
	        dekompresuj(upis,ispis);
	    }
    }while(n!=0);
	return 0;
}