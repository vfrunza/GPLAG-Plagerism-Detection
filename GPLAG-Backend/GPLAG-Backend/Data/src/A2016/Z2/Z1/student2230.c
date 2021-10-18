#include <stdio.h>
#include <math.h>

int main() {
	int d=0,konacno=0;
	int i=0;
	int broj;
	int brojac=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	int n=broj;
	int br=broj;
	int brojac1=0;
	while(br!=0){
		br/=10;
		brojac1++;
	}
	if(broj!=0){
	while(brojac!=brojac1){
		int a=n%10;
		n=n/10;
		
		int b=n%10;
		brojac++;
		if(a<0) a=-1*a;
		if(b<0) b=-1*b;
		d=(a-b)*pow(10,i);
		if(d<0) d=-1*d;
		i++;
		
		
	
	konacno+=d;
	
	}
	}
printf("%d    ",konacno);
	
	return 0;
}
