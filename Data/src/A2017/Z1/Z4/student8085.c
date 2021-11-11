#include <stdio.h>

int main() {

int a,b,c;
int i,j;

do {
printf("Unesite broj redova: ");
scanf("%d", &a);

printf("Uneiste broj kolona: ");
scanf("%d", &b);

printf("Uneiste sirinu jedne kolone: ");
scanf("%d", &c);

} while((a<0 || a>=10) || (b<0 || b>=10) || (c<0 || c>=10));

for(i=0; i<2*a+1; i++) {
	for(j=0; j<b*(c+1)-c; j++) {
		if(i%2==0 && j%(c+1)==0 ) printf("+");
		else if(i%2!=0 && j%(c+1)==0) printf("|");
		else if(i%2==0) printf("-");
		else printf(" ");
	}
	printf("\n");
}
	return 0;
}
