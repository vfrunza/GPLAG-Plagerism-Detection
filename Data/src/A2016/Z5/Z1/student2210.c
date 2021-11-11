#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EPSILON 0.000001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int DaLiImaPetica(int niz[], int velicina)
{
	int i;
	for(i = 0; i < velicina; i++)
	{
		if(niz[i] == 5)
			return 1;
	}
	
	return 0;
}

int genijalci(struct Student studenti[], int velicina_niza, float prosjek)
{
	int i, j, k, l;
	int suma_ocjena = 0;
	float prosjek_pomocna = 0;
	float niz_prosjeka[1000] = {0};
	float first = 0, second = 0, third = 0;
	int niz_brojaca[1000] = {0};
	int temp;

	for(i = 0; i < velicina_niza; i++)
	{
		suma_ocjena = 0;
		if(DaLiImaPetica(studenti[i].ocjene, studenti[i].br_ocjena))
		{
			prosjek_pomocna = 5;
			for(k = i; k < velicina_niza - 1; k++)
			{
				studenti[k] = studenti[k+1];
			}
			velicina_niza--;
			i--;
		}
		if(studenti[i].br_ocjena == 0)
		{
			prosjek_pomocna = 5;
			prosjek_pomocna = 5;
			for(k = i; k < velicina_niza - 1; k++)
			{
				studenti[k] = studenti[k+1];
			}
			velicina_niza--;
			i--;
		}
		if(i < 0)
			i = 0;
			
		for(j = 0; j < studenti[i].br_ocjena; j++)
		{
			suma_ocjena += studenti[i].ocjene[j];
		}
			
		prosjek_pomocna = ((float)suma_ocjena/(float)studenti[i].br_ocjena);
			
		if((prosjek_pomocna - prosjek) < EPSILON && (prosjek_pomocna - prosjek) < 0)
		{
			for(k = i; k < velicina_niza - 1; k++)
			{
				studenti[k] = studenti[k+1];
			}
			velicina_niza--;
			i--;
		}
	}
	
	
	for(i = 0; i < velicina_niza; i++)
	{
		suma_ocjena = 0;
		for(j = 0; j < studenti[i].br_ocjena; j++)
		{
			suma_ocjena += studenti[i].ocjene[j];
		}
		prosjek_pomocna = ((float)suma_ocjena/(float)studenti[i].br_ocjena);
		niz_prosjeka[i] = prosjek_pomocna;
	}
	
	/* za prvi po prosjeku */
	
	for(i = 0; i < velicina_niza; i++)
	{
		if(niz_prosjeka[i] > first)
			first = niz_prosjeka[i];
	}
	
	j = 0;
	for(i = 0; i < velicina_niza; i++)
	{
		if(first == niz_prosjeka[i])
		{
			niz_brojaca[j++] = i;
			niz_prosjeka[i] = 0;
		}
	}

	if(first != 0)
	{
		if(j == 1)
		{
			k = 0;
			while (studenti[niz_brojaca[0]].prezime[k] != '\0')
			{
				printf("%c", studenti[niz_brojaca[0]].prezime[k++]);
			}
			printf(" ");
			k = 0;
			while (studenti[niz_brojaca[0]].ime[k] != '\0')
			{
				printf("%c", studenti[niz_brojaca[0]].ime[k++]);
			}
			printf("\n");
		}
		else if(j > 1)
		{
			for(i = 0; i < j; i++)
			{
				for(k = i+1; k < j; k++)
				{
					
					/*if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) == 0)
					{
						for(l = k; l < j-1; l++)
						{
							niz_brojaca[l] = niz_brojaca[l+1];
						}
						j--;
						k--;
					}
					else */if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime)  != 0)
					{
						if(strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) > 0)
						{
							temp = niz_brojaca[i];
							niz_brojaca[i] = niz_brojaca[k];
							niz_brojaca[k] = temp;
							/*d*/
							for(l = k; l < j-1; l++)
							{
								niz_brojaca[l] = niz_brojaca[l+1];
							}
							j--;
							k--;
						}
					}
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) != 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime)  == 0)
					{
						if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) > 0)
						{
							temp = niz_brojaca[i];
							niz_brojaca[i] = niz_brojaca[k];
							niz_brojaca[k] = temp;
							/*d
							for(l = k; l < j-1; l++)
							{
								niz_brojaca[l] = niz_brojaca[l+1];
							}
							j--;
							k--;*/
						}
					}
					/*dodato*/
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) > 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) > 0)
					{
						temp = niz_brojaca[i];
						niz_brojaca[i] = niz_brojaca[k];
						niz_brojaca[k] = temp;
					}
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) == 0)
					{
						for(l = k; l < j-1; l++)
						{
							niz_brojaca[l] = niz_brojaca[l+1];
						}
						j--;
						k--;
					}
					/* kraj dodato */
				}
				k = 0;
				while (studenti[niz_brojaca[i]].prezime[k] != '\0')
				{
					printf("%c", studenti[niz_brojaca[i]].prezime[k++]);
				}
				printf(" ");
				k = 0;
				while (studenti[niz_brojaca[i]].ime[k] != '\0')
				{
					printf("%c", studenti[niz_brojaca[i]].ime[k++]);
				}
				printf("\n");
			}
		}
	}
	
	/* kraj za prvi po prosjeku */
	
	/*za drugi po prosjeku */
	
	for(i = 0; i < velicina_niza; i++)
	{
		if(niz_prosjeka[i] > second)
			second = niz_prosjeka[i];
	}
	
	j = 0;
	for(i = 0; i < velicina_niza; i++)
	{
		if(second == niz_prosjeka[i])
		{
			niz_brojaca[j++] = i;
			niz_prosjeka[i] = 0;
		}
	}

	if(second != 0)
	{
		if(j == 1)
		{
			k = 0;
			while (studenti[niz_brojaca[0]].prezime[k] != '\0')
			{
				printf("%c", studenti[niz_brojaca[0]].prezime[k++]);
			}
			printf(" ");
			k = 0;
			while (studenti[niz_brojaca[0]].ime[k] != '\0')
			{
				printf("%c", studenti[niz_brojaca[0]].ime[k++]);
			}
			printf("\n");
		}
		else if(j > 1)
		{
			for(i = 0; i < j; i++)
			{
				for(k = i+1; k < j; k++)
				{
					/*if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) == 0)
					{
						for(l = k; l < j-1; l++)
						{
							niz_brojaca[l] = niz_brojaca[l+1];
						}
						j--;
						k--;
					}
					else */if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime)  != 0)
					{
						if(strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) > 0)
						{
							temp = niz_brojaca[i];
							niz_brojaca[i] = niz_brojaca[k];
							niz_brojaca[k] = temp;
							/*d*/
							for(l = k; l < j-1; l++)
							{
								niz_brojaca[l] = niz_brojaca[l+1];
							}
							j--;
							k--;
						}
					}
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) != 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime)  == 0)
					{
						if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) > 0)
						{
							temp = niz_brojaca[i];
							niz_brojaca[i] = niz_brojaca[k];
							niz_brojaca[k] = temp;
							/*d*/
							for(l = k; l < j-1; l++)
							{
								niz_brojaca[l] = niz_brojaca[l+1];
							}
							j--;
							k--;
						}
					}
					/*dodato*/
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) > 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) >0)
					{
						temp = niz_brojaca[i];
						niz_brojaca[i] = niz_brojaca[k];
						niz_brojaca[k] = temp;
					}
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) == 0)
					{
						for(l = k; l < j-1; l++)
						{
							niz_brojaca[l] = niz_brojaca[l+1];
						}
						j--;
						k--;
					}
					/* kraj dodato */
				}
				k = 0;
				while (studenti[niz_brojaca[i]].prezime[k] != '\0')
				{
					printf("%c", studenti[niz_brojaca[i]].prezime[k++]);
				}
				printf(" ");
				k = 0;
				while (studenti[niz_brojaca[i]].ime[k] != '\0')
				{
					printf("%c", studenti[niz_brojaca[i]].ime[k++]);
				}
				printf("\n");
			}
		}
	}
	/* kraj za drugi po prosjeku */
	
	/* za treci po prosjeku */
	
	for(i = 0; i < velicina_niza; i++)
	{
		if(niz_prosjeka[i] > third)
			third = niz_prosjeka[i];
	}
	
	j = 0;
	for(i = 0; i < velicina_niza; i++)
	{
		if(third == niz_prosjeka[i])
		{
			niz_brojaca[j++] = i;
			niz_prosjeka[i] = 0;
		}
	}

	if(third != 0)
	{
		if(j == 1)
		{
			k = 0;
			while (studenti[niz_brojaca[0]].prezime[k] != '\0')
			{
				printf("%c", studenti[niz_brojaca[0]].prezime[k++]);
			}
			printf(" ");
			k = 0;
			while (studenti[niz_brojaca[0]].ime[k] != '\0')
			{
				printf("%c", studenti[niz_brojaca[0]].ime[k++]);
			}
			printf("\n");
		}
		else if(j > 1)
		{
			for(i = 0; i < j; i++)
			{
				for(k = i+1; k < j; k++)
				{
					/*if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) == 0)
					{
						for(l = k; l < j-1; l++)
						{
							niz_brojaca[l] = niz_brojaca[l+1];
						}
						j--;
						k--;
					}
					else */if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime)  != 0)
					{
						if(strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) > 0)
						{
							temp = niz_brojaca[i];
							niz_brojaca[i] = niz_brojaca[k];
							niz_brojaca[k] = temp;
							/*d*/
							for(l = k; l < j-1; l++)
							{
								niz_brojaca[l] = niz_brojaca[l+1];
							}
							j--;
							k--;
						}
					}
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) != 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime)  == 0)
					{
						if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) > 0)
						{
							temp = niz_brojaca[i];
							niz_brojaca[i] = niz_brojaca[k];
							niz_brojaca[k] = temp;
							/*d
							for(l = k; l < j-1; l++)
							{
								niz_brojaca[l] = niz_brojaca[l+1];
							}
							j--;
							k--;*/
						}
					}
					/*dodato*/
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) > 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) >0)
					{
						temp = niz_brojaca[i];
						niz_brojaca[i] = niz_brojaca[k];
						niz_brojaca[k] = temp;
					}
					else if(strcmp(studenti[niz_brojaca[i]].ime, studenti[niz_brojaca[k]].ime) == 0 && strcmp(studenti[niz_brojaca[i]].prezime, studenti[niz_brojaca[k]].prezime) == 0)
					{
						for(l = k; l < j-1; l++)
						{
							niz_brojaca[l] = niz_brojaca[l+1];
						}
						j--;
						k--;
					}
					/* kraj dodato */
				}
				k = 0;
				while (studenti[niz_brojaca[i]].prezime[k] != '\0')
				{
					printf("%c", studenti[niz_brojaca[i]].prezime[k++]);
				}
				printf(" ");
				k = 0;
				while (studenti[niz_brojaca[i]].ime[k] != '\0')
				{
					printf("%c", studenti[niz_brojaca[i]].ime[k++]);
				}
				printf("\n");
			}
		}
	}
	
	
	/* kraj za treci po prosjeku */
	return velicina_niza;
}

int main() {

struct Student s = { "aaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaa", {}, 50 };
int i;
for (i=0; i<50; i++) s.ocjene[i]=10;
printf("Vel: %llu\n", sizeof s);
/* = 244 = 20*1 (char) + 20*1 (char) + 50*4 (int) + 4 (int) */

struct Student niz[1];
niz[0]=s;
genijalci(niz, 1, 9.9);
	
	return 0;
}
