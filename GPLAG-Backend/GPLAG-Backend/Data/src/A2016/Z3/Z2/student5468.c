#include <stdio.h>
#include <stdlib.h>
	void ubaci (int niz[],int vel){
		int i,temp[100],zbir[100]={0},cifra,j=0;
			for(i=0; i<vel; i++){
			temp[i]=niz[i];
			while(niz[i]!=0){
				cifra=abs(niz[i]%10);
				niz[i]=abs(niz[i]/10);
				zbir[i]+=cifra;
			}
			niz[i]=temp[i];
		}
		for(i=1; i<vel*2; i+=2){
			for( ; j<vel; ){
			niz[i]=zbir[j];
			niz[i-1]=temp[j];
			j++;
			break;
			}
		}
	}
	int izbaci (int niz[],int vel){
		int i,fibo[40],j,k;
		fibo[0]=1;
		fibo[1]=1;
		for(i=2; i<40; i++)
			fibo[i]=fibo[i-2]+fibo[i-1];
		for(i=0; i<vel; i++){
			for(j=0; j<40; j++){
				if(niz[i]==fibo[j]){
					for(k=i; k<vel-1; k++)
						niz[k]=niz[k+1];
					vel--;
					i--;
					break;
				}
			}
		}
		return vel;
	}
int main() {
	int i,niz[20],vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d",&niz[i]);
	vel=i;
	ubaci(niz,vel);
	vel=vel*2;
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++){
		if (i==vel-1)
		printf("%d.",niz[i]);
		else
		printf("%d, ",niz[i]);
	}
	return 0;
}
