#include <stdio.h>
#include <math.h>

int main() {
	int i,j,n;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<=0 || n>50){
		printf("Pogresan unos\nUnesite broj n: ");
		scanf("%d",&n);
	}
	if(n==1){
		printf("***");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<=4*n;j++){
          if(i==j && (j<=n || j==2*n || j==4*n)){
          	printf("*");
          }
          	if(j>=n && j<=2*n-i)
          	
          		if(i==j)
          		printf("*");
          	     if(i==0 && j>0 && j<=2*n){
          	     	printf(" ");
          	     }
          	  
          	     if(i==n && (j!=n-1 || j!=3*n-1)){
          	     	printf(" ");
          	     }
          	 if(i>0 && i<=n && i!=j){
          	     	printf(" ");
          	     }
          	     if(i==0 && j>2*n && j<4*n){
          	     	printf(" ");
          	     }
          	   
          	     
          	     
                        if(j==2*n+i-3)
          					printf("*");
          		
          			if(j==(2*n-i-3))
          				printf("*");
          	
          					if(j==4*n-i-5)
          						printf("*");
          					
          				}
           	printf("\n");
	}
			return 0;
		}