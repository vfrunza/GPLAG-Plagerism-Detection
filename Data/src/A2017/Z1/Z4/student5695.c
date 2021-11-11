#include <stdio.h>

int main() {
	int a,b,c,i,j;
	for(;;) {
		printf("Unesite broj redova: ");
		scanf("%d",&a);
		if(a>0 && a<=10) break;
	}
	for(;;) {
		printf("Unesite broj kolona: ");
		scanf("%d",&b);
		if(b>0 && b<=10) break;
	}
	for(;;) {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&c);
		if(c>0 && c<=10) break;
	}
	for(i=0;i<(2*a+1);i++) {
		for(j=0;j<((c+1)*b+1);j++) {
			if(i%2==0) {
				if(j%(c+1)==0) printf("+");
				else printf("-");
			}
			else {
				if(j%(c+1)==0) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}