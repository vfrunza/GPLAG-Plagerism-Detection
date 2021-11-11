#include <stdio.h>

int main() {
	
	int i,j,n;
	for(;;){
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50 ){printf("Pogresan unos\n");}
	else break;
}
	if(n==1){printf("**");}
	for(i=0;i<n;i++){
		for(j=0;j<(n*4)-3;j++){
			 if(i==j){printf("*");}
		else if(i+j==2*(n-1) && i!=n){printf("*");}
		else if(j==2*(n-1)+i && i!=0){printf("*");}
		else if(j+i==(4*n)-4 && i!=n){printf("*");}
			else printf(" ");
		}
		printf("\n");
	}

	
	return 0;
}
