#include <stdio.h>

int izbaci_cifre(int *niz,int vel,int *cifre,int velcifri)
{
	int i,j,cifra,istina,tmp,k;
	
	for(i=0;i<velcifri;i++){
		if(cifre[i]<0 || cifre[i]>9) return 0;
		for(k=0;k<i;k++) if(cifre[i]==cifre[k]) return 0;
	}
	
	for(i=0;i<vel;i++){
		tmp=0;
		do{
			istina=0;
			cifra=niz[i]%10;
			for(j=0;j<velcifri;j++) if(cifra==cifre[j] || -cifra==cifre[j]) istina=1;
			if(istina==0){
			tmp*=10;
			tmp+=cifra;
			}
			niz[i]/=10;
		} while(niz[i]!=0);
		
		do{
			niz[i]*=10;
			niz[i]+=tmp%10;
			tmp/=10;
		} while(tmp!=0);
	}
	
	return 1;
}

int main(){
	int i;
	int niz[5]={-1654,-236,236,-2504,-3521,0};
	int cif[]={7,0,3};
	izbaci_cifre(niz,5,cif,3);
	
	for(i=0;i<5;i++) printf("%d",niz[i]);
	return 0;
}