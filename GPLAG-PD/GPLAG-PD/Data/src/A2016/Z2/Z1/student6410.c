#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int n,i,brojac=0;
	int k,j,m;
	int krajnji=0;

	printf("Unesite broj: ");
	scanf("%d", &n);
	if (n>=0 && n<10) {printf("0"); return 0;}
	i=abs(n);
	while(i!=0){
	     k=i%10;
	     if(k>=0) brojac++;
	     i=i/10;
	}
	i=n/10; 
	for(j=0; j<brojac; j++){ 
	m=abs(n%10-i%10);
	i=i/10; 
	if(i==0) n=0;
	n=n/10;
	
	krajnji=krajnji+m*pow(10,j);
	}
	printf("%d", krajnji);
	return 0;
}
