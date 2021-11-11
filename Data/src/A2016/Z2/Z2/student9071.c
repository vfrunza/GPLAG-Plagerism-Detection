#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>
int main(){
	double ang,rem,rez,minu,secu;
	int ugao[500]={0},min[500]={0},sec[500]={0},i,j;
	int bruglova;
	printf("Unesite broj uglova: ");
	scanf("%d",&bruglova);
	
	for (i=0;i<bruglova;i++){
		scanf("%lf",&ang);
		rez=(ang*180.)/PI;
		//hrs
		ugao[i]=rez;
		//min
		rem=fabs(rez-ugao[i]);
		minu=(rem*60);
		min[i]=minu;
		//sec
		rem=fabs(minu-min[i]);
		secu=(rem*60)+0.5;
		sec[i]=secu;
		if (sec[i]==60){
			min[i]++;
			sec[i]=0;
		}
		if (min[i]==60){
			if (ugao[i]>0){
			ugao[i]++;}
			else {
				ugao[i]--;
			}
			min[i]=0;
		}
	}
	//izbacivanje elemenata gdje je sec[i]>30 ili 
	
	for (i=0; i<bruglova; i++) {
		if (sec[i]>30) {
			for (j=i; j<bruglova-1; j++) {
			ugao[j] = ugao[j+1];
			min[j] = min[j+1];
			sec[j] = sec[j+1];
		}
	bruglova--;
	i--;
	}
}
	printf("Uglovi su: \n");
	for (i=0;i<bruglova;i++){
		printf("%d stepeni %d minuta %d sekundi\n",ugao[i],min[i],sec[i]);
	}
	return 0;
}

/*int main() {
	double angle=0,decimal1=0,decimal2=0,n=0,minu=0,secx=0;
	int i=0,bruglova=0,integer1=0,integer2=0,a=0,b=0,c=0,k=0;
	int ugao[500]={0},min[500]={0},sec[500]={0};
	printf("Unesite broj uglova: ");
	scanf("%d",&bruglova);
	
	for(i=0;i<bruglova;i++){
		scanf("%lf",&n); //odredjivanje "sati"
		
		angle=(n*180)/PI;
		
		ugao[i]=(int)angle;
		
		
		integer1=ugao[i]; //odredjivanje minuta
		decimal1=angle-integer1;
		minu=(decimal1*60);
		if (minu>=0){
		c=minu+0.5;
		} else {
		c=minu-0.5;	
		}
		c=abs(c);
		min[i]=c;
		
		b=minu;
		integer2=b;  //odredjivanje sekundi
		decimal2=minu-integer2;
		secx=decimal2*60;
		
		if (secx>=0){
		a=0.5+secx;
		} else {
		a=secx-0.5;
		}
		a=abs(a);
		sec[i]=a;
if ((sec[i]>30)||(sec[i]<-30)){
	i--;
	bruglova--;
}
	}
	printf("Uglovi su:\n");
	for (k=0;k<bruglova;k++){
	printf("%d stepeni %d minuta %d sekundi\n",ugao[k],min[k],sec[k]);
	}
		
	return 0;
}
*/