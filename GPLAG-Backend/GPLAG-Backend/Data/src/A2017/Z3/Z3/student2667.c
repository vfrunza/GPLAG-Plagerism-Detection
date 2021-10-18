#include <stdio.h>
#include <math.h>
int izbaci_cifre(int *niz1,int vel1,int *niz2,int vel2){
	int pomocni[100],i,j,m=0,broj,negativan=0,cifra,k,ima=1;

	for(i=0;i<vel2;i++){
		if(niz2[i]<0 || niz2[i]>9 ) return 0;
	}
	for(i=0;i<vel2;i++){
		for(j=i+1;j<vel2;j++){
			if(niz2[i]==niz2[j]) return 0;
	}
	}

	for(i=0;i<vel1;i++)	{
		if(niz1[i]<0) negativan=1;
		niz1[i]=fabs(niz1[i]);
		while(niz1[i]!=0){
			cifra=niz1[i]%10;
	     	ima=1;
	     for(j=0;j<vel2;j++){
	     	if(cifra==niz2[j]) ima=0;

	     }
	     	if(ima) pomocni[m++]=cifra;
	  		niz1[i]=niz1[i]/10;
	}
	broj=0;
for(k=m-1;k>=0;k--){
	broj=broj*10+pomocni[k];
	}
m=0;
if(negativan)
	niz1[i]=((-1)*broj);
else 
	niz1[i]=(broj);
negativan=0;
cifra=0;
}


return 1;
}
int main() {
int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
int i;
i=izbaci_cifre(brojevi, 2, cifre, 2);
printf(" %d %d", brojevi[0], brojevi[1]);




	return 0;
}
