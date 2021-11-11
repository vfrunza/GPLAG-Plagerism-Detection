#include <stdio.h>
#include <math.h>

int main() {
int broj;
int a;
int b;
int pomocni=0;
int c;
int suma=0;
int k=1;
printf("Unesite broj: ");
scanf("%d",&broj);
if(broj<0){
broj=fabs(broj);
}
while(broj>0){
	if(broj/10==0)break;
a=broj%10;
broj/=10;
b=broj%10;
c=fabs(a-b);
c=c*k;

pomocni+=c;
k*=10;

}

printf("%d",pomocni);
	return 0;
}
