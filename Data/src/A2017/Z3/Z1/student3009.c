#include <stdio.h>
int dva_od_tri(int* niz1,int velicina1,int* niz2,int velicina2,int* niz3, int velicina3)
{
	int i,j,k,brojac=0,tacno,m,l;
	for (i=0; i<velicina1; i++) {

		tacno=1;
		for (j=0; j<velicina2; j++) {
			if (niz1[i]==niz2[j]) {
				if (velicina3==0) {
					brojac++;
				} else {
					for (k=0; k<velicina3; k++) {
						if (niz1[i]==niz3[k]) break;
					}
					if (k==velicina3) {
						for (m=i; m>0; m--) {
							if(niz1[i]==niz1[m-1]) tacno=0;
						}
							for (l=j; l>0; l--) {
								if(niz2[j]==niz2[l-1]) tacno=0;
							}						
						if (tacno==1)
							brojac++;
					}
				}
			}
		}
	}
	for (i=0; i<velicina1; i++) {
		tacno=1;
		for (k=0; k<velicina3; k++) {
			if (niz1[i]==niz3[k]) {
				if (velicina2==0) {
					brojac++;
				} else {
					for (j=0; j<velicina2; j++) {
						if (niz1[i]==niz2[j]) break;
					}
					if (j==velicina2) {
						for (m=i; m>0; m--) {
							if(niz1[i]==niz1[m-1]) tacno=0;
						}
							for (l=k; l>0; l--) {
								if(niz3[k]==niz3[l-1]) tacno=0;
							
						}
						if (tacno==1)

							brojac++;
					}
				}
			}
		
	}
}
for (k=0; k<velicina3; k++)
{
	tacno=1;
	for (j=0; j<velicina2; j++) {
		if (niz3[k]==niz2[j]) {
			if (velicina1==0) {
				brojac++;
			} else {
				for (i=0; i<velicina1; i++) {
					if (niz3[k]==niz1[i]) break;
				}
				if (i==velicina1)
				{
					for (m=k;m>0;m--){
						if(niz3[k]==niz3[m-1]) tacno=0;
					}
					for (l=j;l>0;l--){
						if(niz2[j]==niz2[l-1]) tacno=0;
					}
					if (tacno==1)
					brojac++;
				}
			}
		}
	}
}
return brojac;
}
int main()

{
	int niz1[100],niz2[100],niz3[100],i,j,k,a,b,c;
	for (i=0; i<100; i++) {
		scanf("%d",&niz1[i]);
		if (niz1[i]==-1) break;
	}
	for (j=0; j<100; j++) {
		scanf("%d",&niz2[j]);
		if (niz2[j]==-1) break;
	}
	for (k=0; k<100; k++) {
		scanf("%d",&niz3[k]);
		if (niz3[k]==-1) break;
	}
	a=i;
	b=j;
	c=k;
	printf("\n %d ",dva_od_tri(niz1,a,niz2,b,niz3,c));
	
	return 0;
}
