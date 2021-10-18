#include <stdio.h>
#define PI 3.1415926
#define c 500
int main() {
	int n,i,j,st[c],min[c],sek[c];
	double ugao;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
	
		scanf("%lf",&ugao);
			if (ugao>0)
			j=(ugao*180*3600/PI)+0.5;
			if (ugao<0)
			j=(ugao+180*3600/PI)-0.5;
			st[i]=j/3600;
			if(j<0)
			j*=-1;
			sek[i]=j%60;
			j/=60;
			min[i]=j%60;
			if (sek[i]>30){
				n--;
				i--;
			}
		
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++) printf("%d stepeni %d minuta %d sekundi\n", st[i],min[i],sek[i]);
	return 0;
}
