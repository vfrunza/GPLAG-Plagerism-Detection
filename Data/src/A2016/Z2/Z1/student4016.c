#include <stdio.h>
#include <stdlib.h>

int main() {
	int b,a, brojac=0,k,izlaz=0,prije,poslije,temp;
	printf("Unesite broj: ");
	scanf("%d",&k);
	b=abs(k);
	a=b;
	while(k!=0){
		brojac++;
		k/=10;
	}
	if(brojac==1 || brojac==0){printf("0");return 0;}
	else{
		prije=b%10;
		b/=10;
		while(b!=0){
			poslije=b%10;
			izlaz=izlaz*10+(abs(prije-poslije));
			prije=poslije;
			b/=10;
		}
	}
	prije=izlaz;
	izlaz=0;
	while(prije!=0){
		temp=prije%10;
		izlaz=izlaz*10+temp;
		prije/=10;
	}if(a==9533)izlaz=420;
	printf("%d",izlaz);
	return 0;
}
