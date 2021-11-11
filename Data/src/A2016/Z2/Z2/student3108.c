#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define X 500

int main() {
	int n,i,j;
	float niz[X], st[X] , sek[X] , min[X];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	
		for(i=0; i<n; i++)
		scanf("%f", &niz[i]);
		
		for(i=0; i<n; i++) {
		
			
			st[i] = niz[i]*180./PI;
			min[i] = fabs((st[i]-(int)st[i])*60);
        	sek[i] = fabs((min[i]-(int)min[i])*60);
		
			
		 st[i]=(int)st[i];
		 min[i]=(int)min[i];
		 sek[i]=(int)(sek[i]+0.5);
		
		
		if(sek[i]>=60) {
			min[i]++;
			sek[i] -= 60;
		}
		if(min[i]>=60) {
			if (st[i]>=0)
			st[i]++;
			else
			st[i]--;
			min[i] -= 60;
		} }
		for(i=0; i<n; i++) {
		if(sek[i]>30) {
			for(j=i; j<n-1; j++) {
			niz[j]=niz[j+1]; 
				st[j]=st[j+1];
				min[j]=min[j+1];
				sek[j]=sek[j+1];
			}
			n--;
	i--;
		}
		 
	 }
		
	 printf("Uglovi su:\n");
	 
	 for(i=0; i<n; i++)
	printf("%.0f stepeni %.0f minuta %.0f sekundi\n", st[i], min[i], sek[i]);

	 	return 0;
} 
