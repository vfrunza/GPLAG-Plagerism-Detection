#include <stdio.h>
#define MAX 100

int main() {
	int A[MAX*MAX],B[MAX*MAX],C[MAX*MAX],m,n,i,j,min,k=1,temp;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
	} while(m<0 || m>MAX || n<0 || n>MAX);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<n*m; i++){
		scanf("%d",&A[i]);
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<n*m; i++){
		scanf("%d",&B[i]);
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<n*m; i++){
		scanf("%d",&C[i]);
	}
	for(i=0; i<n*m; i++){
		min=i;
		for(j=i+1; j<m*n; j++){
		
			if(A[j]<A[min]){
				min=j;
				temp=A[i];
				A[i]=A[min];
				A[min]=temp;
			}}}
		for(i=0; i<n*m; i++){
		min=i;
		for(j=i+1; j<m*n; j++){
		
			if(B[j]<B[min]){
				min=j;
				temp=B[i];
				B[i]=B[min];
				B[min]=temp;
			}}}
	for(i=0; i<n*m; i++){
		min=i;
		for(j=i+1; j<m*n; j++){
		
			if(C[j]<C[min]){
				min=j;
				temp=C[i];
				C[i]=C[min];
				C[min]=temp;
			}}}
	for(i=0; i<n*m; i++){
		
			if(A[i]!=B[i] || A[i]!=C[i]){
				k=0; break;
			}
			
	}	
		
		if(k==0){
			printf("NE");
		}
	else printf("DA");
	return 0;
}
