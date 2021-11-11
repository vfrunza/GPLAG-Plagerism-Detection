#include <stdio.h>
int daj_prost(){
	static int x=1;
	int i,prost;
	do{
		x++;
		prost=1;
		if(x==2)
		break;
		else{
			for(i=2;i<x;i++){
				if(x%i==0){
					prost=0;
					break;
				}
			}
		}
	}
	while (prost==0);
	return x;
}

int main() {
	int x,y,zbir=0,t=0;
	do {
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &x, &y);
		if (x>0 && y>0 && x<y)
		break;
		else if (x<0 || x==0)
		printf ("A nije prirodan broj.\n");
		else if (x==y || y<x )
		printf ("A nije manje od B.\n");
	}
	while(1);
	while(t<y){
		t=daj_prost();
		if(t>x && t<y)
		zbir=zbir+t;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", x,y,zbir);
	return 0;
}