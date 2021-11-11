#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define n 500
int main() {
	double B[n],d,v,b;
	int st, mi,se,a,c,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&a);
	for(i=0; i<a; i++){
		scanf("%lf",&B[i]);
	}
	c=a;
	printf("Uglovi su: \n");
	for(i=0;i<a;i++){
		d=B[i]*(180/PI);
		st=(int)d;
		v=(d-st)*60;
		mi=(int)(v);
		b=(v-mi)*60;
		if(b<0)
		se=(abs)(b-0.5);
		else if(b>0)
		se=(int)(b+0.5);
		else se=0;
		
		if(se==60)
		{
			se=0;
			mi=(abs)(mi);
			mi++;
			if(mi==60)
			{
				mi=0;
				if(st<0)
				st--;
				else if(st>0)
				st++;
			}
			
		}
		mi=(abs)(mi);
		if(se<=30 && se>=-30){
			printf("%d stepeni %d minuta %d sekundi\n", st,mi,se);}
			if(se>30 || se<-30)
			{for(j=i;j<c-1;i++)
			{B[i]=B[j+1];
			i--;
			c--;
		}
	}
		}
	return 0;
}
