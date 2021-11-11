#include <stdio.h>

int main()
{
	int a,b,c;
	int i,j;

do{	printf("Unesite broj redova: ");
	scanf("%d",&a);
}while(a<=0 || a>10);
	
do{	printf("Unesite broj kolona: ");
	scanf("%d",&b);
}while(b<=0 || b>10); 
do{	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);

}while(c<=0 || c>10 );

	for(i=0; i<(2*a+1); i++) {
		for(j=0; j<(b+1+b*c); j++) {
			if(i%2==0 && j%(c+1)==0) {
				printf("+");
			} else if(i%2==0 && j%(c+1)!=0) {
				printf("-");
			} else if (i%2!=0 && j%(c+1)==0) {
				printf("|");
			} else	if(i%2!=0 && j%(c+1)!=0) {
				printf(" ");
			}
		}

		printf("\n");
	}


	return 0;
}
