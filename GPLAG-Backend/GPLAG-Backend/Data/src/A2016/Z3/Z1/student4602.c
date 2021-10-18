#include <stdio.h>
int daj_prost(){
	int broj,logicka,i;
	static int zeko=1;
	zeko++;
	logicka=0;
	for (i=2;i<zeko;i++){
		if (zeko%i==0){
			logicka=1;
			break;
	}
}
if (logicka==0)return zeko;
else return daj_prost();
}
int main() {
 int a=-1,b=-1,i,c=0;
 int suma=0;
 int neka,nesto;
 /*printf("Unesite brojeve A i B: ");
 scanf("%d" "%d",&a,&b);*/
 neka=a;
 while(a<1||b<1||a>=b){
  printf("Unesite brojeve A i B: ");
 scanf("%d" "%d",&a,&b);
 if(a<1)printf("A nije prirodan broj.\n");
 if (a>=b)printf("A nije manje od B.\n");}
 if(b<1)printf("B nije prirodan broj.\n");
 
 for(;;){c++;if (c==10)break;}
 
 for(;;){
 	nesto=daj_prost();
 	
 	
 	if (nesto>a&&nesto<b)suma+=nesto;
 	if(nesto>=b)break;
 	i++;
 }
 //for(i=a;i<b;i++){suma=suma+daj_prost();}
 
 printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
 
 
 
	return 0;
}
