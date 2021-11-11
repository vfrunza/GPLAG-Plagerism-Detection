#include <stdio.h>
int daj_prost() {
	static int broj=2;
	int nije_prost=1;
	int i=0;
	while(nije_prost)
	{
		nije_prost=0;
		for(i=2;i<broj;i++)
				if(broj%i==0) nije_prost=1; 
				broj++;
	}
	 return broj-1;
}
int main() {
	int x,y,z=0,i=0,sum=0;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &x, &y);
	if(x<=0) printf("A nije prirodan broj.\n");
	if(x>=y) printf("A nije manje od B.\n"); 
	}
	while(x<=0||y<=0||x>=y);
	for(i=x;i<y;i++)
	{
	z=daj_prost();
	if(z<=x||z>=y) continue;
	sum=sum+z;
	}
	printf("Suma prostih brojeva izmedju %d ",x);
	printf("i %d ",y);
	printf("je %d.",sum);
	return 0;
}
