#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
int n,n1=0,broj1=0,broj2=0,broj=0,i=0,cifre=0,brojac=0;
printf("Unesite broj: ");
scanf("%d",&n);
if(n>0){
	n1=n;
while(n1>0){
	broj=n1%10;
	brojac++;
	n1/=10;
}}else if(n<0){
	n=abs(n);
	n1=n;
	while(n1>0){
		broj=n1%10;
		brojac++;
		n1/=10;
}}if(brojac==1 || n==0) printf("0");
else if(brojac>1 && n>0){
	for(i=brojac-1;i>0;i--){
		cifre=pow(10,i);
		broj1=n/cifre;
		n%=cifre;
		cifre=pow(10,i-1);
		broj2=n/cifre;
		broj=broj1-broj2;
		if(broj<0) broj=abs(broj);
		if(broj1==broj2 && broj1>0 && broj1<9) {printf("0");break;}
		else if(broj1==broj2 && broj1!=1 && i==brojac-1){
			i-=3;
			cifre=pow(10,i);
			n=n%cifre;
		}else printf("%d",broj);
	}}
	else if(brojac>1 && n<0){
		n=abs(n);
		for(i=brojac-1;i>0;i++){
			cifre=pow(10,i);
			broj1=n/cifre;
			n%=cifre;
			cifre=pow(10,i-1);
			broj2=n/cifre;
			broj=broj1-broj2;
			if(broj<0) broj=abs(broj);
			if(broj1==broj2 && broj1>0 && broj1<9) {printf("0");break;}
			else if(broj1==broj2 && broj1!=1 && i==brojac-1){
				i-=3;
				cifre=pow(10,i);
				n=n%cifre;
			}else printf("%d",broj);
	}}return 0;}
