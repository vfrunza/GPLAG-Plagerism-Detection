#include <stdio.h>

int main() {
	
	double matricaA[100][100],matricaB[100][100];
	int i,j,a,b,c,d,brojac=0,temp;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a, &b);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<b; i++) {
		for(j=0; j<a; j++) {
			scanf("%lf", &matricaA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &c, &d);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<c; i++) {
		for(j=0; j<d; j++) {
			scanf("%lf", &matricaB[i][j]);
		}
	}
	
	if(a==d && b==c){
	
	//OKRETANJE REDOVA MATRICE
	for(i=0; i<b/2;i++){
		for(j=0;j<a;j++){
			temp=matricaA[i][j];
			matricaA[i][j]=matricaA[b-i-1][j];
			matricaA[b-i-1][j]=temp;
			
		}
	}

	//TRANSPONOVANJE MATRICE
	for(i=0;i<b;i++){
	for(j=i+1;j<a;j++){
		temp=matricaA[i][j];
		matricaA[i][j]=matricaA[j][i];
		matricaA[j][i]=temp;
	
	}
}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(matricaA[i][j]==matricaB[i][j]) brojac++;
		}
	}
	if(brojac==a*b && brojac==c*d)printf("DA\n");
	else printf("NE\n");
    }
 else printf("NE\n");

	return 0;
}
