#include <stdio.h>
#define pi 3.1415926

int main()
{
	int s,n,i,j,m,stepen, negativan=0;
	int a,b,c,d;
	double kcic, fale;
	double niz[500];
	printf("Unesite broj uglova: ");
	a=b+c;
	scanf("%d", &n);
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
		a-=c;
	}
	for(i=0; i<n; i++) {
		negativan=0;
		a=a+b-c+d-i;
		kcic=niz[i];
		if(kcic<0) {negativan=1; kcic*=-1;}
		b+=negativan;
		fale=kcic*(180/pi);
		c=a-b;
		stepen=(int)fale;
		fale=(fale-stepen);
		a++;
		fale=fale*60;
		b--;
		m=fale;
		fale=(fale-m);
		b=-b;
		fale=fale*60;
		s=fale;
		c=d-a;
		fale-=s;
		if(fale>0.5) s+=1;
		a++;
		if(s==60) { s=0; m+=1;}
		d++;
		if(m==60) {m=0; stepen+=1;}
		if(s>30) {
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
				c*=d;
			}
			n--;
			a/=b;
			i--;
		}

	}
	for(i=0; i<n; i++) {
		a++;
		negativan=0;
		c++;
		kcic=niz[i];
		if(kcic<0) {negativan=1; kcic*=-1;}
		d+=negativan-1;
		fale=kcic*(180/pi);
		d=a-b-c-d;
		stepen=(int)fale;
		c++;
		fale=(fale-stepen);
		fale=fale*60;
		a-=b;
		m=fale;
		fale=(fale-m);
		fale=fale*60;
	    a++; 
		s=fale;
		fale=fale-s;
		b+=d;
		if(fale>0.5) {
			s+=1;
			d++;
		}
		if(s==60) { s=0; m+=1; b++;}
		if(m==60) {m=0; stepen+=1; c++;}
		if(negativan==1) stepen=-stepen;
		d--;
		printf("%d stepeni %d minuta %d sekundi\n", stepen, m, s);
	}





	return 0;


}
