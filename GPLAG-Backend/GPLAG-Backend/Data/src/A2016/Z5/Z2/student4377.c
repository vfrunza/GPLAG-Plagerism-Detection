#include <stdio.h>
#include <stdlib.h>

int broj_slova(char *s)
{
	int brojac=0;
	while((*s >= 'A' && *s <='Z') || (*s >= 'a' && *s <='z'))
	{ 
		brojac++;
		s++;
	}
	return brojac;
}

int provjeri_rijec(char* s)
{
	int br = broj_slova(s);
	
	if(br < 10 && br > 1)
	{
		return 1;
	}
	
	return 0;
}

int poredi(char* prva, char* druga)
{
	int isto = 0;
	if(broj_slova(prva) == broj_slova(druga))
	{
		while(*prva != '\0' && *druga != '\0')
		{
			if(*prva == *druga)
			{
				isto = 1;
			}
			else
			{
				return 0;
			}
			prva++;
			druga++;
		}
	}
	return isto;
}

void dekompresuj()
{
	FILE *ulaz;
	FILE *ulaz2;
	FILE *izlaz;
	
	char tabela[10][30] = {{0}, {0}};
}

void kompresuj()
{
	FILE *ulaz;
	FILE *ulaz2;
	FILE *izlaz;
	char temp[30];
	char rijec[30];
	char rijec_koju_provjeravam[30];
	int max = 0, brojac = 0;
	char tabela[10][30] = {{0}, {0}};
	int tabela_br[10];
	int i=0, j=0, k=0, slovo, slovo2, t,p, z, pos;
	char ime1[300], ime2[300];
	
	printf("Unesite ime ulazne datoteke: ");
	scanf("%s", ime1);
	
	printf("Unesite ime izlazne datoteke: ");
	scanf("%s", ime2);
	
	for(p=0; p < 10; p++)
	{
		ulaz = fopen(ime1, "r");
		
		max = 0;
		i=0;
		while(!feof(ulaz))
		{
			i=0;
			brojac = 0;
			
			while(1)
			{
				slovo = fgetc(ulaz);
				if((slovo >= 'A' && slovo <='Z') || (slovo >= 'a' && slovo <='z'))
				{
					rijec[i++] = slovo;
					rijec[i] = '\0';
				}
				else
				{
					break;
				}
			}
			//printf("%s \n", rijec);
			if(!provjeri_rijec(rijec))
			{
				i=0;
				continue;
			}
			
			for(k=0; k<10; k++)
			{
				if(poredi(rijec, tabela[k]) == 1)
				{
					break;
				}
			}
			if(k<10) continue;
			
			ulaz2 = fopen(ime1, "r");	
			while(!feof(ulaz2))
			{
				j=0;
				
				while(1)
				{
					slovo2 = fgetc(ulaz2);
					if((slovo2 >= 'A' && slovo2 <='Z') || (slovo2 >= 'a' && slovo2 <='z'))
					{
						rijec_koju_provjeravam[j++] = slovo2;
						rijec_koju_provjeravam[j] = '\0';
					}
					else
					{
						j=0;
						break;
					}
				}
				
				//printf("Provjeravamo: %s sa  %s \n", rijec, rijec_koju_provjeravam);
				
				if(poredi(rijec, rijec_koju_provjeravam))
				{
					rijec_koju_provjeravam[j] = '\0';
					brojac++;
				}
			}
			
			t=0;
			if(brojac > max)
			{
				tabela_br[p] = brojac;
				max = brojac;
				for(t=0; t<20; t++)
				{
					tabela[p][t] = rijec[t];
				}
			}
			//fclose(ulaz);
		}
	}
	
	/*printf("\n TABELA: \n");
	for(i=0; i<10 && *tabela[i] != 0; i++) printf("%d --- %s\n", tabela_br[i], tabela[i]);*/
	
	for(i=0; i<10 && *tabela[i] != 0; i++)
	{
		for(j=0; j<10 && *tabela[j] != 0; j++)
		{
			if(i != j)
			{
				if(tabela_br[i] == tabela_br[j])
				{
					//printf("\nRijeci %s i %s su isto puta ponavljaju", tabela[i], tabela[j]);
					
					for(k = 0; k<broj_slova(tabela[i]) && k<broj_slova(tabela[j]); k++)
					if(*tabela[i+k] - *tabela[j+k] > 0)
					{
						for(z=0; z<10; z++)
						{
							temp[z] = tabela[i][z];
							tabela[i][z] = tabela[j][z];
							tabela[j][z] = temp[z];
						}
					}
				}
			}
		}
	}
	
	/*	printf("\n TABELA22222222222: \n");
	for(i=0; i<10 && *tabela[i] != 0; i++) printf("%d --- %s\n", tabela_br[i], tabela[i]);
*/
	
	izlaz = fopen(ime2, "w");
	
	i=0;
	while(i<10 && *tabela[i] != 0)
	{
		fprintf(izlaz, "%s\n", tabela[i]);
		i++;
	}
	if (ferror(izlaz)) printf("Greska prilikom pisanja datoteke.\n");
	fprintf(izlaz, "\n");
	
	ulaz = fopen(ime1, "r");
	
		i=0;
		
		do
		{
			slovo = fgetc(ulaz);
			if((slovo >= 'A' && slovo <='Z') || (slovo >= 'a' && slovo <='z'))
			{
				//printf("\n%c - %d", slovo, i);
				rijec[i++] = slovo;
				rijec[i] = '\0';
			}
			else
			{
				if(i != 0) 
				{
					for(k=0; k<10; k++)
					{	
						if(poredi(rijec, tabela[k]))
						{
							//printf("\nPeint '%s'  '%s'", rijec, tabela[k]);
							fprintf(izlaz, "[%d]", k+20);
							if(slovo != EOF) fprintf(izlaz,"%c", slovo);
							i=0;
							break;
						}
					}
					if(k<10) 
					{
						continue;
					}
					else
					{
						for(z=0; z<broj_slova(rijec); z++)
						fprintf(izlaz,"%c", rijec[z]);
						if(slovo != EOF) fprintf(izlaz,"%c", slovo);
					}
				}
				else
				{
					//printf("i ima broj %d", i);
					if(slovo != EOF) fprintf(izlaz,"%c", slovo);
				}
				
				i=0;
			}
		}while(slovo != EOF);
	
	fclose(ulaz);
	fclose(izlaz);
	
}

