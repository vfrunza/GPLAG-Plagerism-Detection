#include <stdio.h>
#define PI 3.1415926
int main() {
	int a,i,s,m,sec;
	printf("Unesite broj uglova: ");
	scanf("%d",&a);
	double niz[500];
	
	for(i=0;i<a;i++){
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<a;i++){
		niz[i]=niz[i]*180/PI;
		s=(int)(niz[i]);
		niz[i]=((niz[i]-(int)(niz[i]))*60);
		m=(int)(niz[i]+0.5);
		niz[i]=((niz[i]-(int)(niz[i]))*60);
		sec=(int)(niz[i]+0.5);
		
		if(sec>30)continue;
		printf("%d stepeni %d minuta %d sekundi\n",s,m,sec);
	}
	
	
	
	
	return 0;}
