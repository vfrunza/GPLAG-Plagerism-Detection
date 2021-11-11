#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	
	int a, c1=0, c2=0, s=0, rez=0, imalnula=1, brojn=0, i;
	printf("Unesite broj: ");
	scanf("%d",&a);
	a=abs(a);
	/*Slucaj kada je unesena jedna cifra*/
	if((a<=9)&&(a>=0)){
		printf("0");
		return 0;
	}
	
	else{
		while(a>9){
		c1=a%10;
		a=a/10;
		if(a>0){
		c2=a%10;
		s=abs(c1-c2);
		if(s!=0)
		imalnula=0;
		if(imalnula==1)
		brojn++;
		else
		rez=rez*10+s;}
		
	}}
	if(imalnula==1){
		printf("0");
		return 0;
	}
	imalnula=1;
	while(rez){
		if(rez%10!=0)
		imalnula=0;
		if(imalnula==0)
		printf("%d",rez%10);
		rez=rez/10;}
		for(i=0;i<brojn;i++){
			printf("0");
		}
		
	
	return 0;
}
