#include <stdio.h>

int main() {
	int n, i, j, a;
	do{ printf("Unesite broj N: ");
	scanf("%d", &n);
		if(n%4==0 && n>=8) break;
		else printf("Neispravno N!\n");
	} while(n%4!=0 || n<8);
	printf("\n");
	a=n/2;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
		if(i==j && i<a && j<a) printf("\\");
		else if((j+1)==(a-i)) printf("/");
			else if((i==0 && ((j==a) || (j+1)==n)) || ((i+1)==a && ((j+1)==n || (j==a)))) printf("+");
			else if(((j+1)!=n && j!=a) && (i==0 || (i+1)==a) && j>a && i<a)
			printf("-");
			else if(((i+1)!=a && i!=0) && (j==a || (j+1)==n) && i<a) printf("|");
			else if((i==a && ((j==0) || (j+1)==a)) || ((i+1)==n && ((j+1)==a || (j==0)))) printf("+");
			else if(((j+1)!=a && j!=0) && (i==a || (i+1==n)) && j<a)
			printf("-");
			else if(((i+1)!=n && i!=a) && (j==0 || (j+1)==a) && i>a) printf("|");
			else if((j==(3*n/4-1) || j==(3*n/4)) && (i!=3*n/4-1 && i!=3*n/4) && i>=a) printf("|");
		    else if((i==j && (i==3*n/4 || i==3*n/4-1)) || ((i+1)==j && i==3*n/4-1) || ((j+1)==i && j==3*n/4-1)) printf("+");
		    else if((i==(3*n/4-1) || i==(3*n/4)) && (j!=3*n/4 && j!=3*n/4-1) && j>=a) printf("-");
		    else printf(" ");}printf("\n");} return 0;}