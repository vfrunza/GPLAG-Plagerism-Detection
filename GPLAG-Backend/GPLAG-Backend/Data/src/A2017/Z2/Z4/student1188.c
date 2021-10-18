#include <stdio.h>
#define STOTINA 100

int koliko(int broj, int M, int N, int mat[][STOTINA]){
	int i, j;
	int brojac=0;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(mat[i][j]==broj) brojac++;
		}
	}
	return brojac;
}

int main() {
	int yor=1;/*yes or no*/
	int pronadjen_isti=0; /*znači došli smo do kraja a nismo našli isti element u matrici*/
	int M, N;
	int i, j, k, l;
	int a[STOTINA][STOTINA], b[STOTINA][STOTINA], c[STOTINA][STOTINA];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M, &N);
	}while(M<0 || N<0 || M>100 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)	scanf("%d", &a[i][j]);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)	scanf("%d", &b[i][j]); 
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)	scanf("%d", &c[i][j]);
	
	for(k=0; k<M; k++){
		for(l=0; l<N; l++){
			for(i=0; i<M; i++){
				for(j=0; j<N; j++){
					if(a[i][j]==b[k][l]){
						pronadjen_isti=1;
						if( koliko(a[i][j], M, N, a) != koliko(b[k][l], M, N, b)  ) { 
							yor=0; 
							break;
						}
					}
					if(k==M-1 && l==N-1 && pronadjen_isti==0 && k==i && l==j){
						yor=0;
						break;
					}
				}
			}
			if(yor==0) break;
		}
		if(yor==0) break;
	}

	pronadjen_isti=0;
	if(yor){
		for(k=0; k<M; k++){
			for(l=0; l<N; l++){
				for(i=0; i<M; i++){
					for(j=0; j<N; j++){
						if(a[i][j]==c[k][l]){
							pronadjen_isti=1;
							if( koliko(a[i][j], M, N, a) != koliko(c[k][l], M, N, c) ){
								yor=0;
								break;
							}
						}
					    if(k==M-1 && l==N-1  && pronadjen_isti==0 && k==i && l==j)/*na kraju smo a nismo našli isti element*/ {
					    	yor=0;
					    	break;
					    }
					}
				}
				if(!yor) break;
			}
			if(!yor) break;
		}
	}
	
	if(yor) printf("DA\n");
	else printf("NE\n");
	return 0;
}
