#include <stdio.h>
#include <math.h>
#define EPS 0.00000001

int suma(int n){
	int suma=0;
	int cifra,pom;
	if(n < 0) {
		pom=fabs(n);
		while(pom>0) {
			cifra=pom%10;
			suma+=cifra;
			pom/=10;
		}
	}
	else{
	while(n>0){
			cifra=n%10;
			suma+=cifra;
			n/=10;
		}
	}
	return suma;
 }

void ubaci(int niz[], int vel){
	int i;

	int suma1=0;
	int pomocni[100];
	for(i=0;i<vel;i++){
		pomocni[i*2]=niz[i];
	}
	for(i=0;i<vel;i++){
		suma1=suma(niz[i]);
	   pomocni[i*2+1]=suma1;
	}
	vel=vel*2;
	for(i=0;i<vel;i++){
		niz[i]=pomocni[i];
	}
}

int izbaci(int niz[], int vel){
	int i,j,k;
	int niz1[50];
	niz1[0]=1;
	niz1[1]=1;
	for(k=2;k<50;k++){
		niz1[k]=niz1[k-1]+niz1[k-2];
	}
	
	for(i=0;i<vel;i++){
		for(j=0;j<49;j++){
			
		     if(fabs(niz[i] - niz1[j])<EPS)  
		{
			
			for(k=i;k<vel-1;k++){
				niz[k]=niz[k+1];
			}
			vel--;
			i--;
			break;
			}
		}
	}
	return vel;
}

int main() {
	int i;
	int k;
	int niz[20];	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d ", &niz[i]);
	}
	
	ubaci(niz,10);
	k=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<k;i++){
	  if(i< k-1)printf("%d, ", niz[i]);
	  else printf("%d.", niz[i]);
	}

	return 0;
}
