#include <stdio.h>

int main() {
	int n,i,j;
	
	do {
	printf("Unesite broj n: "); 	
	scanf("%d",&n);
		if (n==1) printf("**");
	
	if (n<=0 || n>50)
	printf("Pogresan unos\n");
	else break;
	} 
	while (1);
	
	for (i=0; i<n; i++){
		for (j=0; j<(n*4)-3; j++){
			
			if(j==i) printf ("*");
			else if (j==2*(n-1)-i) printf ("*");
			else if (j==2*(n-1)+i) printf ("*");
			else if (j==4*(n-1)-i) printf ("*");
			else printf(" ");
		}
		printf("\n");
	
		
	}
	

	return 0;
}
