#include <stdio.h>

int main() {
    
    int broj, novi_broj=0, puta=1,cifra,temp1,temp2;
    
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	if(broj<0)broj*=-1;
	
	while(broj/10!=0){
	    
	    temp1=broj%10;
	    broj/=10;
	    temp2=broj%10;
	    
	    cifra=temp1-temp2;
	    if(cifra<0)cifra*=-1;
	    cifra*=puta;
	    
	    puta*=10;
	    
	    novi_broj+=cifra;
	}
	
	printf("%d", novi_broj);
	return 0;
}
