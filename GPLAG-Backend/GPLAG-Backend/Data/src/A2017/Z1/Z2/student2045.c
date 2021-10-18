#include <stdio.h>
#include <math.h>
#define E 0.0001

int main() {
	double t1,t2,t3,t12,t22,t32,AB,KA,BA,KB,CA,KC;
	printf ("Unesite koordinate tacke t1: ");
	scanf ("%lf%lf",&t1,&t12);
	printf ("Unesite koordinate tacke t2: ");
	scanf ("%lf%lf",&t2,&t22);
	printf ("Unesite koordinate tacke t3: ");
	scanf ("%lf%lf",&t3,&t32);
	
	AB = pow(t1-t2,2)+pow(t12-t22,2);
	KA = sqrt (AB);
	
	BA = pow ((t2-t3),2)+pow((t22-t32),2);
	KB = sqrt (BA);
	
	CA = pow ((t1-t3),2)+pow((t12-t32),2);
	KC = sqrt (CA);
	
  
    if (fabs(KA-KB)<E && fabs(KA-KC)<E)
    printf ("Jednakostranicni\nNajveci ugao ima 60 stepeni, 0 minuta i 0 sekundi.");
    else if (fabs(KA-KB)<E || fabs(KB - KC)<E || fabs(KA - KC)<E)
    printf ("Jednakokraki");
    else if (fabs(KA-KB)>E && fabs(KB-KC)>E && fabs(KA-KC)>E)
    printf ("Raznostranicni");
    else if ((fabs(KA-KB)<E + fabs(KB-KC)<E) - fabs(KA-KC)<E <E)
    printf ("Linija");
    



	return 0;
}
