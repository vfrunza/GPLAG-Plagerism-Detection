#include <stdio.h>

int izbaci_cifre (int niz1[], int vel1,int niz2[], int vel2) {
	int i,j,brojac=0,y,x,m,c;

	  for (j=0;j<vel2;j++) {
	  	if (niz2[j]<0 || niz2[j]>9) return 0;
	 else {
	  	for(i=j+1;i<vel2;i++) {
	  		if(niz2[i]==niz2[j]) brojac++;
	  	}
	  if (brojac!=0) return 0;
	 }
	  }
	  for (i=0;i<vel1;i++) {
	  	for (j=0;j<vel2;j++) {
	  		m=1;
	  		y=0;
	  	if (niz1[i]<0) x=niz1[i]*(-1);
	  		else x=niz1[i];
	  	
	  	while (x!=0) {
	  		c=(x%10);
	  		x=x/10;
	  			if (c==niz2[j]) {
	  			y +=c*m*10;
	  			m=m*10;
	  		}
	  	}
	  	if (niz1[i]<0) niz1[i]=y*(-1);
	  	else  niz1[i]=y;
	  	}
	  }
	  return 1;
}
	  

int main () {
	int niz1[1000],niz2[1000],vel1,vel2,i,niz[1000];
	printf("Unesite velicinu niza brojeva: ") ;
	scanf("%d",&vel1);
	printf("Unesite niz brojeva: ");
	for(i=0;i<vel1;i++) {
		scanf("%d ",&niz1[i]);
	}
	printf("Unesite velicniu niza cifara: ");
	scanf("%d",&vel2);
	printf("Unesite niz cifara: ");
	for(i=0;i<vel2;i++) {
		scanf("%d ",&niz2[i]);
	}
	niz[i]=izbaci_cifre(niz1,vel1,niz2,vel2);
	printf("%d",niz[i]);
	return 0;
}