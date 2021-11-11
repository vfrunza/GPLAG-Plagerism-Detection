#include <stdio.h>
#include<math.h>
int main() {
	//printf("Zadaća 1, Zadatak 4");
	int i,j,n; float f;
	
//	do{
//	printf("Unesite broj n: ");
//	scanf("%f",&f);
//	
//	if(f>50||ceilf(f) != f||f<1){
//		printf("Pogresan unos");
//	}
	//printf("\n");  ZA OVO TESTIRATI KAD SE BUDE IMALO VREMENA
	
//	} while (f>50||ceilf(f) != f);
	
	
	for(;;){
		
			printf("Unesite broj n: ");
	scanf("%f",&f);
	
	if(f>50||ceilf(f) != f||f<1){
		printf("Pogresan unos\n");
	} else if (f<50||ceilf(f)==f){
		break;
	}
	printf("\n");
		
	}
	
	
	
	n=(int)f;
	if(n==1){
		for(i=1;i<=3;i++){
			printf("*");
		}
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=(4*n-3);j++){
			if(i==1){
				
					if(j==1||j==(2*n-1)||j==(4*n-3)){
						printf("*");
					} else {
						printf(" ");
					}
				
			} else if (i<n&&i!=1) {
				
				if(j==i||j==2*n-i||j==2*n+i-2||j==4*n-2-i){
					printf("*");
				} else {
					printf(" ");
				}
			} else if (i==n){
				if(j==i||j==2*n+i-2){
					printf("*");
				} else {
					printf(" ");
				}
				
				
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
