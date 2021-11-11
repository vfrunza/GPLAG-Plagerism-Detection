#include <stdio.h>
#define d 10
int main() {
	int m1,n1,m2,n2,i,j,t=0;
	double A[d][d],B[d][d];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m1,&n1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
			scanf("%lf",&A[i][j]);
			}
		}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&m2,&n2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m2;i++){
		for(j=0;j<n2;j++){
			scanf("%lf",&B[i][j]);
		}
	}
	if(m1==n2 && m2==n1){
		
		for(i=0;i<m1;i++){
			for(j=0;j<m2;j++){
				if(A[i][j]==B[j][n2-1-i])t++;
				else t=0;
				
			}
		}	
			
	}	else printf("NE");
	if(t==0) printf("NE");
	else if(t==m1*n1) printf("DA");
	else printf("NE");
	return 0;
}
