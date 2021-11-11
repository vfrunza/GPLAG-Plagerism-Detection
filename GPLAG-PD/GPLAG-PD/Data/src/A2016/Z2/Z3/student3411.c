#include <stdio.h>
#define duzina 20
int main() {
	int a[duzina]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, b[duzina]={-1}, x=-1, j, i, c[duzina][duzina]={0}, o, p;
	while(x<1 || x>10){
		printf("Unesite broj tacaka: ");
		scanf("%d", &x);
		if(x<1 || x>10) {printf("Pogresan unos");printf("\n");}
	}
	if(x>10) {printf("Pogresan unos. Unesitete broj tacaka ponovo.");scanf("%d", &x);}
	for(i=0; i<x; i++){
		while((a[i]<0 || a[i]>19) || (b[i]<0 || b[i]>19)){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
		if((a[i]<0 || a[i]>19) || (b[i]<0 || b[i]>19)) {printf("Pogresan unos");printf("\n");}
		}
	p=a[i];
	o=b[i];
	c[o][p]=1;
	}
	for(i=0; i<duzina; i++){
		for(j=0; j<duzina; j++){
			if(c[i][j]==1) printf("*"); else printf(" ");
	   }
	   printf("\n");
	}
	return 0;
}
