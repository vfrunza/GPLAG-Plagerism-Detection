#include <stdio.h>
#define PI 3.1415926

int main() {
	int a,b,c,j;
	double niz[500],niz2[500],niz3[500];
	int n,i;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	printf("Uglovi su:\n");
	
	for(i=0;i<n;i++) scanf("%lf",&niz[i]);

	for(i=0;i<n;i++) {
	
		niz[i]=niz[i]*(180/PI); 
		
		a=(int)niz[i];
	//	printf("a %d ",a);
		niz2[i]=niz[i]-(int) niz[i];
		niz2[i]=niz2[i]*60;
		b=(int)niz2[i];
		//printf("b %d ",b);
		niz3[i]=niz2[i]-(int)niz2[i];
		niz3[i]=niz3[i]*60;
		c=(int) niz3[i];
	//	printf("c %d",c);
		if((niz3[i]-(int)niz3[i])>=0.5 ){
		c++;	
		if(c==60){
			b++; c=0;
			if(b==60){
				a++; b=0;
			}
		}
	
		}
		
		if(niz3[i]-(int)niz3[i]<=-0.5){
			c--;
			if(c==-60){
				c=0; b--;
				if(b==-60){
					b=0; a--;
				}
			}
		}
		//if(niz3[i]-(int)niz3[i]>0.5 && b>=59 && b<60){ a++; b=0;c=0; printf("%d stepeni 0 minuta 0 sekundi",a);}
		if(c>30 || c<-30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];}
				n--;
				i--;
			}
		else{
			
			if(c<0) c*=(-1);
			if(b<0) b*=(-1);
			//if(c==0) printf("%d stepeni %d minuta 0 sekundi\n",a,b);
			 printf("%d stepeni %d minuta %d sekundi\n",a,b,c);}
	}
		
	return 0;
}
