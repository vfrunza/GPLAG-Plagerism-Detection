#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int i,j=0,a,sec=0,min=0,stepen=0;
	double n[500],us=0,c=0,b=0,sanida=0;
	printf("Unesite broj uglova: ");
	scanf("%d",&a);
	for (i=0;i<a;i++) scanf("%lf",&n[i]);
	sanida=a;
	printf ("Uglovi su:\n");
	for (i=0;i<a;i++) 
	{us=(n[i]*(180/PI)); stepen=(int)(us); 
	 c=(us-stepen)*60; min=(int)(c);
	 b=(c-min)*60;
	 if (b<0) sec=(abs)(b-0.5);
	 else if (b>0) sec=(int)(b+0.5);
	 else sec=0;
	 
	 if (sec==60) {sec=0; min=(abs)(min); min++;}
	 if (min==60) {min=0; if (stepen<0) stepen--;
	 					  else if (stepen>0) stepen++;}
	 min=(abs)(min);
	 if (sec<=30 && sec>=-30) printf ("%d stepeni %d minuta %d sekundi\n",stepen,min,sec);
	 if (sec>30 || sec<-30)  { for (j=i;j<sanida-1;j++) { n[j]=n[j+1]; sanida--; j--;}}}
	 return 0;
}
