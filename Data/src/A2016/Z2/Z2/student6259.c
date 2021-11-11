#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	int n, i, k;
	double niz[500], st[500], m[500], s[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		
		niz[i]=niz[i]*(double)180/PI;
		st[i]=(int)niz[i];
		
		niz[i]=(niz[i]-st[i])*60;
		m[i]=(int)niz[i];
		
		niz[i]=(niz[i]-m[i])*60;
		if(niz[i]>0)
			s[i]=(niz[i] +0.5);
		else s[i]=(niz[i]-0.5);
		
		if(abs((int)s[i])==60){
			s[i]=0;
			if(niz[i]>0) m[i]++;
			else m[i]--;
		}
			
		if(abs((int)m[i])==60){
			m[i]=0;
			if(niz[i]>0) st[i]++;
			else st[i]--;
		}
		
		if(abs(s[i])>30) {
			for(k=i; k<n-1; k++)
			niz[k]=niz[k+1];
			i--;
			n--;
			}
	}
	
	for(i=0; i<n; i++)
	printf("%d stepeni %d minuta %d sekundi\n", (int)st[i], abs((int)m[i]), abs((int)s[i]));

	return 0;
}
