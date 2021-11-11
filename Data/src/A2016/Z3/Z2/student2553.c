#include <stdio.h>
int suma_cifara(int broj){
	int suma=0,cifra;
	if (broj<0)broj*=-1;
	do{
		cifra=broj%10;
		suma+=cifra;
		broj=broj/10;
	}while(broj!=0);
	return suma;
}
int max_clan_niza(int niz[],int brclan){
	int i,max;
	max=niz[0];
	for(i=0;i<brclan;i++){if(niz[i]>max) max=niz[i];}
	return max;
}
void ubaci(int stari_niz[],int brclan){
	int i,j,velicinaniza=brclan;
	/*printf("\n brclan %d \n",brclan);*/
	for (i=0;i<brclan*2;i++){
		if(i%2!=0){
			for(j=velicinaniza;j>i;j--){
				stari_niz[j]=stari_niz[j-1];
			}
			velicinaniza++;
			stari_niz[i]=suma_cifara(stari_niz[i-1]);
		}
	}
		
}
int izbaci(int stari_niz[],int brclanova){
	int i,j,maxclan,prvibroj=0,drugibroj=1,fib=1;
	
	maxclan=max_clan_niza(stari_niz,brclanova);
	
	while(fib<maxclan){
		fib=prvibroj+drugibroj;
		prvibroj=drugibroj;
		drugibroj=fib;
		if (fib>maxclan) break;
	/*	printf(" %d ",fib);*/
		for(i=0;i<brclanova;i++){
			if(stari_niz[i]==fib){
				for(j=i;j<(brclanova-1);j++){stari_niz[j]=stari_niz[j+1];}
				brclanova--;
				i--;
			}
		}
	}
	return brclanova;	
}
int main() {
	int niz[20]={0};
	int i,br;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
/*	for(i=0;i<20;i++){
		if(i!=(20-1))
		printf(" %d,",niz[i]);
		else printf(" %d",niz[i]);
	}*/
	br=izbaci(niz,20);
	printf("Modificirani niz glasi:");
	for(i=0;i<br;i++){
		if(i!=(br-1))
		printf(" %d,",niz[i]);
		else printf(" %d.",niz[i]);
	}
	return 0;
}
