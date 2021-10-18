#include <stdio.h>
#include <math.h>
int main() {
	
	int a, b, c, i, j, z;
		do {
	printf("Unesite broj redova: ");
	scanf("%d", &a);
} while (a<=0 || a>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &b);
	} while (b<=0 || b>10);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
		
	}	while (c<=0 || c>10);
	
	for(i=0; i<b*2; i++ )
{
		if (i%2==0 ){
			printf ("+");
	
			for(j=0; j<b*2; j++){
				
			
		 if (j%3==0){ 
			printf("|");}
	
		



	
}	
		}
		printf("\n");
}
		

return 0;
}
