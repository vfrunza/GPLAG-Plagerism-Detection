#include <stdio.h>

int main() {
	  int i,n,j,m,l,o;
	  for(i=0;i<1;i++){
	  	printf("Unesite broj n: ");
	  	scanf("%d",&n);
	  	if(n<1 || n>50){
	  		printf("Pogresan unos\n");
	  		i--;
	  	}
	  }
	  m=n*4-3;
	  l=(n-1)*2;
	  o=(n-1)*3;
	  if(n==1){
	  	printf("***");
	  }
	  
	  else for(i=0;i<n;i++){
	  	for(j=0;j<=m;j++){
	  		if(j>0 && j<n && i==j) {
	  			printf("*");
	  		}
	  		else if(j>l && j<o && j==l+i){
	  			printf("*");
	  		}
	  		else if(j>=n && j<l && j==l-i ){
	  			printf("*");
	  		}
	  		else if (j>o && j<m && j==m-1-i){
	  			printf("*");
	  		}
	        else if((j==l && i==0)||(j==m-1 && i==0)||(i==0 && j==0)||(i==n-1 && j==o)){
	        	printf("*");
	        }
	  		else printf(" ");
	  	}
	  	printf("\n");
	  }
	return 0;
}