/*	while(!feof(ulaz))
	{
		j=0;
		while((slovo = fgetc(ulaz)) != EOF)
		{
			if((slovo >= 'A' && slovo <='Z') || (slovo >= 'a' && slovo <='z'))
			{
				rijec[j++] = slovo;
			}
			else
			{
				rijec[j] = '\0';
				for(k=0; k<10; k++)
				{	
					if(poredi(rijec, tabela[k]) == 1)
					{
						fprintf(izlaz, "[%d]", k+20);
						break;
					}
				}
				if(k == 10)
				{
					fprintf(izlaz, "%s", rijec);
				}
				fprintf(izlaz, "%c", slovo);
			}
		}
	}
}*/
		
		/*for(k=0; k<10; k++)
		{
			if(poredi(rijec, tabela[k]) == 1)
			{
				fprintf(izlaz, "[%d]", k+20);
				break;
			}
		}
		if(k<10) continue;
	}			
				
}
	
	
	
	
	while(fscanf(ulaz, "%s ", rijec) != EOF)
	{
		i=0;
		while(i<10 && *tabela[i] != 0)
		{
			if(poredi(rijec, tabela[i]))
			{
				//printf("[%d]", i+20);
				fprintf(izlaz, "[%d]", i+20);
	
				break;
			}
			i++;
		}
		if(i==10)
		fprintf(izlaz, "%s", rijec);
	}*/
	

int main() 
{
	FILE *ulaz;
	int odabir, c;
	
	do
	{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &odabir);
	
		switch(odabir)
		{
			case 0: 
			//printf("izlaz");
			break;
			
			case 1: 
			kompresuj();
			printf("Datoteka kompresovana. \n");
			break;
			
			case 2: 
			printf("Datoteka dekompresovana.");
			break;
		}
	}	
	while(odabir != 0);	
	
	return 0;
}


	/*for(j=0; j<10; j++)
	{
		max=0;
		ulaz = fopen(ime1, "r");
		if(ulaz == NULL) printf("Nije uso");
		while(fscanf(ulaz, "%s ", rijec) != EOF)
		{
			for(k=0; k<10; k++)
			{
				if(poredi(rijec, tabela[k]) == 1)
				{
					break;
				}
			}
			if(k<10) continue;

			ulaz2 = fopen(ime1, "r"); 
			brojac=0;
			while(fscanf(ulaz2, "%s ", rijec_koju_provjeravam) != EOF)
			{
				if(poredi(rijec, rijec_koju_provjeravam))
				{
					brojac++;
				}
			}
					
			i=0;
			if(brojac>max)
			{
				max=brojac;
				for(i=0; i<20; i++)
				{
					tabela[j][i] = rijec[i];
				}
			}
		}
	}
	
	izlaz = fopen(ime2, "w");
	
	i=0;
	while(i<10 && *tabela[i] != 0)
	{
		fprintf(izlaz, "%s\n", tabela[i]);
		i++;
	}
	if (ferror(izlaz)) printf("Greska prilikom pisanja datoteke.\n");
	fprintf(izlaz, "\n");
	
	ulaz = fopen(ime1, "r");
	//izlaz = fopen("izlaz.txt", "w");
	while(fscanf(ulaz, "%s ", rijec) != EOF)
	{
		i=0;
		while(i<10 && *tabela[i] != 0)
		{
			if(poredi(rijec, tabela[i]))
			{
				printf("[%d]", i+20);
				fprintf(izlaz, "[%d]", i+20);
	
				break;
			}
			i++;
		}
		if(i==10)
		fprintf(izlaz, "%s", rijec);
	}

	fclose(ulaz);*/