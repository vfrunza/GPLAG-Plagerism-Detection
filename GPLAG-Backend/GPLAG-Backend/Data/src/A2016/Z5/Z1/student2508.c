#include <stdio.h>
#include <string.h>
#include <math.h>
#define E 0.0001
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student niz[],int vel,double prosjek)
{
	struct Student genijalac[100],temp;
	double prosjek2[100];
	int i,j,k,suma,min;
	double prosjek1,temp2;

	/*Provjeravanje da li student ima ocjenu 5 ili nema nijednu ocjenu te racunanje prosjeka*/

	for(i=0; i<vel; i++) {
		suma=0;
		prosjek1=0;

		if(niz[i].br_ocjena==0)
			prosjek1=5.0;
		else
			for(k=0; k<niz[i].br_ocjena; k++) {

				if(niz[i].ocjene[k]==5) {
					prosjek1=5.0;
					break;
				}
				suma=suma+niz[i].ocjene[k];
			}

		if(fabs(prosjek1-5.0)>E) {
			prosjek1=(double)suma/niz[i].br_ocjena;
		}

		if(prosjek1<prosjek) {
			for(j=i; j<vel-1; j++) {
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
	}
	
	for(i=0;i<vel;i++)
	{
		suma=0;
		genijalac[i]=niz[i];
		for(j=0;j<niz[i].br_ocjena;j++)
			suma=suma+niz[i].ocjene[j];
		prosjek2[i]=(double)suma/niz[i].br_ocjena;
	}
	
	for(i=0;i<vel;i++)
	{
		min=i;
		for(j=i+1;j<vel;j++)
		{
		
		if((prosjek2[j]>prosjek2[min]) || 
		(fabs(prosjek2[j]-prosjek2[min])<E && strcmp(niz[j].prezime,niz[min].prezime)<0) || 
		(fabs(prosjek2[j]-prosjek2[min])<E && (strcmp(niz[j].prezime,niz[min].prezime)==0) && strcmp(niz[j].ime,niz[min].ime)<0))
			min=j;
		}
	temp2=prosjek2[i];
	prosjek2[i]=prosjek2[min];
	prosjek2[min]=temp2;
	temp=genijalac[i];
	genijalac[i]=genijalac[min];
	genijalac[min]=temp;
	}
	
	
	if(vel>=3)
	{
		for(i=0;i<3;i++)
		{
			printf("%s %s\n",genijalac[i].prezime,genijalac[i].ime);
		}
	}
	else
	{
		for(i=0;i<vel;i++)
		{
			printf("%s %s\n",genijalac[i].prezime,genijalac[i].ime);
		}
	}


	return vel;
}

int main()
{
	int i,x;
struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
x=genijalci(studenti, 5, 6.5);

for(i=0;i<x;i++)
	printf("%s\n",studenti[i].prezime);
    
	return 0;
}
