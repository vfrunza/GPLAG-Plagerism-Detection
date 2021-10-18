#include <stdio.h>
#include <math.h>
#define BROJ_EL 500
#define PI 3.1415926

int main() {
    int i,j,n,stepen_1[BROJ_EL],minuta_1[BROJ_EL],sekunda_1[BROJ_EL];
	double radijan [BROJ_EL],stepen[BROJ_EL],minuta[BROJ_EL],sekunda[BROJ_EL],ostatak_stepen[BROJ_EL],ostatak_minuta[BROJ_EL],ostatak_sekunda[BROJ_EL];
	printf ("Unesite broj uglova: ");
	scanf ("%d",&n);
	for (i=0;i<n;i++) {
		scanf ("%lf",&radijan[i]);
		stepen[i]=radijan[i]*(180/PI); ostatak_stepen[i]=stepen[i]-((int)stepen[i]); stepen_1[i]=((int)stepen[i]);
		minuta[i]=ostatak_stepen[i]*60; ostatak_minuta[i]=minuta[i]-((int)minuta[i]);
		if (ostatak_minuta[i]>0.5) minuta_1[i]=((int)(minuta[i]+0.5));
		else minuta_1[i]=((int)minuta[i]);
		sekunda[i]=ostatak_minuta[i]*60; ostatak_sekunda[i]=sekunda[i]-((int)sekunda[i]);
		if (ostatak_sekunda[i]>0.5) sekunda_1[i]=((int)(sekunda[i]+0.5));
		else sekunda_1[i]=((int)sekunda[i]);
		if (sekunda[i]<(-59.5)) {
			minuta_1[i]-=1;
			sekunda_1[i]=0;
		}
		if (minuta[i]<(-59.5)) {
			stepen_1[i]-=1;
			minuta_1[i]=0;
		}
		if (sekunda[i]>59.5) {
			minuta_1[i]+=1; 
			sekunda_1[i]=0;
		}
		if (minuta[i]>59.5) {
			stepen_1[i]+=1;
			minuta_1[i]=0;
		}
		if (sekunda_1[i]<0) (sekunda_1[i]==fabs(sekunda_1[i]));
		if (minuta_1[i]<0) (minuta_1[i]==fabs(minuta_1[i]));
	}

	for (i=0;i<n;i++) {
        if (fabs(sekunda_1[i])>30) {
            for (j=i;j<n-1;j++) {
            	stepen_1[j]=stepen_1[j+1];
            	minuta_1[j]=minuta_1[j+1];
                sekunda_1[j]=sekunda_1[j+1];
                }
            n--;
            i--;
        }
}
	
	
	
	printf ("Uglovi su:\n");
	for (i=0;i<n;i++) {
		if (radijan[i]==0) printf ("0 stepeni 0 minuta 0 sekundi\n");
		else
        printf ("%d stepeni %d minuta %d sekundi\n",stepen_1[i],minuta_1[i],sekunda_1[i]);
	}
return 0;
}




