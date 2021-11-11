#include <stdio.h>

int main() {
	int a,b,c;
	int i,j,l,m,n;
	
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&a);
	}
	while (a<=0 || a>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&b);
	} while (b<=0 || b>10);
	
	
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&c);
	} while (c<=0||c>10);
	
	
	
	n=0;
	while (n<(a+1)){
	i=0;
	while (i<(b+1)){
		
		printf("+");
		
		 j=0;
		while (j<c && i<b){
			printf("-");
			j++;
			
		}
		
		i++;
		
	}
	
	printf("\n");
	
	
	l=0;
	while(l<(b+1)&&n<a){
		printf("|");
		
		m=0;
		while(m<c){
			printf(" ");
			m++;
		}
			l++;
	}
	printf("\n");
	
	n++;
	}
	return 0;
	
	
		return 0;
}
