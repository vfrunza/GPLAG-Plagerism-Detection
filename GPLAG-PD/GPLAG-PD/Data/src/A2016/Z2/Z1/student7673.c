#include <stdio.h>

int main() {
	int n,k=1,pom1,pom2,suma=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0)
	n=-n;
	if(n<10){
	printf("%d",0);
	return 0;}
	while(n>10){
		pom1=n%10;
		n/=10;
		pom2=n%10;
		pom1=pom1-pom2;
		if(pom1<0) pom1=-pom1;
		suma=suma+pom1*k;
		k=k*10;
		
	}
	
	
	
	
	
	
	
	printf("%d",suma);
	return 0;
}
