#include <stdio.h>
#include <math.h>

int main () {
			
	int a=0,b=0,c=0,d=0,i=-1,j=0,pamti=1;
	float A[10][10]={{0}}, B[10][10]={{0}},temp;
		
		printf ("Unesite sirinu i visinu matrice A: ");
		scanf ("%d %d",&a,&b);
		
		printf("Unesite clanove matrice A: ");
	while(++i<a) {
			
		for(j=0;j<b;j++)
		scanf("%f",&A[i][j]);
		}
		
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d %d",&c,&d);
		
		printf("Unesite clanove matrice B: ");
		i=-1;
	while(++i<c) {
			for(j=0;j<d;j++)
		scanf("%f", &B[i][j]);
		}
		i=0;
		do { /*transponovanje matrice*/
		j=-1;
			while(++j<i) { 
			temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}}while(++i<10);
		 /*zamjena mjesta kolonama */
		for(i=0;i<a;i++) {
			j=-1;
			while(++j<b/2) {
				temp = A[i][j];
				A[i][j] = A[i][b-j-1];
				A[i][b-j-1] = temp;
			}
		}
		/*ispitivanje matrica */ 
		i=10;
		while (--i>-1){
			j=10;
			while (--j>-1) {
				if (fabs(B[i][j]-A[i][j])>0.0001) {
					pamti = 0; 
					break;
					}
			}
		if(pamti==0) 
		break;
		}
		if(pamti) {
		printf("DA\n");
		} else { 
		printf ("NE\n");
		}
		return 0;
}