#include <stdio.h>

int main() {
	int N, i, j;
	do{
	printf("Unesite broj N: ");
	scanf("%d", &N);
	
	if(N%4!=0 || N<8){
		printf("Neispravno N!\n");
		
	     }
	
	}while(N%4!=0 || N<8);
	
		printf("\n");
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			
			
			
			if((i>=0 && i<=((N/2)-1)) && (j>=0 && j<=(N/2)-1)){
				if(i==j){
				printf("\\");
			}  else if(j==(N/2)-1-i){
				
				printf("/");
		}	else printf(" ");
		
	}
	    else if(( i>=0 && i<=(N/2)-1) && (j>=(N/2) && j<N)){
	       	     if((i==0 && (j==N/2 || j==N-1)) || (i==(N/2)-1 && (j==N/2 || j==N-1))){
	       	    	printf("+");
	       	    	
	       	  }   else if((i==0 && (j>N/2 || j<N-1)) || (i==(N/2)-1 && (j>N/2 || j<N-1))){
	       	    	printf("-");
	       	 }    else if((i>0 && i<(N/2)-1) && (j==(N/2) || j==N-1)){
	       	 	    printf("|");
	       	 }     else printf(" ");
	       }
			
			
		else if((i>=(N/2) && i<N) && (j>=0 && j<=(N/2)-1)){
			 if((i==(N/2) && (j==0 || j==(N/2)-1)) || (i==N-1 && (j==0 || j==(N/2)-1))){
			 	printf("+");
			 } else if((i==(N/2) && (j>0 || j<(N/2)-1)) || (i==N-1 && (j>0 || j<(N/2)-1))){
			 	printf("-");
			 } else if((i>(N/2) && i<N-1) && (j==0 || j==(N/2)-1)){
			 	printf("|");
			 } else printf(" ");
		}
		
		else if((i>=(N/2) && i<N) && (j>=(N/2) && j<=N-1)){
			 if((j==(N/4)*3-1 || j==(N/4)*3) && i!=N/4*3-1 && i!=N/4*3){
			 	printf("|");
		}
		
		     else if((i==((N/4)*3)-1 || i==(N/4)*3) && (((j>=(N/2)-1) && j<((N/4)*3-1)) || ((j>(N/4*3) && j<=N-1)))){
		 	printf("-");
		 }  else if((i==((N/4)*3-1) || i==(N/4)*3) && ((j==((N/4)*3)-1) || j==(N/4)*3)){
		 	printf("+");
		 } else printf(" ");
		 
		}
		
			
			
		}
	printf("\n");
	
		} 
		return 0; }


	
