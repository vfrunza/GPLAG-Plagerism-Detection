#include <stdio.h>

int main() {
	/*printf("Zadaća 2, Zadatak 3");*/
	
	char a[20][20];
	int n,X[20],Y[20],i,j,k,l;
	
	printf("Unesite broj tacaka: ");

	do{
		scanf("%d", &n);
		
		if(n>10 || n<=0){
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
			continue;
			}
	}
	
	while(n>10 || n<=0);
	
	for(i=0; i<n; i++){
		do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &X[i], &Y[i]);
		
		if((X[i]>=20 || X[i]<0) || (Y[i]>=20 || Y[i]<0)){
			printf("Pogresan unos\n");
			continue;}}
		while((X[i]>=20 || X[i]<0) || (Y[i]>=20 || Y[i]<0));}
		
	for(j=0; j<20; j++){
		for(k=0; k<20; k++){
			a[j][k]=' ';
		}
	}
	
	for(l=0; l<n; l++){
		for(j=0; j<20; j++){
			for(k=0; k<20; k++){
				
				if(j==Y[l] && k==X[l]) a[j][k]='*';
			}
		}
	}
	
	for(j=0; j<20; j++){
		for(k=0; k<20; k++){
			printf("%c", a[j][k]);
		}
		printf("\n");
	}
	
	
	return 0;
}


