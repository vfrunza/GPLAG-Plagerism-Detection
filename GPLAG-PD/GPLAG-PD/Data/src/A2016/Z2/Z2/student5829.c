#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double niz [500],uks;
	int n, st, m, s,i=0, j=0;
	
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	
	for (i=0; i<n; i++){
		scanf ("%lf", &niz[i]);}
	
 printf ("Uglovi su: \n");

	for (i=0; i<n; i++){
	if (niz[i]>0){
		uks=(niz[i]*180/PI)*3600;
		uks=(int)(uks+0.5);
		st=uks/3600;
		m=(((int)uks%3600)/60);
		s=(((int)uks%3600)%60);}
	else {
		uks=(niz[i]*180/PI)*3600;
		uks=(int)(uks-0.5);
		st=uks/3600;
		m=abs((((int)uks%3600)/60));
		s=abs((((int)uks%3600)%60));}	
	

		if (s>30) {
            for (j=i; j<n-1; j++) {
                niz[j] = niz[j+1];
            }
            n--;            
            i--;
        }
        else{
		printf ("%d stepeni %d minuta %d sekundi\n", st, m, s);}
	}
	
	return 0;
}
