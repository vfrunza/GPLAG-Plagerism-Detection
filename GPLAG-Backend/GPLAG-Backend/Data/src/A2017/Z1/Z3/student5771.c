#include<stdio.h>
int Podniz (const int *p1, const int *p2, const int *q1, const int *q2)
{

	int *pok1=q1;
	int *pok2=q2;
	int brojac=0, brojac1=0;

	int *pokazivac1=p1;
	int *pokazivac2=p2;

	while(pok1!=pok2) { //broji od q1 do q2
		pok1++;
		brojac++;
	}
	int indeks=-1;
	int *pomocni=q1;
	while(pokazivac1!=pokazivac2) {
		if(*pokazivac1==*pomocni) {
			int *x=*pokazivac1;
			while(*x++==*pomocni++) brojac1++;
			if(brojac1==brojac) return indeks=x-brojac1;
			if(brojac!=brojac1) pomocni=q1;
		}
		pokazivac1++;
	}

	return indeks;
}
int main()
{
	printf("ZSR 8, Zadatak 7");
	return 0;
}
