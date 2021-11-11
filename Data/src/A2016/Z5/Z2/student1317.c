#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUZ_RIJ_KOM 10
#define BROJ_RIJ_KOM 10
#define DUZ_RIJ_UL 1001
#define BROJRIJ 1000

int dekompresuj(const char* ime_ul, const char* ime_iz)
{
	
	int br_rij=0, br_znak=0, razmak=0, i=0;
	char rij_komp[BROJRIJ][DUZ_RIJ_KOM]={{""}};
	char rij[DUZ_RIJ_UL]="", praz_niz[DUZ_RIJ_UL]="";
	char znak=' ';
	
	FILE* ulaz=fopen(ime_ul, "r");
	FILE* izlaz=fopen(ime_iz, "w");
	
	if(ulaz==NULL)
	{
		printf("Otvaranje ulazne datoteke nije uspjelo!\n");
		return 0;
	}
	if(izlaz==NULL)
	{
		fclose(ulaz);
		printf("Otvaranje izlazne datoteke nije uspjelo!\n");
		return 0;
	}
	/* Ucitavanje rijeci koje se koriste za dekompresiju iz ulazne datoteke */
	while((znak=fgetc(ulaz))!=EOF)
	{
		if(ferror(ulaz))
		{
			printf("Greska u citanju ulazne datoteke.\n");
			fclose(ulaz);
			fclose(izlaz);
			return 0;
		}
		if((znak==' ' || znak=='\t') && br_rij==0)
		{
			if(razmak==0)
			{
				fseek(ulaz, 0, SEEK_SET);
				do
				{
					znak=fgetc(ulaz);
					if(ferror(ulaz))
					{
						printf("Greska u citanju ulazne datoteke.\n");
						fclose(ulaz);
						fclose(izlaz);
						return 0;
					}
					if(znak!=EOF) fputc(znak, izlaz);
					if(ferror(izlaz))
					{
						printf("Greska u pisanju u izlaznu datoteku.\n");
						fclose(ulaz);
						fclose(izlaz);
						return 0;
					}
				} while(!feof(ulaz));
				printf("Datoteka dekompresovana.\n");
				return 0;
			}
		}
		if(znak=='\n')
		{
			if(razmak==0)
			{
				strncpy(rij_komp[br_rij], rij, DUZ_RIJ_KOM);
				br_rij++;
				if(br_rij==BROJ_RIJ_KOM)
				{
					br_znak=0;
					strncpy(rij, praz_niz, DUZ_RIJ_UL);
					break;
				}
			}
			br_znak=0;
			strncpy(rij, praz_niz, DUZ_RIJ_UL);
			
			if(razmak==1) break;
			razmak=1;
		}
		else
		{
			rij[br_znak]=znak;
			br_znak++;
			if(br_znak>DUZ_RIJ_KOM) printf("Dekompresuj: prevelika duzina rijeci za dekompresiju u ulaznoj datoteci.\n");
			razmak=0;
		}
	}
	/* Ucitavanje rijeci iz ulazne datoteke */
	while(1)
	{
		znak=fgetc(ulaz);
		if(ferror(ulaz))
		{
			printf("Greska u citanju ulazne datoteke.\n");
			fclose(ulaz);
			fclose(izlaz);
			return 0;
		}
		if(!((znak>='A' && znak<='Z') || (znak>='a' && znak<='z')) && !(znak>=20 && znak<=29))
		{
			if(razmak==0) fputs(rij, izlaz);
			
			if(znak!=EOF) fputc(znak, izlaz);
			br_znak=0;
			strncpy(rij, praz_niz, DUZ_RIJ_UL);
			razmak=1;
			if(znak==EOF) break;
		}
		else
		{
			if(znak>=20 && znak<=29)
			{
				for(i=0; i<br_rij; i++)
				{
					if(i==(znak-20))
					{
						br_znak=strlen(rij_komp[i])-1;
						strncpy(rij, rij_komp[i], DUZ_RIJ_UL);
						razmak=0;
						break;
					}
				}
				if(i==(znak-20)) continue;
			}
			rij[br_znak]=znak;
			br_znak++;
			if(br_znak>DUZ_RIJ_UL)
			{
				printf("Dekompresuj: prevelika duzina rijeci u ulaznoj datoteci.\n");
				return 0;
			}
			razmak=0;
		}
	}
	printf("Datoteka dekompresovana.\n");
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}

