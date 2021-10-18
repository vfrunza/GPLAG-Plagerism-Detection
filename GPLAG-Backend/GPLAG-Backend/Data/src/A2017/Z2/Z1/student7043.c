#include <stdio.h>

int main() {
	int N,i,j,k=1;
	do{
	printf("Unesite broj N: \n");
	scanf("%d",&N);
	if (N%4!=0 || N<8) printf("Neispravno N!\n");
	} while (N%4!=0 || N<8 );
	for (i=0;i<N/2;i++){
		for(j=0;j<(N);j++){
			if (i==j && i<N/2) printf ("\\");
			 else if (j==((N/2)-k) ){ 
				printf ("/");
					k=k+1;
			}
			 else  if(j<N/2)printf (" ");
		
		if(((i==0) || (i==N/2-1) )&&((j==N/2)||(j==N-1)) ) printf("+");
		else if ((i==0 || i==N/2-1) && j>N/2-1 && j<N-1) printf("-");
	
		else if ((i!=0) && (i!=N/2-1) && j==N/2-1) printf("|");
		else	if((i>0 && i<N/2-1)&&(j<N-2 && j>N/2-1)&&j!=0) printf(" ");
		else if ((i!=0) && (i!=N/2-1) && j==N-1) printf("|");
		
			   
			 	
		}	 
		
		printf("\n");
	
	}
	for (i=0;i<N/2;i++){
		for (j=0;j<N;j++){
			if(((i==0) || (i==N/2-1) )&&((j==0)||(j==N/2-1)) ) printf("+");
		else if ((i==0 || i==N/2-1) && j>0 && j<N/2-1) printf("-");
	
		else if ((i!=0) && (i!=N/2-1) && j==0) printf("|");
		else	if((i>0 && i<N/2-1)&&(j>0 && j<N/2-1)) printf(" ");
		else if ((i!=0) && (i!=N/2-1) && j==N/2-1) printf("|");
		
		if((j==3*N/4+2 || j==3*N/4+1)&&(i!=N/4-1 && i!=N/4)) printf("|");
 		if (N==8 && (j==3*N/4+2)&&(i!=N/4-1 && i!=N/4)) printf("|");
	 else if(((j!=3*N/4+1 && j!=3*N/4)&&(i==N/4-1 || i==N/4) && j>N/2 ) || (j==N-1 && (i==N/4-1 || i==N/4)))  printf ("-");
	  if ((j==N-1 && (i==N/4-1 || i==N/4))) printf ("-");
	 else  if (j>N/2 && i!=N/4-1 && i!=N/4 && j!=3*N/4+1 && j!=3*N/4)printf (" ");
			else	if ((j==3*N/4+1 || j==3*N/4)&&(i==N/4-1 || i==N/4)) printf("+");
	if(j==N && (i==N/4-1 || i==N/4)) printf(" ");
		
	
			
		
			
		}
		if (N==8 && (j==3*N/4+2)&&(i!=N/4-1 && i!=N/4)) printf("|");
		if (N==8 && (j==3*N/4+2)&&(i==N/4-1 && i==N/4)) printf("+");
		if(j==N && (i==N/4-1 || i==N/4)) printf(" ");
		printf("\n");	
		}
	

	
	return 0;
}
