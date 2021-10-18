#include <stdio.h>
#include <math.h>

#define PI 3.14
/*vrsta trougla*/


int main() {
	double x1 ,x2,x3, y1,y2,y3;
	double stranica_a,stranica_b,stranica_c;
	int stepeni,minute,sekunde;
	double ugao1,ugao2, ugao3;
	double max = 0 ;
	
	
	printf("Unesite koordinate tacke t1: ");
	scanf("&lf &lf",&x1,&y1);
	printf(" Unesite koordinate tacke t2: ");
	scanf("%lf %lf",&x2,&y2);
	printf(" Unesite koordinate tacke t3: ");
	scanf("%lf %lf",&x3,&y3);
	
	stranica_a = sqrt((x2-x1)*(x2-x1) - (y2-y1)*(y2-y1));
	stranica_b = sqrt((x3-x1)*(x3-x1) - (y3-y1)*(y3-y1));
	stranica_c = sqrt((x3-x2)*(x3-x2) - (y3-y2)*(y3-y2));
	
	if((stranica_a == 0 && stranica_b == 0 && stranica_c != 0 ) || (stranica_a != 0 && stranica_b == 0 && stranica_c == 0) || 
	(stranica_a == 0 && stranica_b != 0 && stranica_c == 0 )) printf("\nLinija");
	
	else if(( stranica_a == stranica_b && stranica_b == stranica_c) || (stranica_a == stranica_c && stranica_c == stranica_b)
	|| (stranica_b == stranica_c && stranica_a == stranica_c)) printf("\nJednakostranicni");
	
	else if((stranica_a * stranica_a + stranica_b * stranica_b == stranica_c*stranica_c) || 
	(stranica_b * stranica_b + stranica_c*stranica_c == stranica_a*stranica_a) || 
	(stranica_a*stranica_a + stranica_c*stranica_c == stranica_b*stranica_b)) printf("\nPravougli");


	else if ( stranica_a == stranica_b || stranica_b == stranica_c || stranica_a == stranica_c) printf("\nJednakokraki");
	else printf("\nRaznostranicni");
	
	
	
	//Odredi najveci ugao
	
	ugao1 = acos( (stranica_b*stranica_b+stranica_c*stranica_c-stranica_a*stranica_a) / (2*stranica_b*stranica_c) );
    ugao2 = acos( (stranica_c*stranica_c+stranica_a*stranica_a-stranica_b*stranica_b) / (2*stranica_c*stranica_a) );
    ugao3 = acos( (stranica_a*stranica_a+stranica_b*stranica_b-stranica_c*stranica_c) / (2*stranica_a*stranica_b) );
 
    ugao1 *= 180/PI;
    ugao2 *= 180/PI;
    ugao3 *= 180/PI;
    
    
    if(ugao1 > ugao2 && ugao1 > ugao3) max = ugao1;
    else if(ugao2 > ugao1 && ugao2 > ugao3) max = ugao2;
    else max = ugao3;
    
    stepeni = (int)max;
    minute = (int)((max - stepeni)*3600)/60;
	sekunde = (int)((max - stepeni)*3600)%60;
 
 	printf("\nNajveci ugao ima %d stepeni, %d minuta i %d sekundi.",stepeni,minute,sekunde);
	return 0;
}
