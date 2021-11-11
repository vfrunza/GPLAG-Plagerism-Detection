#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001

int main() {
	
	
	int m, n, i, j, z, t=0, c=0;
	
	float pocetna;
	
	float matrica[100][100];
	
	do {
		printf("Unesite M i N: ");
		
		scanf("%d", &m);
		
		scanf("%d", &n);
		
		if(m<=0 || m>100 || n<=0|| n>100) printf("Pogresan unos!\n");
		
		} while(m<=0 || m>100 || n<=0|| n>100);
		
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++) {
		
		for(j=0; j<n; j++) {
			
			scanf("%f", &matrica[i][j]);
			
		}
	}
	
	for(z=0; z<m; z++) {
		
			pocetna=matrica[z][0];
		
		for(i=0; i<m; i++) {
			
			
			
			for(j=0; j<n; j++) {
				
				
				if(i-j==z) {
					
					if(fabs(matrica[i][j]-pocetna)>EPSILON) t=1;
					
					
					
				
				}
			}
		}
	}
	


	
	for(z=0; z<n; z++) {
		
		pocetna=matrica[0][z];
		
		for(i=0; i<m; i++) {
			
			for(j=0; j<n; j++) {
				
				
				if(j-i==z) {
				
					if(fabs(matrica[i][j]-pocetna)>EPSILON) t=1;
				}
			}
		}
	}
	

	
	for(i=0; i<m; i++) {
		if(i>0 && fabs(matrica[i-1][n-1]-matrica[i][0])>EPSILON) {
			c=1;
		}
	}


	
	
	
	
	if(t==0 && c==1) printf("Matrica je Teplicova");
	if(t==0 && c==0) printf("Matrica je cirkularna");
	if((t==1 && c==1) || (t==1 && c==0)) printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	
return 0;

}
	
