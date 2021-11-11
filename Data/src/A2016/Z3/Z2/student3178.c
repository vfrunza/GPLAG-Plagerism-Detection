#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BROJ_ELE 100


    
void ubaci(int* niz, int vel){
	int i=0, j;
	int suma=0;
	int kopija=0;
	for (i=0; i<vel; i++){
        suma=0;
        if (i%2!=0){
        vel++;
            for (j=vel-1; j>i; j--){
            niz[j]=niz[j-1];
        }
        kopija=niz[i-1];
        while (kopija!=0){
            suma+=kopija%10;
            kopija/=10;
        }
        suma=fabs(suma);
        niz[i]= suma;
        }
    }	
	}


int DaLiJeFibonacci(int n){
	int fib_niz[37]; int i=0; int j=1; int m=0; int k;
	fib_niz[0]=1;
	fib_niz[1]=1;
	for(m=2; m<37; m++){
		fib_niz[m]=fib_niz[i] + fib_niz[j];
		i++; j++;
	}
	
	for(k=0; k<37; k++){
		if(n==fib_niz[k])
		return 1;
	}
	
	return 0;
	}

int izbaci(int* niz, int vel){
	int i,j;
	for(i=0; i<vel; i++){
		if(DaLiJeFibonacci(niz[i])==1){
			for(j=i; j<vel-1; j++){
		niz[j]=niz[j+1];}
		vel--;
		i--;
		}
	}
	return vel;
    }


  
int main() {
	
	
int niz[100];
int i, vel=0;
int vel2;
int vel_pomocna;


printf("Unesite niz od 10 brojeva: ");
for(i=0; i<10; i++){
	scanf("%d", &niz[i]);
	vel++;
}


vel_pomocna= 2*vel;
ubaci(niz, vel_pomocna);
vel2=izbaci(niz, vel_pomocna); 


printf("Modificirani niz glasi: ");

for(i=0; i<vel2; i++){
	printf("%d", niz[i]);
		if(i==vel2-1)
	printf(".");
	else
	printf(", ");
}
	return 0;
}



