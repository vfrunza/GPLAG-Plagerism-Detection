#include <stdio.h>

int main() {
	int N;
	int i,j,k;
	
	
	do{
	printf ("Unesite broj N: ");
	scanf ("%d", &N);
	if ((N<=0 || N<8) || N%4!=0) printf ("Neispravno N!\n");
	} while ( (N<0 || N<8) || N % 4 != 0); 
	printf("\n");
	//X//
	for (i=1;i<=N/2;i++){
	    for (j=1;j<=N/2;j++){
	        if (i==j) printf ("\\");
	        else if (i+j==(N/2) + 1) printf ("/");
	        else printf (" ");
	    }
	    //KVADRAT GORNJI//
	     for (j=1 ;j<=N/2;j++){
	        if ((i==1 && j==1) || (i==N/2   && j==1)){ printf ("+");
	        	for(k=2;k<=N/2 - 1 ;k++) printf ("-");
	        	printf ("+");
	        }
	        if (i!=1 && i!=N/2 && j<=N/2){ printf ("|");
	        	for(k=2;k<=N/2 - 1 ;k++) {printf (" ");}
	        	printf ("|");
	        	break;
	        }
	    }
	    printf ("\n");
	}
	
	//DRUGI DIO//
		for (i=1;i<=N/2;i++){
	     
	     for (j=1 ;j<=N/2;j++){
	        if ((i==1 && j==1) || (i==N/2   && j==1)){ printf ("+");
	        	for(k=2;k<=N/2 - 1 ;k++) printf ("-");
	        	printf ("+");
	        }
	        if (i!=1 && i!=N/2 && j<=N/2){ printf ("|");
	        	for(k=2;k<=N/2 - 1 ;k++) {printf (" ");}
	        	printf ("|");
	        	break;
	        }
	    }
	    
	    for (j=1; j<=N/2;j++){
	    	if ((i!=N/4) && (i!=N/4 + 1)){
	    		if ((j== N / 4) || (j==N / 4 + 1)) printf ("|");
	    		else printf (" ");
	    		
	    		
	    	}
	    	else {
	    		for(k=1; k<N/4;k++) printf("-");
	    		printf ("++");
	    		for(k=1; k<N/4;k++) printf("-");
	    		break;
	    	} 
	    }
	    
	    
	    printf ("\n");
	}
	
	return 0;
}
