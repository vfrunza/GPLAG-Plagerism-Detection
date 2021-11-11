#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define br_uglova 500
int main() {
	int i,j,n,stepeni,minute,sekunde;
	int a=1;
	double niz[br_uglova];
	double brsekundi;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}	
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		a=1;
		if(niz[i]<0) {a=-1; niz[i]=niz[i]*(-1);}
		brsekundi=niz[i]*(180/PI)*3600;
		stepeni=(int)(brsekundi/3600);
		brsekundi-=stepeni*3600;
		minute=(int)(brsekundi/60);
		brsekundi-=minute*60;
		if(brsekundi-(int)brsekundi<0.5){
			sekunde=brsekundi;
		}
		else {sekunde=brsekundi+1;}
		if(sekunde==60){
			sekunde=0; minute++;
			if(minute==60){
				minute=0; stepeni++;
			}
		}
		if(sekunde>30){}
		else { printf("%d stepeni %d minuta %d sekundi\n", a*stepeni, minute, sekunde); }
		
	}
		return 0;
}