#include <stdio.h>
/* Napisati program koji na ekranu ispisuje tabelu sastavljenu od znakova plus (+), minus (-) i vertikalna linija tj. pipe (|) kao u primjeru. 
Korisnik unosi broj redova, broj kolona i širinu jedne kolone (u minusima) a zatim se iscrtava tabela.
Pomoću do-while petlje osigurati da su svi uneseni brojevi veći od nule a manji ili jednaki 10. */
int main() {

    int i,r,s,j,k,x=0;
    
    do{
    printf("Unesite broj redova: ");
    scanf("%d",&r);
    }while(r<1 || r>10);
    do{
    printf("Unesite broj kolona: ");
    scanf("%d",&k);
    }while(k<1 || k>10);
    do{ printf("Unesite sirinu jedne kolone: ");
    scanf("%d",&s);
    } while(s<1 || s>10);
  	while(x<=r){
  	    x++;
  	for(i=0; i<=(k*s+k); i++) {
  	    if(i==0 || i%(s+1)==0){
  	        printf("+");
  	    }
  	    else
  	    printf("-");
  	}
  	printf("\n");
  	if(x<=r){
  	for(j=0;j<=k*s+k;j++){
  	    
  	    if(j==0 || j%(s+1)==0){
  	        printf("|");
  	    }
  	    else
  	    printf(" ");
  	    
  	}
	 printf("\n");     
  	}
}
	return 0;
}
