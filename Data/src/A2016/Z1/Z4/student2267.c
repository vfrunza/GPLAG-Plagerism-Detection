#include <stdio.h>

int main() {
	int i,j,k=0,n;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=50 && n>0)
		 break;
		else
		 printf("Pogresan unos\n");
      }

   while (n>50 || n<=0);

for(i=n;i>=1;i--){
	for(j=i;j<n;j++){
	printf(" ");	
	}
for(j=1;j<=(4*n-3-k);j++){
	if(n==1){
	 printf("***");
	 break;}
	else if(j==1 || j==2*i-1 || j==4*n-3-k || j==2*n-1){
		printf("*");
	}
	else{
	 printf(" ");
	}}
	printf("\n");
	k+=2;
	
}
	
return 0;	
	
}

