#include <stdio.h>
#include <math.h>
int main() {
int i,j,n,y;
for(y=0;y<1000;y++){
	printf("\nUnesite broj n: ");
	scanf("%d",&n);

if(n<=0 || n>50){
	printf("Pogresan unos");
	
}
	else break;
}


for(i=0;i<n;i++){
	for(j=0;j<pow(n,2);j++){
		if(i==j){
			printf("*");
		}
		else if(i+j==2*n-2 && i!=n-1 && i!=0){
			printf("*");
		}
		else if(i+j==4*n-4 ){
			printf("*");
		}
		else if(j-i==2*n-2 ){
			printf("*");
		}
		else printf(" ");
	}
	printf("\n");
}
	return 0;
}
