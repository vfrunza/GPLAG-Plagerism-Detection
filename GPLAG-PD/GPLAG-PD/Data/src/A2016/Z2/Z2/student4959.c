#include <stdio.h>
#include <math.h>
#define pi 3.1415926
int main() {
	
	double niz[500];
	double s[500],m[500],ss[500];
	int n,i,k,d;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%lf",&niz[i]);
	for(i=0;i<n;i++)
	{ scanf("%lf",&niz[i]);
	niz[i]*=180/pi;
	s[i]=(int)niz[i];
	niz[i]-=s[i];
	niz[i]*=60;
	m[i]=(int)niz[i];
	niz[i]-=m[i];
	niz[i]*=60;
    if(niz[i]>=0)
    niz[i]=niz[i]+0.5;
    else niz[i]=niz[i]-0.5;
	ss[i]=(int)niz[i];
	if(fabs(ss[i])>=60)
	{ ss[i]=0;
	if(m[i]>0) m[i]+=1;
	else m[i]-=1;
	}
	if(fabs(m[i])>=60)
	{ m[i]=0;
	if(s[i]>0) s[i]+=1;
	else s[i]-=1;
	}
	}
	for(k=0;k<n;k++){
		if(fabs(ss[k])>30){
		for (d=k;d<n-1;d++)
		{ s[d]=s[d+1];
		  m[d]=m[d+1];
		  ss[d]=ss[d+1];
		}
		n--;
		k--;
		}
	}printf("Uglovi su: \n");
	for(i=0;i<n;i++)
	{ printf("%.0lf stepeni %.0lf minuta %.0lf sekundi \n",s[i],fabs(m[i]),fabs(ss[i]));
		
	}
	return 0;
}
