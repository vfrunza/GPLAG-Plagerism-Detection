#include <stdio.h>

int main() {
	int m, n, w; 
	int i, j; 
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &m); }
	while(m <=0 || m > 10); 
	
	do{
	printf("Unesite broj kolona: "); 
	scanf("%d", &n); }
	while(n<=0 || n> 10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &w); }
	while(w <=0 || w> 10); 

	for(i=0; i < 2*m+1; i++){
		for(j=0; j < w*n + n+1; j++){
			 if((j==n+n*w && i%2==0) || (j==0 && i%2==0) || (j%(w+1)==0 && i ==0 ) || (j%(1+w)==0 && i== 2*m ) || (j%(1+w) == 0 && i%2==0) ) printf("+"); 
			else if((j==0 || j==n+n*w) || j%(1+w)==0 && i%2!=0 )  printf("|"); 
			else if(i%2 == 0 ) printf("-"); 
			else printf(" ");
		}
		printf("\n");
		
	}
	
	
	return 0;
}
