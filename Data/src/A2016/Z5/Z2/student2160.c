#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void unesi(char niz[], int velicina)
{
	char znak = getchar();
	int i = 0;
	
	if(znak == '\n')
		znak = getchar();
		
	while(i < velicina - 1 && znak != '\n')
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	
	niz[i] = '\0';
}

int je_li_slovo(char e)
{
	if((e >= 'A' && e <= 'Z') || (e >= 'a' && e <= 'z'))
		return 1;
		
	return 0;
}

int ima_rijec(char mat[1000][10], int br_rijeci, char rijec[])
{
	int i = -1;
	
	for(i = 0; i < br_rijeci; i++)
	{
		if(strcmp(mat[i], rijec) == 0)
			return i;
	}
	
	return -1;
}

void zamijeni_rijeci(char rijec1[], char rijec2[])
{
	char temp[10];
	
	strcpy(temp, rijec1);
	strcpy(rijec1, rijec2);
	strcpy(rijec2, temp);
}

void kompresuj(char *ulazna_datoteka, char *izlazna_datoteka)
{
	int razmak = 1, i = 0, j = 0;
	char rijeci[1000][10], privremena[10];
	int brojaci[1000] = {0};
	int br_rijeci = 0, br_slova = 0;
	char znak;
	FILE *ulaz;
	
	ulaz = fopen(ulazna_datoteka, "r");
	
	if(ulaz == NULL)
	{
		printf("Pogreska pri otvaranju datoteke.");
		exit(1);
	}
	
	FILE *izlaz = fopen(izlazna_datoteka, "w");
	
	if(izlaz == NULL)
	{
		printf("Pogreska pri otvaranju datoteke.");
		fclose(ulaz);
		exit(1);
	}
	
	do
	{
		if (razmak != 0)
			znak = fgetc (ulaz);
			
		if(je_li_slovo(znak) == 0)
			razmak = 1;
			
		else if(razmak == 1)
		{
			razmak = 0;
			br_slova = 0;
			//printf(">>>");
			
			while(znak != EOF && je_li_slovo(znak))
			{
				//printf("%c", znak);
				if(br_slova < 9)
					privremena[br_slova] = znak;
					
				br_slova++;
				znak = fgetc(ulaz);
			}
			if(br_slova > 1 && br_slova < 9)
			{
				
				privremena[br_slova] = 0;
				//printf ("privremena >%d<\n", br_rijeci);
				//for (i = 0; i < br_rijeci; i++)
				//	printf ("rijeci[%d]: >%s<\n", i, rijeci[i]);
				i = ima_rijec(rijeci, br_rijeci, privremena);
				//printf ("i = %d\n", i);
				if(i != -1)
					brojaci[i]++;
					
				else
				{
					for(i = 0; i <= br_slova; i++)
						rijeci[br_rijeci][i] = privremena[i];
					
					brojaci[br_rijeci]++;
					br_rijeci++;
				}
			}
			//printf("<<<\n");
			
			if(znak == EOF)
				break;
		}
	}
	while (znak != EOF);
	
	/*sortiranje niza*/
	for(i = 0; i < br_rijeci; i++)
	{
		for(j = i + 1; j < br_rijeci; j++)
		{
			if(brojaci[i] < brojaci[j])
			{
				int temp = brojaci[i];
				brojaci[i] = brojaci[j];
				brojaci[j] = temp;
				zamijeni_rijeci(rijeci[i], rijeci[j]);
			}
			
			else if(brojaci[i] == brojaci[j])
			{
				if(strcmp(rijeci[i], rijeci[j]) > 0)
					zamijeni_rijeci(rijeci[i], rijeci[j]);
			}
		}
	}
	if(br_rijeci > 10)
		br_rijeci = 10;
	
	/*upisivanje rijeci u datoteku*/	
	for(i = 0; i < br_rijeci; i++)
		fprintf(izlaz, "%s\n", rijeci[i]);
		
	if(br_rijeci < 10)
		fprintf(izlaz, "\n");
		
	fclose(ulaz);
	
	ulaz = fopen(ulazna_datoteka, "r");
	
	if(ulaz == NULL)
	{
		printf("Pogreska pri otvaranju datoteke.");
		fclose(izlaz);
		exit(1);
	}
	
	razmak = 1;
	do
	{
		if(razmak != 0)
			znak = fgetc(ulaz);
			
		if(je_li_slovo(znak) == 0 && znak != EOF)
		{
			razmak = 1;
			fputc(znak, izlaz);
		}
			
		else if(razmak == 1)
		{
			razmak = 0;
			br_slova = 0;
			
			while(znak != EOF && je_li_slovo(znak) == 1)
			{
				//printf ("%c", znak);
				if (br_slova == 9) 
					break;
					
				//printf("%c",znak);
				
				if(br_slova < 9)
					privremena[br_slova] = znak;
				
				br_slova++;
				znak = fgetc(ulaz);
			}
			
			//printf("\n");
			//printf(" < %d znak: %d\n", br_slova, znak);
			if(znak != EOF && je_li_slovo (znak) == 1)
			{
				//printf("1\n");
				privremena[br_slova] = 0;
				fprintf(izlaz, "%s", privremena);
				
				while(znak != EOF && je_li_slovo(znak) == 1)
					{
						fputc(znak, izlaz);
						znak = fgetc(ulaz);
					}
					
				if (znak == EOF)
					break;
			}
			
			else if (znak != EOF || (znak == EOF && br_slova < 9))
			{
				//printf("2\n");
				privremena[br_slova] = 0;
				i = ima_rijec(rijeci, br_rijeci, privremena);
				
				if(i == -1)
					fprintf(izlaz, "%s", privremena);
					
				else
				{
					fputc(20 + i, izlaz);
				}
			}
		}
	}
	while(znak != EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka kompresovana.\n");
}

void dekompresuj(char *ulazna_datoteka, char *izlazna_datoteka)
{
	char rijeci[10][10];
	char znak;
	int razmak = 1, br_rijeci = 0, i = 0, br_slova = 0;
	
	FILE *ulaz = fopen(ulazna_datoteka, "r");
	
	if(ulaz == NULL)
	{
		printf("Pogreska pri otvaranju datoteke.");
		exit(1);
	}
	
	FILE *izlaz = fopen(izlazna_datoteka, "w");
	
	if(izlaz == NULL)
	{
		printf("Pogreska pri otvaranju datoteke.");
		fclose(ulaz);
		exit(1);
	}
	
	for(i = 0; i < 10; i++)
	{
		br_slova = 0;
		
		while((znak = fgetc(ulaz)) != EOF && znak != '\n')
			rijeci[br_rijeci][br_slova++] = znak;
		rijeci[br_rijeci][br_slova] = 0;
		if(br_slova == 0)
			break;
			
		
		br_rijeci++;
	}
	
	//for(i = 0; i < br_rijeci; i++)
	//	printf(">>>%s<<<\n", rijeci[i]);
	
	do
	{
		znak = fgetc(ulaz);
		
		if(znak == EOF)
			break;
			
		if(znak >= 20 && znak <= 29)
		{
			znak -= 20;
			
			/*if(znak < br_rijeci)*/
				fprintf(izlaz, "%s", rijeci[(int)znak]);
				
			/*else
				fputc(znak, izlaz);*/
		}
		
		else
			fputc(znak, izlaz);
	}
	
	while(znak != EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
}

int main() 
{
	/*printf("Zadaća 5, Zadatak 2");*/
	int a;
	char ulaz[100], izlaz[100];
	
	do
	{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &a);
		
		if(a == 1)
		{
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulaz, 100);
			
			printf("Unesite ime izlazne datoteke: ");
			unesi(izlaz, 100);
			
			kompresuj(ulaz, izlaz);
		}
		
		if(a == 2)
		{
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulaz, 100);
			
			printf("Unesite ime izlazne datoteke: ");
			unesi(izlaz, 100);
			
			dekompresuj(ulaz, izlaz);
		}
		
		if(a == 0)
			return 1;
	}
	
	while(a != 0);
	return 0;
}
