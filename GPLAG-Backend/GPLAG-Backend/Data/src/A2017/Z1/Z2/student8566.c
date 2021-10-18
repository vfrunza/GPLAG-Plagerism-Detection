#include <stdio.h>
#include <math.h>

int main() {
	
	double x1,x2,x3,y1,y2,y3;
    double P;
	
    float a,b,c;
    
    

	
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf""%lf",&x1, &y1);
		printf("Unesite koordinate tacke t2: ");
	scanf("%lf""%lf",&x2, &y2);
		printf("Unesite koordinate tacke t3: ");
	scanf("%lf""%lf",&x3, &y3);

	a = sqrt( pow(x1-x2,2) + pow(y1-y2,2));
	b=sqrt( pow(x1-x3,2) + pow(y1-y3,2));
	c=sqrt(pow(x2-x3,2)+pow(y2-y3,2));

 P=0.5*(fabs( (x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2))));
 if(P==0){
 printf("Linija");}
 else {
 
   if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)){
	printf("Pravougli\n");}

	
  if ((a==b && a==c )||( b==c && b==a) ||(c==a && c==b)) {
	printf("Jednakostranicni");}
	 if ((a==b && a!=c)|| a==c &&  || b==c) {
	printf("Jednakokraki");} 
	 else if(a!=b && b!=c && a!=c)
	printf("Raznostranicni");
 }
	

return 0;
}
