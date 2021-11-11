#include <stdio.h>
int main() {
	int a,i=0,j=0,b,n;
	char niz[20][20];
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			niz[i][j]=' '; }	}
		do {        
	printf("Unesite broj tacaka: ");
	scanf("%i",&n);
	if(n<=0||n>10) printf("Pogresan unos\n"); }
while(n<=0||n>10);
	for(i=0;i<n;i++) {
		do {
	printf("Unesite %i. tacku: ",i+1);
	scanf("%d",&a);
	scanf("%d",&b);
	if(a<0||a>19||b<0||b>19) printf("Pogresan unos\n");
	else niz[b][a]='*';
	}
while(a<0||a>=20||b<0||b>=20);
}
		for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			printf("%c",niz[i][j]);
		}
				printf("\n");
		}
	return 0;
}
