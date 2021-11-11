#include <stdio.h>
#define PI 3.1415926
#define MAX 500
int main() {
	int a=0;
	double niz[MAX];
	double niz1[MAX];
	int niz2[MAX];
	double niz3[MAX];
	int niz4[MAX];
	int niz6[MAX];
	double niz5[MAX];
	int i;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&a);
	if(a<1 || a>500){
		return main();
	}
	
	for(i=0;i<a;i++){
		scanf("%lf",&niz[i]);
	}
	
	for(i=0;i<a;i++){
		niz[i]=niz[i]*180/PI;
	}
	
	for(i=0;i<a;i++){
		niz2[i]=(int)(niz[i]);
	}
	
	for(i=0;i<a;i++){
		niz1[i]=niz[i]-niz2[i];  
	}
	
	for(i=0;i<a;i++){
		niz3[i]=niz1[i]*60;  
	}
	for(i=0;i<a;i++) {
		niz4[i]=(int)(niz3[i]);    
	}
	for(i=0;i<a;i++) {
		niz5[i]=niz3[i]-niz4[i];  
	}
	for(i=0;i<a;i++) {
		niz5[i]=niz5[i]*60;    
	}
		
	for(i=0;i<a;i++) {
		niz6[i]=(int)(niz5[i]+0.5);  
	}
	printf("Uglovi su: \n");
	for(i=0;i<a;i++) {
		if(niz6[i]<=30) {
		printf("%d stepeni %d minuta %d sekundi\n", niz2[i],niz4[i],niz6[i]);
		}
	}
	
	return 0;
		
}
	
	
	
	