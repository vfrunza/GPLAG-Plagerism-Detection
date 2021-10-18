#include <stdio.h>
#define BROJ_EL 100

int main() {
	float A[BROJ_EL][BROJ_EL],B[BROJ_EL][BROJ_EL];
	int m1,n1,m2,n2,i,j,uspjeh=1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&n1,&m1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
			scanf("%f",&A[i][j]);
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&n2,&m2);
		printf("Unesite clanove matrice B: ");
	for(i=0;i<m2;i++){
		for(j=0;j<n2;j++){
			scanf("%f",&B[i][j]);
		}
	}
	if(m1!=n2 || n1!=m2) {
		printf("NE");
return 0;}
	 for(i=0;i<m1;i++){
	 	
	 	for(j=0;j<n1;j++){
	 		if(A[i][j]!=B[j][m1-i-1]){
	 			uspjeh=0;
	 			break;
	 		}
	 		
	 	}
	 	
	 }
	 if(uspjeh) printf("DA");
	 else printf("NE");
	
	
	return 0;
}
