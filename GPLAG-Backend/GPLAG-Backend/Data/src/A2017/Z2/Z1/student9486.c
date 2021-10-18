#include <stdio.h>
#include <math.h>
int main() {
	int i, j, n, k;
	do{
		printf ("Unesite broj N: ");
		scanf ("%d", &n);
		if (n%4!=0 || n<8 || n==4)
		printf ("Neispravno N!");
		printf ("\n");
	}while (n%4!=0 || n<8 || n==4);
	for (i=1; i<=(n/2); i++){
		for (j=1; j<=(n/2+1); j++){
		   if (j<=(n/2)){
		   	  if (i==j)
		   	  printf ("\\");
		   	 if (i+j==(n/2)+1)
		   	  printf ("/");
		   	 if (i!=j && (i+j)!=((n/2)+1))
		   	 printf (" ");
		   	}
		   
		   	else if (j>(n/2)&& j<=n){ 
		   	if (i==1 || i==(n/2)){
		   		printf ("+");
		   		for (k=1; k<=((n/2)-2); k++)
		   		printf ("-");
		   		printf ("+");
		   	}
		   		else {
		   			printf ("|");
		   			for (k=1; k<=((n/2)-2);k++)
		   			printf (" ");
		   			printf ("|");
		   	} }}
		printf ("\n");	}
		for (i=1; i<=(n/2); i++){
			for (j=1; j<=(n/2); j++){
				if (j==1){
					if (i==1|| i==n/2){
					printf ("+");
					for (k=1; k<=((n/2)-2);k++)
					printf ("-");
					printf ("+"); }
					else {
						printf ("|");
						for (k=1; k<=((n/2)-2); k++)
				          printf (" ");
				          printf ("|");
					}
				}
			if ((j==(n/4) || j==(n/4+1)) && i!=(n/4)&& i!=(n/4 +1))
		    printf ("|");
		    else if ((i==(n/4)|| i==(n/4+1))&& j!=(n/4)&& j!=(n/4+1))
					printf ("-");
		    else if (i==n/4||j==n/4||i==n/4+1 ||j==n/4+1)
					printf ("+");
			else printf (" ");
				
				
				
			}
			printf ("\n");
		}
		   return 0;
		}
			
	