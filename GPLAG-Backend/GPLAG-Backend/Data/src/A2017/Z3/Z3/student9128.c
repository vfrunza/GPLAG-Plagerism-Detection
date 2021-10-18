#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ukloni_sastavi(int x, int cifra) {
	int i=0, niz_cifri[20]={0}, brojac=0, j, negativan=0;
	
	//da li je broj negativan
	
	if(x>=0) negativan=0;
	else negativan=1;
	
	x=abs(x); 
	
	while(x!=0) {
		niz_cifri[i]=x%10;
		i++;
		x/=10;
	}
	brojac=i;
	
	for(i=0; i<brojac; i++) {
		if(niz_cifri[i]==cifra) {
			for(j=i; j<brojac-1; j++) {
				niz_cifri[j]=niz_cifri[j+1];
			}
			brojac--;
			i--;
		}
	}
	x=0;
	for(i=brojac-1; i>=0; i--) {
		x=10*x+niz_cifri[i];
	}

	if(negativan==1) return (x*(-1));
	return x;
}



int izbaci_cifre(int *niz, int vel1, int *niz_cifri, int vel2) {
	int i, j, temp;
	
	//provjeravanje niza cifri
	
	for(i=0; i<vel2; i++) {
		if(niz_cifri[i]<0 || niz_cifri[i]>9) return 0;
	}
	
	for(i=0; i<vel2; i++) {
		for(j=i+1; j<vel2; j++) {
			if(niz_cifri[j]==niz_cifri[i]) return 0;
		}
	}
	
	// rastavljanje broja i provjera da li su cifre jednake
	
	for(i=0; i<vel1; i++) {
		temp=(niz[i]);
		for(j=0; j<vel2; j++) {
			while(temp!=0) {
				if((abs(temp)%10)==niz_cifri[j]) {
					niz[i]=ukloni_sastavi(niz[i], niz_cifri[j]);
				}
				temp/=10;
			}
			temp=(niz[i]);
		}
	}
	return 1;
}


int main() {
	int vel1, niz[100]={0}, niz_cifri[100]={0}, vel2, i, *p;
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel1);
	
	printf("Unesite niz: ");
	for(i=0; i<vel1; i++) {
		scanf("%d", &niz[i]);
	}
	
	printf("Unesite velicinu niza cifri: ");
	scanf("%d", &vel2);
	
	printf("Unesite niz cifri: ");
	for(i=0; i<vel2; i++) {
		scanf("%d", &niz_cifri[i]);
	}
	
	p=izbaci_cifre(niz, vel1, niz_cifri, vel2);
	for(i=0; i<vel1; i++) {
		printf("\n%d", niz[i]);
	}
	return 0;
}
