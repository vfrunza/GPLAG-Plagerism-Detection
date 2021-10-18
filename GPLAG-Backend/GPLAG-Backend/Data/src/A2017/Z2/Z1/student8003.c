#include <stdio.h>
int main () {
int i, j,k, n, g ;
printf("Unesite broj N: \n");
scanf("%d", &n);


for (i=0; i<n/2; i++){
	for (j=0; j<n/2; j++){
		if (j==i)
		printf ("\\");
		else if(i==n/2-j-1) printf("/");
		else printf (" ");
	}
		if(i==0 || i==n/2-1)
		{
			printf("+");
			for(k=0;k<n/2-2;k++)
			printf("-");
			printf("+");
				
		}
		else
		{
			printf("|");
			for(k=0;k<n/2-2;k++)
			printf(" ");
			printf("|");
		}
	printf("\n");
}


for (i=0; i<n/2; i++){
	
		if(i==0 || i==n/2-1)
		{
			printf("+");
			for(k=0;k<n/2-2;k++)
			printf("-");
			printf("+");
				
		}
		else
		{
			printf("|");
			for(k=0;k<n/2-2;k++)
			printf(" ");
			printf("|");
		}
	g=n/4*3	;
	
	
		for (j=n/2; j<n; j++)
		{
			if (i==g-1 || i==g){
				if (i==g-1 || i==g)
				printf ("+");
				else printf ("-");
			}
			else if (j==g || j==g-1)
			printf ("|");
			else
			printf (" ");
			
		}
	
	printf("\n");
}
return 0;
}
