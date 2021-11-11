#include <stdio.h>

int main() {
	float i, j, k, l, m;
	int n;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<1 || n>50)printf("Pogresan unos\n");
	}while(n<1 || n>50);
	if(n==1){
		printf("***");
		return 0;
	}
	for(i=0; i<n; i++){
	    for (j=0; j<=(n-1)-(n-i); j++)
        {
            printf(" ");
        }
            printf("*");
    
        for(k=0; k<((n-3)+(n-2*i)); k++){
            printf(" ");
        }
        if (i<n-1)printf("*");
        for(l=0; l<=(2*n-2)-2*(n-i); l++){
        	printf(" ");
        }
        if (i!=0)printf("*");
        for(m=0; m<(2*n-1)-2*(i+1); m++){
        	printf(" ");
        }
        if(i!=n-1)printf("*");
        printf("\n");
	}
	return 0;
}
