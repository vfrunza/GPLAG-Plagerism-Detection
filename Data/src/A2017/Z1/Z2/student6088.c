#include <stdio.h>
#include <math.h>
#define e 0.0001
#define pi 3.1415926535
int main() {
	int ALFA, BETA, GAMA;
	double a,b,c,tax,tay,tbx,tby,tcx,tcy,L,B,C,L1,B1,C1,P;
	int max;
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf",&tax,&tay);
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&tbx,&tby);
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&tcx,&tcy);
	a=sqrt(pow(tbx-tcx,2)+pow(tby-tcy,2));
	b=sqrt(pow(tax-tcx,2)+pow(tay-tcy,2));
	c=sqrt(pow(tbx-tax,2)+pow(tby-tay,2));
	
	P=0.5*fabs( tax*(tby-tcy) + tbx*(tcy-tay) + tcx*(tay-tby)   );
	
	L1=acos( (pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c) );
	B1=acos( (pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c) );
	C1=acos( (pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b) );
	std::cout<<""
	
	L=L1 *(180/pi);
	B=B1 *(180/pi);
	C=C1 *(180/pi);
	
	double sekA=L-((int)L);
	int minL = (sekA*3600)/60;
	int sekuL = fmod((sekA*3600.00),60.00);
	ALFA=(int)L;
	
	
	double sekB=B-((int)B);
	int minB=(sekB*3600)/60;
	int sekuB= fmod((sekB*3600.00),60.00);
	BETA=(int)B;
	
	double sekC=C-((int)C);
	int minC=(sekC*3600)/60;
	int sekuC= fmod((sekC*3600.00),60.00);
    GAMA=(int)C;
    
	
	if ( P==0){
	printf("Linija\n");
	printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	return 0;}
	if(fabs(L-90.00)<=e || fabs(B-90.00)<=e || fabs(C-90.00)<=e)
	printf("Pravougli\n");
	if ( fabs(L-B)<=e && fabs(B-C)<=e )
	printf("Jednakostranicni\n");
	else if ( fabs(L-B)<=e || fabs(B-C)<=e || fabs(L-C)<=e)
	printf("Jednakokraki\n");
	else printf("Raznostranicni\n");
	
	if(L>B && L>C)printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",ALFA,minL,sekuL);
	else if(B>L && B>C)printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",BETA,minB,sekuB);
	else if(C>L && C>B)printf ("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",GAMA,minC,sekuC);
	
	
	
	 
	
	
	
	
	
	
	
	
	return 0;
}
