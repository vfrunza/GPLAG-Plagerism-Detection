#include <stdio.h>

int main() {
	int a,j,i,z,c,n,t;
	z= 0;
	c = 0;
	t = 0;
	do{
		
		printf("Unesite broj N: ");
		scanf ("%d",&a);
		if ((a < 8 || a % 4 != 0)){
			printf("Neispravno N!\n");
		}
	} while ((a < 8 || a % 4 != 0) );
	printf("\n");
	for (i = 0;i<a;i++) {
		if ( i < a/2) {
		for (j=0;j<a/2;j++) {
			if (j == i) {
				printf("\\");
			}	else if (j == a/2 - 1 - i){
					printf ("/");
			} else {
				printf(" ");
			}
		}
		for (j = a/2;j<a;j++){
			if (i == 0 || i == a/2 - 1) {
				if (j == a/2 || j == a - 1) {
					printf ("+");
				} else {
					printf ("-");
				}
			} else {
				if (j == a - 1 || j == a/2) {
					printf ("|");
				} else {
					printf (" ");
				}
			}
			}
				printf("\n");
		} else {
			for (j = 0;j<a/2;j++){
				if (i == a/2 || i == a - 1) {
					if (j == 0 || j == a/2 - 1) {
						printf ("+");
					} else {
						printf ("-");
					}
				} else {
					if (j == a/2 - 1 || j == 0) {
						printf ("|");
					} else {
						printf (" ");
					}
				}
			}
			for (j = a/2;j<a;j++){
				if ((i == a - (a/2)/2) || (i== a -(a/2)/2 - 1)){
					if ((j == a - (a/2)/2) || (j== a -(a/2)/2 - 1)){
					printf ("+");
					} else {
						printf("-");
					}
				} else if ((j == a - (a/2)/2) || (j== a -(a/2)/2 - 1)){
					printf ("|");
				} else if ((j == a/2 + ((a/2 - 2)/2)) || ((j == a/2 + ((a/2 - 2)/2)) + 1)) {
					printf (" ");
				} else {
					printf(" ");
				}
			}
				printf("\n");
		}
	
	} 
	return 0;
}
