#include <stdio.h>

int main() {
	
	int n,i,j;
do{
	scanf("%d",&n);
}while(n<8 || n%4!=0);

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		
		 if(i==0 || i==n/2-1){
	 	
			if(j==0  || j==n/2-1)
			printf("+");
			
	else if( j>0 && j<n/2-1 )
	
	printf("-");
			
		}else if((j==0 || j==n/2-1) && i<=n/2-1)
			printf("|");
					
           else printf(" ");
		
		}
		
		
	printf("\n");	




}

	return 0;
}
