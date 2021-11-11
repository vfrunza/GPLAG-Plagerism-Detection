#include <stdio.h>
#define PI 3.14159265359

int main() {
	//printf("Zadaća 2, Zadatak 2");

	//printf ("Unesite broj uglova: ");
	int n, i;
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	float niz[500]={0};
	for (i=0; i<n; i++) scanf ("%f", &niz[i]);
/*	int stepeni[n];
	int minute[n];
	int sekunde[n];
	*/
	
	printf ("Uglovi su: ");
	for (i=0; i<n; i++) {
		float tmp; //tmp2;
		int a, b, c, j;
		tmp=niz[i]*180/PI; //printf ("\n%lf", tmp);
	//	tmp2=tmp;
		a=(int) tmp; // printf ("\n%d", a);
		if (tmp<0) tmp*=-1;
		if (a<0) tmp=tmp+a;	//printf ("\n%lf", tmp);
		else tmp=tmp-a;
		b=(int) (tmp*60);// printf ("\n%d", b);
		tmp=tmp*60- b;	//printf ("\n%lf", tmp);
		c=(int) (tmp*60+0.5); 
		if (c==60) {
			c=0; 
			b++;
		}
		if (b>59) {
			b=0; 
			a++; //printf ("\n%d", c);
		}
		
	//	printf ("Uglovi su: ");
	//	if (c <= 30) printf ("\n%d stepeni %d minuta %d sekundi", a, b, c);
	//	else {
			if (c>30)
			for (j=i; j<n; j++) {
			niz[j]=niz[j+1];
			n--;
			i--;
			}
		}
	//}
	
	for (i=0; i<n; i++) {
		//printf ("%d: %f", i, niz[i]);
		float tmp; //tmp2;
		int a, b, c, j;
		tmp=niz[i]*180/PI; //printf ("\n%lf", tmp);
	//	tmp2=tmp;
		a=(int) tmp; // printf ("\n%d", a);
		if (tmp<0) tmp*=-1;
		if (a<0) tmp=tmp+a;	//printf ("\n%lf", tmp);
		else tmp=tmp-a;
		b=(int) (tmp*60);// printf ("\n%d", b);
		tmp=tmp*60- b;	//printf ("\n%lf", tmp);
		c=(int) (tmp*60+0.5); 
		if (c==60) {
			c=0; 
			b++;
		}
		if (b>59) {
			b=0; 
			a++; //printf ("\n%d", c);
		}
		printf ("\n%d stepeni %d minuta %d sekundi", a, b, c);
		}
	return 0;
}
