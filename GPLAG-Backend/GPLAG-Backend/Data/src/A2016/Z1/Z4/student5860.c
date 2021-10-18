#include <stdio.h>

int main() {
	int n, j, s, i=0;

do{
	scanf("%d", &n);
	printf("Unesite broj n: ");
	
	
	if(n>50 || n<=0){
		printf("Pogresan unos \n");

	}
}
	while(n>50 || n<=0);
	
	
if(n==1){
	printf("***");
}
else{

	s=4*n-3;

		for(j=0; j<s; j++)
		{
			if(j==0 || j==s/2 || j==s-1)
			printf("*");
			else 
			printf(" ");
		}
		printf("\n");

      for(i=1; i<(n-1); i++){
	       for(j=1; j<s; j++){
		     if(j==i){
		           	printf(" *");
		     }
		else
		printf(" ");
			if(j==(s-i-4)){
				printf("*");
			}
			if(j==(s/2)-i -1){
      			printf("*");
      		}
      		if(j==(s/2)+i -2)
      		printf("*");
		 }
		 printf("\n");
    	
      }
  
   	for(j=0; j<s; j++){
   		if(j==n-1 || j==(s-n)){
   			printf("*");
   		}
   		else printf(" ");
   	}
 }
   


	return 0;
}



