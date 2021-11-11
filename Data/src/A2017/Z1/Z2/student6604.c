#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define PI 3.14159265
int main() {
	
	//Varijable
	double x1,x2,x3,y1,y2,y3,d1,d2,d3,ugao,minute,sekunde,ugao1,ugao2,ugao3;
	
	//Unos varijabli
	printf("Unesite koordinate tacke t1: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Unesite koordinate tacke t2: ");
	scanf("%lf %lf", &x2, &y2);
	
	printf("Unesite koordinate tacke t3: ");
	scanf("%lf %lf", &x3, &y3);
	
	//Stranice trougla
	
	d1=sqrt( (pow( x2-x1 , 2) ) + pow( y2-y1 , 2) );
	d2=sqrt( (pow( x3-x1 , 2) ) + pow( y3-y1 , 2) );
	d3=sqrt( (pow( x3-x2 , 2) ) + pow( y3-y2 , 2) );

	//Linija
	
	if(fabs( d1+d2-d3) <= EPSILON || fabs( d1+d3-d2) <= EPSILON || fabs( d2+d3-d1) <= EPSILON){
		printf("Linija\n");
		printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
	}
	
	//Jednakostranicni
	
	else if (fabs(d1-d2)<=EPSILON && fabs(d2-d3)<=EPSILON) {
		printf("Jednakostranicni\n");
		printf("Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
	}
	
	//Pravougli
	
	else if ( fabs( pow(d1, 2) - pow(d2, 2) - pow(d3,2) ) <= EPSILON || fabs ( pow(d2, 2) - pow(d1, 2) - pow(d3,2) ) <= EPSILON || fabs( pow(d3, 2) - pow(d2, 2) - pow(d1,2)) <= EPSILON)
	{
		printf("Pravougli\n");
		
	//Jednakokraki pravougli
		
		if ( fabs(d1-d2)<=EPSILON || fabs(d1-d3)<=EPSILON || fabs(d2-d3)<=EPSILON) {
			printf("Jednakokraki\n");
		}
		else if (d1!=d2 && d2!=d3 && d1!=d3) {
			printf("Raznostranicni\n");
		}
		
		printf("Najveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		
	}
	
	else if ( fabs(d1-d2)<=EPSILON || fabs(d1-d3)<=EPSILON || fabs(d2-d3)<=EPSILON) {
			printf("Jednakokraki\n");
			ugao1 = acos((pow(d2, 2) + pow(d3, 2) - pow(d1, 2) ) / (2.*d2*d3) )*(180/PI);
			ugao2 = acos((pow(d1, 2) + pow(d3, 2) - pow(d2, 2) ) / (2.*d1*d3) )*(180/PI);
			ugao3 = acos((pow(d1, 2) + pow(d2, 2) - pow(d3, 2) ) / (2.*d1*d2) )*(180/PI);

			if (d1>d2) {
			ugao=floor (ugao1);
			minute=floor((ugao1-ugao)*60);
			sekunde=floor(((ugao1-ugao)*60 - minute)*60);

			}
			
			else if (d2>d1) {
			ugao=floor (ugao2);
			minute=floor((ugao2-ugao)*60);
			sekunde=floor(((ugao2-ugao)*60 - minute)*60);

			}
			
			else if (d3>d1){
			ugao=floor (ugao3);
			minute=floor((ugao3-ugao)*60);
			sekunde=floor(((ugao3-ugao)*60 - minute)*60);

			}
			
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", ugao, minute, sekunde);		
		}
		
		
		
	else if (d1!=d2 && d1!=d3 && d2!=d3){
		printf("Raznostranicni\n");
			ugao1 = acos((pow(d2, 2) + pow(d3, 2) - pow(d1, 2) ) / (2.*d2*d3) )*(180/PI);
			ugao2 = acos((pow(d1, 2) + pow(d3, 2) - pow(d2, 2) ) / (2.*d1*d3) )*(180/PI);
			ugao3 = acos((pow(d1, 2) + pow(d2, 2) - pow(d3, 2) ) / (2.*d1*d2) )*(180/PI);

			if (d1>d2 && d1>d3) {
			ugao=floor (ugao1);
			minute=floor((ugao1-ugao)*60);
			sekunde=floor(((ugao1-ugao)*60 - minute)*60);

			}
			
			else if (d2>d1 && d2>d3) {
			ugao=floor (ugao2);
			minute=floor((ugao2-ugao)*60);
			sekunde=floor(((ugao2-ugao)*60 - minute)*60);

			}
			
			else if (d3>d1 && d3>d2){
			ugao=floor (ugao3);
			minute=floor((ugao3-ugao)*60);
			sekunde=floor(((ugao3-ugao)*60 - minute)*60);

			}
			printf("Najveci ugao ima %g stepeni, %g minuta i %g sekundi.", ugao, minute, sekunde);		

	}
		
	return 0;
	
}
