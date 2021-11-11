#include <stdio.h>
#include<math.h>

int main() {
	int M, N, i, j, u, k, p, y;
	double mat[100][100], niz[100], nizprosli[100], kraj;
	int NijeTep=0, NijeCirk=0;
	do{
		
		u=1;
		printf("Unesite M i N: ");
		scanf("%d%d", &M, &N);
		if(M>100 || M<=0 || N>100 || N<=0) {u=0; printf("Pogresan unos!\n");}
	}while(u==0);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
			
		}}
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(j==0)y=0;
				niz[y]=mat[i][j];
				y++;
				
			}
			if(y==N)break;
		}
	
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++,p++){
        if(j==0)p=0; 
		if(fabs(mat[i][j]-niz[p])>0.001) { NijeCirk=1;break;}
		
	}
		
		for(k=0;k<N;k++){
			nizprosli[k]=niz[k];}
			
			for(k=0;k<N;k++){
			kraj=niz[N-1];}
		for(k=0;k<N;k++){
			if(k>0) { niz[k]=nizprosli[k-1];}
			
		}
		for(k=0;k<N;k++){
			niz[0]=kraj;
			
		}
		
	}
	
	if(NijeCirk==0) {printf("Matrica je cirkularna"); return 0;}
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			 
            if(fabs(mat[i][j]-mat[i+1][j+1] )>0.001)
                    {NijeTep=1; break;}
    
		}
	}
	
		if(NijeTep==0 && NijeCirk==1) {printf("Matrica je Teplicova"); return 0;}
	
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	
	return 0;
}
