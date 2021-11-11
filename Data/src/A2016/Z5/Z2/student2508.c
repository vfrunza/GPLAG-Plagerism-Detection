#include <stdio.h>
#include <stdlib.h>

struct ClanTabele
{
	char rijec[100];
	int brojPonavljanja;
};

void kopirajRijec(char* ulaz, char* izlaz)
{
	while(*ulaz != '\0' && *ulaz != '\n')
	*izlaz++ = *ulaz++;
	*izlaz = '\0';
}

int jeLiChar(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z')) return 1;
	else return 0;
}

char maloSlovo(char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		return c-('A'-'a');
	}
	else return c;
	
}

int vecaRijec(char* r1,char* r2)
{
	char prva[100];
	char druga[100];
	kopirajRijec(r1,prva);
	kopirajRijec(r2,druga);
	//prva[0] = maloSlovo(prva[0]);
	//druga[0] = maloSlovo(druga[0]);
	int clan = 0;
	
	while((prva[clan] != '\n' && prva[clan] != '\0') &&(druga[clan] != '\n' && druga[clan] != '\0'))
	{
		if(prva[clan] < druga[clan]) return 1;
		else if(prva[clan] > druga[clan]) return 0;
		clan++;
	}
	if(prva[clan] == '\n' ||prva[clan] == '\0') return 1;
	else return 0;

}

int jednakeRijeci(char* prva,char* druga)
{
	int jednake = 1;
	while((*prva != '\n' && *prva != '\0') && (*druga != '\n' && *druga != '\0'))
	{
		if(*prva != *druga) jednake = 0;
		prva++;
		druga++;
	}
	
	if(*prva != *druga) jednake = 0;
	return jednake;
}

int duzinaRijeci(char* rijec)
{
	int duzina = 0;
	while(*rijec != '\0' && *rijec != '\n')
	{
		duzina++;
		rijec++;
	}
	
	return duzina;
}




void dodajUTabelu(char* rijec, struct ClanTabele* tabela, int *brojClanova, int velicinaTabele)
{
	int i;
	for(i=0;i<*brojClanova;i++)
	 {
	 	if(jednakeRijeci(tabela[i].rijec,rijec))
	 	{
	 		tabela[i].brojPonavljanja++;
	 		break;
	 	}
	 }
	 
	 
	 if(i==*brojClanova && *brojClanova < velicinaTabele)
	 {
	 	if(duzinaRijeci(rijec) >1 && duzinaRijeci(rijec)<10)
	 	{
	 	kopirajRijec(rijec,tabela[i].rijec);
	 	tabela[i].brojPonavljanja = 1;
	 	*brojClanova = *brojClanova + 1;
	 	}
	 }
}

void modificirajTabelu(struct ClanTabele* tabela,int *brojClanova, int velicinaTabele)
{
	int i,j;
	struct ClanTabele tempClanTabele;
	for(i=0;i<*brojClanova;i++)
	{
		for(j=i;j<*brojClanova;j++)
		{
			if(tabela[j].brojPonavljanja > tabela[i].brojPonavljanja || (tabela[j].brojPonavljanja == tabela[i].brojPonavljanja && vecaRijec(tabela[j].rijec,tabela[i].rijec)))
			{
				tempClanTabele = tabela[j];
				tabela[j] = tabela[i];
				tabela[i] = tempClanTabele;
			}
		
			
		}	
			
		
	}
	
}


