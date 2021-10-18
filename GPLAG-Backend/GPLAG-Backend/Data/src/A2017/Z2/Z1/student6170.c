#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 1");*/
    int i,j,N,k;
    
    do {
    	printf("Unesite broj N: ");
    	scanf("%d", &N);
    
    if(N%4!=0 || N<8) {
    	printf("Neispravno N!\n");
    }
    } while(N%4!=0 || N<8);
    printf("\n");
    k=0;
    	for(i=1;i<=N/2;i++){
		
		for(j=1;j<=N;j++){
			
		if(j<=N/2){	
		   if(i==j) {
    	      printf("\\");
    	   } 
    	   else if((j==(N/2)-k)) {
    		  printf("/");
    		k++;
    	   }
    	   else printf(" ");
		}
    else{
    
	if((j==(N/2)+1 && i==1) || (i==1 && j==N) || (i==N/2 && j==(N/2)+1) || (i==N/2 && j==N)) {
				printf("+");
			} 
			else if(i==1  || i==N/2) {
			   printf("-");
			}
			
			 else if(j==(N/2)+1 || j==N){
				printf("|");
			}
			else {
				printf(" ");
			}
			
		}}
			printf("\n");
			
    	}
 
    
	
/*2.*/		
		for(i=(N/2)+1;i<=N;i++){
		
		for(j=1;j<=N;j++){
			
		if(j<=N/2) {
			if((j==1 && i==(N/2)+1) || ((i==(N/2)+1) && j==N/2) || (i==N && j==1) || (i==N && j==N/2)) {
				printf("+");
			} 
			else if(i==(N/2)+1 || i==N) {
			   printf("-");
			}
			
			 else if(j==1 || j==N/2){
				printf("|");
			}
			else {
				printf(" ");
			}
			
			}
			
			
	 else {
	 	if((i==(N/2)/2+(N/2) && (j==(N/2)/2+(N/2) || j==(N/2)/2+(N/2)+1)) || (i==(N/2)/2+(N/2)+1 &&(j==(N/2)/2+(N/2) || j==(N/2)/2+(N/2)+1))) {
	 	   printf("+");
	 	}
	 	else if(j==(N/2)/2+(N/2) || j==(N/2)/2+(N/2)+1) {
	 		printf("|");
	 	}
	 	else if(i==(N/2)/2+(N/2) || i==(N/2)/2+(N/2)+1) {
	 		printf("-");
	 	}
	 	else printf(" ");
	 }
		}
		printf("\n");
		}
	return 0;
}
