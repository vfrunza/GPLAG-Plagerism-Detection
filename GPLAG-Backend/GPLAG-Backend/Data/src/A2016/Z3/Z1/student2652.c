#include <stdio.h>
int daj_prost ()
{
	static int x = 1;
	static int p = 2;
	int i,j,c;
	c=1;
	if (x==1){x++; return p;}
	for (j = p+1;;j++)
	{
		for (i = 2; i<j; i++)
		{
			if (j%i==0){c=0; break;}
		}
		if (c==1){p =j; x++; return p;}
		c = 1;
	}
}
int main ()
{
	int a,b,c,S,p;
	c = 1;
	S = 0;
	do {
	printf("Unesite brojeve A i B: ");
	scanf ("%d",&a);
	scanf ("%d",&b);
	if (a <= 0) {printf("A nije prirodan broj.\n"); continue; }
	/*if (b <= 0) {printf("B nije prirodan broj.\n"); continue; }*/
	if (a >= b) {printf("A nije manje od B.\n"); continue; }
	c = 0;
	}
	while (c!= 0);
	for (;;){
		p = daj_prost(); 
		if ((p>a) && (p<b)) {S=S+p;}
		if (p>b) {break;}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,S);
	return 0;
}


