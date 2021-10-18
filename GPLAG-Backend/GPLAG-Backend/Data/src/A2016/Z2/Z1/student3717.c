#include <stdio.h>
#include <stdlib.h>

int main() {
 int broj,c,d,f,p=1,br=0;
 printf("Unesite broj: ");
 scanf("%d",&broj);
 while(broj!=0){
 	c=broj%10;
 	broj=broj/10;
 	if(broj==0){
 	 break;
 	}
 	d=broj%10;
 	f=abs(d-c);
 	br=br+p*f;
 	p*=10;
 }
 printf("%d",br);
	return 0;
}


