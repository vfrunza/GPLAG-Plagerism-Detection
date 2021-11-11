#include <stdio.h>
#include <math.h>
int main() {
	int br,pom1,pom2,brojac=0,n=0,brojacbroja=0,m, pomocna;

	printf("Unesite broj: ");
	scanf("%d",&br);
	pomocna=br;
	while(pomocna!=0){
		pomocna=pomocna/10;
		brojacbroja++;
	}
	
	
	if(br<0){
		br=-br;
	}
	if(br<10){
		n=0;
		
	}
	else{
while(br!=0 && brojacbroja>1){

	pom1=br%10;
	br=br/10;
	pom2=pom1;
	pom1=br%10;

m=pom2-pom1;
if(m<0){
	m=-m;}

		n=m*pow(10,brojac)+n;
	
	brojacbroja--;
	brojac++;
	
	
}}


printf("%d",n);
	return 0;
}
