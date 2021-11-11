#include <stdio.h>

int main() {
	int x, i, j;
	printf("Unesite broj n: ");
	scanf("%d", &x);
	while((x<=0)||(x>50)){
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &x);
	}
	if (x==1){printf("***");}
	else{
	
	for(i=0;i<x;i++){
		for(j=0;j<=4*x-4;j++){
			if ((i==j)||
			(j==x*2-2-i)||
		    (j==x*2-2+i)||
			(j==x*4-4-i)){printf("*");}
			else {printf(" ");}
		
		}
		printf("\n");
	}
	}
	return 0;
}
