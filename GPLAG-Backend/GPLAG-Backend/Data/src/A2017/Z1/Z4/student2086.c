#include <stdio.h>

int main() {
int a, b, c, i, j, k, x, y, l;


do{
	printf("Unesite broj redova: ");
	scanf("%d", &a);
} while(a<1 || a>=11);

do{
	printf("Unesite broj kolona: " );
	scanf("%d", &b);
} while(b<1 || b>=11);

do {	
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &c);
} while(c<1 || c>=11);



for(y=0; y<a; y++){
  for(l=a; l<(a+1); l++){
    for(i=0; i<(b+1); i++){
	printf("+");
	for(j=0; j<c; j++) {
		if(i==b) 
			break;
			
		printf("-");
      }
    }	
  }
printf("\n");
for(k=0; k<(b+1); k++){
	printf("|");
	for(x=0; x<c; x++){
		if(k==b) 
			break;
			
		printf(" ");
	  }
    }
printf("\n");
}	
	
for(l=a; l<(a+1); l++){
  for(i=0; i<(b+1); i++){
	printf("+");
	for(j=0; j<c; j++) {
		if(i==b) 
			break;
			
		printf("-");
      }
    }
}

return 0;

	
}

