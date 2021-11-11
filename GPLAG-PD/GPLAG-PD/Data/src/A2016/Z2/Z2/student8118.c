#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
    double br,niz[500];
    int n=0,i,j=0, st[500], m[500], s[500];
    printf ("Unesite broj uglova: ");
    scanf ("%d",&n);
    printf ("Uglovi su:");
    for (i=0; i<n; i++) {
    scanf ("%lf",&niz[i]);
    br=niz[i]*180/PI;
    st[i]=(int)br;
    m[i]=(int)((fabs(br-st[i]))*60);
    s[i]=(int)((60*(fabs(60*(br-st[i]))-m[i]))+0.5);
    if (s[i]==60)
    { s[i]=0;
    m[i]++; }
    if (m[i]==60)
{ m[i]=0;
st[i]++;}
}
 for (i=0; i<n; i++) {
    if (s[i]>30) {
        for (j=i; j<n-1; j++) {
            s[j]=s[j+1];
            niz[j]=niz[j+1];  
            }
        n--;
        i--;
    }
        }
    for (i=0; i<n; i++) {
    br=niz[i]*180/PI;
    st[i]=(int)br;
    m[i]=(int)((fabs(br-st[i]))*60);
    s[i]=(int)((60*(fabs(60*(br-st[i]))-m[i]))+0.5);
        if (s[i]==60)
    { s[i]=0;
    m[i]++; }
    if (m[i]==60)
    { m[i]=0;
    if (st[i]<0)
st[i]--;
else
    st[i]++; }
     
        printf ("\n%d stepeni %d minuta %d sekundi", st[i], m[i], s[i]);
    }
    

    
	
	return 0;
}
