#include <stdio.h>
#define VEL 20

int main() {
	char mat[VEL][VEL];
	int i, j, n, a, b;
	int k=1;
		
	for(i=0; i<VEL; i++){
		for(j=0; j<VEL; j++){
			mat[j][i]= ' ';
		}
	}

	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10){
		printf("Pogresan unos \n");
		 }
	} 
	while(n<=0 || n>10);
	
	do{
		printf("Unesite %d. tacku: ", k);
		scanf("%d", &a);
		scanf("%d", &b);k++;n--;	
		if(a<0 || a>19 || b<0 || b>19) {
			printf("Pogresan unos \n"); 
			n++;
			k--;
		}
		else {mat[a][b]= '*';}
	
	
	}
	while(n>0);

	for(i=0; i<VEL; i++){
		for(j=0; j<VEL; j++){
			printf("%c", mat[j][i]);
		}
		printf("\n");
	}


	return 0;
}
	
