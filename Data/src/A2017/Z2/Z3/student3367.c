#include <stdio.h>


int main() {
	
	double a[100][100], b[100][100], trans[100][100];
	int i,j,n,m,k,c,d;
	
	int iste;

	iste=1; 
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&m,&n);
	
	printf("Unesite clanove matrice A: "); 


	for(i=0; i<n; i++){ 
		for(j=0; j<m; j++) {
			scanf("%lf",&a[i][j]); 
			
		}
	}

	for(i=0; i<n; i++) {
		
	for(j=0; j<m; j++) {
		
		trans[j][n-1-i]=a[i][j];
		
		
		}
	}
	
	


	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&d,&c);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<c; i++) {
		for(j=0; j<d; j++) {
			scanf("%lf",&b[i][j]); 

		} 
	
	}
	
	if((m*n!=c*d) || (n==c && m==d && m!=n)) {printf("NE");}
	
	else {
	for(i=0; i<c; i++) {
		for(j=0; j<d; j++) {
		
			if(trans[i][j]!=b[i][j]) { 
				iste=0; break;
				}
				
			} }
			
	

	

	if(iste==1) {printf("DA");}
	if(iste==0) {printf("NE");} 
	} 
	
/* for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
	printf("%g",trans[i][j]); }printf("\n");} */



	return 0;
}