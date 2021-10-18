#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1 (float niz[], int vel) {
    int i;
	for (i=0;i<vel;i++) {
		    niz[i] = round(niz[i]*10)/10.;
		}
}

void preslozi (float niz[],int vel, int k) {
    float suma=0,temp;
    int i,j,n,vel1;
    zaokruzi1(niz,vel);
    vel1=vel;
    for (i=0;i<vel;i++) {
        int n= round (niz[i]*10);
    	do {
    		suma += abs(n%10);
    	n=n/10;
    	}
    while (abs(n)>0);
    if (suma<k) {
        temp=niz[i];
        for (j=i;j<vel1-1;j++) {
        niz[j]=niz[j+1];
        }
        niz[vel1-1]=temp;
        vel--;
        i--;
    
    }
    suma=0;
    }
    }

int main () {
    float niz[100];
    int k,vel,i;
    printf("Unesite velicinu niza: ");
    scanf("%d",&vel);
    printf("Unesite k:");
    scanf("%d",&k);
    printf("Unesire clanove niza: ");
    for (i=0;i<vel;i++) {
        scanf("%f",&niz[i]);
    }
    preslozi(niz,vel,k);
    for (i=0;i<vel;i++) {
        printf("%f ",niz[i]);
    }
    return 0;
}


