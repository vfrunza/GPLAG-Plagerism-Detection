#include <stdio.h>

int daj_prost()	{
	static int adis=1;
	int i, br=0;
	adis++;
	for(i=2;i<adis;i++){
		if((adis%i)==0){br++;}
	}
	if(br==0)return adis;
	else return daj_prost();
}

int main() {
	int a, b, b1=0, b2=0, b3=0, suma=0, temp=0;
	/* Unos brojeva A i B */
	do{
		 if(b3>0){printf("A nije prirodan broj.\n"); b3=0;}
	else if(b1>0){printf("A nije manje od B.\n"); b1=0;}
	else if(b2>0){printf("A nije prirodan broj.\n"); b2=0;}
	
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a,&b);

	if(a>=b)b1++;
	if(a<0)b2++;
	if(a==0)b3++;
	}while(a>=b||a<=0);
	/* Kraj unosa brojeva A i B */
	
	/* Pozivanje funkcije u svrhu sabiranja prostih brojeva između A i B */
	while(1){
		temp=daj_prost();
		if (temp>a && temp<b)suma=suma+temp;
		if (temp>=b)break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	return 0;
}
