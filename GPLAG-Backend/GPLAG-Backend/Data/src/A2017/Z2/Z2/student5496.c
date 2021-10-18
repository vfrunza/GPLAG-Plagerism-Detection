#include <stdio.h>
#define max_el 100
#define max_el2 1000
int main() {
	int vel_niza, i, c, br_cifara=0, s=0, x, x1, c1, j=0,brojac=0,broj; 
	int niz1[max_el], niz2[max_el2], niz3[max_el2];
	printf("Unesite velicinu niza: ");
	do{
		scanf("%d", &vel_niza);
	} while(vel_niza<0 && vel_niza<100);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel_niza; i++){
		scanf("%d", &niz1[i]);
	}
	
	for(i=0; i<vel_niza; i++){
		x=niz1[i];
		if(x==0) {
			niz1[i]=0; 
			continue;}
	    while(x!=0){
			c=x%10;
			s=s*10+c;
			x/=10;
		}
		niz1[i]=s;
		s=0;
	}
	niz1[vel_niza]=-1;
	
	/* Neprekinuti niz cifara*/
	for(i=0; i<=vel_niza; i++){
		x1=niz1[i];
		if(x1==0) {
			niz2[br_cifara]=0;
			br_cifara++;
			continue;
		}
		while(x1!=0){
			c1=x1%10;
			niz2[br_cifara]=c1;
			br_cifara++;
			x1/=10;
	    }
	}
	for(i=0; i<br_cifara; i++){
		broj=niz2[i]; 
		brojac=0;
		if(broj==-1) break;
		while(broj==niz2[i] && i<br_cifara){
			brojac++; i++;
		}
		niz3[j]=broj;
		j++;
		niz3[j]=brojac;
		j++;
		i--;
	}
	printf("Finalni niz glasi:\n");
	for(i=0; i<j; i++){
		printf("%d ", niz3[i]);
	}
	return 0;
}