#include <stdio.h>

int main() {
	
	int i,j,r,k,s,l;
		do{
		printf("Unesite broj redova: ");
			scanf ("%d,", &r);
		} while (r<=0 || r>10) ;
		
		do{
		printf("Unesite broj kolona: ");
			scanf("%d", &k);
		} while  (k<=0 || k>10);
		
		do{
		printf("Unesite sirinu jedne kolone: ");
			scanf("%d",&s);
		} while  (s<=0 || s>10);
			
		l=0;
		while (l<r) {
			i=0;
		while (i<k) {
			printf("+");
		j=0;
		while (j<s) {
			printf ("-");
			j++;
		}
		
		if (i==k-1) {
			printf ("+");
			printf ("\n");
			}
			i++;
		}
		
		i=0;
		while (i<k) {
			printf ("|");
			j=0;
			while (j<s) {
				printf (" ");
				j++;
			}
			if(i==k - 1) {
				printf ("|");
				printf ("\n");
			}
			i++;	
			}
			l++;
		}
		
		i=0;
		while (i<k) {
			printf ("+");
			j=0;
			while (j<s) {
				printf ("-");
				j++;
			}
			if(i==k- 1) {
				printf ("+");
				printf ("\n");
			}
			i++;
	}
		return 0;
}