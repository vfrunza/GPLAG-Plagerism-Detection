#include <stdio.h>
	int suma_cifri(int broj){
	int cifra;
	int suma=0;
	if(broj<0) broj=0-broj;
	while(broj>0){
		cifra=broj%10;
		broj=broj/10;
		suma=suma+cifra;
	}
	return suma;
 	}
 	
void ubaci(int *p,int velicina){
	int suma=0;
	int i,k,j;
	int cifra;
	int broj2;
	int temp;
	int pom;
	int niz2[5];
	int *pomocni_pointer;
	int *p2;
	
	pomocni_pointer=p;
	for(i=0; i<velicina*2-1; i++){
		*pomocni_pointer++;
	}
	for(i=0; i<velicina; i++){
		broj2=*p;
		suma=suma_cifri(broj2);
		p2=pomocni_pointer;
		while (p2>=p+1){
			*p2=*(p2-1);
			*p2--;
		}
		*p++;
		*p=suma;
		*p++;
	}
}
	
	int  izbaci(int  *p,int velicina){
	int fibonacijev[200];
	int i,k,j;
	int fibonacijev_broj;
	int broj2;
	int *p2;
	int pom;
	int *p3;
	fibonacijev[0]=1;
	fibonacijev[1]=1;
	
	for(i=2; i<200; i++){
		fibonacijev[i]=fibonacijev[i-1]+fibonacijev[i-2];
	}	
	
	for(i=0; i<velicina; i++){
		broj2=*p;
		fibonacijev_broj=0;
		for(j=0; j<200; j++){
			if(broj2==fibonacijev[j]){
				fibonacijev_broj=1;
			}
		}
		if(fibonacijev_broj==1){
			p2=p;
			p3=p;
			p3++;
			for(j=i; j<(velicina-1); j++){
				*p2=*p3;
				*p2++;
				*p3++;
			}
			i--;
			velicina--;
		}
		else {
			*p++;
		}
	}
	return velicina;
	}
	
int main() {
	int velicina=10;
	int niz[20];
	int i;
	printf("Unesite niz od 10 brojeva:");
	for(i=0; i<velicina; i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(&niz,velicina);
	velicina=20;
	velicina=izbaci(&niz,velicina);
	printf(" Modificirani niz glasi:");
	for(i=0; i<velicina; i++){
		if(i!=velicina-1) {
			printf(" %d,",niz[i]);
		}
		else {
			printf(" %d.",niz[i]);
		}
	}
	return 0;
}
