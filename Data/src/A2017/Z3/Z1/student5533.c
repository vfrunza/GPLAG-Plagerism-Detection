#include <stdio.h>
int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
    int brojac=0, i, pom1[100], velpom1=0, j,k, pom2[100], velpom2=0, pom3[100], velpom3=0;
    int brojaci[1000]={0};
    for (i=0; i<vel1; i++) {
    	pom1[velpom1]=niz1[i];
    	velpom1++;
    }
    for (i=0; i<velpom1-1; i++) {
    	for (j=i+1; j<velpom1; j++) {
    		if (pom1[j]==pom1[i]) {
    			for (k=j; k<velpom1; k++) {
    				pom1[k]=pom1[k+1];
    			}
    			velpom1--;
    			j--;
    		}
    	}
    }
    for (i=0; i<velpom1; i++) {
    	brojaci [pom1[i]]++;
    }
    
    for (i=0; i<vel2; i++) {
    	pom2[velpom2]=niz2[i];
    	velpom2++;
    }
    for (i=0; i<velpom2-1; i++) {
    	for (j=i+1; j<velpom2; j++) {
    		if (pom2[j]==pom2[i]) {
    			for (k=j; k<velpom2; k++) {
    				pom2[k]=pom2[k+1];
    			}
    			velpom2--;
    			j--;
    		}
    	}
    }
    for (i=0; i<velpom2; i++) {
    	brojaci [pom2[i]]++;
    }
    
    for (i=0; i<vel3; i++) {
    	pom3[velpom3]=niz3[i];
    	velpom3++;
    }
    for (i=0; i<velpom3-1; i++) {
    	for (j=i+1; j<velpom3; j++) {
    		if (pom3[j]==pom3[i]) {
    			for (k=j; k<velpom3; k++) {
    				pom3[k]=pom3[k+1];
    			}
    			velpom3--;
    			j--;
    		}
    	}
    }
    for (i=0; i<velpom3; i++) {
    	brojaci [pom3[i]]++;
    }
    for (i=0; i<1000; i++) {
    	if (brojaci[i]==2) {
    		brojac++;
    	}
    }
    
	return brojac;
}
int main() {
	int niz1[]={1,2,3,5}, niz2[]={1,2,4,6,7}, niz3[]={1, 3, 4, 8, 9, 10}, rez, vel1, vel2, vel3;
	vel1=4;
	vel2=5;
	vel3=6;
	rez=dva_od_tri (niz1, vel1, niz2, vel2, niz3, vel3);
	printf("Rezultat je %d", rez);
	return 0;
}
