#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	int br,c,d,s,BROJ=0,lbroj=0,i=0;
	printf("Unesite broj: ");
	scanf("%d", &br);
	if(br<0)
	br=abs(br);
	while(br!=0){
		c=br%10; 
		d=((br%100)-c)/10;
		br=br/10;
		if(br==0) break;
		s=abs(d-c);
		BROJ=pow(10,i)*s;
		lbroj+=BROJ;
		i++;
		
	}
		printf("%d", lbroj);
		return 0;
}
