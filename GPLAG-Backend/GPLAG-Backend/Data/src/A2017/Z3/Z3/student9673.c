#include <stdio.h>
#include <math.h>

int izbaci_cifre(int* niz1, int vel_niz1, int* niz2, int vel_niz2)
{



	int i,j;
	int temp, cifra;
	int k=0,brojac=0;
	int znak;

	for(i=0; i<vel_niz2; i++) {
		if(niz2[i]>9 || niz2[i]<0)				/*...Provjeravamo ispravnost niza cifara...*/
			return 0;
	}

	for(i=0; i<vel_niz2-1; i++) {
		for(j=i+1; j<vel_niz2; j++) {			/*...Provjeravamo da li se neki clanovi niza ponavljaju...*/
			if(niz2[i]==niz2[j]) {
				return 0;
			}
		}
	}



	for(i=0; i<vel_niz1; i++) {

		znak=0;
		k=0;
		brojac=0;

		if(niz1[i]>0) znak=1;					/*...Pamtimo znak clana niza...*/
		if(niz1[i]<0) znak=-1;



		temp=fabs(niz1[i]);



		niz1[i]=0;

		while(temp!=0) {
			brojac=0;

			cifra=temp%10;

			temp=temp/10;



			for(j=0; j<vel_niz2; j++) {
				if(cifra!=niz2[j]) {			/*...Provjeravamo da li se neka cifra niza ne pojavljuje u nizu cifara...*/
					brojac++;

				}
			}

			if(brojac==vel_niz2) {
				niz1[i]=niz1[i]+cifra*pow(10,k);		/*...Ako se ne pojavljuje, "vracamo" je na odgovarajuce mjesto...*/
				k++;
			}

		}
		niz1[i]*=znak;							/*...Clanu niza dodjeljujemo odgovarajuci predznak...*/
	}


	return 1;

}

int main()
{

	return 0;

}
