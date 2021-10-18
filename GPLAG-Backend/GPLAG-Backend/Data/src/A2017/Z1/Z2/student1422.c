#include <stdio.h>
#include <math.h>
#define e 0.0001
#define PI 3.1415926535

int main() {
	double x1, x2, x3, y1, y2, y3, ak, bk, ck, A, B, C, a, b, c, max;
	int A_STEP, B_STEP, C_STEP, A_MIN, B_MIN, C_MIN, A_SEK, B_SEK, C_SEK;
	/*Varijable za uglove su sljedece respektivno kod tacaka trougla A, B i C, dok  su varijable A_STEP, B_STEP, C_STEP, A_MIN, B_MIN, C_MIN, A_SEK, B_SEK i C_SEK 
	definiane za cjelobrojne iznose stepena, minuta i sekundi navedenih uglova*/
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	/*Izracunavanje stranica a, b i c trougla, te uglova pomocu kosinusne teoreme*/
	ak=(pow((x3-x2),(2.00)))+(pow((y3-y2),(2.00)));
	bk=(pow((x1-x3),(2.00)))+(pow((y1-y3),(2.00)));
	ck=(pow((x2-x1),(2.00)))+(pow((y2-y1),(2.00)));
	
	a=sqrt(ak);
	b=sqrt(bk);
	c=sqrt(ck);
	
	A=((acos((bk+ck-ak)/((2.00)*b*c)))*180.00)/PI;
	B=((acos((ak+ck-bk)/((2.00)*a*c)))*180.00)/PI;
	C=((acos((bk+ak-ck)/((2.00)*b*a)))*180.00)/PI;

	A_STEP = (int) (A) ;
	A_MIN = (int) ((A-A_STEP)*60.00) ;
	A_SEK = (int) ((((A-A_STEP)*60.00)-A_MIN)*60.00) ;
	B_STEP = (int) (B) ;
	B_MIN = (int) ((B-B_STEP)*60.00) ;
	B_SEK = (int) ((((B-B_STEP)*60.00)-B_MIN)*60.00) ;
	C_STEP = (int) (C) ;
	C_MIN = (int) ((C-C_STEP)*60.00) ;
	C_SEK = (int) ((((C-C_STEP)*60.00)-C_MIN)*60.00) ;
	
if(a+b>c && a+c>b && b+c>a){	
	if ((fabs(a-b)<e) && (fabs(c-b)<e) && (fabs(a-c)<e)) {
	printf("Jednakostranicni");
	printf("\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
		else if(fabs(a*a+b*b-c*c)<e || fabs(b*b+c*c-a*a)<e || fabs(c*c+a*a-b*b)<e){
		
		if((fabs(a-b)<e) || (fabs(c-b)<e) || (fabs(a-c)<e)){
		printf("Pravougli\nJednakokraki");}
		else {
		printf("Pravougli\nRaznostranicni");}
		printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
	}
	else if(fabs(A-B)<e)
		{if(A>C && A<90){
		max=A;
		printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", A_STEP, A_MIN, A_SEK);
		}
		else if(C>A && C!=90) {
		max=C;
		printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", C_STEP, C_MIN, C_SEK);
	}
	}
	else if (fabs(A-C)<e)
		{if(A>B && A<90){
		max=A;
		printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", A_STEP, A_MIN, A_SEK);
		}
		else if (B>A && B!=90) {
		max=B;
		printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", B_STEP, B_MIN, B_SEK);
	}
	}
	else if (fabs(B-C)<e)
	{if(B>A && B<90){
		max=B;
		printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", B_STEP, B_MIN, B_SEK);
		}
		else if(A>B && A!=90) {
		max=A;
		printf("Jednakokraki\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", A_STEP, A_MIN, A_SEK);
	}
	}
	else if(a!=b && b!=c){	
	printf("Raznostranicni");
	if(A>B && A>C){
		max=A;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", A_STEP, A_MIN, A_SEK);
	}
	else if (B>C && B>A){
		max=B;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", B_STEP, B_MIN, B_SEK);
	}
	else if (C>B && C>A){
		max=C;
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", C_STEP, C_MIN, C_SEK);
	}
	
	}
}
else{	
printf("Linija");
printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");

}
	return 0;
}
