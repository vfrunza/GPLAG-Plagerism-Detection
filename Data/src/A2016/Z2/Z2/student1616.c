#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define N 500
int main () {
	double niz[N], hf, mf, sf;
	int n, i, m, h, s, j;

	do {
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	} while (n<1 && n>500); 

	for (i=0; i<n; i++) {
		scanf ("%lf", &niz[i]);
		
	    hf=niz[i]*180/PI;
	    h=(int)hf;
	    mf=(hf-h)*60;
	    m=(int)mf;
	    sf=(mf-m)*60;
	    if (sf<0) sf-=0.5;
	    else if (sf>0) sf+=0.5;
	    s=(int)sf;
	    
	    if (s==60) {
	    	m=m+1;
	    	s=0;
	    }
	    if (m==60) {
	    	h=h+1;
	    	m=0;
	    }
	    if (s==-60) {
	    	m=m-1;
	    	s=0;
	    }
	    if (m==-60) {
	    	h=h-1;
	    	m=0;
	    }
	    if (s>30 || s<-30) {
			for (j=i; j<n-1; j++) {
				niz[j]=niz[j+1]; }
				i--;
				n--;
			}
	}	
	printf ("Uglovi su:\n");
	for (i=0; i<n; i++) {
		hf=niz[i]*180/PI;
	    h=(int)hf;
	    mf=(hf-h)*60;
	    m=(int)mf;
	    sf=(mf-m)*60;
	    if (sf<0) sf-=0.5;
	    else if (sf>0) sf+=0.5;
	    s=(int)sf;
		
	    if (s==60) {
	    	m=m+1;
	    	s=0;
	    }
	    if (m==60) {
	    	h=h+1;
	    	m=0;
	    }
	    if (s==-60) {
	    	m=m-1;
	    	s=0;
	    }
	    if (m==-60) {
	    	h=h-1;
	    	m=0;
	    }
	   m=abs(m); 
	   s=abs(s);
	 
	 printf ("%d stepeni %d minuta %d sekundi\n", h, m, s);   
	}
	return 0;
}