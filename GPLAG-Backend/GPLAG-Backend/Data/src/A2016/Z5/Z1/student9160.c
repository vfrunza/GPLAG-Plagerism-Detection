#include <stdio.h>
#include <string.h>
struct  Student
{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/* IZRACUNAVANJE PROSJEKA ZA STUDENTE */
double Prosjek(struct Student student[], int broj_studenta)
{
	int i;
	double prosjek, suma=0;
	if(student[broj_studenta].br_ocjena<1)return 5;
	for(i=0;i<student[broj_studenta].br_ocjena;i++)
	{
		/*uslov ako je makar jedna ocjena 5 da je i prosjek 5*/
		if(student[broj_studenta].ocjene[i]==5)
		{
			prosjek=5;
			break;
		}
		/*sumiranje ocjena*/
		else suma+=student[broj_studenta].ocjene[i];
	}
	/*ako je suma 0 tj ako nema ocjena prosjek je 5*/
	if(suma==0)return 5;
	
	else prosjek=suma/student[broj_studenta].br_ocjena;
	return prosjek;
}

int genijalci(struct Student *studenti,int velicina,float prosjek)
{
	int i,max1,max2,max3;
	double max=5.;
	for(i=0;i<velicina;i++)
	{
		/*provjera prosjeka studenata*/
		if(Prosjek(studenti,i)<prosjek)
		{
			int k;
			/*izbacivanje studenata sa manjim prosjekom od zadanog*/
			for(k=i;k<velicina-1;k++)
			{
				studenti[k]=studenti[k+1];
			}
			/*smanjivanje niza nakon ibacivanja studenata*/
			velicina--;
			i--;
		}
	}
	/*odredjivanje maximalnih prosjeka*/
	/*
	for(i=0;i<velicina;i++)
	{
		if(Prosjek(studenti,i)>max)
		{
			max=Prosjek(studenti,i);
			max1=i;
		}
	}
	max=5.;
	for(i=0;i<velicina;i++)
	{
		if(i==max1)i++;
	    if(Prosjek(studenti,i)>max)
		{
			max=Prosjek(studenti,i);
			max2=i;
		}
	}
	max=5;
	for(i=0;i<velicina;i++)
	{
		if(i==max1)i++;
		if(i==max2)i++;
		if(Prosjek(studenti,i)>max)
		{
	    max=Prosjek(studenti,i);
    	max3=i;
	    }
	}*/
	for(i=0;i<velicina;i++)
	{	/* trazenje prvog max prosjeka*/
		if(Prosjek(studenti,i)>max && Prosjek(studenti,i)>prosjek){
		max=Prosjek(studenti,i);
		max1=i;}
	}
	max=5.;
	for(i=0;i<velicina;i++)
	{	/* trazenje prvog max prosjeka*/
		if(Prosjek(studenti,i)>max && Prosjek(studenti,i)>prosjek && Prosjek(studenti,i)<Prosjek(studenti,max1)){
		max=Prosjek(studenti,i);
		if(Prosjek(studenti,i)==Prosjek(studenti,max1))
		{
			if(strcmp(studenti[i].prezime,studenti[max1].prezime)<0)
			max2=max1;
			max1=i;
		}else max2=i;
		}
	}
	max=5.;
	for(i=0;i<velicina;i++)
	{	/* trazenje prvog max prosjeka*/
		if(Prosjek(studenti,i)>max && Prosjek(studenti,i)>prosjek && Prosjek(studenti,i)<Prosjek(studenti,max2)){
		max=Prosjek(studenti,i);
		if(Prosjek(studenti,i)==Prosjek(studenti,max2))
		{
			if(strcmp(studenti[i].prezime,studenti[max2].prezime)<0)
			max3=max2;
			max2=i;
		}else max3=i;
		}
	}
	
	/*ispis studenata*/
	if(Prosjek(studenti,max1)>=prosjek)
		printf("%s %s\n",studenti[max1].prezime,studenti[max1].ime);
	if(Prosjek(studenti,max2)>=prosjek)	
		printf("%s %s\n",studenti[max2].prezime,studenti[max2].ime);
	if(Prosjek(studenti,max3)>=prosjek)	
		printf("%s %s\n",studenti[max3].prezime,studenti[max3].ime);
	return velicina;
}
int main() {
	struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
};
genijalci(studenti, 5, 6.5);
	return 0;
}
