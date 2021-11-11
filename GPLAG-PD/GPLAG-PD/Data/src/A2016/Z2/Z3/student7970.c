#include <stdio.h>
#include<stdlib.h>
int main() {
	int n,i,j,k,h,nizX[10],nizY[10];


	for(;;){
	greska:	printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		
		if(n>10 || n<=0) {printf("Pogresan unos\n");
			goto greska;
		}
		if(n>0 &&  n<=10) break;
		
	}
	

	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&nizX[i],&nizY[i]);
	
		if(nizX[i]<0 || nizX[i]>19 || nizY[i]<0 || nizY[i]>19){
		printf("Pogresan unos\n");
		i--;
		}
		if(i==n) break;
	}

	
    for(k=0; k<20; k++){
    
		for(h=0; h<20; h++){
			j=0;
			for(i=0;i<n;i++){
				
			if(i<n-1 && nizY[i]==nizY[i+1] && nizX[i]==nizX[i+1]  ) continue;
			
			else if(k==nizY[i] && h==nizX[i] ) {
				printf("*"); j=1;
			}
			
			}
			if(j==0)
			printf(" ");
		
		}
		printf("\n");
		
	
	
}

	
	return 0;
}
