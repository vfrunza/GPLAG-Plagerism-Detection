#include <stdio.h>

int main() {
int A1,A2,B1,B2;
int i,j,brojac,k,z;
double A[50][50],B[50][50];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&A1,&A2);
	printf("Unesite clanove matrice A: ");
		for(i=0;i<A1;i++){
			for(j=0;j<A2;j++){
				scanf("%lf",&A[i][j]);
			}
		}
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d%d",&B1,&B2);
		printf("Unesite clanove matrice B: ");
		for(i=0;i<B1;i++){
			for(j=0;j<B2;j++){
				scanf("%lf",&B[i][j]);
			}
		}
		brojac=0;
		k=B2-1;
		z=0;
		if ( A1 == B1 && A2==B2 && A1==A2) {
		k=B2-1;
		brojac=0;
		for(i=0;i<A1;i++){
			z=0;
			for(j=0;j<A2;j++){
				if(A[i][j]!=B[z][k]) brojac++;
				z++;
				if(z>B1) { z=0; k--;}
			}
			k--;
		}
		if(brojac==0)printf("DA\n");
		else printf("NE\n");
		}
		else {
			if(B1<A1 && B1==1) {
			brojac=0;
			k=A2-1;
		brojac=0;
		for(i=0;i<B1;i++){
			z=0;
			for(j=0;j<B2;j++){
				if(A[z][k]!=B[i][j]) brojac++;
				z++;
			}
			k--;
		}
			if(brojac==0)printf("DA\n");
		else printf("NE\n");
		}
		else if(A1<B1 && A1==1) {
			brojac=0;
		brojac=0;
		z=0;
		for(i=0;i<A1;i++){
			k=B1-1;
			for(j=0;j<A2;j++){
				if(A[i][j]!=B[k][z]) brojac++;
				k--;
			}
			z++;
		}
			if(brojac==0)printf("DA\n");
		else printf("NE\n");
		
		}
				else if(A1<B1 && A1>1) {
			brojac=0;
		brojac=0;
		z=0;
		k=A2-1;
		for(i=B2-1;i>0;i--){
	
			for(j=0;j<B1;j++){
				if(B[j][i]!=A[z][k]) brojac++;
				z++;
				if(z>A1-1) { z=0; k--; }
			}
			
		}
			if(brojac==0)printf("DA\n");
		else printf("NE\n");
		
		}
				else if(A1==B1 || A2==B2) {
			brojac=0;
		brojac=0;
		z=0;
		k=A2-1;
		for(i=B2-1;i>0;i--){
	
			for(j=0;j<B1;j++){
				if(B[j][i]!=A[z][k]) brojac++;
				z++;
				if(z>A1-1) { z=0; k--; }
			}
			
		}
			if(brojac==0)printf("DA\n");
		else printf("NE\n");
		
		}
		}
	
	return 0;
}
