#include <stdio.h>

int main() {
	int a,b,c,j,i,I,J;
	do {
	   printf("Unesite broj redova: ");
	   scanf("%d",&a); }
	   while(a<=0 || a>10);
	   
	do {   
	printf("Unesite broj kolona: ");
	scanf("%d",&b); }
	while(b<=0 || b>10);
	
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c); }
	while(c<=0 || c>10);
	I=(a*2)+1;
	J=b*c+1;
	for(i=0;i<I;i++ ) {
		for(j=0;j<J;j++) {
			if(i%2==0 && j%c==0) printf("+");
			if(i%2!=0 && j%c==0) printf("|");
			if(i%2==0 && j%c+1!=0 && j<J-1 ) printf("-");
			
			else printf(" ");
			
		}
		printf("\n");
	}
	return 0;
}
