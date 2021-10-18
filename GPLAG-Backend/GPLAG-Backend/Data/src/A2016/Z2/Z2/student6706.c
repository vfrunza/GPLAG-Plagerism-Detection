#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define eps 0.0000001
int main() {
	double niz[500],step=0,stepen=0,dec=0,min=0,minn=0,dec1=0,sek=0,sekk=0;
	int n,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n<=0 || n>500) return 0;
	for(i=0;i<n;i++){
	scanf("%lf",&niz[i]);	
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
    step=niz[i]*(180./PI);
    stepen=(int)step;
	dec=step-(int)step;
	min=dec*60;
	minn=min+ 0.000;
	minn=(int)minn;
	dec1=min-(int)min;
	sek=dec1*60;
	if(sek>0)
	sekk=sek + 0.50;
	else
	sekk=sek - 0.50;
	sekk=(int)sekk;
	
	if(sekk>=60){sekk-=60;minn++;}
	if(sekk<=-60){sekk+=60;minn--;}
	if(minn>=60){minn-=60;stepen++;}
	if(minn<=-60){minn+=60;stepen--;}

	
	if(sekk>30 || sekk<-30){
		for(j=i;j<n-1;j++){
			niz[j]=niz[j+1];
		}
		n--; i--;
	}
	else if(stepen<0 && minn<0 && sekk<0){ minn=fabs(minn); sekk=fabs(sekk); printf("%g stepeni %g minuta %g sekundi\n",stepen,minn,sekk);}
	else if(minn<0 && stepen<0 && sekk<0){ minn=fabs(minn); sekk=fabs(sekk); printf("%g stepeni %g minuta %g sekundi\n",stepen,minn,sekk);}
	else if(sekk<0 && stepen<0 && minn<0){ minn=fabs(minn); sekk=fabs(sekk); printf("%g stepeni %g minuta %g sekundi\n",stepen,minn,sekk);}
	else if(fabs(stepen-0)<eps && minn<0){sekk=fabs(sekk); printf("%g stepeni %g minuta %g sekundi\n",stepen,minn,sekk);}
	else if(fabs(minn-0)<eps && stepen<0){sekk=fabs(sekk); printf("%g stepeni %g minuta %g sekundi\n",stepen,minn,sekk);}
	else
	printf("%g stepeni %g minuta %g sekundi\n",stepen,minn,sekk);
	}


	

	return 0;
}
