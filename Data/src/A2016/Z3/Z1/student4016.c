#include <stdio.h>

long int daj_prost(){
	static long int pamti=0;
	long int i,j,povrat, prekid=0,brojac=-1;
	for(i=2;i<2147483640+7;i++){
		prekid=0;
		for(j=2;j<i/2+1;j++){
			if(i%j==0){prekid=1;}
			}
			if(prekid==0)brojac++;
			if(pamti==brojac){povrat=i;pamti++;break;}
		}
		return povrat;
}

int main() {
	//printf("Zadaća 3, Zadatak 1");
	int radi=1,i,j,a,b,temp;
	long long int brojac=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<=0)printf("A nije prirodan broj.\n");
		else if(a>=b)printf("A nije manje od B.\n");
		else radi=0;
	}while(radi==1);
	do{
		temp=daj_prost();
		if(temp<=a)continue;
		else if(temp<b)brojac+=temp;
	}while(temp<b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,brojac);
	return 0;
}
