#include <stdio.h>

struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};
int genijalci(struct Student studenti[], int velicina, float prosjek)
{
	
	int broj, suma=0, a=0,i,j;
	float prosjek1[100];
	broj=velicina;

	 i=0;
       while(i<velicina)
       {
		suma=0;
		a=0;
		for(j=0;j<studenti[i].br_ocjena; j++)
	{
		if(studenti[i].ocjene[j]==5) 
		{
			
			a++;
		}
		suma+=studenti[i].ocjene[j];
	
	}
	if(a!=0  || studenti[i].br_ocjena==0 ) prosjek1[i]=5.0; 
	else prosjek1[i]=suma*1.0/studenti[i].br_ocjena;
	i++;
	}
	
	for (i=0; i<broj; i++) {
		if (prosjek1[i]<prosjek) {
			
			for (j=i; j<broj-1; j++) {
				
				studenti[j] = studenti[j+1];
					}
				for (j=i; j<broj-1; j++) {
				
				prosjek1[j] = prosjek1[j+1];
					}
				broj--;
				i--;
				
		}
			
				
				
		}
		
		for(i=0; i<broj; i++)
		{
			
		
			printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
		}
		
	
	
	return broj;
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}

		
