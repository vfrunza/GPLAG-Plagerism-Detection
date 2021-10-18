#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int b = 0;
	int a,f,z;
	double d,c,e,k,l,g;
	int broj;
	double radijani[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &broj);
	printf("Uglovi su: \n");
	do{
	    scanf("%lf",&radijani[b]);
	    b++;
	}while(b < broj);
	for(a = 0;a < broj;a++){
		d = ((radijani[a]*180)/PI);
		c = (fabs(d) - (int)(fabs(d)))*60;
		e = abs((int)((c - (int)(c))*60 + 0.5));
		if(fabs(e) > 30 && fabs(e) < 60){
            for(f = a;f <(broj - 1);f++){
                radijani[f]=radijani[f+1];
            }
            broj--;
            a--;
		}
		
		
	}
	for(z = 0;z < broj;z++){
		k = ((radijani[z]*180)/PI);
		l = (fabs(k) - abs((int)(k)))*60;
		g = abs((int)((l - (int)(l))*60 + 0.5));
		if(abs(g) > 59.99){
			g = 0;
			l++;
			
		}
		if(fabs(l) > 59.99){
			l = 0;
			if(k >= 0.0)
			k++;
			else k--;
		}
		printf("%d stepeni %d minuta %d sekundi\n", (int)k,(int)l,(int)g);
		
     }
	return 0;
}

