#include <stdio.h>

int main() {
	int i=0,j=0,n;
	do{scanf("%d",&n);}
	while((n%4!=0) && (n<8)); 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			if((i==0)&&(j==0)){
				printf("\\");}
			
				if((i==0)&&(j==n/2)){
					printf("/");
				}
				if(((i==0)&&((j==n/2+1)||(i==0)&&(j==n-1)||(i==n/2+1)&&((j==n/2+1)||(i==n/2+1)&&(j==n-1))))){
					printf("+");
				}
				if(((i==0)&&(j>n/2)&&(j<n-1))){
					printf("-");
				}if((i==0)&&(j>0)&&(j<n/2)){
					printf(" ");
				}if((i==n/2)&&(j==0)){
					printf("\n\\");
				}
				if((i==n/2)&&(j==n/2)){
					printf("\n/");
				}
				
			
			
		}
	}
	return 0;
}
