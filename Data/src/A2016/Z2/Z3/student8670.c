#include <stdio.h>
int main() {
int m,i,j,l,c,d;
char niz[20][20];
while(1) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &m);
	if(m<=10 && m>0) break;
	  else  printf("Pogresan unos \n");
}
for(j=0;j<20;j++) {
	for(l=0;l<20;l++) {
		niz[j][l]=' ';
	}}
for(i=1;i<=m;i++) {
	printf("Unesite %d. tacku: ",i);
	scanf("%d %d", &c,&d);
	if(c<0 || c>19) {printf("Pogresan unos\n"); i--; }else if  ( d<0 || d>19) { printf("Pogresan unos\n");
	i--;
} else {for(j=0;j<20;j++) {
		for(l=0;l<20;l++) {
			if(j==d && l==c) 	niz [j][l]='*';	}
	}}
}
for(j=0;j<20;j++) {
	for(l=0;l<20;l++) {
		printf("%c",niz[j][l]);
	}
	printf("\n");
}
return 0;
}