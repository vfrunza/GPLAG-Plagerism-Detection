#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	
	int ponavljanja[20000];
	int i, j, q;
	int gdje;
	int granica = 0;
	
	for(i=0; i<20000; i++) 
		ponavljanja[i] = 1;
	
	
	for(i=0; i<visina; i++) {
		
		for(j=0; j<sirina; j++) {
			
			for(q=0; q<granica; q++) 
				
				if(ponavljanja[q] == matrica[i][j]) break;
				
				if(q==granica)	ponavljanja[granica++] = matrica[i][j];
				
				else ponavljanja [q+10000]++;
			
		}
	}
		
	gdje = 0;
		
	for(i=10000; i<(10000+granica); i++) {
			
		if(ponavljanja[i] > ponavljanja[gdje+10000] || (ponavljanja[i] == ponavljanja[gdje+10000] && ponavljanja[i-10000] < ponavljanja[gdje])) {
				
				gdje = i-10000;
				
		}
	}

	return ponavljanja[gdje];
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	
	int i, j, p, q;
	int broj_izbacenih = 0;
	int broj_kolona = sirina;
	
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			
			if(matrica[i][j] == n) {
				
				for(p=0; p<visina; p++) 
					
					for(q=j; q<sirina-1; q++) 
						
						matrica[p][q] = matrica[p][q+1];
						broj_izbacenih++;
						sirina--;
						
						if(matrica[i][j] == n) 	j--;
					
			}
		}
		
	}
	
	return broj_kolona-broj_izbacenih;
}

int main() {
	
	int i, j;
	int brojac = 1;
	int mat[100][100];
	int S, H;
	int pomocni_max;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d", &S);
	scanf("%d", &H);
	
	for(i=1; i<=H; i++) {
		
		printf("Unesite elemente %d. reda: ", i);
		
		for(j=0; j<S; j++) {
			
			scanf("%d", &mat[i-1][j]);
		}
		
	}
	
	while(1) {
		
		pomocni_max = max(mat, H, S);
		S = izbaci_kolone(mat, H, S, pomocni_max);
		
		if(!S) {
			
			printf("\n");
			printf("Nakon %d. prolaza matrica je prazna!", brojac);
			return 0;
			
		}
		
		printf("\n");
		printf("Nakon %d. prolaza matrica glasi:", brojac);
		printf("\n");
		brojac++;
		
		for(i=0; i<H; i++) {
			
			for(j=0; j<S; j++) {
				
				printf("%5d", mat[i][j]);
				
			}
			
				printf("\n");
		}
		
	}
	
	return 0;
}
