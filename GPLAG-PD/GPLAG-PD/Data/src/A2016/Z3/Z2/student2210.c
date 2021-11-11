#include <stdio.h>
#include <math.h>
void ubaci(int *niz, int vel) {
     int i,j,suma=0,x,cifre;
     int pom_niz[20];
     x=vel/2;
     for(i=0;i<20;i++){
     	pom_niz[i]=niz[i];
     }
     for(i=0;i<x;i++){
     niz[2*i]=pom_niz[i];
     }
     for(i=0;i<vel;i+=2){
     	j=niz[i];
     	if(j<0)
     	j*=-1;
     	while(j!=0){
     		cifre=j%10;
     		suma+=cifre;
     		j/=10;
     	}
     	niz[i+1]=suma;
     	suma=0;
     }
}
     
int izbaci(int *niz, int vel){
	int i,j,k, fib[100]={1,1};
	for(i=2;i<100;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(i=0;i<vel;i++) {
		for(j=0; j<100; j++) {
			if(niz[i]==fib[j]){ 
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
	int i, vel=20;;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
		scanf("%d", &niz[i]);
	ubaci(niz,vel);
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi:");
	for(i=0;i<vel;i++){
		printf(" %d",niz[i]);
		if(i<vel-1) printf(",");
		if(i==vel-1) printf(".");
	}
	
	return 0;
}