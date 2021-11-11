#include <stdio.h>
int niz1[10]={0}, niz2[10]={0},  i, j, n, k, brojac, temp, isti_j=0, isti_i=0;

int main() {
	do {
	printf("Unesite broj tacaka: ");
	scanf("%i", &n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
	}while(n<=0 || n>10);
	
	for(i=0; i<n; i++){
	
			
			printf("Unesite %i. tacku: ", i+1);
			scanf("%d %d", &niz1[i], &niz2[i]);
			
			
				if(niz1[i]>19 || niz1[i]<0 || niz2[i]>19 || niz2[i]<0) {printf("Pogresan unos\n"); i--;}
		
		}

for(i=0; i<n; i++){
	for(j=i+1; j<n; j++){
		if(niz1[i]==niz1[j] && niz2[i]==niz2[j]){
			niz1[j]=niz1[n-1];
			niz2[j]=niz2[n-1];
			n--;
			j--;
		}
	}
}
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			k=1;
			
			for(brojac=0; brojac<n; brojac++){
				if(j== niz1[brojac] && i==niz2[brojac]){printf("*"); k=0;}
			}
		 if(k != 0) printf(" ");
		 	} 
		 	printf("\n");
	}
	return 0;
}
	
