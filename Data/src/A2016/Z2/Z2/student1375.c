#include <stdio.h>
#define PI 3.1415926
int main() {
	
float niz[500], stepeni, minute, sekunde, min, t, sec, k;
    int i, n, br, minuta, brm, sek, p, h,r,a,l,j;
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%f", &niz[i]);
    }
    printf("Uglovi su:\n");
    for(i=0; i<n; i++)
    {  if(niz[i]<0) {
       niz[i]=-1*niz[i]; stepeni= (niz[i]*180)/PI; r=stepeni*10,a=stepeni, l=stepeni*100;
       br=stepeni;  if(r%10==9){ br++; if(l%10<=5) br--;}; if(br==360) br--;  br=-1*br; 
        
        }
       else {
       stepeni= (niz[i]*180)/PI; r=stepeni*10,a=stepeni, l=stepeni*100;
       br=stepeni; if(r%10==9){ br++; if(l%10<=5) br--;}; if(br==360) br--; }
       minute=stepeni-a;
       min=minute*60;  h=min; minuta=min;
       t=min*10;
       brm=t;
       if (brm%10>=5) minuta++;
       sekunde= min-h;
       sec=sekunde*60; sek=sec;
       k=sec*10;
       p=k;
       if(p%10>=5) sek++; if(sek==60) sek=0;
       if(minuta==60) {minuta=0;}
       if(sek>30) {
           for(j=i; j<n-1; j++) {
               niz[j] = niz[j+1];
           } n--; i--;
           
       }
       else {
       printf("%d stepeni %d minuta %d sekundi\n", br, minuta, sek);}  }
       

	
	return 0;
}
