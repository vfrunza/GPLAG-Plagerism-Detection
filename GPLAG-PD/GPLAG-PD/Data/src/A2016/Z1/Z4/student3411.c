#include <stdio.h>

int main() {
	int n=-1, pocx,br1=0;
	while(n<1 || n>50)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<1 || n>50) printf("Pogresan unos\n");
	}
	pocx=(2*(n-1)-1);
	int i, j;
	for(i=0; i<n; i++)
    {   if(n==1) {printf("***"); break; }
    	for(j=0; j<br1; j++) printf(" ");
		if(i==(n-1)){
			printf("*");
			for(j=0; j<pocx; j++) printf(" ");
			printf("*");
	     	}
		if(i==0){
			printf("*");
			for(j=0; j<pocx; j++) printf(" ");
			printf("*");
			for(j=0; j<pocx; j++) printf(" ");
			printf("*");
		    }
		if(i>0 && i<(n-1)){
		    printf("*");
		    for(j=0; j<(pocx-2*i); j++) printf(" ");
		    printf("*");
		    for(j=0; j<(2*i-1); j++) printf(" ");
		    printf("*");
		    for(j=0; j<(pocx-2*i); j++) printf(" ");
		    printf("*");
		    
		}
	br1++;
	printf("\n");
	}
	return 0;
}
