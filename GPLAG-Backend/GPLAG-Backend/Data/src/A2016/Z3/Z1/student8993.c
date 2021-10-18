#include <stdio.h>

int daj_prost() {
	int i=0;
	int prost=1;
	static int n=2;
	do {
		prost=1;
	for(i=2;i<n-1;i++) { 
		if(n%i==0) 
		prost=0; }
		if(prost==1)
			break;
		else n++; 
	} while(1);
	n++;
	return n-1;
}

int main() {
	
	int a,b,x,suma=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d",&a);
	scanf("%d",&b);
	if(a<=0) 
	printf("A nije prirodan broj.");
    while(a<=0) {
    	printf("\nUnesite brojeve A i B: ");
    	scanf("%d",&a);
    	scanf("%d",&b);
    	if(a>0) break;
    	else printf("A nije prirodan broj.");
    }
    if(a>b || a==b)
    printf("A nije manje od B.");
    while(a>b || a==b || a<=0) {
    	printf("\nUnesite brojeve A i B: ");
    	scanf("%d",&a);
    	scanf("%d",&b);
    	if(a<0) printf("A nije prirodan broj.");
    	else if(a<b && a>0) break;
    	else printf("A nije manje od B.");
    }
	while((x=daj_prost())<b) {
		if(x>a)
		suma=suma+x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma); 
	
	return 0;
}
