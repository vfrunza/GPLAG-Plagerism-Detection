#include <stdio.h>
#define vel 100000
	int prost (int x){
	int i;
	for(i=2;i<x-1;i++){
		if(x%i==0)
		return 0;
	}
	
	return 1;
	}
	


	int daj_prost (){
	int i;
	static int a=1; // u a spasavamo proste brojeve 
	for(i=a+1;i<vel;i++){  //ide svaki put od iduceg prostog broja 
		int vr=prost(i); //ispitujemo jel nam i prost broj 
		if(vr==1){
			a=i;   //nasa staticna promjenjiva postaje i, da bi iduci put krenula od iduceg broja 
			return i;
		}
	}
}


	int main() {
	int a,b,s=0,i;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<1)
		printf("A nije prirodan broj.\n");
		else if(a>=b)
		printf("A nije manje od B.\n");
		
	}
	while (a<1 || a>=b);
	for(i=0;i<b;i++){
		int vr=daj_prost();
		if(vr>a && vr<b)
		s+=vr;
		
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,s);
	
	return 0;
}