void kompresuj(char* ulaznaDatoteka, char* izlaznaDatoteka)
{
	FILE* ulaz = fopen(ulaznaDatoteka,"r+");
	if(ulaz == NULL)
	{
		printf("Otvaranje datoteke %s nije uspjelo", ulaznaDatoteka);
		return;
	}
	FILE* ulazTemp = ulaz;
	FILE* izlaz = fopen(izlaznaDatoteka,"w+");
	if(ulaz == NULL)
	{
		printf("Otvaranje datoteke %s nije uspjelo",izlaznaDatoteka);
		return;
	}
	int i;
	int c;
	char rijec[100];
	int clanRijeci = 0;
	struct ClanTabele tabela[1000];
	int velicinaTabele = 1000;
	int brojClanova = 0;
	int ocitanPocetakRijeci = 0;
	int brojValidnihClanovaTabele = 10;
	
	do
	{
		c=fgetc(ulaz);
		if(ocitanPocetakRijeci == 0 && jeLiChar(c))
		{
			ocitanPocetakRijeci = 1;
			clanRijeci = 0;
			rijec[clanRijeci++] = c;
		}
		else if(ocitanPocetakRijeci == 1 && jeLiChar(c))
		{
			rijec[clanRijeci++] = c; 
		}
		else if(ocitanPocetakRijeci == 1 && !jeLiChar(c))
		{
			rijec[clanRijeci] = '\0';
			clanRijeci = 0;
			ocitanPocetakRijeci = 0;
			dodajUTabelu(rijec,tabela,&brojClanova,velicinaTabele);
		}
		else
		{
			continue;
		}
	}while(c!=EOF);
	
fclose(ulaz);
ulaz = fopen(ulaznaDatoteka, "r+");
modificirajTabelu(tabela,&brojClanova,velicinaTabele);

if(brojClanova<brojValidnihClanovaTabele) brojValidnihClanovaTabele = brojClanova;
for(i=0;i<brojValidnihClanovaTabele;i++)
{
	fprintf(izlaz, "%s\n", tabela[i].rijec);
}

if(brojValidnihClanovaTabele < 10)
	fprintf(izlaz,"\n");
ocitanPocetakRijeci = 0;

do{
	c=fgetc(ulaz);
	if(ocitanPocetakRijeci == 0 && jeLiChar(c))
	{
		ocitanPocetakRijeci = 1;
		clanRijeci = 0;
		rijec[clanRijeci++] = c;
	}
	else if(ocitanPocetakRijeci == 1 && jeLiChar(c))
	{
		rijec[clanRijeci++] = c;
	}
	else if(ocitanPocetakRijeci == 1 && !jeLiChar(c))
	{
		rijec[clanRijeci] = '\0';
		clanRijeci = 0;
		ocitanPocetakRijeci = 0;
		for(i=0; i<brojValidnihClanovaTabele;i++)
		{
			if(jednakeRijeci(tabela[i].rijec,rijec))
			{
				fprintf(izlaz,"%c",i+20);
				break;
			}
		}
		if(i == brojValidnihClanovaTabele)
		{
			fprintf(izlaz,"%s",rijec);
		}
		fprintf(izlaz,"%c",c);
	}
	
	else
	{
		fprintf(izlaz,"%c",c);
	}
}
while(c != EOF);




fclose(ulaz);
fclose(izlaz);
	
printf("Datoteka kompresovana. \n");

}

void dekompresuj(char* ulaznaDatoteka,char* izlaznaDatoteka)
{
	FILE* ulaz = fopen(ulaznaDatoteka,"r+");
	if(ulaz == NULL)
	{
		printf("Otvaranje datoteke %s nije uspjelo",ulaznaDatoteka);
		return;
	}
	FILE* izlaz = fopen(izlaznaDatoteka,"w");
	if(ulaz == NULL)
	{
		printf("Otvaranje datoteke %s nije uspjelo",izlaznaDatoteka);
		return;
	}
	
	int c;
	char rijec[100];
	int clanRijeci = 0;
	struct ClanTabele tabela[10];
	int velicinaTabele = 10;
	int ocitanPocetakRijeci = 0;
	int brojValidnihClanovaTabele = 10;
	int brojClanova = 0;
	
	do
	{
		c=fgetc(ulaz);
		if(ocitanPocetakRijeci == 0 && jeLiChar(c))
		{
			ocitanPocetakRijeci = 1;
			clanRijeci = 0;
			rijec[clanRijeci++] = c;
		}
		else if(ocitanPocetakRijeci == 1 && jeLiChar(c))
		{
			rijec[clanRijeci++] = c;
		}
		else if(ocitanPocetakRijeci == 1 && !jeLiChar(c))
		{
			rijec[clanRijeci] = '\0';
			clanRijeci = 0;
			ocitanPocetakRijeci = 0;
			dodajUTabelu(rijec,tabela,&brojClanova,velicinaTabele);
		}
		else
		{
			break;
		}
	}while(c!=EOF && brojClanova < 10);
	
	
brojValidnihClanovaTabele = brojClanova;

	do
	{
		c=fgetc(ulaz);
		if(c >= 20 && c < 20 + brojValidnihClanovaTabele)
		{
			fprintf(izlaz, "%s", tabela[c-20].rijec);
		}
		else
			fputc(c,izlaz);
	
	}while(c != EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	
	printf("Datoteka dekompresovana. \n");
}


int main() {
	
	int izbor;
	char ulaz[20];
	char izlaz[20];
	
	do
	{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d",&izbor);
		switch (izbor)
		{
			case 1: 
			{
				printf("Unesite ime ulazne datoteke: ");
				scanf("%s", ulaz);
				printf("Unesite ime izlazne datoteke: ");
				scanf("%s", izlaz);
				kompresuj(ulaz,izlaz);
				ulaz[0] = '\0';
				izlaz[0] = '\0';
				break;
			}
			case 2:
			{
				printf("Unesite ime ulazne datoteke: ");
				scanf("%s", ulaz);
				printf("Unesite ime izlazne datoteke: ");
				scanf("%s",izlaz);
				dekompresuj(ulaz,izlaz);
				ulaz[0] = '\0';
				izlaz[0] = '\0';
				
				break;
			}
			
			case 0:
			{
				
				break;
			}
			default: 
			{
				printf("Pogresan unos. Pokusajte ponovo: ");
				
			}
		}
	}
	while(izbor != 0);

	
	
	return 0;
}
