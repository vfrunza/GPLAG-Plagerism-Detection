#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void izbaci_cifru(int *n, int cif){
	int cifra=abs((*n)), ntemp=0, cifratemp, pot, i=0, predznak;
	
	if((*n)>=0)
	predznak=1;
	else
	predznak=-1;
	
	while(cifra!=0){
		cifratemp=cifra%10;
		
		if(cifratemp!=cif){
			i++;
			pot=(int)(pow(10,i));
			ntemp=ntemp+cifratemp*pot;
		}
		cifra/=10;
	}
	ntemp/=10;
	(*n)=ntemp*predznak;
}

int izbaci_cifre(int niz1[], int n1, int niz2[], int n2){
	int i, j;
	
	for(i=0; i<n2; i++){
		if(niz2[i]<0 || niz2[i]>9)
		return 0;
		
		for(j=0; j<i; j++){
			if(niz2[j]==niz2[i])
			return 0;
		}
	}
	
	for(i=0; i<n1; i++){
		for(j=0; j<n2; j++)
		izbaci_cifru(&niz1[i], niz2[j]);
	}
	return 1;
}

int main() {

	return 0;
}
