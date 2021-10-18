#include <stdio.h>
#include <math.h>

int main() {
	
	int A[100], B[1000], C[10000];
	int velicina, i, j, temp=0, br_cifara=0, br=0, cifra=0, mjesto=0, brojac=0;
	
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &velicina);
	}
	while(velicina<1);
	
	printf("Unesite clanove niza: ");
	
	for(i=0; i<velicina; i++) {
		scanf("%d", &A[i]);
		if(A[i]<0) i--;
	}
	
	
	for(i=0; i<velicina; i++) {
		
		temp=A[i];
		br_cifara=0;
		
		for(;;) {
			if(temp/10!=0) {
			br_cifara++;
			temp/=10;
			}
			else {
				br_cifara++;
				break;
			}
		}
		
		cifra=0;
		
		temp=A[i];
		for(j=br_cifara-1; j>=0; j--) {
			temp=temp-cifra*pow(10,j+1);
			cifra=temp/pow(10, j);
			C[br]=cifra;
			br++;
		}
	}
	
	mjesto=0;
	for(i=0; i<br; i++) {
		brojac=0;
		temp=C[i];
		if(i!=br-1) {
			if(C[i]==C[i+1] && i!=br-1) {
				for(j=i; j<br; j++) {
					if(C[i]==C[j]) brojac++;
					else break;
				}
			
			}
			
			else brojac++;
		}
		
		else brojac++;
		
		if(brojac!=0) {
			B[mjesto]=temp;
			B[mjesto+1]=brojac;
			mjesto+=2;
		}
		
		i=i+brojac-1;
		
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<mjesto; i++) {
		printf("%d ", B[i]);
	}
	return 0;
}
