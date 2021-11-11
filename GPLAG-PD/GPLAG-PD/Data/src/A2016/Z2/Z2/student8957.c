#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	int n,i,j,nizsek[500],nizm[500],nizs[500];
	double nizr[500],minute;
	printf ("Unesite broj uglova: ");
	scanf ("%d",&n);
	for (i=0;i<n;i++)
	    scanf ("%lf",&nizr[i]);

	for (i=0;i<n;i++)
		nizr[i]=nizr[i]*180/PI;
		
	for (i=0;i<n;i++){
		if (fabs((int)(fabs(((((nizr[i]-(int)(nizr[i]))*60)-((int)((nizr[i]-(int)(nizr[i]))*60)))*60))+0.5))>30 && fabs((int)(fabs(((((nizr[i]-(int)(nizr[i]))*60)-((int)((nizr[i]-(int)(nizr[i]))*60)))*60))+0.5)) != 60 ){
			for (j=i;j<n-1;j++){
				nizr[j]=nizr[j+1];
			}
			n--;
			i--;
		}
	}
for (i=0;i<n;i++){
		nizs[i]=(int)(nizr[i]);
		minute=fabs(((nizr[i]-(int)(nizr[i]))*60));
		nizm[i]=(int)minute;
		nizsek[i]=(int)(((minute-nizm[i])*60)+0.5); if (nizsek[i]==60) {nizsek[i]=0; nizm[i]+=1;}
	}
	for (i=0; i<n;i++)
		 if (nizm[i]==60) {
		 	if (nizs[i]<0){
		 		nizm[i]=0;
		 		nizs[i]+=(-2);
		 	}
			else 
				nizm[i]=0;
				nizs[i]+=1;
		 }

	printf ("Uglovi su: \n");
	for (i=0;i<n;i++)
		printf ("%d stepeni %d minuta %d sekundi\n",nizs[i],nizm[i],nizsek[i]);
		
	return 0;
}
