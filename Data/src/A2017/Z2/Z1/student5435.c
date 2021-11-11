#include <stdio.h>

int main() {
	
	int n,i,j,k;
	
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		}while((n%4==1 ) || (n%4==2) || (n%4==3) || (n<8));
	  for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
           if(i>n/2 && i<=n){
           	if(i==(n/2+1) || i==n){
           		printf("+");
           	}
           	
           }
           
           
      	
      	
      }printf("\n");
	  }
           return 0;}
	  	
	  	
	  	
	  	
	  	
	  	
	  	
	  	
	  	
	  	
	  	
      