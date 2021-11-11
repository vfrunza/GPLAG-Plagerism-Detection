#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define q 500

int main() {
	int n, i, s, stepen, M, st[q], m[q], sek[q], p;
	double a[500], alfa, S;
	p=0;
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf ("%lf", &a[i]);
	}
	printf ("Uglovi su: \n");
	for (i=0; i<n; i++)
	{
		alfa=a[i]*180/PI;
	while (alfa<-360)
	{
		alfa=alfa+360;
	}
	while (alfa>360)
	{
		alfa=alfa-360;
	}
	S=alfa*3600;
	S=round(S);
	s=S;
	stepen=alfa;
	M=(s-stepen*3600)/60;
	s=s%60;
	if (M==60)
	{
		M=0;
		stepen=stepen+1;
	}
	else if (M==-60)
	{
		M=0;
		stepen=stepen-1;
	}
	sek[i]=abs(s);
	st[i]=stepen;
	m[i]=abs(M);
	}
	for (i=0; i<n; i++)
	{
		if (sek[i]<=30)
		{
			sek[p]=sek[i];
			m[p]=m[i];
			st[p]=st[i];
			p++;
		}
	}
	for (i=0; i<p; i++)
	{
		printf ("%d stepeni %d minuta %d sekundi", st[i], m[i], sek[i]);
		printf ("\n");
	}
	return 0;
}
