#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main() {
	
	float a_x;
	float a_y;
	
	float b_x;
	float b_y;
	
	float c_x;
	float c_y;
	
	double A;
	double B;
	double C;
	
	double alpha;
	double beta;
	double gamma;
	
	double minute;
	double sekunde;
	
	printf("Unesite koordinate tacke t1: ");
	scanf(" %f", &a_x);
	scanf(" %f", &a_y);
	
	printf("Unesite koordinate tacke t2: ");
	scanf(" %f", &b_x);
	scanf(" %f", &b_y);
	
	printf("Unesite koordinate tacke t3: ");
	scanf(" %f", &c_x);
	scanf(" %f", &c_y);
	
	
	C = sqrt( pow( (b_x - a_x), 2 ) + pow( (b_y - a_y), 2 ) ) ;  // stranica C
	B = sqrt( pow( (c_x - a_x), 2 ) + pow( (c_y - a_y), 2 ) ) ; // stranica B
	A = sqrt( pow( (b_x - c_x), 2 ) + pow( (b_y - c_y), 2 ) ) ; // stranica A
	
	
	alpha = (pow( A, 2 ) - pow( B, 2 ) - pow ( C, 2 )) / -(2 * B * C) ;
	beta =  (pow( B, 2 ) - pow( A, 2 ) - pow ( C, 2 )) / -(2 * A * C) ;
	gamma = (pow( C, 2 ) - pow( A, 2 ) - pow ( B, 2 )) / -(2 * A * B);
	
	if (alpha < 1 && alpha > -1)
		alpha = acos (alpha) * 180.0 / PI;
	else 
		alpha = 180;
		
	
	if (beta < 1 && beta > -1)
		beta = acos (beta) * 180.0 / PI;
	else 
		beta = 180;
	
	
	if (gamma < 1 && gamma > -1)
		gamma = acos (gamma) * 180.0 / PI;
	else 
		gamma = 180;
	
	
	if ( !(180-alpha <= 0.0001) ) {
		if ( fabs(90-alpha) <= 0.0001 || fabs(90-beta) <= 0.0001 || fabs(90-gamma)  < 0.0001) {
			printf("Pravougli\n");
		}
			
		if (60-alpha <= 0.0001 && 60-beta <= 0.0001 && 60-gamma <= 0.0001) {
			printf("Jednakostranicni \n");
			
		} else if ( ( (alpha == beta) || (alpha == gamma) || (gamma == beta) ) ) {
			printf("Jednakokraki\n");
		} else {
			printf("Raznostranicni\n");
		}
	} else {
		printf("Linija \n");
	}
	
	
	if (alpha > beta) {
		
		if (alpha > gamma) {
			minute = ((alpha - (int)alpha) * 0.6);
			sekunde = ((minute - (int)minute) * 0.6);
			printf( "Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", floor(alpha), floor( minute * 100 ), floor( sekunde * 100 )  );
		} else {
			minute = ((gamma - (int)gamma) * 0.6);
			sekunde = ((minute - (int)minute) * 0.6);
			printf( "Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", floor(gamma), floor( minute * 100 ), floor( sekunde * 100  )  );
		}
		
	} else {
		
		if (beta > gamma) {
			minute = ((beta - (int)beta) * 0.6);
			sekunde = ((minute - (int)minute) * 0.6);
			printf( "Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", floor(beta), floor( minute * 100 ), floor( sekunde * 100  )  );
		} else {
			minute = ((gamma - (int)gamma) * 0.6);
			sekunde = ((minute - (int)minute) * 0.6);
			printf( "Najveci ugao ima %.0f stepeni, %.0f minuta i %.0f sekundi.", floor(gamma),  floor( minute * 100 ), floor( sekunde * 100  )   );
		}
		
	}
	
	return 0;
}
