#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int izbaci_cifre(int niz[],int vel,int cifre[],int vel2)
{

    int pomocni[300], br1, i, j, k, l, a, c, m, br2;

    for(i=0; i<vel2; i++) {
        if(cifre[i]<0 || cifre[i]>9) return 0;
        for(j=i+1; j<vel2; j++) {
            if(cifre[i]==cifre[j]) return 0;
        }
    }

    for(i=0; i<vel; i++) {
        br1=0;
        br2=0;
        a=niz[i];

        while (a!=0) {
           c=a%10;
           br1++;
           a=a/10;
        }
        a=niz[i];

        for(j=0; j<br1; j++) {
            c=a%10;
            pomocni[j]=c;
            a=a/10;
        }

        for(k=0; k<br1; k++) {
            for(l=0; l<vel2; l++) {
                if(abs(pomocni[k])==abs(cifre[l])) {
                    for(m=l; m<br1-1; m++) {
                        pomocni[m]=pomocni[m+1];
                    }
                    br2=1;
                    if(br2!=0) {
                        br1--;
                        k--;
                        break;
                    }
                }
            }
        }
        niz[i]=0;


        if(br1!=0) {
            for(j=0; j<br1; j++) {
                niz[i]+=pomocni[j]*pow(10,j);
            }
        }
    }

    return 1;
}


int main()
{

int niz[4] = {12345, 12456, 6646, 234101};
	int cifre[2] = {6, 1};

	izbaci_cifre(niz, 4, cifre, 2);

	int i;

	for(i = 0; i < 4; i++)
		printf("%d ", niz[i]);

    return 0;
}
