#include <stdio.h>
#include <math.h>
#define EPS 0.0001

int main() {
	float A[100][100],B[100][100];
	int i,j,sir_a,vis_a,sir_b,vis_b,rotirana_mat=1;
	do {
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sir_a,&vis_a);
	} while(sir_a<=0 || vis_a<=0 || sir_a>100 || vis_a>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vis_a; i++){
		for(j=0; j<sir_a; j++){
			scanf("%f", &A[i][j]);
		}
	}
	
	do {
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sir_b, &vis_b);
	} while(sir_b<=0 || sir_b>100 || vis_b<=0 || vis_b>100);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vis_b; i++){
		for(j=0; j<sir_b; j++){
			scanf("%f", &B[i][j]);
		}
	}
	
	if(vis_a!=sir_b || sir_a!=vis_b) {
		rotirana_mat=0;
		printf("NE");
		return 0;
	}
	
	for(i=0; i<vis_a; i++){
		for(j=0; j<sir_a; j++){
			if(fabs(A[i][j]-B[j][vis_a-1-i]) > EPS) {
				rotirana_mat=0;
				break;
	    	}
	    }
	}
	if(rotirana_mat) printf("DA");
	else printf("NE");
	
	return 0;
}
