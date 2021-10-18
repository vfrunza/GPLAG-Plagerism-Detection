#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define eps 0.0001
int main() {
	double x1,y1,x2,y2,x3,y3,a,b,c,P,alfa,beta,gama,cosx,cosy,cosz,stepeni1,stepeni2,stepeni3;
	double minute1,minute2,minute3,sekunde1,sekunde2,sekunde3;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);         /*Unijeli smo koordinate tacaka trougla*/
	/*Izracunajmo stranice trougla, da ih mozemo medjusobno uporedjivati*/
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	/*Nadjimo povrsinu, da vidimo da li te tri tacke formiraju trougao ili pripadaju jednom pravcu*/
	P=(1.0/2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
	/*Nisam uzimao modul pa zbog cinjenice da koordinate tacke mogu biti i negativne P moze biti pozitivna i negativna*/
	if(P<0) P=(-1)*P;
		
	
	cosx= (b*b + c*c - a*a)/(2*b*c);
    alfa = (acos(cosx)*180)/PI;
    minute1=(alfa- (int)alfa)*60;
	sekunde1=(minute1 - (int)minute1)*60;
	minute1=(int)minute1;
	sekunde1=(int)sekunde1;
	stepeni1=(int)alfa;
	cosy = (a*a + c*c - b*b)/(2*a*c);
	beta = (acos(cosy)*180)/PI;
	minute2=(beta- (int)beta)*60;
	sekunde2=(minute2 - (int)minute2)*60;
	minute2=(int)minute2;
	sekunde2=(int)sekunde2;
	stepeni2=(int)beta;
	cosz = (a*a + b*b - c*c)/(2*b*a);
	gama = (acos(cosz)*180)/PI;
	minute3=(gama - (int)gama)*60;
	sekunde3=(minute3 - (int)minute3)*60;
	minute3=(int)minute3;
	sekunde3=(int)sekunde3;
	stepeni3=(int)gama;
	if(sekunde1>59){
		minute1=minute1 + 1;
		sekunde1=sekunde1 - 60;
	}
		if(sekunde2>59){
		minute2=minute2 + 1;
		sekunde2=sekunde2 - 60;
	}
		if(sekunde3>59){
		minute3=minute3 + 1;
		sekunde3=sekunde3 - 60;
	}
		if(minute1>59){
		stepeni1= stepeni1 + 1;
		minute1=minute1 - 60;
	}
		if(minute2>59){
		stepeni2= stepeni2 + 1;
		minute2=minute2 - 60;
	}
		if(minute3>59){
		stepeni3= stepeni3 + 1;
		minute3=minute3 - 60;
	}
	if ((a*b)/2 == P || (a*c)/2 == P || (b*c)/2 == P){
		printf("Pravougli\n");
	}
	
	if (P>0){
		
		if((fabs(a-b))>0.0001 && (fabs(a-c))>0.0001 && (fabs(b-c))>0.0001){
		printf("Raznostranicni");
	}
	else if((fabs(a-b))<=0.0001 && (fabs(a-c))<=0.0001 && (fabs(b-c))<=0.0001){
		printf("Jednakostranicni");
	}
	else 
		printf("Jednakokraki");
}
	else  printf("Linija");
if ((beta<gama && alfa<gama)){
	printf("\nNajveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",stepeni3,minute3,sekunde3);
}
else if ((alfa<beta && gama<beta)){
	printf("\nNajveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",stepeni2,minute2,sekunde2);
}
else if ((alfa>beta && alfa>gama)){
	printf("\nNajveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.",stepeni1,minute1,sekunde1);
}
	
	
	
	
	return 0;
}
