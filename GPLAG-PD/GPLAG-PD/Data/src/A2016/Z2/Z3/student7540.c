#include <stdio.h>

int main() {
	int  i,j,n,k,l,m,X[20],Y[20];
	char niz[20][20];
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if (n<1 || n>10) printf("Pogresan unos\n");
	} while((n<1 || n>10));
	
	for (i=0; i<20; i++){
        for (j=0; j<20; j++){
            niz[i][j]=' ';}}
	
	for (k=0; k<n; k++)
       {
        	printf("Unesite %d. tacku: ", k+1);
        	scanf("%d", &X[k]);
        	scanf("%d", &Y[k]);
        	if (((X[k]>=0)&&(X[k]<=19))&&((Y[k]>=0)&&(Y[k]<=19))) continue;
            
         printf("Pogresan unos\n"); 
        k--;}
        
		for (k=0; k<n; k++){
	for (i=0; i<20; i++){
        for (j=0; j<20; j++){
		if(i==Y[k]&& j==X[k]) niz[i][j]='*';
        }	
        }  
	}
	
	for (i=0; i<20; i++){
        for (j=0; j<20; j++){
            printf("%c", niz[i][j]);}
            printf("\n");}
            
        return 0;
}	