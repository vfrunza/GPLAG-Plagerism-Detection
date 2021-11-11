#include <stdio.h>

int main() {
int br_tackica,i=0,j=0,k=0,a=0,b=0;
char m[20][20];
printf("Unesite broj tacaka: ");
scanf("%d",&br_tackica);
if(br_tackica>10 || br_tackica<=0 || br_tackica>400) {printf("Pogresan unos");
printf("\nUnesite broj tacaka: ");
scanf("%d",&br_tackica); }
while(br_tackica>10 || br_tackica<=0 || br_tackica>400) {
	printf("Pogresan unos");
	printf("\nUnesite broj tacaka: ");
	scanf("%d",&br_tackica);
	if(br_tackica<=10 && br_tackica>0) break;
}
for(i=0;i<=19;i++) {
	for(j=0;j<=19;j++) {
		m[i][j]=' ';
	}
}
for(k=1;k<=br_tackica;k++) {
	printf("Unesite %d. tacku: ",k);
	scanf("%d %d",&a,&b);
	
	if(a<0 || a>19 || b<0 || b>19) {
		printf("Pogresan unos"); 
		
	}
		while(a<0 || a>19 || b<0 || b>19) {
			printf("\nUnesite %d. tacku: ", k);
			scanf("%d %d",&a,&b);
			if(a>=0 && a<=19 && b>=0 && b<=19) break;
			printf("Pogresan unos");
	}
	
	m[a][b]='*';
}
for(i=0;i<=19;i++) {
	for(j=0;j<=19;j++) {
		printf("%c",m[j][i]);
		
	}
	printf("\n");
}
return 0; }