int kompresuj(const char* ime_ul, const char* ime_iz)
{
	int razmak=0, br_znak=0, br_rij=0, i=0, j=0, br_komp=0, max_br=0, temp_br=0;
	int broj_komp[BROJRIJ]={0};
	char rijeci[BROJRIJ][DUZ_RIJ_KOM]={{""}};
	char rij[DUZ_RIJ_UL]="", praz_niz[DUZ_RIJ_UL]="";
	char znak=' ', c=' ';
	char rij_komp[BROJRIJ][DUZ_RIJ_KOM]={{""}};
	char komp_rij[DUZ_RIJ_KOM]="", niz_praz[DUZ_RIJ_KOM]="";
	char temp_niz[DUZ_RIJ_KOM]="", max_rij[DUZ_RIJ_KOM]="";
	FILE* ulaz=fopen(ime_ul, "r");
	FILE* izlaz=fopen(ime_iz, "w");
	
	if(ulaz==NULL)
	{
		printf("Otvaranje ulazne datoteke nije uspjelo!\n");
		return 0;
	}
	if(izlaz==NULL)
	{
		fclose(ulaz);
		printf("Otvaranje izlazne datoteke nije uspjelo!\n");
		return 0;
	}
	/* Ucitavanje rijeci iz datoteke i upisivanje u matricu rijeci u kojoj
	se nalaze rijeci iz ulazne datoteke koje imaju zadati broj slova */
	while(1)
	{
		znak=fgetc(ulaz);
		if(ferror(ulaz))
		{
			printf("Greska u citanju ulazne datoteke!\n");
			fclose(ulaz);
			fclose(izlaz);
			return 0;
		}
		
		if(!((znak>='A' && znak<='Z') || (znak>='a' && znak<='z')))
		{
			if(razmak==0)
			{
				if(br_znak>1 && br_znak<DUZ_RIJ_KOM)
				{
					strncpy(rijeci[br_rij], rij, DUZ_RIJ_UL);
					br_rij++;
					if(br_rij>BROJRIJ) 
					{
						/*printf("\nKompresuj: u ulaznoj datoteci ima vise od 1000 rijeci.\n"); */
						break;
					} 
				}
			}
			br_znak=0;
			strncpy(rij, praz_niz, DUZ_RIJ_UL);
			razmak=1;
			if(znak==EOF) break;
		}
		else
		{
			rij[br_znak]=znak;
			br_znak++;
			if(br_znak>DUZ_RIJ_UL) 
			{
				printf("\nKompresuj: prevelika duzina rijeci u ulaznoj datoteci.\n");
				return 0;
			}
			razmak=0;
		}
	}
	
	for(i=0; i<br_rij; i++)
	{
		strncpy(komp_rij, rijeci[i], DUZ_RIJ_KOM);
		for(j=0; j<br_rij; j++)
		{
			if(strcmp(rij_komp[j], niz_praz)==0)
			{
				strncpy(rij_komp[j], komp_rij, DUZ_RIJ_KOM);
				broj_komp[j]=1;
				br_komp++;
				break;
			}
			else if(strcmp(rij_komp[j], komp_rij)==0)
			{
				broj_komp[j]++;
				break;
			}
		}
	}
	/* Sortiranje nizova broj_komp i rij_komp prema broju pojavljivanja rijeci,
	odnosno prema leksikografskom redoslijedu rijeci koje imaju isti broj pojavljivanja */
	for(i=0; i<br_komp-1; i++)
	{
		max_br=broj_komp[i];
		strncpy(max_rij, rij_komp[i], DUZ_RIJ_KOM);
		
		for(j=i+1; j<br_komp; j++)
		{
			if(broj_komp[j]>max_br)
			{
				max_br=broj_komp[j];
				strncpy(max_rij, rij_komp[j], DUZ_RIJ_KOM);
				
				temp_br=broj_komp[j];
				broj_komp[j]=broj_komp[i];
				broj_komp[i]=temp_br;
				
				strncpy(temp_niz, rij_komp[j], DUZ_RIJ_KOM);
				strncpy(rij_komp[j], rij_komp[i], DUZ_RIJ_KOM);
				strncpy(rij_komp[i], temp_niz, DUZ_RIJ_KOM);
			}
			else if(broj_komp[j]==max_br && (strcmp(rij_komp[j], max_rij)<0))
			{
				max_br=broj_komp[j];
				strncpy(max_rij, rij_komp[j], DUZ_RIJ_KOM);
				
				temp_br=broj_komp[j];
				broj_komp[j]=broj_komp[i];
				broj_komp[i]=temp_br;
				
				strncpy(temp_niz, rij_komp[j], DUZ_RIJ_KOM);
				strncpy(rij_komp[j], rij_komp[i], DUZ_RIJ_KOM);
				strncpy(rij_komp[i], temp_niz, DUZ_RIJ_KOM);
			}
		}
	}
	fseek(ulaz, 0, SEEK_SET);
	if(br_komp==0)
	{
		do
		{
			znak=fgetc(ulaz);
			if(ferror(ulaz))
			{
				printf("Greska u citanju ulazne datoteke.\n");
				fclose(ulaz);
				fclose(izlaz);
				return 0;
			}
			if(znak!=EOF) fputc(znak, izlaz);
			if(ferror(izlaz))
			{
				printf("Greska u pisanju u izlaznu datoteku.\n");
				fclose(ulaz);
				fclose(izlaz);
				return 0;
			}
		} while(!feof(ulaz));
		printf("Datoteka kompresovana.\n");
		return 0;
	}
	else if(br_komp>=10) br_komp=10;
	
	for(i=0; i<br_komp; i++)
		fprintf(izlaz, "%s\n", rij_komp[i]);
	
	if(br_komp<10)
	{
		znak='\n';
		fprintf(izlaz, "%c", znak);
	}
	/* Citanje ulazne datoteke i upisivanje kompresovanih znakova u izlaznu datoteku */
	br_znak=0;
	strncpy(rij, praz_niz, DUZ_RIJ_UL);
	while(1)
	{
		znak=fgetc(ulaz);
		if(ferror(ulaz))
		{
			printf("Greska u citanju ulazne datoteke.\n");
			fclose(ulaz);
			fclose(izlaz);
			return 0;
		}
		if(!((znak>='A' && znak<='Z') || (znak>='a' && znak<='z')))
		{
			if(razmak==0)
			{
				if(br_znak>1 && br_znak<DUZ_RIJ_KOM)
				{
					for(i=0; i<br_komp; i++)
					{
						if(strcmp(rij_komp[i], rij)==0)
						{
							c=(char)(i+20);
							fputc(c, izlaz);
							break;
						}
					}
				}
				else if(br_znak>=DUZ_RIJ_KOM) fputs(rij, izlaz);
				else if(br_znak==1) fputc(znak, izlaz);
			}
			if(znak!=EOF) fputc(znak, izlaz);
			br_znak=0;
			strncpy(rij, praz_niz, DUZ_RIJ_UL);
			razmak=1;
			if(znak==EOF) break;
		}
		else
		{
			rij[br_znak]=znak;
			br_znak++;
			razmak=0;
		}
	}
	printf("Datoteka kompresovana.\n");
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}

void unesi(char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void meni()
{
	int opcija=0;
	char ime_ulaz[20]="";
	char ime_izlaz[20]="";
	
	do
	{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &opcija);
		
		switch(opcija)
		{
			case 1:	
			{
				printf("Unesite ime ulazne datoteke: ");
				unesi(ime_ulaz, 20);
				printf("Unesite ime izlazne datoteke: ");
				unesi(ime_izlaz, 20);
				
				kompresuj(ime_ulaz, ime_izlaz);
				break;
			}
			case 2:
			{
				printf("Unesite ime ulazne datoteke: ");
				unesi(ime_ulaz, 20);
				printf("Unesite ime izlazne datoteke: ");
				unesi(ime_izlaz, 20);
				
				dekompresuj(ime_ulaz, ime_izlaz);
				break;
			}
			case 0: break;
			default: printf("Nepoznata opcija!\n");
		}
	} while(opcija!=0);
}

int main() 
{
	meni();
	return 0;
}
