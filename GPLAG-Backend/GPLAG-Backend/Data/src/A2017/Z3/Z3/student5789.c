#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int ponavljanje(int niz_cifara[],int d2)
{
	int i,j,t=0,br=0;
	for(i=0; i<d2; i++) {
		t=1;
		for(j=0; j<i; j++) {
			if(niz_cifara[j]==niz_cifara[i]) {
				t=0;
				br=0;
				break;
			}
		}
		if(t==1) {
			br++;
		}
	}
	return br;
}
int izbaci_cifre(int niz_brojeva[],int d1,int niz_cifara[],int d2)
{
	int i=0,j=0,cifra=0,br=0,novi_broj=0,broj=0,b=0,k=0,s=0,t,x=0,negativni=0;
	int novi[100],p,novi_niz[100],novi_broj1=0,broj1=0,k1=0,cifra1=0;
	br=ponavljanje(niz_cifara,d2);
	for(i=0; i<d2; i++) {
		if((niz_cifara[i]<0)||(niz_cifara[i]>9)||(br!=d2)) {
			return 0;
		}
	}
	k=0;
	for(i=0; i<d1; i++) {
		if(niz_brojeva[i]<0) {
			niz_brojeva[i]=abs(niz_brojeva[i]);
			negativni=1;
		}
		while(niz_brojeva[i]!=0) {
			b=0;
			cifra=niz_brojeva[i]%10;
			p=0;
			t=1;
			for(j=0; j<d2; j++) {
				if(cifra==niz_cifara[j]) {
					t=0;
				}
			}
			if(t) {
				if(k==0) {
					novi_broj=cifra;
					broj=novi_broj;
				}
				if(k!=0) {
					novi_broj*=10;
					broj=novi_broj+cifra;
					novi_broj=broj;
				}
				k++;
			}
			niz_brojeva[i]/=10;
		}
		if(negativni)
			broj*=(-1);
		novi[s]=broj;
		s++;
		k=0;
		broj=0;
		negativni=0;
	}
	negativni=0;
	k1=0;
	for(i=0; i<s; i++) {
		if(novi[i]<0) {
			novi[i]=abs(novi[i]);
			negativni=1;
		}
		while (novi[i]!=0) {
			cifra1=novi[i]%10;
			if(k1==0) {
				novi_broj1=cifra1;
				broj1=novi_broj1;
			}
			if(k1!=0) {
				novi_broj1*=10;
				broj1=novi_broj1+cifra1;
				novi_broj1=broj1;
			}
			k1++;
			novi[i]/=10;
		}
		if(negativni) broj1*=(-1);
		novi_niz[x]=broj1;
		x++;
		broj1=0;
		k1=0;
		negativni=0;
	}
	for(i=0; i<d1; i++) {
		niz_brojeva[i]=novi_niz[i];
	}
	return 1;
}
int main()
{
	int d1=3,d2=3,i,t,niz_cifara[100],niz_brojeva[100];
	printf("Unesite niz brojeva: ");
	for(i=0; i<d1; i++) {
		scanf("%d",&niz_brojeva[i]);
	}
	printf("Unesite niz cifara: ");
	for(i=0; i<d2; i++) {
		scanf("%d",&niz_cifara[i]);
	}
	t=izbaci_cifre(niz_brojeva,d1,niz_cifara,d2);
	printf("\n T = %d",t);
	return 0;
}
