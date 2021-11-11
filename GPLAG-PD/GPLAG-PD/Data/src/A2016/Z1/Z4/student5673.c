#include <stdio.h>

int main(){
	int n,i,j;
	i=1;
	do{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<=0 || n>50){
			printf("Pogresan unos\n");
			continue;
			}
			
		i=0;
	}
	while(i);
	if(n==1){
		printf("***");
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
			printf("*");
			else 
			printf(" ");
		}
		for(j=n-1;j>=1;j--){
			if(i==j)
			printf("*");
			else
			printf(" ");
		}
		for(j=2;j<=n;j++){
			if(i==j)
			printf("*");
			else
			printf(" ");
		}
		for(j=n-1;j>=1;j--){
			if(i==j)
			printf("*");
			else
			printf(" ");
		}
		if(i<n)
		printf("\n");
	}
	return 0;
}
