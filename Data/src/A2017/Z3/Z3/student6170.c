#include <stdio.h>
#include <math.h>

int izbaci_cifre(int niz1[],int vel1,int niz2[],int vel2) {
	int i,j;
	for(i=0;i<vel2;i++) {
	  if(niz2[i]<0 || niz2[i]>9)	return 0;
	  for(j=i+1;j<vel2;j++) {
	  	if(niz2[i]==niz2[j]) return 0;
	  }
	}
	for(i=0;i<vel1;i++) {
		int broj=0;
		int k=0;
		int predznak=1;
		if (niz1 [i]<0) predznak=-1;
		while(niz1[i]!=0) {
			int cifra=fabs(niz1[i]%10);
			int ima=0;
			for(j=0;j<vel2;j++) {
				if(niz2[j]==cifra) ima=1;
			}
			if(ima!=1) {
			broj+=cifra*pow(10,k);
			k++;
			}
			niz1[i]/=10;
		}
		niz1[i]=broj*predznak;
	}
	return 1;
	
}
int main() {
/*	printf("Zadaća 3, Zadatak 3");*/
	return 0;
}
