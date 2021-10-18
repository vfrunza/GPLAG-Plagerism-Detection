#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n,i,j,ST,MS,STS;
	double S,M,M1,SS,STt;
	double niz[500]={0};
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++){
		S=niz[i]*180/PI;
		ST=(int)(S/1.);
		M=S-ST;
		M1=M*60;
		MS=(int)(M1/1.);
		SS=M1-MS;
		STt=SS*60;
		STS=(int)(STt/1.+0.5);
		if(STt>59.49 || STt<-59.49){
			if(STt<0){
				STS=0;
				MS=M1-1;
				MS=(int)(M1);
			}
			else{
				STS=0;
				MS=M1+1;
				MS=(int)(M1);
			}
		}
		if(MS>59 || MS<-59){
			MS=0;
			ST=ST+1;
			ST=(int)(ST);
		}
		if(STS>30 || STS<-30){
			for(j=i;j<n-1;j++)
				niz[j]=niz[j+1];
			n--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		S=niz[i]*180/PI;
		ST=(int)(S);
		M=(S-ST);
		M1=(M*60);
		MS=(int)(M1);
		SS=(M1-MS);
		STt=(SS*60);
		
		if(STt>=0)
		STS=(int)(STt+0.5);
		if(STt <0)
        STS=(int)(STt-0.5);
		
		if(STt>59.49|| STt<-59.49){
			if(STt<0){
				STS=0;
				M1=M1-1;
				MS=(int)(M1);
			}
			else{
				STS=0;
				M1=M1+1;
				MS=(int)(M1);
			}
		}
		if(MS>=59.49 || MS<=-59.49){
			if(MS<0){
				MS=0;
				ST=ST-1;
				ST=(int)(ST);
			}
			else{
				MS=0;
				ST=ST+1;
				ST=(int)(ST);
			}
		}
		MS=fabs(MS);
		STS=fabs(STS);
		ST=fabs(ST);
		if (niz[i]<0)
		printf("-%d stepeni %d minuta %d sekundi\n",ST,MS,STS);
		else printf("%d stepeni %d minuta %d sekundi\n",ST,MS,STS);
	}
	return 0;
}
