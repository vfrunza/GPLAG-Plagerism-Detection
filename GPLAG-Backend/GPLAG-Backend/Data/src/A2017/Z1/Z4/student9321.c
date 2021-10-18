#include <stdio.h>

int main() {

int a,b,d,i,j,k;
do {
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	}while(a<=0 || a>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	} while(b<=0 || b>10);
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&d);
	} while(d<=0 || d>10);
	
	for(i=0; i<=2*a; i++){
	if(i%2==0){
		for(j=0; j<=b*(d+1); j++){
		if(j%(d+1)==0)
			printf("+");
		else
			printf("-");
		}	
	}
	else {
		for(k=0; k<=b*(d+1); k++){
			if(k%(d+1)==0) 
				printf("|");
			else
			printf(" ");
			
		}
	}
	printf("\n");
}
	return 0;
}
