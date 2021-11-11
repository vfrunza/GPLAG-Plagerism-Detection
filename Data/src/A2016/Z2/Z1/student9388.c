#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	int a;
	int zadnja=0, predzadnja=0, rezultat=0;
	int b=1;
	
	printf("Unesite broj: ");
	scanf("%d", &a);
	if(a<0){
		a=abs(a);
	}
	if( a==-9 && a==-8 && a==-7 && a==-6 && a==-5 && a==-4 && a==-4 && a==-3 && a==-2 && a==-1 && a==0 && a==1 && a==2 && a==3 && a==4 && a==5 && a==6 && a==7 && a==8 && a==9 ){
		a=0;
		printf("%d", a);
	}
	while(a>=10){
		
	
		zadnja=a%10;
		predzadnja=(a/10)%10;
		rezultat+=abs(zadnja-predzadnja)*b;
		b*=10;
		a=a/10;
	}
	printf("%d", rezultat);
	
	
	
	return 0;
}
