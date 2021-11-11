#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define EPSILON 0.0001
int main() {
	double niz[500],stepeni,minute,sekunde,x,s[500],m[500],sec[500];
	int i=0,j,n,br=0;
	printf("Unesite broj uglova: ");
	scanf ("%d",&n);
	do {
			scanf("%lf",&x);
		    niz[i]=x;
		    i++;
		    br++;
		    if (br==n) break;
	} while (br<500);printf("Uglovi su: \n");
	for (i=0;i<br;i++){
		stepeni=((niz[i]*180.00)/PI);minute = (stepeni - (int) stepeni)*60; sekunde = fabs((minute - (int) minute))*60;
		stepeni = (int) stepeni;
		minute = fabs((int) minute);
		sekunde = (int) (sekunde+0.5);
		if (fabs(sekunde-60) < EPSILON ) {minute++;sekunde-=60;}
		if (stepeni < 0 && fabs(minute-60)<EPSILON) {stepeni--;minute-=60;}
		else if (stepeni > 0 && fabs(minute-60)<EPSILON) {stepeni++;minute-=60;}
		s[i]=stepeni;
		m[i]=minute;
		sec[i]=sekunde;
	}
	for (i=0;i<br;i++){
		if (fabs(sec[i]) > 30) {
			for (j=i;j<br-1;j++){
			    sec[j]=sec[j+1];
			    s[j]=s[j+1];
			    m[j]=m[j+1];
		    }
		    br--;
		    i--;
		}
			
	} 
	    for (i=0;i<br;i++)
		printf("%g stepeni %g minuta %g sekundi\n" ,s[i],m[i],sec[i]);
	
	
	return 0;
}
