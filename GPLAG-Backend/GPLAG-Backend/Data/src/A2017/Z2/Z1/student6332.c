#include <stdio.h>

int main(){
	int N,i,j;
	
	do{ 
		
		printf("Unesite broj N: ");
		scanf("%d",&N);
		if(N%4!=0 || N<8)printf("Neispravno N!\n");
		if(N%4==0 && N>=8)printf("\n");
      }while(N%4!=0 || N<8);
    
    
    for(i=1; i<=N; i++){
    	for(j=1; j<=N; j++){
    		
    		if((i>=1 && i<=N/2) && (j>=1 && j<=N/2)){ if(i+j==(N/2)+1) printf("/");
    		   else if(i==j) printf("\\");
    		    
    		    else printf (" ");
    		}
    		if((i>N/2 && i<=N) && (j>=1 && j<=N/2)){
    		    if((i==(N/2)+1 || i==N) && (j==1 || j==N/2)) printf("+");
    		    else if(i==(N/2)+1 || i==N)printf("-");
    		    else if(j==1 || j==N/2) printf("|");
    		    else printf(" ");
    		}
    		if((i>=1 && i<=N/2) && (j>N/2 && j<=N)){
    	        if((i==1 || i==N/2) && (j==(N/2)+1 || j==N)) printf("+");
    	        else if(i==1 || i==N/2) printf("-");
    	        else if(j==(N/2)+1 || j==N) printf("|");
    	        else printf(" ");
    		}
    		if((i>N/2 && i<=N) && (j>N/2 && j<=N)){
    		    if((j==(N/2)+(N/4) || j==(N/2)+(N/4)+1)&&(i==(N/2)+(N/4) || i==(N/2)+(N/4)+1))printf("+");
    		    else if(j==(N/2)+(N/4) || j==(N/2)+(N/4)+1)printf("|");
    		    else if(i==(N/2)+(N/4) || i==(N/2)+(N/4)+1)printf("-");
    		   
    		    else printf(" ");
    		   
    		   }
    	}
    	printf("\n");
    }
    		return 0;
}
    		
    		
    		
    		
    		
    		
    		
    		
    		
    		
    
