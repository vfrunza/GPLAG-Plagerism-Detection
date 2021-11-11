#include <stdio.h>
#include <stdlib.h>
int main() {
	int pr,dr,br,rez=0,r=0,i=1;
	printf("Unesite broj: ");
	scanf("%d",&br);
	if(br/10==0){ printf("0");
	return 0;}
	if(br<0) br=br*(-1);
	while (br!=0){
	pr=br%10;	
	br=br/10;
	if(br==0) break;
	dr=br%10;
	r=(pr-dr);
	rez=rez+abs(r)*i;
	i=i*10;}
	
	printf("%d",rez);
	return 0;
}
