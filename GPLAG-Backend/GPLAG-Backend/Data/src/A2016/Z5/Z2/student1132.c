#include <stdio.h>
#include <ctype.h>
#include <string.h>
void unesi(char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n')
    {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
/* Funkcija kompresuje datoteku mijenjajuci deset najcescih rijeci sa specijalnim znakovima*/
void kompresuj(char *ul,char *iz)
{
	int i,j,k,N = 0,ima,cnt[1001]={0},tmp;
	FILE* ulaz = fopen(ul,"r"), *izlaz = fopen(iz,"w");
	int aux=0;
	char pom[11],mat[1001][11];
	for(i=0;i<10;i++) for(j=0;j<11;j++) mat[i][j] = 126;
	while(aux != EOF)
	{
		aux = fgetc(ulaz);
		if(!isalpha(aux)) continue;
		else
		{
			k = 0;
			while(isalpha(aux) && k<9 )
			{
				pom[k] = aux;
				k++;
				aux = fgetc(ulaz);
			}
			if(isalpha(aux) || k==1)
			{
				while(isalpha(aux))
				{
					aux =  fgetc(ulaz);
				}
			}
			else
			{
				pom[k] = 0;
				ima = 0;
				for(i=0;i<N;i++)
				{
					if(strcmp(mat[i],pom)==0)
					{
						ima = 1;
						cnt[i]++;
						break;
					}
				}
				if(ima == 0)
				{
					strcpy(mat[N++],pom);
					cnt[N-1] = 1;
				}
			}
		}

	}
	fseek(ulaz,0,SEEK_SET);
	for(i=0; i<N;i++)
	{
		for(j=i;j>0;j--)
		{
			if(cnt[j] > cnt[j-1] || (cnt[j]==cnt[j-1] && strcmp(mat[j],mat[j-1]) < 0))
			{
				strcpy(pom,mat[j-1]);
				strcpy(mat[j-1],mat[j]);
				strcpy(mat[j],pom);
				tmp = cnt[j-1];
				cnt[j-1] = cnt[j];
				cnt[j] = tmp;
			}
			else break;
		}
	}

	if(N>10) N = 10;
	for(i=0;i<N;i++) fprintf(izlaz,"%s\n",mat[i]);
	if(N!=10) fprintf(izlaz,"\n");
    aux = 0;
	while(aux != EOF)
	{
		aux = fgetc(ulaz);
		if(!isalpha(aux))
		{
			fputc(aux,izlaz);
		}
		else
		{
			k = 0;
			while(isalpha(aux) && k<9 )
			{
				pom[k] = aux;
				k++;
				aux = fgetc(ulaz);
			}
			if(isalpha(aux))
			{
				for(i=0;i<k;i++) fputc(pom[i],izlaz);
				fputc(aux,izlaz);
				while(isalpha(aux))
				{
					aux =  fgetc(ulaz);
					fputc(aux,izlaz);
				}
			}
			else
			{
			    pom[k]=0;
				ima = 0;
				for(i=0;i<N;i++)
				{
					if(strcmp(mat[i],pom)==0)
					{
						ima = 1;
						fputc(i+20,izlaz);
						break;
					}
				}
				if(ima == 0)
				{
					for(i=0;pom[i]!=0;i++) fputc(pom[i],izlaz);
				}
				fputc(aux,izlaz);
			}
		}

	}
	printf("Datoteka kompresovana.\n");
	fclose(ulaz);
	fclose(izlaz);
}

/* Funkcija dekompresuje datoteku kompresovanu funkcijom "kompresuj"*/
void dekompresuj(char *ul,char *iz)
{
	int i,j,aux,k,N = 0,ima,cnt[1001]={0},tmp;
	FILE* ulaz = fopen(ul,"r"), *izlaz = fopen(iz,"w");
	char mat[11][11];
	for(i=0;i<10;i++)
	{
		aux = fgetc(ulaz);
		if(aux=='\n') break;
		mat[i][0] = aux;
		for(j=1;;j++)
		{
			aux = fgetc(ulaz);
			if(aux=='\n') break;
			mat[i][j] = aux;
		}
		mat[i][j] = 0;
	}
	while(aux!=EOF)
	{
		aux = fgetc(ulaz);
		if(19<aux && aux<30)
		{
			fprintf(izlaz,"%s",mat[aux-20]);
		}
		else fputc(aux,izlaz);
	}
	printf("Datoteka dekompresovana.\n");
	fclose(ulaz);
	fclose(izlaz);
}

int main()
{
	int k;
	char a[1000],b[1000];
	while(1)
	{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d",&k);
		if(k==0) break;
		else if(k==1)
		{
			printf("Unesite ime ulazne datoteke: Unesite ime izlazne datoteke: ");
			unesi(a,1000);
			unesi(b,1000);
			kompresuj(a,b);
		}
		else if(k==2)
		{
			printf("Unesite ime ulazne datoteke: Unesite ime izlazne datoteke: ");
			unesi(a,1000);
			unesi(b,1000);
			dekompresuj(a,b);
		}
	}
	return 0;
}
