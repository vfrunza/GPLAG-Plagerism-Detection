#include <stdio.h>
#define duzina 10

int main() {
	int n,i,j,k,l,m,o,p,provjera=0,provjera2=0;
	int nizi[duzina];
	int nizj[duzina];
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>10 || n<=0)  {
	do {
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}while(n>10 || n<=0);
	}
	
	for(k=0;k<n;k++) {
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d",&i,&j);
		if(i>19 || j>19 || i<0 || j<0) {
			do{
				printf("Pogresan unos\n");
				printf("Unesite %d. tacku: ",k+1);
				scanf("%d %d",&i,&j);
			}while(i>19 || i<0 || j<0 || j>19);
		}
		nizi[k]=i;
		nizj[k]=j;
		
	}
	
	for(l=0;l<20;l++) {
		for(m=0;m<20;m++) {
			for(o=0;o<n;o++) {
				if (o>0) {
				for(p=0;p<o;p++) {
				if(nizi[o]==nizi[p] && nizj[o]==nizj[p]) provjera=1;
				}
				}
				if(provjera!=0) { provjera=0; continue; }
				if(nizi[o]==m && nizj[o]==l) {printf("*"); provjera2=1;}
			}
			if(provjera2==0) printf(" ");
			provjera2=0;
		}
		printf("\n");
	}
	
	return 0;
}
