#include <stdio.h>
#define PI 3.1415926

int main() {
	int n,i,j;
	float niz[500];
	unos:
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n<1 || n>500) goto unos;
	for(i=0;i<n;i++){
	scanf("%f",&niz[i]);
	
}
for(i=0;i<n;i++){
	float uk=niz[i]*180/PI;
	float uks=uk*3600;
	uks=(int) (uks+0.5);
	int stepen=uks/3600;
	int minute=(uks-stepen*3600)/60;
	int sekunde=uks-stepen*3600-minute*60;
	if(sekunde>=60) { sekunde=sekunde-60; minute++;}
	if(minute>=60) { minute=minute-60; stepen++;}
	
	if(sekunde>30) {
		for(j=i;j<n-1;j++){
			niz[j]=niz[j+1];
		}
		n--;
		i--;
	}}
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		float uk=niz[i]*180/PI;
		float uks=uk*3600;
		uks=(int)(uks+0.5);
		int stepen=uks/3600;
		int minute=(uks-stepen*3600)/60;
		int sekunde=uks-stepen*3600-minute*60;
		if(sekunde>=60) {sekunde-=60; minute++;}
		if(minute>=60) {minute=minute-60; stepen++;}
		printf("\n%d stepeni %d minuta %d sekundi",stepen,minute,sekunde);
		
		
	}
	return 0;
	
}
