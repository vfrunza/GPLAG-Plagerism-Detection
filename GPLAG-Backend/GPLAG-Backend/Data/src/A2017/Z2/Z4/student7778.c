#include <stdio.h>

int main() {
	int A[100][100], B[100][100], C[100][100];
	int niz[10000], niz1[10000], niz2[10000];
	int M, N;
	do{
		printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	
		}while (M<0 || M>100 || N<0 || N>100);	
	
	int i,j;
	int q=0;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			int element;
			scanf("%d", &element);
			A[i][j]=element;
			niz[q]=element;
			q++;
		}
	}
	
	q=0;
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			int element;
			scanf("%d", &element);
			B[i][j]=element;
			niz1[q]=element;
			q++;
		}
	}
	
	q=0;
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			int element;
			scanf("%d", &element);
			C[i][j]=element;
			niz2[q]=element;
			q++;
			
		}
	}
	
	for(i=0;i<M*N;i++){
		for(j=0;j<M*N;j++){
			if(niz[i]==niz1[j]){
			niz1[j]=-99999;
			break;
			}
		
		}
		
		
	}

	for(i=0;i<M*N;i++){
		for(j=0;j<M*N;j++){
			if(niz[i]==niz2[j]){
			niz2[j]=-99999;
			break;
			} 
			
		}
			
		
	}
	for(i=0;i<M*N;i++){
		if(niz1[i]!= -99999 || niz2[i]!=-99999){printf("NE\n"); return 0;}

		
	}
	printf("DA\n");
	return 0;
}