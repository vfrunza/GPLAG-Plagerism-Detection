#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double niz[500];
	int i,n,j,a,b,c;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%lf", &niz[i]);
		niz[i]=(niz[i]*180)/PI;
			a=(int)niz[i];
		b=(int)((niz[i]-a)*60);
		if(b<0){
			b*=(-1);
		}
	if(a<0){
	c=(int)((((-1)* (niz[i]-a)*60)-b)*60+1./2);
	} 
	else
	{
		c=(int)((( (niz[i]-a)*60)-b)*60+1./2);
	}
		
	if(c<0){
		c*=(-1);
	}
	if(c>59.54){
		c=0;
		b++;
	}
	if(b>59.54){
		b=0;
		if(a<0){
			a--;
		} else if(a>0){
		a++;
		}
	}
	if(c>30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			
		}
	}

		printf("Uglovi su: \n");
for(i=0;i<n;i++){
	a=(int)niz[i];
	b=(int)( (niz[i]-a)*60);
	if(b<0){
		b*=(-1);

	}
	if(a<0){
	c=(int)((((-1)* (niz[i]-a)*60)-b)*60+1./2);
	} 
	else
	{
		c=(int)((( (niz[i]-a)*60)-b)*60+1./2);
	}
	if(c<0){
		c*=(-1);
	}
		if(c>59.54){
		c=0;
		b++;
	}
	if(b>59.54){
		b=0;
		if(a<0){
			a--;
		} else if(a>0){
		a++;
		}
	}
	printf("%d stepeni %d minuta %d sekundi\n",a,b,c );
	
}

return 0;
}