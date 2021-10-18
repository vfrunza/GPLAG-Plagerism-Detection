#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz1[],int vel1,int niz2[],int vel2)
{
	int i,j,cifre,broj=0,predznak=0;
	for(i=0; i<vel2; i++) {
		if(niz2[i]<0 || niz2[i]>9) return 0;
		for(j=i+1; j<vel2; j++) {
			if(niz2[i]==niz2[j]) return 0;
		}
	}
	for(i=0; i<vel1; i++) {
		if(niz1[i]<0) predznak=1;
		cifre=fabs(niz1[i]);
		niz1[i]=0;
		while(cifre!=0) {
			broj=broj*10+cifre%10;
			for(j=0; j<vel2; j++) {
				if((broj%10)==niz2[j]) broj/=10;
			}
			cifre/=10;
		}
		while(broj!=0) {
			niz1[i]=niz1[i]*10+broj%10;
			broj/=10;
		}
		if(predznak) niz1[i]=-niz1[i];
		predznak=0;
	}
	return 1;
}

int main()
{

	return 0;
}
