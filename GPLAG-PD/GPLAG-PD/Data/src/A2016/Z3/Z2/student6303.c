#include <stdio.h>
#include <stdlib.h>
int izbroji(int n) {
	int zbir=0, temp, m=n;
	while(m!=0) {
		temp = m % 10;
		zbir += temp;
		m /= 10;
	}
	return abs(zbir);
}

void ubaci(int niz[], int vel) {
	int i, j;
	for(i=0; i<vel;) {
		for(j=vel-1; j>=i; j--)
		niz[j+1] = niz[j];
		niz[i+1] = izbroji(niz[i]);
		vel++;
		i += 2;
	}
}

int izbaci(int niz[], int vel) {
	int i=1, j=0, k, temp=niz[0], red[50], pamti=0;
	for(k=0;k<50;k++) red[k]=1;
	while(red[i++]>0) red[i] = red[i-1] + red[i-2];
	do{
		if(j==vel)continue;
	  	if(pamti==1) {j--;pamti=0;}
	  		i=1;
     	while(i<50) {
	     	if(niz[j]==red[i]) {
	   			k=j;
    			while(k<vel-1)
      			niz[k] = niz[k+++1];
	   			vel--;
       			if(j==0) pamti=1;
      			else j--;
	   		} i++;
       	}
    j++;
    }while(j<vel);
	for(i=0;i<50;i++)
    if(niz[0]==red[i]){vel--;break;}
    return vel;
}
int main() {
	int niz[20] = {0}, vel=10, i=0;
	printf("Unesite niz od 10 brojeva: ");
	while(i<vel) scanf("%d", &niz[i++]);
	ubaci(niz, vel);
	vel=izbaci(niz, vel*2);
	printf("Modificirani niz glasi:");
	for(i=0; i<vel; i++) {
		if(i+1<vel) printf(" %d,", niz[i]);
		else printf(" %d.", niz[i]);
	}
	return 0;
}
