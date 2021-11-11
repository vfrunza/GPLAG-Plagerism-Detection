#include <stdio.h>

int main() {
	
	int A[100],B[100]={0},C[1000]={0};
	int i,n,j,k=0,pom,br=0;
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
		if(n>100 || n<=0) continue;
		else break;
	}while (1==1); 
	
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		if(A[i]<0)i--;
	}
	
	for(i=n-1; i>=0;i--){
		pom=A[i];
		if(pom==0){
			B[k]=pom;
			k++;
			continue;
		}
		while (pom!=0) {
			B[k]=pom%10;
			pom/=10;
			k++;
		}
	}
	
	for(i=0;i<k/2;i++){
		pom=B[i];
		B[i]=B[k-i-1];
		B[k-i-1]=pom;        
	}
	 
	j=0;
	
	for(i=0;i<k;i++){
		br=0;
		pom=B[i];
		while (B[i]==pom && i<k) {
			br++;
			i++;
		}
		i--;
		C[j]=B[i];
		C[j+1]=br;
		j+=2;
	}
	
	printf("Finalni niz glasi: \n");	
	
	for(i=0;i<j;i++){
		printf("%d ",C[i]);
	}
	
	return 0;
}
0