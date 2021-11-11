#include <stdio.h>

int main() {
	int i,j,a,b,n;
	/*ogranicimo slucajeve za unos kao sto je u tekstu zadatka stajalo*/
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&n);
	}while(n<=0 || n>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	}while(b<=0 || b>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&a);
	}while(a<=0 || a>10); 
	/*neka je i velika petlja koja je zaduzena za redove*/
	for (i=0; i<=(2*n); i++){
		for(j=0; j<=b*(a+1); j++){			/*j petlja je zaduzena za kolone*/
			if(i%2==0 && j%(a+1)==0){		/*uslov, ako se ispuni ispisat ce se +*/
				printf("+");
			}
			else if (i%2==0 && j%(a+1)!=0){		/*uslov, ako se ispuni ispisat ce se -*/
				printf("-");
		}
			else if(i%2!=0 && j%(a+1)==0){			/*uslov, ako se ispuni ispisat ce se |*/
				printf("|");
			}
		else if (i%2!=0 && j%(a+1)!=0){				/*uslov, ako se ispuni ispisat ce se razmak*/
		printf(" ");
			}
			
	}							/*predji u novi red, napomena ovo je npr. kad ispise +- red, predji gdje je pipe i razmak*/

		printf("\n");
	}
	return 0;
}
