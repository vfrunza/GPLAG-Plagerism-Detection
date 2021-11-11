#include <stdio.h>
#include <math.h>
int izbaci_cifre(int* niz1, int vel1, int* niz2, int vel2)
{
	int i,j,logicki=1;
	int broj,brojac=1,temp=0,br;
	//ispitivnje ispravnosti drugog niz tj. da li je on niz medjusobno razlicitih cifara 0-9
	//u slucaju da nije funckija vraca 0
	for(i=0; i<vel2; i++) {
		for(j=0; j<vel2; j++) {
			if(*(niz2+i)==*(niz2+j) && i!=j) {
				logicki=0;
				break;
			}
		}
		if(logicki!=0) {
			// provjera da li je broja manji od 0 ili veci od 9
			if(*(niz2+i)<0 || *(niz2+i)>9 ) {
				logicki=0;
				break;
			} else {
				logicki=1;
			}
		} else break;
	}
	if(logicki!=0) {
		for(j=0; j<vel2; j++) {
			br=*(niz2+j);
			for(i=0; i<vel1; i++) {
				broj=fabs(*(niz1+i));
				brojac=1;
				temp=0;
				do {
					if(broj%10!=br) {
						//ako broj nije jednak trazenom zadnja cifra *brojac
						//brojac se uvecama takozvanim deseticama(1,10,100,...)
						temp+=((broj%10)*brojac);
						brojac*=10;
					}
					broj/=10;
				} while(broj>0);

				if(broj==0 && temp==0) *(niz1+i)=0;
				else {
					//posto je koristena apsolutna vrijednost broja broj treba vratiti
					//u prvobitan oblik tj ako je bio negativan da opet bude
					if(*(niz1+i)<0) temp*=-1;
					*(niz1+i)=temp;

				}
			}
		}
	}
	return logicki;
}
int main()
{
	int niz1[5]= {234,206,35678,91134,123};
	int niz2[5]= {1,9,8,4,5};
	int i;
	int a=izbaci_cifre(niz1,5,niz2,5);
	if (a!=0) printf("Izbacivanje je bilo uspjesno! ");
	else printf("Izbacivanje nije bilo uspjesno");
	for(i=0; i<5; i++) {
		printf("%d ",niz1[i]);
	}
	return 0;
}
