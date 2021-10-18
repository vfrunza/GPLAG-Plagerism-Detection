#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define PI 3.1415926
struct uglovi{
	float stepeni,minuta,sekundi;
};
struct uglovi prebacivanje(float n){
	struct uglovi ugao;
	float y,x;
	y=n*180/PI;
	if(y>=0){
		ugao.stepeni=floor(y);
		x=(y-ugao.stepeni)*60;
		ugao.minuta=floor(x);
		ugao.sekundi=(x-ugao.minuta)*60;
		ugao.sekundi=floor(ugao.sekundi+0.5);
		if (ugao.sekundi>=60) {ugao.minuta++; ugao.sekundi-=60;}
    	if (ugao.minuta>=60) {ugao.stepeni++; ugao.minuta-=60;}
	}
	else if(y<0){
		ugao.stepeni=floor(y)+1;
		x=((y-ugao.stepeni)-(2*(y-ugao.stepeni)))*60;
		ugao.minuta=floor(x);
		ugao.sekundi=(x-ugao.minuta)*60;
		ugao.sekundi=floor(ugao.sekundi+0.5);
		if (ugao.sekundi>59) {ugao.minuta++; ugao.sekundi-=60;}
    	if (ugao.minuta>59) {ugao.stepeni--; ugao.minuta-=60;}
	}
	return ugao;
}

int main() {
	float radijani[500];
	struct uglovi ugao[500];
	int n,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f",&radijani[i]);
	}
	for(i=0;i<n;i++){
		ugao[i]=prebacivanje(radijani[i]);
	}
	for(i=0;i<n;i++){
		if(ugao[i].sekundi>30){
			for(j=i;j<n-1;j++){
				ugao[j]=ugao[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		printf("%.0f stepeni %.0f minuta %.0f sekundi\n",ugao[i].stepeni,ugao[i].minuta,ugao[i].sekundi);	
	}
	return 0;
}
