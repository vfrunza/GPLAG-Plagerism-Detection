#include <stdio.h>
#include <math.h>
int izbaci_cifre(int a[], int br1,int b[], int br2)
{
	int i,j,n,m,br,brojac1=0,brojac2=0,broj=0;
	if (br2==0) {
		m=0;
		return m;
	}
	for(i=0; i<br2; i++) {
		if(b[i]<0 || b[i]>9)
			return 0;
		for(j=0; j<i; j++) {
			if(b[j]==b[i])
				return 0;
		}
	}


	for(i=0; i<br1; i++) {
		n=a[i];
		a[i]=fabs(a[i]);
		brojac1=0;
		brojac2=0;
		while(a[i]!=0) {
			for(j=0; j<br2; j++) {
				if(a[i]%10==b[j]) {
					br=1;
					brojac1++;
					break;
				} else br=0;
			}
			if(br==0) {
				broj=(broj+(a[i]%10))*10;

			}
			a[i]=(int)(a[i]/10);
			brojac2++;
		}
		if(brojac1==brojac2) {
			a[i]=0;
		} else {
			broj/=10;
			a[i]=broj;
			broj=0;
			while(a[i]%10!=0) {
				broj=(broj+(a[i]%10))*10;
				a[i]/=10;
			}
			broj/=10;
			if(n<0) {
				a[i]=-broj;
			} else {
				a[i]=broj;
			}

			broj=0;
		}
	}
	for(i=0; i<br1; i++) {

		for(j=0; j<i; j++) {
			if(a[i]==a[j] && a[i]!=0) {
				m=0;
				return m;
			} else m=1;
		}

	}

	return m;

}


int main()
{
	return 0;
}
