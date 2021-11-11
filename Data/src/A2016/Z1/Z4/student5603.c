#include <stdio.h>
#include<math.h>

int main() {
	int n,i,j,s,k;
	do{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	 
	 if(n<=0 || n>50) 
	 printf("Pogresan unos\n");
		
	}while(n<=0 || n>50);
	   
          k=fabs(n-2);
		s=n+k;
	
	for(i=0;i<n;i++){
		for(j=0;j<=2*s;j++){
			if(i==j || i+j==s || j-i==s || j+i==2*s)
			printf("*");
			else if (n==1) continue;
			else printf(" ");
		}
		printf("\n");
	}
		
      
	
	
	
	
	
	return 0;
}
