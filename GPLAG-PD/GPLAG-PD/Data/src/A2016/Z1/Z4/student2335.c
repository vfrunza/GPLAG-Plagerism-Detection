#include <stdio.h>

int main() {
int n=0,i=0,j=0,x=0;
do {
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n>0 && n<=50)
	break;
	printf("Pogresan unos\n");
} while(1);

if(n==1){
printf("***");
return 0;
}

for (i=1;i<=n;i++){
	for(j=1;j<=(4*n-3);j++){
		
		if (i==1){
			if(j==1 || j==(4*n-3) || j==2*n-1)
			printf("*");
			else printf(" ");
		}
		
		else if(i==n){
			if(j==n || j==3*n-2)
			printf("*");
			else printf(" ");
		}
		
		else {
			if(i==j || i+j==2*n+x ||(i+j==2*n) || (i+j==4*n-2))
			printf("*");
			else printf(" ");
		}
	}
		printf("\n");
		x+=2;
}
		return 0;
}
