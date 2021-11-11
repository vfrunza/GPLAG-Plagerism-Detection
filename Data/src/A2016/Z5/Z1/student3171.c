#include <stdio.h>

struct Student
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
	
};

int genijalci(struct Student niz[100], int velicina, float prosjek)
{
	/* potrebno je naci prosjek ocjena svakog studenta*/
	int suma=0, i, j, k;
	float prosjek_ocjena[100]; /*prosjek ocjena napisati kao niz i u njega sacuvati prosjeke ocjena studenata pojedinacno*/
	float max=-10000;
	
	for(i=0; i<velicina; i++)
	{
		/*i-broj studenta; j-ocjena*/
			for(j=0; j<niz[i].br_ocjena; j++)
			{
				suma=suma+niz[i].ocjene[j];
				if(niz[i].ocjene[j]==5 || niz[i].br_ocjena==0) 
				{ 
					prosjek_ocjena[i]=5;
					break;
				}
				
			}
			
		if(j!=niz[i].br_ocjena || niz[i].br_ocjena==0) prosjek_ocjena[i]=5;
		else prosjek_ocjena[i]=(float)suma/niz[i].br_ocjena;
		
		suma=0;
	
	}
	

	
	for(i=0; i<velicina; i++)
	{
		if(prosjek_ocjena[i]<prosjek)
		{
			/*ukoliko je prosjek manji od zadanog, vrsimo izbacivanje*/
			for(j=i; j<velicina-1; j++)
			{
				niz[j]=niz[j+1];
				prosjek_ocjena[j]=prosjek_ocjena[j+1];
			}
			
			
			i--;
			velicina--;
			
		}
	}
	
	int br=0;
	
	/*potrebno je naci osobu sa najvecim prosjekom te ispisati je , takodjer ispisati dvoje narednih sa najvecim prosjekom*/
	for(i=0; i<velicina; i++)
	{
		for(j=0; j<velicina; j++)
		{
			if(prosjek_ocjena[i]>=max) max=prosjek_ocjena[i];
		}
		
		for(j=0; j<velicina; j++)
		{
			if(prosjek_ocjena[j]==max && max!=0 && br<3) 
			{
				printf("\n%s %s", niz[j].prezime, niz[j].ime);
				prosjek_ocjena[j]=0;
				br++;
			}
		}
		
		max=-10000;
		
	}
	
	
return velicina;	

	
}

int main() {
	
	struct Student studenti[100];
	float prosjek;
	int i, j;
	
	printf("Unesite prosjek: ");
	scanf("%f", &prosjek);
	
	for(i=0; i<20; i++)
	{
		printf("Unesite ime: ");
		scanf("%s", &studenti[i].ime);
		printf("Unesite prezime: ");
		scanf("%s", &studenti[i].prezime);
		scanf("Unesite broj ocjena: ");
		scanf("%d", &studenti[i].br_ocjena);
		printf("Unesite ocjene: ");
		
		
		for(j=0; j<studenti[i].br_ocjena; j++)
		{
			scanf("%d", &studenti[i].ocjene[j]);
		}
		
	}
	
	int broj_studenata;
	
	broj_studenata=genijalci(studenti, 6, prosjek);
	

	
	
	return 0;
}
