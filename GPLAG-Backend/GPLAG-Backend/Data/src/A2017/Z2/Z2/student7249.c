#include <stdio.h>

int main() {
	int A[100],n,i,C[1000],B[100],j,br;
	int b=0;
	
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	
	printf("Unesite clanove niza: ");

	for(i=0;i<n;i++){
			do{
	scanf("%d, ",&A[i]);
			} while(A[i]<0);
	}
	
	for(i=0;i<n;i++) {
		
		while(A[i]!=0){
		C[b]=A[i]%10;
		A[i]/=10;
		b++;
		}
	}
	
	for(b=0;b<1;b++){
		
		for(j=b;j<n;j++){
			if (C[b]==C[j]) br++;
		}
		
		B[b]=br++;
	}
	for(i=0; i<n; i++)printf("%d", B[i]);  
	
	for(i=0;i<n;i++)printf("%d", C[i]);
	printf("\nFinalni niz glasi: ");
	return 0;
	
}
