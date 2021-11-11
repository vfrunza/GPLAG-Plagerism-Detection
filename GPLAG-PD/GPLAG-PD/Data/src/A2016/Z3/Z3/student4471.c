#include <stdio.h>

int main() {
	
	int M,N,i,j,k,l,d,g,niz[200][200], sviredovijednaki = 1,svekolonejednake = 1;
	
	do{
	   printf("Unesite brojeve M i N: ");
	   
	   scanf("%d %d",&M,&N);
	   
	   if(M<=0 || M>200 || N<=0 || N>200){
	       printf("Brojevi nisu u trazenom opsegu.\n");
	       
	   }
	}while(M<=0 || M>200 || N<=0 || N>200);
	
	//SKENIRANJE MATRICE 
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++){
		
	    for(j=0;j<N;j++){
	    	
	        scanf("%d",&niz[i][j]);
	        
	    }
	}
	
	//PRVO IZBACUJEMO ISTE REDOVE 
	for(g=0; g<M; g++){
		
		for(i=0;i<M;i++){
			
			for(j=0;j<M;j++){
				
				sviredovijednaki = 1;
				
				if(j == i){
					
					continue;
					
				}else {
					
					for(k=0;k<N;k++){
						
						if(niz[i][k] != niz[j][k]){
							
							sviredovijednaki = 0;
							
							break;
						}
					}
					
					if(sviredovijednaki == 1){
						
						for(l=j;l<M;l++){
							
							for(d=0;d<N;d++){
								
								niz[l][d] = niz[l+1][d];
							}
						}
						
						j--;
						M--;
					}
				}
			}
		}
	}
	
	
	//SADA IZBACUJEMO ISTE KOLONE 
	
	for(g=0; g<N; g++){
		
		for(i=0;i<N;i++){
			
			for(j=0;j<N;j++){
				
				svekolonejednake = 1;
				//OVIM USLOVOM OBEZBJEDUJEMO DA PETLJA NE POREDI KOLONU SAMU SA SOBOM I DA SE ISPUNI USLOV PA DA JE IZBACI ...
				if(j == i){
					
					continue;
					
				}else {
					
					for(k=0;k<M;k++){
						
						if(niz[k][i] != niz[k][j]){
							
							svekolonejednake = 0;
							
							break;
						}
					}
					
					if(svekolonejednake == 1){
						
						for(l=j;l<N;l++){
							
							for(d=0;d<M;d++){
								
								niz[d][l] = niz[d][l+1];
							}
						}
						
						j--;
						N--;
					}
				}
			}
		}
	}
	
	
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	for(i=0;i<M;i++){
		
		for(j=0;j<N;j++){
			
			printf("%5d",niz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
