#include <stdio.h>

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{

	int i, cifra, j, broj, novi_broj, temp=0, t, brojaci[101]= {0};
  /*provjeravam da li je niz cifara ispravan */
	for(i=0; i<vel2; i++) {
		if(niz2[i]<0 || niz2[i] >9)
			return 0;
	}
	for(i=0; i<vel2; i++) {
		brojaci[niz2[i]]++;
	}
	for(i=0; i<vel2; i++) {
		if( brojaci[i]>1 )
			return 0;
	}
   /* dvostruka petlja koja poredi cifre niza2 sa brojevima niza1*/
	for(i=0; i<vel2; i++) {
		cifra=niz2[i];
		for(j=0; j<vel1; j++) {
			broj=niz1[j];
			t=1;
			novi_broj=0;
			/*za negativne brojeve*/
			if(broj<0) {
				broj=-broj;
       /* prolazim kroz cifre broja, ako broj ne sadrzi cifru zadrzavam ga,a ako sadrzi cifru izbacujem je*/
				while(broj!=0) {
					temp=broj%10;
					broj/=10;
					if(temp!=cifra) {
						novi_broj=novi_broj+temp*t;
						t=t*10;
					}
				}
				niz1[j]=-novi_broj;
			} /*za pozitivne brojeve*/
			else {
				while(broj!=0) {
					temp=broj%10;
					broj/=10;
					if(temp!=cifra) {
						novi_broj=novi_broj+temp*t;
						t=t*10;
					}
				}
				niz1[j]=novi_broj;
			}
		}
	}
	return 1;
}
int main()
{

	int niz1[100], niz2[100], i, n1, n2;

	printf("Niz1:");
	for(i=0; i<100; i++)
		scanf("%d", &niz1[i]);
	n1=i;

	printf("Niz2:");
	for(i=0; i<100; i++)
		scanf("%d", &niz2[i]);
	n2=i;

	izbaci_cifre(niz1,n1,niz2,n2);

	return 0;
}
