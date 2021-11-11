#include <stdio.h>
int daj_prost(){
	static int n=2;
	/* Koristimo beskonacnu for petlju i trazimo prost broj */
	for(;;){
		int i,cs=1;
		for(i=2;i<n;i++){
			if(n%i==0)
			cs=0;
			if(cs==0){
				n++;break;
			}
		}
		/* Sacuvamo nadjeni prost broj u cs, zatim uvecamo da sljedeci put ispituje sljedeci prost broj */
		if(cs){cs=n;
		n++;
		return cs;}
	}
}
int main(){
	int a,b,suma=0,i,pom,p;
	for(;;){
		int dobro=1;
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&a,&b);
		/* Osigurati unos prirodnog broja i da je A<B */
		if(a<=0){
			printf("A nije prirodan broj.\n");
			dobro=0;
		}
		else if(a>=b){
			printf("A nije manje od B.\n");
			dobro=0;
		}
		if(dobro)break;
	}
	/* Suma prostih brojeva koji se nalaze izmedu A i B */
	pom=daj_prost(); 
	p=a;
	p++;
	for(i=p;i<b;i++){
		for(;i>pom;){
			pom=daj_prost();
		}
		if(i==pom)
		suma+=pom;
	} printf ("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}