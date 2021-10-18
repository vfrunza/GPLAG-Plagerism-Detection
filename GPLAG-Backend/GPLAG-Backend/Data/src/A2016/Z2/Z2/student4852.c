#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define Pi 3.1415926
int main() {
	double Uglovi[500],Sd,md;
	int u,i,j,S,m,s;
	printf("Unesite broj uglova: ");
	scanf("%d", &i);
	u=0;
	do{
	 scanf("%lf", &Uglovi[u]);
	 u++;
	}while(u<i);
	printf("Uglovi su:\n");
	for(j=0;j<i;j++){
		S=(180./Pi)*Uglovi[j];
		Sd=(180./Pi)*Uglovi[j];
		md=fabs((Sd-S)*60);
		m=abs((Sd-S)*60);
		s=(md-m)*60+0.5;
		if(s==60&&m>=59){s=0;m=0;
		if(S<0)S--;if(S>0)S++;}
			if(s==60){
			m++;s=0;
		}
		if(s>30&&s<60){
			for(u=j;u<i;u++)
			Uglovi[u]=Uglovi[u+1];
			i--;j--;continue;}
			printf("%d stepeni %d minuta %d sekundi\n",S,m,s);
			}
return 0;}