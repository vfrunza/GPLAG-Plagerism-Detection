#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.14159265359
int main() {
	double t1x,t1y,t2x,t2y,t3x,t3y,A,B,C,hip,katv,katm,P,ugaoR,ugaoS,step,min,sec;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf %lf", &t1x,&t1y);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf %lf", &t2x,&t2y);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf %lf", &t3x,&t3y);
	A=sqrt((t1x-t2x)*(t1x-t2x)+(t1y-t2y)*(t1y-t2y));
	B=sqrt((t2x-t3x)*(t2x-t3x)+(t2y-t3y)*(t2y-t3y));
	C=sqrt((t3x-t1x)*(t3x-t1x)+(t3y-t1y)*(t3y-t1y));
	P=1./2*(t1x*(t2y-t3y)+t2x*(t3y-t1y)+t3x*(t1y-t2y));
	if (P<0) 
	P=-P;
	
	if (A>=B && A>=C) {
		hip=A;
	if (B>C) {
	   katv=B;
	   katm=C; }
	else {
		katv=C;
		katm=B;	}}
		
	else if (B>=A && B>=C) {
		hip=B;
	if (A>C) {
		katv=A;
		katm=C; }
	else {
		katv=C;
		katm=A; }}
		
	else if (C>=A && C>=B) {
		hip=C;
	if (A>B) {
		katv=A;
		katm=B; }
	else {
		katv=B;
		katm=A; }}

	ugaoR=acos((katv*katv+katm*katm-hip*hip)/(2*katv*katm));
	ugaoS=(ugaoR*180)/PI;
	step=(int)ugaoS;
	min=(ugaoS-(int)ugaoS)*60;
	sec=(min-(int)min)*60;
	if (sec>59) {
		min+=1; 
		sec=0; }
	if (min>59) {
		step+=1;
		min=0; }
	min=(int)min;
	sec=(int)sec;
	
	if ((int)step==90 && (int)min==0 && (int)sec==0)
	printf ("Pravougli\n");
	if (katv+katm==hip || hip+katv==katm || hip+katm==katv)  
	printf ("Linija\n"); 
	else if (hip-katv<E && hip-katm<E && hip-katv>-E && hip-katm>-E) 
	printf ("Jednakostranicni\n"); 
	else if ((hip-katv<E && hip-katv>-E) || (katv-katm<E && katv-katm>-E) || (hip-katm<E && hip-katm>-E)) 
	printf ("Jednakokraki\n"); 
	else
	printf ("Raznostranicni\n");
	
	printf ("Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", step,min,sec);
	return 0;
}
