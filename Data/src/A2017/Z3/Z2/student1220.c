#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int velicina)
{
	float *p = niz;
	int i;

	for(i=0; i<velicina; i++) {
		*p=round(*p*10)/10;
		p++;
	}

}

void preslozi(float* niz, int velicina, int k)
{
	zaokruzi1(niz,velicina);
	int i;
	int broj1=0;
	int broj2=0;
	int suma=0;
	int tmp=0;
	float niz1[1000];
	float niz2[1000];

	for(i=0; i<velicina; i++) {
		suma=0;
		/*Mnozimo sa 10 da bi poslije zaokruzili broj na 1 decimali*/
		tmp=fabs(*(niz+i)*10);

		do {
			/*Rastavljamo broj na pojedinacne cifre, te te cifre sabiramo */
			suma+=tmp%10;
			tmp/=10;
		} while(tmp>0);

        /*Ako je suma manja od k, novi niz1 postaje niz brojeva cija je suma manja od k*/
		if(suma<k) {
			niz1[broj1] = *(niz+i);
			broj1++;
		}
		
        /*Ako je suma veca ili jednaka od k, novi niz2 postaje niz brojeva cija je suma veca ili jednaka k*/
		else if(suma>=k) {
			niz2[broj2] = *(niz+i);
			broj2++;
		}
	}
    
    /*Sada cemo proci kroz pocetni niz, i razdvojiti ga na 2 dijela. Prvo da se ispisuje niz koji smo odredili da bude niz brojeva ciji je zbir cifara veci ili jednak k, a onda se ispisuje niz brojeva ciji je zbir cifara manji od k*/
	/*Treba razumjeti da ovo nece ispisati od najveceg ka najmanjem broju, jer se ispisuje prvo niz2 pa niz1, a niz 2 se sastoji od brojeva ciji je zbir cifara veci ili jednak k, i clanovi niza 2 su ispisani neovisno koji od njih je veci lili manji, dok se niz1 sastoji od brojeva ciji je zbir cifara manji od k, clanovi niza1 su ispisani neovisno od toga koji je od njih veci ili manji */
	for(i=0; i<velicina; i++) {
		/*Ispisuj prvo niz2*/
		if(i<broj2)
			*(niz+i) = *(niz2+i);

		else
		/*Ispisuj niz1(mora ici -broj2 da se ne bi ispisivao niz+i-ti clan(posto je i vec doseglo neku vrijednost, i onda se ne bi clanovi niza1 ispisivali od pocetka). - broj2 vraca niz1 da se ispisuje od prvog clana, jer je i vec poraslo dok se ispisivao niz2*/
			*(niz+i) = *(niz1-broj2+i);
	}
}

int main()
{
	float A[100];
	int i,k;
	int velicinaA;

	printf("Unesi velicinu niza A:\n");
	scanf("%d",&velicinaA);

	printf("Unesi niz A:\n");
	for(i=0; i<velicinaA; i++) {
		scanf("%f", &A[i]);
	}

	printf("Unesi k: ");
	scanf("%d",&k);

	preslozi(A,velicinaA,k);

	printf("Niz glasi: ");
	for(i=0; i<velicinaA; i++)
		printf("%g ",A[i]);

	return 0;
}
