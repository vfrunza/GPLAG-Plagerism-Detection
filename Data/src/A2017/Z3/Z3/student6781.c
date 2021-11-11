#include <stdio.h>
#include <math.h>
int  izbaci_cifre (int niz1[],int vel1,int niz2[],int vel2)
{
	int i,j,mult=0,sadrzi=0,suma=0;
	int temp,cifra;
	/*Provjera da li su clanovi drugog niza veci od 9 ili manji od 0.*/
	for (i=0; i<vel2; i++) {
		if (niz2[i]<0 || niz2[i]>9) {
			return 0;
		}

	}
	/*Provjera da li se clanovi drugog niza ponavljaju*/
	for (i=0; i<vel2; i++) {
		for (j=i+1; j<vel2; j++) {
			if (niz2[i]==niz2[j])
				return 0;
		}
	}
	/*Rastavljanje svakog clana niza na cifra,uz provjeru da li taj clan niza sadrzi cifru iz drugog niza,sto kontrolisemo uz pomoc logicke varijable.Ako elemnat niza sadrzi cifru,nju izbacujemo*/
	for (i=0; i<vel1; i++) {
		temp=niz1[i];
		if (temp<0)
			temp=-temp;
		while (temp>0) {
			cifra=temp%10;
			temp/=10;
			for (j=0; j<vel2; j++) {
				if (cifra==niz2[j]) {
					sadrzi=1;
					break;
				}

			}
			/*Nakon provjere da li element sadrzi odredjenu cifru,sastavljamo taj elemenat iz pocetka.*/
			if (sadrzi==0) {
				suma=suma+cifra*pow(10,mult);
				mult++;
			}
			sadrzi=0;
		}
		if (niz1[i]<0)
			suma=-suma;
		niz1[i]=suma;
		suma=0;
		mult=0;
	}
	return 1;

}

int main()
{
	int nizA[100],nizB[10];
	int i,vel1,vel2;
	printf ("Unesite dimenzije: ");
	scanf ("%d %d", &vel1,&vel2);

	printf ("Unesite prvi niz: \n");
	for (i=0; i<vel1; i++)
		scanf ("%d", &nizA[i]);

	printf ("Unesite drugi niz: ");
	for (i=0; i<vel2; i++)
		scanf ("%d", &nizB[i]);

	izbaci_cifre(nizA,vel1,nizB,vel2);
	printf ("Novi niz glasi: \n");
	for (i=0; i<vel1; i++)
		printf ("%d ",nizA[i]);
	return 0;
}
