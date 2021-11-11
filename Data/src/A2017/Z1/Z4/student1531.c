#include <stdio.h>

int main() {
	int i,j,r,k,s;
	do {printf("Unesite broj redova: ");
	scanf("%d", &r);}
	while (r<1 || r>10);
	do {printf("Unesite broj kolona: ");
	scanf("%d", &k);}
	while (k<1 || k>10);
	do {printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &s);}
	while (s<1 || s>10);
	for (i=0; i<(2*r+1);i++){
		for (j=0; j<k*(s+1)+1;j++){
	    	if(i%2==0 && (j==0 || j%(s+1)==0))
	    		printf("+");
	    	else if(i%2==0 && (j%(s+1)!=0 || j!=0) ) printf("-");
	}
	for (j=0; j<k*(s+1)+1;j++){
		if(i%2!=0 && (j==0 || j%(s+1)==0)) printf("|");
	    	else printf(" ");

	}
	printf("\n");
		
	}
	return 0;
}