#include <stdio.h>

int obrni(int broj)
{
	int cifra,nova=0;
	while(broj>0) {
		cifra=broj%10;
		nova=nova*10+cifra;
		broj/=10;
	}
	return nova;
}

int izbaci_cifre(int *nizbr, int vel1, int *nizc, int vel2)
{
	int i,j,temp,nova=0,cifra=0,predznak;

	for(i=0; i<vel1; i++) {
		temp=nizbr[i];
		if(temp>0) predznak=1;
		else {
			predznak=-1;
			temp*=predznak;
		}
		if(vel2==0) nova=temp;
		for(j=0; j<vel2; j++) {

			cifra=0;
			nova=0;
			while(temp!=0) {
				cifra=temp%10;
				if(cifra!=nizc[j]) nova=nova*10+cifra;
				temp/=10;
			}
			temp=nova;
		}
		if(vel2%2!=0) nova=obrni(nova);
		nova*=predznak;
		nizbr[i]=nova;

	}

	for (i=0; i<vel2; i++) {
		for (j=i+1; j<vel2; j++)
			if (nizc[i]==nizc[j])
				return 0;
		if (nizc[i]>9 || nizc[i]<0)
			return 0;
	}
	return 1;

}

int main()
{
	return 0;
}
