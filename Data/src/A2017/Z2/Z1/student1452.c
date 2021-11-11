#include <stdio.h>
#include <math.h>

int main() {
	int b,i,j,k,o=0;
	float a;

	do{
		if(o) printf("Neispravno N! \n");
			printf("Unesite broj N: ");
		scanf("%f",&a);
		o++;
	} while((ceil)(a)!=a || (int)a%4!=0 || a<8);
	printf("\n");
	b=a/2;
	
	for(i=0;i<b;i++)
	{
		
		for(j=0;j<b;j++){
			if(i==j) printf("\\");
			 else if(i+j==b-1) printf("/");
			   else printf(" ");
			
			          }
			
			
	    for(k=0;k<b;k++){
			if(i==0 || i==b-1){
				if(k==0 || k==b-1) printf("+");
				  else printf("-");
		             	     }
			else if(k==0 || k==b-1) printf("|");
			else printf(" ");
			
		} printf("\n");
		
	}
	
	for(i=0;i<b;i++){
		
		for(j=0;j<b;j++){
			if(i==0 || i==b-1){
				if(j==0 || j==b-1) printf("+");
				else printf("-");
			}
			else if(j==0 || j==b-1) printf("|");
			else printf(" ");
		}
		
		for(k=0;k<b;k++){
			
			if(i==(b/2-1) || i==b/2){
				if(k==(b/2-1) || k==b/2) printf("+");
				else printf("-");
			}
			else if(k==b/2 || k==(b/2-1)) printf("|");
			else printf(" ");
			
		}
		
	printf("\n");	
		
		}
	
	return 0;
}
