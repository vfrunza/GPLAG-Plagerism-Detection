#include <stdio.h>
#define a 20 
int main() {
	int n,i,s,t,k, m[a][a]={0};
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);	
	if(n<=0 || n>10) printf("Pogresan unos\n");
		}while(n<=0 || n>10);
		
		
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d",&s,&t);
		if(s<0 || s>=20 || t<0 || t>=20){ printf("Pogresan unos\n");
			i--;}
		else m[t][s]=1;
		}
		
		
	for(i=0;i<a;i++){
		for(k=0;k<a;k++){
			if (m[i][k]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
		
	}
	
		
	return 0;
}
