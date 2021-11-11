#include <stdio.h>

int main() {
	int n, i, j, k, l, m, o, p, r, s, t;
	int z=1, f=1;
	
	do{
 	printf("Unesite broj n: ");
 	scanf("%d", &n);
 	if(n<1 || n>50)
 		printf("Pogresan unos\n");
	}while(n<1 || n>50);
 	
 	
 	
 	
 	printf("*");
 	for(j=0;j<((n-1)+(n-2));j++){
 		printf(" ");
 	}
 	printf("*");
 	for(k=0;k<((n-1)+(n-2));k++){
 		printf(" ");
 	}
 	printf("*\n");
 	
 	
 	int br=n;
 	
 	
 	for(i=0;i<(n-2);i++){
 		br--;
 		for(m=0;m<z;m++)
 			printf(" ");
 		printf("*");
 		for(l=0;l<((br-1)+(br-2));l++)
 			printf(" ");
 		printf("*");
 		for(o=0;o<f;o++)
 			printf(" ");
 		printf("*");
 		for(p=0;p<((br-1)+(br-2));p++)
 			printf(" ");
 		printf("*");
 		for(r=0;r<z;r++)
 			printf(" ");
 		printf("\n");
 		z++;
 		f=f+2;
 	}
 	
 	if(n>1){
	 	for(s=0;s<(n-1);s++)
	 		printf(" ");
	 	printf("*");
	 	for(t=0;t<((n-1)+(n-2));t++)
	 		printf(" ");
	 	printf("*");
 		
 	}	
 	
	return 0;
}
