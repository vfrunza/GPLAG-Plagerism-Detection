#include <stdio.h>
#include <stdlib.h>

int brojac_cifara(int broj)
{
	int temp=0,brojac=0;
	do {
		temp=broj%10;
		brojac++;
		broj/=10;
	} while(broj!=0);
	return brojac;
}

int main()
{

	int x=0,y=0,n=0,niz1[100]= {0},niz2[1000]= {0};
	int br=0,b=0,j=0,i=0,l=0,k=0,temp=0,p,logicka=0,brojac=0;
	char c;

	do {
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);

	} while(n<0);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; ++i) {
		scanf("%d",&x);
		niz1[i]=x;
	}
	
	for(i=0;i<n;++i) {
		logicka=1;
		b=brojac_cifara(niz1[i]);
		while(b>0){
		if(logicka){
			if(b==1){
				temp=niz1[i]%10;
				niz2[k++]=temp;
				niz2[k++]=1;
				logicka=0;
			}
			else if(b==b-1){
				temp=niz1[i]%10;
				logicka=0;
			}
			else{
				for(j=0;j<b-1;++j){
					 p=niz1[i]/10;
					 p%=10;
					 temp=p;
				}
			}
			
			niz1[i]/=10;
	}
		else{
			if(b==b-1){
				p=niz1[i]%10;
				if(p==temp)
					brojac++;
				else
					niz2[k++]=temp;
					niz2[k++]=brojac;
					brojac=0;
			}
			else{
				for(j=0;j<b-1;++j){
					 p=niz1[i]/10;
					 p%=10;
					 if(p==temp)
					 	brojac++;
					 else
					 	niz2[k++]=temp;
					niz2[k++]=brojac;
					brojac=0;
				}
		}

	}
	b--;
}

}
	printf("Finalni niz glasi: ");
	for(i=0; i<k; ++i)
		printf("%d ",niz2[i]);
	return 0;
}
