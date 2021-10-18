#include <stdio.h>
#define eps 0.001
#include <math.h>

int main() {
	double matA[100][100], matB[100][100];
	int i,j,sA,vA,sB,vB, k=0;
	double temp,temp1;
	
	
	/* Matrica A */
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA,&vA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vA; i++){
		for(j=0; j<sA; j++){
			scanf("%lf", &matA[i][j]);
		}
	}
	
	/* Matrica B */
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB,&vB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vB; i++){
		for(j=0; j<sB; j++){
			scanf("%lf", &matB[i][j]);
		}
	}

   if(sA!=vB || vA!=sB){ printf("NE"); }
   else if(sA==vA){
   	
	/* Rotacija kvadratne matrice */
   for(i=0; i<vA; i++){
   	for(j=0; j<sA; j++){
   		if(i==j && i<vA/2 && j<sA/2){
   			temp=matA[i][j];
   	        matA[i][j]=matA[vA-i-1][j];
   	        matA[vA-i-1][j]=matA[vA-i-1][sA-i-1];
   	        matA[vA-i-1][sA-i-1]=matA[i][sA-i-1];
   	        matA[i][sA-i-1]=temp;
   		}
   		else if(i<j && j<sA-1-i) {
   			temp1=matA[i][j];
   			matA[i][j]=matA[j][i];
   			matA[j][i]=matA[sA-i-1][j];
   			matA[sA-1-i][j]=matA[j][vA-1-i];
   			matA[j][vA-1-i]=temp1;
   		} 
   	} 
   }
  
	for(i=0; i<vA; i++){
		for(j=0; j<sA; j++){
			if(fabs(matA[i][j]-matB[i][j])<eps){
				k++;
			}
		}
	}
	if(k==vA*sA){printf("DA");}
	else printf("NE");
   
    } else {
    	for(i=0; i<vA; i++){
    		for(j=0; j<sA; j++){
    			if(fabs(matA[i][j]-matB[j][vA-1-i])<eps){
    				k++;
    			}
    		}
    	}
    	if(k==vB*sB){ printf("DA"); }
    	else printf("NE");
    } 

	return 0;
}
