#include <stdio.h>
#include <math.h>
#define E 0.0001
#define PI 3.141592654

int main() {
    double x1, y1, x2, y2, x3, y3, d1, d2, d3, a, b, k1, k2, k3, h, L, B, G, p, val, pom1, pom2, q, w, e;
    int pret = 0, pret_j = 0, pret_p = 0, pret_i = 0, pret_r = 0, step, min, sec;
    
	printf("Unesite koordinate tacke t1: "); scanf("%lf %lf", &x1, &y1 );
	printf("Unesite koordinate tacke t2: "); scanf("%lf %lf", &x2, &y2 );
	printf("Unesite koordinate tacke t3: "); scanf("%lf %lf", &x3, &y3 );
	d1 = sqrt( (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) );
	d2 = sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
	d3 = sqrt( (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) );
	k1=( fabs(y2-y1)/fabs(x2-x1) );
	k2=( fabs(y3-y1)/fabs(x3-x1) );
	k3=( fabs(y3-y2)/fabs(x3-x2) );
	if( (fabs(k1 - k2) < E) && (fabs(k1 - k3) < E) && (fabs(k2 - k3) < E) ) {
		pret = 1;
		printf("Linija\n");
	}
	if( fabs(d1 - d2) < E &&  fabs(d1 - d3) < E &&  fabs(d2 - d3) < E  ) {
		a = d1 + d2 + d3;
		b = 3 * d1;
		if( b - a < E ) {
			printf("Jednakostranicni\n");
			pret_i=1;
		}
	}
	if( d1 - d2 > E && d1 - d3 > E ) {
		a = d1 * d1;
		b = d2 * d2 + d3 * d3;
		if(a - b < E) {
			printf("Pravougli\n");
			pret_p=1;
		}
	}
	if( d2-d1 > E && d2 - d3 > E ) {
		a = d2 * d2;
		b = d1 * d1 + d3 * d3;
		if( a - b < E ) {
			printf("Pravougli\n");
			pret_p=1;
		}
	}
	if( d3-d1 > E && d3-d2 > E ) {
		a = d3 * d3;
		b = d1 * d1 + d2 * d2;
		if( a - b < E ) {
			printf("Pravougli\n");
			pret_p=1;
		}
	}
	if( fabs(d1 - d2) < E && fabs(d1 - d3) > E && pret == 0 ) {
		a = d1 + d2 + d3;
		b = d3 + 2*d1;
		if( a - b < E ) {
			printf("Jednakokraki\n");
			pret_j=1;
		}
	}
	if(fabs(d1 - d3) < E && fabs(d1 - d2) > E && pret == 0) {
		a = d1 + d2 + d3;
		b = d2 + 2*d1;
		if( a - b < E ) {
			printf("Jednakokraki\n");
			pret_j=1;
		}
	}
	if(fabs(d2 - d3) < E && fabs(d2 - d1) > E && pret == 0) {
		a = d1 + d2 + d3;
		b = d1 + 2*d2;
		if( a - b < E ) {
			printf("Jednakokraki\n");
			pret_j=1;
		}
	}
	if( pret_j != 1 && pret != 1 && pret_i != 1 ) {
		printf("Raznostranicni\n");
		pret_r = 1;
	}
	if(pret_j == 1 && pret_p != 1 && pret_i != 1) {
		if( fabs(d1 - d2) < E) {
			val = 180 / PI;
			p = d3/2;
			h = sqrt(fabs( (d1 * d1) - ( p * p ) ) );
			L = h / d1;
			L = asin( L ) * val;
			step = L;
			pom1 = L - step;
			pom2 = pom1 * 60;
			min = pom2;
			pom1 = min;
			pom2 = pom2 - min;
			sec = pom2 * 60;
		}
		if( fabs(d1 - d3) < E ) {
			val = 180 / PI;
			p = d2/2;
			h = sqrt(fabs( (d1 * d1) - ( p * p ) ) );
			L = h / d1;
			L = asin( L ) * val;
			step = L;
			pom1 = L - step;
			pom2 = pom1 * 60;
			min = pom2;
			pom1 = min;
			pom2 = pom2 - min;
			sec = pom2 * 60;
		}
		if( fabs(d2 - d3) < E ) {
			val = 180 / PI;
			p = d1/2;
			h = sqrt(fabs( (d2 * d2) - ( p * p ) ) );
			L = h / d2;
			L = asin( L ) * val;
			step = L;
			pom1 = L - step;
			pom2 = pom1 * 60;
			min = pom2;
			pom1 = min;
			pom2 = pom2 - min;
			sec = pom2 * 60;
		}
		printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sec);
		return 0;
	}
	if(pret_i == 1){
		printf("\Najveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	} 
	if(pret_p == 1 ) { 
		printf("\nNajveci ugao ima 90 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	if(pret == 1) {
		printf("\nNajveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
		return 0;
	}
	if(pret_r == 1) {
		val = 180 / PI;
		q = d1 * d1;
		w = d2 * d2;
		e = d3 * d3;
		L = ( w + e - q ) / ( 2 * d2 * d3 );
		B = ( q + e - w ) / ( 2 * d1 * d3 );
		G = ( q + w - e ) / ( 2 * d1 * d2 );
		L = acos( L ) * val;
		B = acos( B ) * val;
		G = acos( G ) * val;
		if(L - B > E && L - G > E) {
			step = L;
			pom1 = L - step;
			pom2 = pom1 * 60;
			min = pom2;
			pom1 = min;
			pom2 = pom2 - min;
			sec = pom2 * 60;
		}
		if(B - L > E && B - G > E) {
			step = B;
			pom1 = B - step;
			pom2 = pom1 * 60;
			min = pom2;
			pom1 = min;
			pom2 = pom2 - min;
			sec = pom2 * 60;
		}
		if(G - L > E && G - B > E) {
			step = G;
			pom1 = G - step;
			pom2 = pom1 * 60;
			min = pom2;
			pom1 = min;
			pom2 = pom2 - min;
			sec = pom2 * 60;
		}
		printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", step, min, sec);
		return 0;
	}
	return 0;
}