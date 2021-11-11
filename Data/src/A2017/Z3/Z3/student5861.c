#include <stdio.h>

int okreni_cifre(int broj)
{
	int cifra;
	int nova=0;
	while(broj>0) {
		cifra=broj%10;
		nova=nova*10+cifra;
		broj=broj/10;
	}
	return nova;
}

int izbaci_cifre(int* niz1, int velicina1, int* niz2, int velicina2)
{
	int i, j, temp, predznak, nova=0, cifra=0;

	for(i=0; i<velicina1; i++) {
		temp=niz1[i];
		if (temp>0) {
			predznak=1;
		} else {
			predznak=-1;
			temp=temp*predznak;
		}

		if (velicina2==0) {
			nova=temp;
		}

		for(j=0; j<velicina2; j++) {

			cifra=0;
			nova=0;
			while(temp!=0) {
				cifra=temp%10;
				if(cifra!=niz2[j]) nova=nova*10+cifra;
				temp=temp/10;
			}
			temp=nova;
		}
		if(velicina2%2!=0) nova=okreni_cifre(nova);
		nova=nova*predznak;
		niz1[i]=nova;

	}


	for(i=0; i<velicina2; i++) {
		for(j=i+1; j<velicina2; j++) 
			if(niz2[i]==niz2[j])
				return 0;
			if(niz2[i]>9 || niz2[i]<0)
				return 0;
		
	}
	return 1;


}


int main()
{

	return 0;
}
