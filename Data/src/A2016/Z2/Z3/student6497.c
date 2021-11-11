#include <stdio.h>

int main() {
	
	int i, n, k[20][20]={{0}}, p, q, f, v;
	unos_tacke:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>10 || n<1) { printf("Pogresan unos\n"); goto unos_tacke; }
	for(i=1; i<n+1; i++) {
	
	unos_kord:	
	    printf("Unesite %d. tacku: ", i);
	    scanf("%d %d", &p, &q);
		if(p>19 || p<0 || q>19 || q<0) { printf("Pogresan unos\n"); goto unos_kord; }
		k[q][p]=1;
	}
	
	for(v=0; v<20; v++) {
		for(f=0; f<20; f++) {
			if(k[v][f]!=0)
			printf("*");
			else 
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}