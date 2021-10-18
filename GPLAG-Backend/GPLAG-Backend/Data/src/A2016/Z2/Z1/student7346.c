#include <stdio.h>
int main() {
	int b,broj;
	int s,s1;
	int suma=0,i=1;
	printf("Unesite broj: ");
	scanf("%d", &b);
	broj=b;
	if(broj<0) broj=-broj;
	if(broj<=9){
		printf("%d", 0); 
		return 0;
	}
	while(broj>=10){
         s=broj%10; broj/=10; 
         s1=broj%10; s-=s1;
         if(s<0){
         	s=-s;
         }
         suma+=s*i;  i=i*10;
	}
	
	printf("%d", suma);
	return 0;
}
