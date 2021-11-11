#include <stdio.h>
#include <math.h>
#define eps 0.001
#define razl 0.1
#define kor0 0.000001
#include <stdlib.h>
int main() {
	double a,b,c,x1,x2,D,t,x1p,x2p;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	t=(b*b-4.*a*c);
	D=sqrt(t);
	

	 if(t<0){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;}
	
	else if (b<kor0 && D>kor0){
		x1=-(sqrt(-c/a));
		x2=(sqrt(-c/a));}
	
	else if(t>0){
		x1=((-b-D)/2.*a);
		x2=((-b+D)/2.*a);}
	
	else if(t<kor0){
		x1=(-b/(2.*a));
		x2=(-b/(2.*a));}

		
	else if(((fabs(b))<kor0) && ((fabs(c))<kor0)){
		x1=0;
		x2=0;}
		
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&x1p);
		
			if ((fabs(x1p-x1))<eps){
				printf("Tacno\n");break;}
			else if(((x1p-x1)<razl) && ((x1p-x1)>=eps)){
				printf("Priblizno vece\n");}
			else if(((x1-x1p)<razl) && ((x1-x1p)>=eps)){
				printf("Priblizno manje\n");}
			else if((x1p-x1)>=razl){
				printf("Vece\n");}
			else if((x1-x1p)>=razl){
				printf("Manje\n");}
		
	}while(((x1-x1p)<eps) || ((x1p-x1)<eps));
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&x2p);
			if((fabs(x2p-x2))<eps){
				printf("Tacno\n");break;}
			else if(((x2p-x2)<razl) && ((x2p-x2)>=eps)){
				printf("Priblizno vece\n");}
			else if(((x2-x2p)<razl) && ((x2-x2p)>=eps)){
				printf("Priblizno manje\n");}
			else if((x2p-x2)>=razl){
				printf("Vece\n");}
			else if((x2-x2p)>=razl){
				printf("Manje\n");}	
	}while(((x2-x2p)<eps)||((x2p-x2)<eps));
	
	return 0; }
